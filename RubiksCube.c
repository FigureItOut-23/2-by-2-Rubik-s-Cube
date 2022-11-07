
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
	rotateFrame(90*(face+1));
}

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
