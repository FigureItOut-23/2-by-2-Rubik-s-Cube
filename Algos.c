#include "FindCases.h"

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



int cube[6*4];
int bro;
task main()
{
cube[0]=3;    //
cube[1]=0;    //
cube[2]=1;    //
cube[3]=0;    //
cube[4]=1; //
cube[5]=1;
cube[6]=1;
cube[7]=5;    //
cube[8]=2;
cube[9]=2;
cube[10]=2;
cube[11]=2;
cube[12]=2;
cube[13]=0;    //
cube[14]=4;    //
cube[15]=3;
cube[16]=4;
cube[17]=4;
cube[18]=4;    //
cube[19]=5;    //
cube[20]=5;
cube[21]=5;
cube[22]=3;    //
cube[23]=0;    //
	SensorType[S1] = sensorEV3_Color;
	SensorType[S3] = sensorEV3_Ultrasonic;
	wait1Msec(50);

	setMotorBrakeMode(motorC, motorBrake);
	//startTask(playMusic);
	nMotorEncoder[motorA] = 0;
	nMotorEncoder[motorB] = 0;
	nMotorEncoder[motorC] = 0;
	nMotorEncoder[motorD] = 0;

	int colour_boundaries_red[6] = {0,0,0,0,0,0};
	int colour_boundaries_green[6] = {0,0,0,0,0,0};
	int colour_boundaries_blue[6] = {0,0,0,0,0,0};

	/*
	while(SensorValue[S3] > 7)
	{}
	wait1Msec(5000);
	//startTask(EmergencyStop);
	CalibrateColourSensor(colour_boundaries_red, colour_boundaries_green, colour_boundaries_blue);

	while(SensorValue[S3] < 7)
	{}

	wait1Msec(2000);

	while(SensorValue[S3] > 7)
	{}
	motor[motorC] = -SENSOR_POWER/2;
	wait1Msec(500);
	motor[motorC] = 0;
	wait1Msec(500);
	playSound(soundBeepBeep);
	*/
	//ScanCube(cube, colour_boundaries_red, colour_boundaries_green, colour_boundaries_blue);
	bro = findCase(cube);
	findCase(cube);
	orientFace(cube);
}
