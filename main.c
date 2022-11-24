#include "AlgorithmsAndCaseFinder.c";
#include "ScanningCube.c"
#include "EndCode.c"
#include "SetUpCube.c"
#include "FirstOrient.c"
#include "WhiteSolving.c"

task emergencyStop();


task playMusic()
{
	int time = 500;
	while(1==1)
	{
		for(int count = 0; count < 3; count++){
			playTone(523, 5);
			playTone(659, 5);
			playTone(880, 5);
			wait1Msec(time);
		}
		for(int count = 0; count < 3; count++){
			playTone(494, 5);
			playTone(659, 5);
			playTone(880, 5);
			wait1Msec(time);
		}
		for(int count = 0; count < 5; count++){
			playTone(494, 5);
			playTone(659, 5);
			playTone(784, 5);
			wait1Msec(time);
		}
		for(int count = 0; count < 3; count++){
			playTone(523, 5);
			playTone(659, 5);
			playTone(880, 5);
			wait1Msec(time);
		}
		time -= 50;
		if(time < 200)
		{
			break;
		}
	}
}
void WriteToFile(int* colour_boundaries_red, int* colour_boundaries_green, int* colour_boundaries_blue)
{
	long colourBoundariesFile = fileOpenWrite("Colour_Boundaries.txt");
	for(int face = 0; face < SIDES_CUBE; face++)
	{
		fileWriteFloat(colourBoundariesFile, colour_boundaries_red[face]);
		fileWriteFloat(colourBoundariesFile, colour_boundaries_green[face]);
		fileWriteFloat(colourBoundariesFile, colour_boundaries_blue[face]);
	}
	fileClose(colourBoundariesFile);
}

void ReadFromFile(int* colour_boundaries_red, int* colour_boundaries_green, int* colour_boundaries_blue)
{
	long colourBoundariesFile = fileOpenRead("Colour_Boundaries.txt");
	for(int face = 0; face < SIDES_CUBE; face++)
	{
		float rgb[3] = {0,0,0};
		fileReadFloat(colourBoundariesFile, &rgb[0]);
		fileReadFloat(colourBoundariesFile, &rgb[1]);
		fileReadFloat(colourBoundariesFile, &rgb[2]);
		colour_boundaries_red[face] = (int)rgb[0];
		colour_boundaries_green[face] = (int)rgb[1];
		colour_boundaries_blue[face] = (int)rgb[2];
	}
	fileClose(colourBoundariesFile);
}

int cube[6*4];
int cubeCase;
task solveCube()
{
cube[0]=2;    //
cube[1]=5;    //
cube[2]=0;    //
cube[3]=0;    //
cube[4]=2; //
cube[5]=0;
cube[6]=2;
cube[7]=5;    //
cube[8]=5;
cube[9]=0;
cube[10]=3;
cube[11]=3;
cube[12]=1;
cube[13]=1;    //
cube[14]=4;    //
cube[15]=2;
cube[16]=4;
cube[17]=1;
cube[18]=1;    //
cube[19]=4;    //
cube[20]=5;
cube[21]=4;
cube[22]=3;    //
cube[23]=3;    //

	SensorType[S1] = sensorEV3_Color;
	SensorType[S3] = sensorEV3_Ultrasonic;
	wait1Msec(50);

	setMotorBrakeMode(motorC, motorBrake);
	setMotorBrakeMode(motorA, motorBrake);

	nMotorEncoder[motorA] = 0;
	nMotorEncoder[motorB] = 0;
	nMotorEncoder[motorC] = 0;
	nMotorEncoder[motorD] = 0;
	int colour_boundaries_red[6] = {0,0,0,0,0,0};
	int colour_boundaries_green[6] = {0,0,0,0,0,0};
	int colour_boundaries_blue[6] = {0,0,0,0,0,0};
	const bool CALIBRATE_SENSOR = false;

	if(CALIBRATE_SENSOR)
	{
		while(SensorValue[S3] > 7)
		{}
		wait1Msec(5000);
		motor[motorC] = -SENSOR_POWER/2;
		wait1Msec(500);
		motor[motorC] = 0;
		CalibrateColourSensor(colour_boundaries_red, colour_boundaries_green, colour_boundaries_blue);
		WriteToFile(colour_boundaries_red, colour_boundaries_green, colour_boundaries_blue);
		while(SensorValue[S3] < 7)
		{}
		wait1Msec(2000);
	}
	else
	{
		ReadFromFile(colour_boundaries_red, colour_boundaries_green, colour_boundaries_blue);
	}

	while(SensorValue[S3] > 7)
	{}

	wait1Msec(3000);

	motor[motorC] = -SENSOR_POWER/2;
	wait1Msec(700);
	motor[motorC] = 0;
	wait1Msec(500);

	//Start timer
	time1[T1] = 0;

	ScanCube(cube, colour_boundaries_red, colour_boundaries_green, colour_boundaries_blue);

	startTask(emergencyStop);

	solvingWhite(cube);
	trackedflip(cube); trackedflip(cube);
	SetUpCube(cube);
	FirstOrient(cube);
	cubeCase = findCase(cube);
	orientFace(cube);
	FinishCube(cube);

	displayBigTextLine(5, "%.2f", time1[T1] * MILLI_MINUTES);

	//End Move
	hold();
	startTask(playMusic);
	wait1Msec(10000);
	finishingMove(CCW + WHACKER_OFFSET, 1);
	stopTask(playMusic);
	wait1Msec(1000);
	playSound(soundBeepBeep);
	eraseDisplay();
	stopTask(emergencyStop);
	done = true;
}
task emergencyStop()
{
	while(!getButtonPress(buttonLeft)){}
	while(getButtonPress(buttonLeft)){}
	stopTask(solveCube);
	//Reset motors
	returnWhacker();
	motor[SENSOR_MOTOR] = SENSOR_POWER;
	wait1Msec(500);
	motor[SENSOR_MOTOR] = 0;
	motor[FLIPPER_MOTOR] = 10;
	wait1Msec(1500);
	motor[FLIPPER_MOTOR] = 0;
	stopAllTasks();
}
task main()
{
	startTask(solveCube);
	while(!done){}
}
