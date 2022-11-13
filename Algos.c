//Solve First Layer
//White Face is solved and on top
const int DEGREES_TURN = 90;
const int TURN_POW = 12;
const int CCW = 90;
const int CW = -90;
const int WACKER_OFFSET = 15;
const int CORNERS_ON_FACE = 4;
int cur_angle = 0;

/*
void rotate(int direction)
{

  nMotorEncoder[motorD] = 0;

  if (direction == CCW){
    motor[motorD] = TURN_POW;
    while(getMotorEncoder(motorD) < DEGREES_TURN)
      { }
    motor[motorD] = 0;
  }
  else if(direction == CW){
    motor[motorD] = -TURN_POW;
    while(getMotorEncoder(motorD) > -DEGREES_TURN)
      { }
    motor[motorD] = 0;
    }
}
*/
void rotate(int angle)
{
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
}


void flip()
{
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

void hold()
{
	nMotorEncoder[motorB] = 0;
  motor[motorB] = -10;
while(abs(nMotorEncoder[motorB]) < 140)
{}
motor[motorB] = 0;

}

void returnWhacker()
{
	motor[motorB] = -20;
	wait1Msec(500);
  motor[motorB] = 0;
  motor[motorB] = 20;
	wait1Msec(1000);
  motor[motorB] = 0;
}
//Rotation functions

//Right face rotation
void R(int direction)
{
	if(direction == CW)
	{

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
	}

	else
	{
		rotate(CW);
		rotate(CW);//Rotate 180 degrees
		flip();
		hold();
		rotate(CW - WACKER_OFFSET);
    returnWhacker();
		rotate(CW + WACKER_OFFSET);
		flip();
	}

}



//Upper face
void U(int direction)
{
	if(direction==CW)
	{
		hold();
		rotate(CCW + WACKER_OFFSET);
		returnWhacker();
		rotate(CW - WACKER_OFFSET);
	}

	else
	{
		hold();
		rotate(CW - WACKER_OFFSET);
		returnWhacker();
		rotate(CCW + WACKER_OFFSET);
	}
}

//Back face rotation
void B(int direction)
{

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
	}

	else
	{
    rotate(CCW);
		flip();
		flip();
		flip();
		hold();
		rotate(CW - WACKER_OFFSET);
		returnWhacker();
		flip();
		rotate(CW + WACKER_OFFSET);
	}
}

struct cube_struct
{
	int cube_faces[6][4];
};

//Front Face Rotation
void F(int direction)
{
	if(direction==CW)
	{
    rotate(CW);
		flip();
		hold();
		rotate(CCW + WACKER_OFFSET);
		returnWhacker();
		rotate(CCW - WACKER_OFFSET);
		flip();
		rotate(CW);
	}

	else
	{
		rotate(CW);
		flip();
		hold();
		rotate(CW - WACKER_OFFSET);
		returnWhacker();
		rotate(CW + WACKER_OFFSET);
		flip();
		rotate(CW);
	}
}

//Algorithms

void alg1()
{
	R(CW);
	B(CCW);
	R(CW);
	F(CW);
	F(CW);
	R(CCW);
	B(CW);
	R(CW);
	F(CW);
	F(CW);
	R(CW);
	R(CW);
}

void alg2()
{
	R(CW);
	U(CW);
	U(CW);
	R(CCW);
	U(CCW);
	R(CW);
	U(CCW);
	R(CCW);

}

void alg3()
{
	R(CW);
	U(CW);
	R(CCW);
	U(CW);
	R(CW);
	U(CW);
	U(CW);
	R(CCW);

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
	if(time < 150)
	{
		break;
	}
}
}

int SumBlue(int* col_blue)
{
	float ave = 0.0;
	for(int count = 0; count < CORNERS_ON_FACE; count++)
	{
		ave += col_blue[count];
	}
	ave /= CORNERS_ON_FACE;
	return(round(ave));
}
int SumRed(int* col_red)
{
	float ave = 0.0;
	for(int count = 0; count < CORNERS_ON_FACE; count++)
	{
		ave += col_red[count];
	}
	ave /= CORNERS_ON_FACE;
	return(round(ave));
}
int SumWhite(int* col_blue, int* col_red, int* col_green)
{
	float ave = 0.0;
	for(int count = 0; count < CORNERS_ON_FACE; count++)
	{
		ave += (col_red[count] + col_green[count] + col_blue[count]);
	}
	ave /= CORNERS_ON_FACE;
	return(round(ave));
}
int all_col_red[6] = {0,0,0,0,0,0};
int all_col_green[6] = {0,0,0,0,0,0};
int all_col_blue[6] = {0,0,0,0,0,0};
void CalibrateColourSensor(int* colour_boundaries)
{
	//White value yellow face
	int white_yellow_boundary = -5;
	//Blue value of orange face
	int yellow_boundary = -5;
	//Red value of red face
	int red_boundary = -5;
	//White value of yellow face
	int orange_boundary = -5;
	//White value of green face
	int green_boundary = -5;
	//If none of these then its blue

	for(int face = 0; face < 6; face++)
	{
		int col_blue, col_red, col_green = 0;

		cur_angle += 360;
		int highest_RGB[3] = {0,0,0};
		motor[motorD] = TURN_POW/2;
		while(getMotorEncoder(motorD) < cur_angle)
		{
			getColorRGB(S1, col_red, col_green,col_blue);
			if(col_red > highest_RGB[0])
				highest_RGB[0] = col_red;
			if(col_green > highest_RGB[1])
				highest_RGB[1] = col_green;
			if(col_blue > highest_RGB[2])
				highest_RGB[2] = col_blue;
		}
		motor[motorD] = 0;
		all_col_red[face] = col_red;
		all_col_green[face] = col_green;
		all_col_blue[face] = col_blue;

		//For white face
		if(face == 2)
		{
			white_yellow_boundary += (col_red + col_green + col_blue);
		}
		//For orange face
		else if(face == 5)
		{
			orange_boundary += (col_red + col_green + col_blue);
		}
		//for red face
		else if(face == 4)
		{
			red_boundary += col_red;
		}
		//for yellow face
		else if(face == 0)
		{
			yellow_boundary += (col_red + col_green + col_blue);
		}
		//for green face
		else if(face == 1)
		{
			green_boundary += (col_red + col_green + col_blue);
		}
		//Orienting Cube
		if(face < 3)
		{
			motor[motorC] = 10;
			wait1Msec(500);
			motor[motorC] = 0;
			flip();
			motor[motorC] = -10;
			wait1Msec(500);
			motor[motorC] = 0;
		}
		else if(face == 3)
		{
			rotate(CCW);
			motor[motorC] = 10;
			wait1Msec(500);
			motor[motorC] = 0;
			flip();
			motor[motorC] = -10;
			wait1Msec(500);
			motor[motorC] = 0;
		}
		else if(face==4){
			motor[motorC] = 10;
			wait1Msec(500);
			motor[motorC] = 0;
			flip();
			flip();
			motor[motorC] = -10;
			wait1Msec(500);
			motor[motorC] = 0;
		}
		else{
			//return to original spot
			rotate(CW);
			motor[motorC] = 10;
			wait1Msec(500);
			motor[motorC] = 0;
			flip();
			rotate(CW);
		}
	}
	colour_boundaries[0] = white_yellow_boundary;
	colour_boundaries[1] = yellow_boundary;
	colour_boundaries[2] = red_boundary;
	colour_boundaries[3] = orange_boundary;
	colour_boundaries[4] = green_boundary;
}
int cube_red[6][4];
int cube_green[6][4];
int cube_blue[6][4];
void ScanCube(int* full_cube, int* col_bounds)
{
	for(int face = 0; face < 6; face++)
	{
		for(int count = 0; count < 4; count++)
		{
			int col_blue, col_red, col_green = 0;
			motor[motorB] = -20;
			wait1Msec(1000);
			motor[motorB] = 0;
			motor[motorC] = -10;
			wait1Msec(500);
			motor[motorC] = 0;
			wait1Msec(100);
			getColorRGB(S1, col_red, col_green,col_blue);
			cube_red[face][count] = col_red;
			cube_green[face][count] = col_green;
			cube_blue[face][count] = col_blue;
			int white = (col_red+col_green+col_blue);
			wait1Msec(100);
			motor[motorC] = 10;
			wait1Msec(500);
			motor[motorC] = 0;
			motor[motorB] = 20;
			wait1Msec(1000);
			motor[motorB] = 0;
			if (white > col_bounds[0])
			{
				if(white > col_bounds[1])
				{
					//Yellow
					full_cube[(face * CORNERS_ON_FACE) + count] = 0;
				}
				else
				{
					//White
					full_cube[(face * CORNERS_ON_FACE) + count] = 2;
				}
			}
			else if(white > col_bounds[3])
			{
				//Orange
				full_cube[(face * CORNERS_ON_FACE) + count] = 5;
			}
			else if(col_red > col_bounds[2])
			{
				//Red
				full_cube[(face * CORNERS_ON_FACE) + count] = 4;
			}
			else if(white > col_bounds[4])
			{
				//Green
				full_cube[(face * CORNERS_ON_FACE) + count] = 1;
			}
			else
			{
				//Blue
				full_cube[(face * CORNERS_ON_FACE) + count] = 3;
			}
			rotate(90);
		}

		//Orienting Cube
		if(face < 3)
		{
			motor[motorC] = 10;
			wait1Msec(500);
			motor[motorC] = 0;
			flip();
		}
		else if(face == 3)
		{
			rotate(CCW);
			motor[motorC] = 10;
			wait1Msec(500);
			motor[motorC] = 0;
			flip();
		}
		else if(face==4){
			motor[motorC] = 10;
			wait1Msec(500);
			motor[motorC] = 0;
			flip();
			flip();
		}
		else{
			//return to original spot
			rotate(CW);
			motor[motorC] = 10;
			wait1Msec(500);
			motor[motorC] = 0;
			flip();
			rotate(CW);
		}
	}
}

int colour_boundaries[5] = {0,0,0,0,0};
int cube_main[6*4];
int red, green, blue = 0;
task main()
{
	nMotorEncoder[motorA] = 0;
	nMotorEncoder[motorB] = 0;
	nMotorEncoder[motorC] = 0;
	nMotorEncoder[motorD] = 0;
	while(1==1)
	{
		getColorRGB(S1, red, green, blue);
		wait1Msec(50);
	}
	//startTask(playMusic);
	//wait1Msec(10000);
	//playSound(soundException);
	//startTask(playMusic);
	CalibrateColourSensor(colour_boundaries);

	wait1Msec(10000);
	//playSound(soundBeepBeep);
	ScanCube(cube_main, colour_boundaries);

	/*
	for(int count = 0; count < 6; count ++)
	{
		for(int count2 = 0; count2 < 4; count2++)
		{
			cube_copy[count][count2] = cube_main->cube[count][count2];
		}
	}
	*/
	//R(CCW);
	//F(CCW);
	//alg1();
	//U(cw);
}
