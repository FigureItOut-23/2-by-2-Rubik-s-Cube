#include "main.h" //includes header file "main.h"

/*
Purpose of File:
This file will hold the code responsible for rotating and flipping the cube.
Primary code that most other files use.
*/

//function to rotate the cube as a whole. Uses the motors from the rotating base
void rotate(int angle) 
{
	cur_angle += angle; //accumulates the angle instead of resetting it to
	//preven error build up
	motor[ROTATOR_MOTOR] = TURN_POW*(angle/abs(angle)); //sets base motor to 
	//turn 
	
	if(getMotorEncoder(ROTATOR_MOTOR) < cur_angle)//if motorEncoder value is 
	//less than current angle...
	{
		//turns until motorEncoder value is more than current angle
		while(getMotorEncoder(ROTATOR_MOTOR) < cur_angle) 
		{}
	}
	else //otherwise
	{ 
		//turns until motorEncoder value is less than current angle
		while(getMotorEncoder(ROTATOR_MOTOR) > cur_angle)
		{}
	}
	motor[ROTATOR_MOTOR] = 0; //sets motor power to 0
}


void finishingMove(int angle, int final_pow)
{
	cur_angle += angle;
	motor[ROTATOR_MOTOR] = final_pow*(angle/abs(angle));
	if(getMotorEncoder(ROTATOR_MOTOR) < cur_angle)
	{
		while(getMotorEncoder(ROTATOR_MOTOR) < cur_angle)
		{}
	}
	else{
		while(getMotorEncoder(ROTATOR_MOTOR) > cur_angle)
		{}
	}
	motor[ROTATOR_MOTOR] = 0;
  	motor[WHACKER_MOTOR] = final_pow;
	wait1Msec(10000);
  	motor[WHACKER_MOTOR] = 0;
}

//function idential to rotate function but includes index mapping.
//index mapping means that all indices of the cube are changed corresponding to
//a rotation of the entire cube
void rot(int angle, int * cube)
{

	cur_angle += angle;
	motor[ROTATOR_MOTOR] = TURN_POW*(angle/abs(angle));
	if(getMotorEncoder(ROTATOR_MOTOR) < cur_angle)
	{
		while(getMotorEncoder(ROTATOR_MOTOR) < cur_angle)
		{}
	}
	else{
		while(getMotorEncoder(ROTATOR_MOTOR) > cur_angle)
		{}
	}
	motor[ROTATOR_MOTOR] = 0;


	//Move Virtual Cube
	//indice mappings
	if(angle < 0)
	{
		int temp[24]; //temp array to store old values and swap with cube array
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
	else
	{
		for(int count = 0; count < 3; count++)
		{
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
	}
}

//function responsible for the mechanism that flips the cube
void flip()
{

	//Flip cube
	motor[FLIPPER_MOTOR] = -15; //power of pushing arm
	nMotorEncoder[FLIPPER_MOTOR] = 0; //resets motor encoder of this arm motor
	while(abs(nMotorEncoder[FLIPPER_MOTOR]) < 95) //95 is degree of motion 
	//needed to flip cube without over turning it
	{}
	motor[FLIPPER_MOTOR] = 0;
	motor[FLIPPER_MOTOR] = 10;
	wait1Msec(1500); //waits 1.5 seconds so arm is pushing for that amount of 
	//time
	motor[FLIPPER_MOTOR] = 0;

	//Whack Cube 
	//whacks cube back into base using the whacker arm and motor
	motor[WHACKER_MOTOR] = -20;
	wait1Msec(1000);
	motor[WHACKER_MOTOR] = 0;
	motor[WHACKER_MOTOR] = 20;
	wait1Msec(1000);
	motor[WHACKER_MOTOR] = 0;

}

//identical to flip function but tracks the indice changes of the cube.
void trackedflip(int * cube)
{

	//Flip cube
	motor[FLIPPER_MOTOR] = -15;
	nMotorEncoder[FLIPPER_MOTOR] = 0;
	while(abs(nMotorEncoder[FLIPPER_MOTOR]) < 95)
	{}
	motor[FLIPPER_MOTOR] = 0;
	motor[FLIPPER_MOTOR] = 10;
	wait1Msec(1500);
	motor[FLIPPER_MOTOR] = 0;

	//Whack Cube
	motor[WHACKER_MOTOR] = -20;
	wait1Msec(1000);
	motor[WHACKER_MOTOR] = 0;
	motor[WHACKER_MOTOR] = 20;
	wait1Msec(1000);
	motor[WHACKER_MOTOR] = 0;


	int temp[24]; //temp array to store temp values of cube array, so that the 
	//indices of the cube array can swap accordingly
	//Front Rotation
	temp[0]=cube[23];
	cube[23]=cube[20];
	cube[20]=cube[21];
	cube[21]=cube[22];
	cube[22]=temp[0];
	//Back Rotation
	temp[1]=cube[16];
	cube[16]=cube[19];
	cube[19]=cube[18];
	cube[18]=cube[17];
	cube[17]=temp[1];
	//Sides Rotation
	//Store Top into Temp Array

	temp[2]=cube[0];
	temp[3]=cube[1];
	temp[4]=cube[2];
	temp[5]=cube[3];

	cube[0]=cube[4];
	cube[1]=cube[5];
	cube[2]=cube[6];
	cube[3]=cube[7];

	cube[4]=cube[8];
	cube[5]=cube[9];
	cube[6]=cube[10];
	cube[7]=cube[11];

	cube[8]=cube[12];
	cube[9]=cube[13];
	cube[10]=cube[14];
	cube[11]=cube[15];

	cube[12]=temp[2];
	cube[13]=temp[3];
	cube[14]=temp[4];
	cube[15]=temp[5];

}


//function that uses whacker to hold the top of the cube in place allowing for
//twisting of the cube to get different orientations
void hold()
{

	nMotorEncoder[WHACKER_MOTOR] = 0;
  	motor[WHACKER_MOTOR] = -20;
	wait1Msec(700);
	motor[WHACKER_MOTOR] = 0;

}

//function to put whacker back in its original position
void returnWhacker()
{
	motor[WHACKER_MOTOR] = 20;
	wait1Msec(1000);
 	motor[WHACKER_MOTOR] = 0;

}


//Right face rotation
//that takes direction (clockwise or counterclockwise) and the cube array that
//is passed by pointer so that we can change indices of virtual cube as well.

void R(int direction, int* cube)
{
	if(direction == CW) //if direction picked is clockwise...
	{
		rotate(CW); //Rotate 90 degrees clockwise
		rotate(CW);//Rotate 90 degrees clockwise
		flip(); //flip
		hold();
		rotate(CCW + WHACKER_OFFSET); //Whacker offset is integer value chosen
		//to account for overturning due to inertia
		returnWhacker();
		rotate(CCW - WHACKER_OFFSET);
    	flip();
    	/*
    	Note: rot() and trackedFlip() are not being used as there is no point to
    	change indices for intermediate steps. It only matters for when the 
    	proper rotatons such as R are finished    	
    	*/
	    
	    //Map Virtual Cube
	    //change indices affected by right face rotation...
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

	else //if counterclockwise...
	{
		rotate(CW);
		rotate(CW);//Rotate 180 degrees
		flip();
		hold();
		rotate(CW - WHACKER_OFFSET);
    	returnWhacker();
		rotate(CW + WHACKER_OFFSET);
		flip();
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



//Upper face rotation function. Similar to R(). Same concept but does everything
//relative to the top face
void U(int direction, int* cube)
{
	if(direction==CW)
	{
		hold();
		rotate(CCW + WHACKER_OFFSET);
		returnWhacker();
		rotate(CW - WHACKER_OFFSET);
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

	else //counterclockwise...
	{
		hold();
		rotate(CW - WHACKER_OFFSET);
		returnWhacker();
		rotate(CCW + WHACKER_OFFSET);
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


//Back face rotation function. Similar to R(). Same concept but does everything
//relative to the back face
void B(int direction, int* cube)
{

	if(direction == CW)
	{
		rotate(CCW);
		flip();
		flip();
		flip();
	  	hold();
		rotate(CCW + WHACKER_OFFSET);
		returnWhacker();
		flip();
		rotate(CW - WHACKER_OFFSET);

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
   	rotate(CCW);
		flip();
		flip();
		flip();
		hold();
		rotate(CW - WHACKER_OFFSET);
		returnWhacker();
		rotate(WHACKER_OFFSET);
		flip();
		rotate(CW);

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

//front face rotation function. Similar to R(). Same concept but does everything
//relative to the front face
void F(int direction, int* cube)
{
	if(direction==CW)
	{
  	rotate(CW);
		flip();
		hold();
		rotate(CCW + WHACKER_OFFSET);
		returnWhacker();
		rotate(CCW - WHACKER_OFFSET);
		flip();
		rotate(CW);
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
		rotate(CW);
		flip();
		hold();
		rotate(CW - WHACKER_OFFSET);
		returnWhacker();
		rotate(CW + WHACKER_OFFSET);
		flip();
		rotate(CW);

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

//All the algorithm functions have cube as param as the rotation functions need
//it in order to update the virtual cube as well. Algorithms of solving the cube
//are a different combinations of the rotation functions
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
