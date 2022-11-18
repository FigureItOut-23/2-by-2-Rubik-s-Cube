#include "AlgorithmsAndCaseFinder.c";
#include "ScanningCube.c"
#include "EndCode.c"
<<<<<<< HEAD
#include "SetUpCube.c"
#include "FirstOrient.c"

=======
#include "WhiteSolving.c"
>>>>>>> 8a5cf11c1a6a077cb18d14430cf82694ecfc4765

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
<<<<<<< HEAD

cube[0]=2;    //
cube[1]=2;    //
cube[2]=2;    //
cube[3]=2;    //
cube[4]=4; //
cube[5]=1;
cube[6]=0;
cube[7]=4;    //
cube[8]=4;
cube[9]=5;
cube[10]=3;
cube[11]=3;
cube[12]=1;
cube[13]=3;    //
cube[14]=1;    //
cube[15]=0;
cube[16]=0;
cube[17]=0;
cube[18]=1;    //
cube[19]=5;    //
cube[20]=4;
cube[21]=5;
cube[22]=5;    //
cube[23]=3;    //
=======
cube[0]=2;    //
cube[1]=3;    //
cube[2]=2;    //
cube[3]=4;    //
cube[4]=5; //
cube[5]=3;
cube[6]=1;
cube[7]=3;    //
cube[8]=4;
cube[9]=0;
cube[10]=4;
cube[11]=5;
cube[12]=1;
cube[13]=5;    //
cube[14]=3;    //
cube[15]=2;
cube[16]=4;
cube[17]=2;
cube[18]=0;    //
cube[19]=1;    //
cube[20]=0;
cube[21]=1;
cube[22]=0;    //
cube[23]=5;    //

solvingWhite(cube);
>>>>>>> 8a5cf11c1a6a077cb18d14430cf82694ecfc4765
/*
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
*/
	int colour_boundaries_red[6] = {0,0,0,0,0,0};
	int colour_boundaries_green[6] = {0,0,0,0,0,0};
	int colour_boundaries_blue[6] = {0,0,0,0,0,0};
/*
<<<<<<< Updated upstream
	const bool calibrateSensor = false;

	if(calibrateSensor)
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
=======
/*
	while(SensorValue[S3] > 7)
	{}
	wait1Msec(5000);
	motor[motorC] = -SENSOR_POWER/2;
	wait1Msec(500);
	motor[motorC] = 0;
>>>>>>> Stashed changes
	//startTask(EmergencyStop);

	while(SensorValue[S3] > 7)
	{}

	wait1Msec(3000);

	motor[motorC] = -SENSOR_POWER;
	wait1Msec(700);
	motor[motorC] = 0;
	wait1Msec(500);
	//playSound(soundBeepBeep);
*/
	//ScanCube(cube, colour_boundaries_red, colour_boundaries_green, colour_boundaries_blue);

	//wait1Msec(2000);
		//solvingWhite(cube);

		SetUpCube(cube);
		FirstOrient(cube);

		cubeCase = findCase(cube);
		orientFace(cube);
		FinishCube(cube);
	//playSound(soundUpwardTones);
	*/
}
