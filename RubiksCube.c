
void rotateFrame(int degrees)
{
	motor[motorD] = 10;

	while(abs(nMotorEncoder[motorD]) < degrees)
	{}
	motor[motorD] = 0;
}
//Scan
int col_blue[6] = {0,0,0,0,0,0};
int col_red[6] = {0,0,0,0,0,0};
int col_green[6] = {0,0,0,0,0,0};
task main()
{
	/*
nMotorEncoder[motorD] = 0;
motor[motorD] = 10;

while(abs(nMotorEncoder[motorD]) < 90 - 4)
{}
motor[motorD] = 0;*/

int cur_degrees = 0;

for(int face = 0; face < 4; face++)
{
	wait1Msec(50);
	getColorRGB(S2, col_red[face], col_green[face], col_blue[face]);
	//playSound(soundBeepBeep);
	if(face < 3)
	{
		cur_degrees += 90;
		rotateFrame(cur_degrees);
	}
}
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
while(abs(nMotorEncoder[motorB]) > 0)
{}
motor[motorB] = 0;

rotateFrame(90);

//Scan Top Face
wait1Msec(50);
getColorRGB(S2, col_red[4], col_green[4], col_blue[4]);

//Scane

/*
for(int face = 4; face < 6; face++)
{
	wait1Msec(50);
	getColorRGB(S2, col_red[face], col_green[face], col_blue[face]);
}
*/
/*
int whiteSum = 0;
int whiteFace = 0;
for(int face = 0; face < 4; face++)
{
	if(col_blue[face] + col_red[face] + col_green[face] > whiteSum)
	{
		whiteSum = col_blue[face] + col_red[face] + col_green[face];
		whiteFace = face;
	}
}
for(int count = 1; count <= (whiteFace + 1); count++)
{
	playSound(soundBeepBeep);
	wait1Msec(500);
}
*/
//wait1Msec(1000000);
}
