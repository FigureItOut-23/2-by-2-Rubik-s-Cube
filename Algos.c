//Solve First Layer
//White Face is solved and on top
const int DEGREES_TURN = 90;
const int TURN_POW = 12;
const int CCW = 87;
const int CW = -87;
const int WACKER_OFFSET = 20;
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
void rotate(int direction)
{
	cur_angle += direction;
	motor[motorD] = TURN_POW*(direction/abs(direction));
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
motor[motorA] = -10;
nMotorEncoder[motorA] = 0;
while(abs(nMotorEncoder[motorA]) < 90)
{}
motor[motorA] = 0;
motor[motorA] = 10;
while(abs(nMotorEncoder[motorA]) > 0)
{}
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
	while(
	for(int count = 0; count < 8; count++){
	playTone(523, 5);
	playTone(659, 5);
	playTone(880, 5);
	wait1Msec(500);
}
	for(int count = 0; count < 3; count++){
	playTone(494, 5);
	playTone(659, 5);
	playTone(880, 5);
	wait1Msec(500);
}
	for(int count = 0; count < 5; count++){
	playTone(494, 5);
	playTone(659, 5);
	playTone(784, 5);
	wait1Msec(500);
}
	for(int count = 0; count < 8; count++){
	playTone(523, 5);
	playTone(659, 5);
	playTone(880, 5);
	wait1Msec(500);
}

}

task main()
{
	startTask(playMusic);
	wait1Msec(10000000);
	//R(CCW);
	//F(CCW);
	//alg2();
}
