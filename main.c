#include "AlgorithmsAndCaseFinder.c";
#include "ScanningCube.c"
#include "EndCode.c"

task EmergencyStop()
{
	while(SensorValue[S3] < 10)
	{
		wait1Msec(500);
	}
	//Reset arms and stuff
	stopAllTasks();
}

task playMusic()
{
	int time = 300;
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
		time -= 20;
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
task main()
{
cube[0]=0;    //
cube[1]=0;    //
cube[2]=5;    //
cube[3]=1;    //
cube[4]=4; //
cube[5]=1;
cube[6]=1;
cube[7]=3;    //
cube[8]=2;
cube[9]=2;
cube[10]=2;
cube[11]=2;
cube[12]=3;
cube[13]=1;    //
cube[14]=4;    //
cube[15]=3;
cube[16]=4;
cube[17]=4;
cube[18]=3;    //
cube[19]=5;    //
cube[20]=5;
cube[21]=5;
cube[22]=0;    //
cube[23]=0;    //

	SensorType[S1] = sensorEV3_Color;
	SensorType[S3] = sensorEV3_Ultrasonic;
	wait1Msec(50);

	setMotorBrakeMode(motorC, motorBrake);
	setMotorBrakeMode(motorA, motorBrake);
	//startTask(playMusic);
	nMotorEncoder[motorA] = 0;
	nMotorEncoder[motorB] = 0;
	nMotorEncoder[motorC] = 0;
	nMotorEncoder[motorD] = 0;

	int colour_boundaries_red[6] = {0,0,0,0,0,0};
	int colour_boundaries_green[6] = {0,0,0,0,0,0};
	int colour_boundaries_blue[6] = {0,0,0,0,0,0};

	const bool cailbrateSensor = true;

	if(calibrateSensor)
	{
		while(SensorValue[S3] > 7)
		{}
		wait1Msec(5000);
		motor[motorC] = -SENSOR_POWER/2;
		wait1Msec(500);
		motor[motorC] = 0;
		CalibrateColourSensor(colour_boundaries_red, colour_boundaries_green, colour_boundaries_blue);
		while(SensorValue[S3] < 7)
		{}
		wait1Msec(2000);
	}
	else
	{

	}
	//startTask(EmergencyStop);

	while(SensorValue[S3] > 7)
	{}

	wait1Msec(3000);

	motor[motorC] = -SENSOR_POWER;
	wait1Msec(700);
	motor[motorC] = 0;
	wait1Msec(500);
	//playSound(soundBeepBeep);

	ScanCube(cube, colour_boundaries_red, colour_boundaries_green, colour_boundaries_blue);

	wait1Msec(2000);

	cubeCase = findCase(cube);
	orientFace(cube);
	FinishCube(cube);
	//playSound(soundUpwardTones);
}
