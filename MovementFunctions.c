#include "main.h"

void rotate(int angle)
{
/*
	cur_angle += angle;
	motor[motorD] = TURN_POW*(angle/abs(angle));
	if(getMotorEncoder(motorD) < cur_angle)
	{
		while(getMotorEncoder(motorD) < cur_angle)
		{}
	}
	else{
		while(getMotorEncoder(motorD) > cur_angle)
		{}
	}
	motor[motorD] = 0;
*/
}

void rot(int angle, int * cube)
{
	/*cur_angle += angle;
	motor[motorD] = TURN_POW*(angle/abs(angle));
	if(getMotorEncoder(motorD) < cur_angle)
	{
		while(getMotorEncoder(motorD) < cur_angle)
		{}
	}
	else{
		while(getMotorEncoder(motorD) > cur_angle)
		{}
	}
	motor[motorD] = 0;

	*/

	//Move Virtual Cube

	int temp[24];
	//Yellow (Top) Rotation
	temp[0]=cube[0];
	cube[0]=cube[1];
	cube[1]=cube[2];
	cube[2]=cube[3];
	cube[3]=temp[0];

	//White (Bottom) Rotation

	temp[1]=cube[10];
	cube[10]=cube[9];
	cube[9]=cube[8];
	cube[8]=cube[11];
	cube[11]=temp[1];

	//Sides Rotation
	//Store Orange into Temp Array

	temp[2]=cube[22];
	temp[3]=cube[23];
	temp[4]=cube[20];
	temp[5]=cube[21];

	cube[22]=cube[13];
	cube[23]=cube[14];
	cube[20]=cube[15];
	cube[21]=cube[12];

	cube[13]=cube[18];
	cube[14]=cube[19];
	cube[15]=cube[16];
	cube[12]=cube[17];

	cube[18]=cube[7];
	cube[19]=cube[4];
	cube[16]=cube[5];
	cube[17]=cube[6];

	cube[7]=temp[2];
	cube[4]=temp[3];
	cube[5]=temp[4];
	cube[6]=temp[5];



}


void flip()
{
/*
	//Flip cube
	motor[motorA] = -15;
	nMotorEncoder[motorA] = 0;
	while(abs(nMotorEncoder[motorA]) < 95)
	{}
	motor[motorA] = 0;
	motor[motorA] = 10;
	wait1Msec(1500);
	motor[motorA] = 0;

	//Whack Cube
	motor[motorB] = -20;
	wait1Msec(1000);
	motor[motorB] = 0;
	motor[motorB] = 20;
	wait1Msec(1000);
	motor[motorB] = 0;

}
*/
void hold()
{
/*
	nMotorEncoder[motorB] = 0;
  motor[motorB] = -10;
while(abs(nMotorEncoder[motorB]) < 140)
{}
motor[motorB] = 0;
*/
}

void returnWhacker()
{
/*
	motor[motorB] = -20;
	wait1Msec(500);
  motor[motorB] = 0;
  motor[motorB] = 20;
	wait1Msec(1000);
  motor[motorB] = 0;
*/
}


//Right face rotation
void R(int direction, int* cube)
{
	if(direction == CW)
	{
/*
		rotate(CW);
		rotate(CW);//Rotate 180 degrees
		flip();
		hold();
		rotate(CCW + WACKER_OFFSET);
		//wait1Msec(100000);
		returnWhacker();
		rotate(CCW - WACKER_OFFSET);
    flip();
    //rotate(-20);
*/
    //Map Virtual Cube
    int temp[3]={0,0,0};

		temp[0]= cube[22];
		temp[1]= cube[21];
		cube[22]=cube[10];
		cube[21]=cube[9];
		cube[10]=cube[16];
		cube[9]=cube[19];
		cube[16]=cube[0];
		cube[19]=cube[3];
		cube[0]=temp[0];
		cube[3]=temp[1];

		temp[2]=cube[14];
		cube[14]=cube[15];
		cube[15]=cube[12];
		cube[12]=cube[13];
		cube[13]=temp[2];
	}

	else
	{
	/*
		rotate(CW);
		rotate(CW);//Rotate 180 degrees
		flip();
		hold();
		rotate(CW - WACKER_OFFSET);
    returnWhacker();
		rotate(CW + WACKER_OFFSET);
		flip();*/
		//Map Virtual Cube
		int temp[3]={0,0,0};

		temp[0]= cube[16];
		temp[1]= cube[19];
		cube[16]=cube[10];
		cube[19]=cube[9];
		cube[10]=cube[22];
		cube[9]=cube[21];
		cube[22]=cube[0];
		cube[21]=cube[3];
		cube[0]=temp[0];
		cube[3]=temp[1];

		temp[2]=cube[14];
		cube[14]=cube[13];
		cube[13]=cube[12];
		cube[12]=cube[15];
		cube[15]=temp[2];
	}

}



//Upper face
void U(int direction, int* cube)
{
	/*if(direction==CW)
	{
		hold();
		rotate(CCW + WACKER_OFFSET);
		returnWhacker();
		rotate(CW - WACKER_OFFSET);
*/
		//Map Virtual Cube
		int temp[3]={0,0,0};

		temp[0]= cube[13];
		temp[1]= cube[14];
		cube[13]=cube[18];
		cube[14]=cube[19];
		cube[18]=cube[7];
		cube[19]=cube[4];
		cube[7]=cube[22];
		cube[4]=cube[23];
		cube[22]=temp[0];
		cube[23]=temp[1];

		temp[2]=cube[0];
		cube[0]=cube[1];
		cube[1]=cube[2];
		cube[2]=cube[3];
		cube[3]=temp[2];
	}

	else
	{
	/*	hold();
		rotate(CW - WACKER_OFFSET);
		returnWhacker();
		rotate(CCW + WACKER_OFFSET);
*/
		//Map Virtual Cube
		int temp[3]={0,0,0};

		temp[0]= cube[7];
		temp[1]= cube[4];
		cube[7]=cube[18];
		cube[4]=cube[19];
		cube[18]=cube[13];
		cube[19]=cube[14];
		cube[13]=cube[22];
		cube[14]=cube[23];
		cube[22]=temp[0];
		cube[23]=temp[1];

		temp[2]=cube[0];
		cube[0]=cube[3];
		cube[3]=cube[2];
		cube[2]=cube[1];
		cube[1]=temp[2];
	}
}

//Back face rotation
void B(int direction, int* cube)
{
/*
	if(direction == CW)
	{
		rotate(CCW);
		flip();
		flip();
		flip();
	  hold();
		rotate(CCW + WACKER_OFFSET);
		returnWhacker();
		flip();
		rotate(CW - WACKER_OFFSET);
*/
		//Map Virtual Cube
		int temp[3]={0,0,0};

		temp[0]= cube[12];
		temp[1]= cube[13];
		cube[12]=cube[8];
		cube[13]=cube[9];
		cube[8]=cube[4];
		cube[9]=cube[5];
		cube[4]=cube[0];
		cube[5]=cube[1];
		cube[0]=temp[0];
		cube[1]=temp[1];

		temp[2]=cube[16];
		cube[16]=cube[17];
		cube[17]=cube[18];
		cube[18]=cube[19];
		cube[19]=temp[2];
	}

	else
	{
   /* rotate(CCW);
		flip();
		flip();
		flip();
		hold();
		rotate(CW - WACKER_OFFSET);
		returnWhacker();
		flip();
		rotate(CW + WACKER_OFFSET);
*/
		//Map Virtual Cube
		int temp[3]={0,0,0};

		temp[0]= cube[4];
		temp[1]= cube[5];
		cube[4]=cube[8];
		cube[5]=cube[9];
		cube[8]=cube[12];
		cube[9]=cube[13];
		cube[12]=cube[0];
		cube[13]=cube[1];
		cube[0]=temp[0];
		cube[1]=temp[1];

		temp[2]=cube[16];
		cube[16]=cube[19];
		cube[19]=cube[18];
		cube[18]=cube[17];
		cube[17]=temp[2];
	}
}

//Front Face Rotation
void F(int direction, int* cube)
{
	if(direction==CW)
	{
  /*  rotate(CW);
		flip();
		hold();
		rotate(CCW + WACKER_OFFSET);
		returnWhacker();
		rotate(CCW - WACKER_OFFSET);
		flip();
		rotate(CW);
*/
		//Map Virtual Cube
		int temp[3]={0,0,0};

		temp[0]= cube[15];
		temp[1]= cube[14];
		cube[15]=cube[11];
		cube[14]=cube[10];
		cube[11]=cube[7];
		cube[10]=cube[6];
		cube[7]=cube[3];
		cube[6]=cube[2];
		cube[3]=temp[0];
		cube[2]=temp[1];

		temp[2]=cube[23];
		cube[23]=cube[22];
		cube[22]=cube[21];
		cube[21]=cube[20];
		cube[20]=temp[2];
	}

	else
	{
/*		rotate(CW);
		flip();
		hold();
		rotate(CW - WACKER_OFFSET);
		returnWhacker();
		rotate(CW + WACKER_OFFSET);
		flip();
		rotate(CW);
*/
		//Map Virtual Cube
		int temp[3]={0,0,0};

		temp[0]= cube[12];
		temp[1]= cube[13];
		cube[12]=cube[8];
		cube[13]=cube[9];
		cube[8]=cube[4];
		cube[9]=cube[5];
		cube[4]=cube[0];
		cube[5]=cube[1];
		cube[0]=temp[0];
		cube[1]=temp[1];

		temp[2]=cube[16];
		cube[16]=cube[17];
		cube[17]=cube[18];
		cube[18]=cube[19];
		cube[19]=temp[2];
	}
}

//Algorithms

void alg1(int* cube)
{
	R(CW, cube);
	B(CCW, cube);
	R(CW, cube);
	F(CW, cube);
	F(CW, cube);
	R(CCW, cube);
	B(CW, cube);
	R(CW, cube);
	F(CW, cube);
	F(CW, cube);
	R(CW, cube);
	R(CW, cube);
}

void alg2(int* cube)
{
	R(CW, cube);
	U(CW, cube);
	U(CW, cube);
	R(CCW, cube);
	U(CCW, cube);
	R(CW, cube);
	U(CCW, cube);
	R(CCW, cube);

}

void alg3(int* cube)
{
	R(CW, cube);
	U(CW, cube);
	R(CCW, cube);
	U(CW, cube);
	R(CW, cube);
	U(CW, cube);
	U(CW, cube);
	R(CCW, cube);
}
