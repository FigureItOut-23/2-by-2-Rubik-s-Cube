#include "MovementFunctions.c";

void CalibrateColourSensor(int* colour_boundaries_red, int* colour_boundaries_green, int* colour_boundaries_blue)
{
	for(int face = 0; face < 6; face++)
	{
		int col_blue, col_red, col_green = 0;

		cur_angle -= 360;
		int highest_RGB[3] = {0,0,0};
		motor[ROTATOR_MOTOR] = -TURN_POW/2;
		while(getMotorEncoder(ROTATOR_MOTOR) > cur_angle)
		{
			getColorRGB(S1, col_red, col_green,col_blue);
			if(col_red > highest_RGB[0])
				highest_RGB[0] = col_red;
			if(col_green > highest_RGB[1])
				highest_RGB[1] = col_green;
			if(col_blue > highest_RGB[2])
				highest_RGB[2] = col_blue;
		}
		motor[ROTATOR_MOTOR] = 0;

		//Y, G, W, B, R, O
		colour_boundaries_red[face] = col_red;
		colour_boundaries_green[face] = col_green;
		colour_boundaries_blue[face] = col_blue;

		//Orienting Cube
		if(face < 3)
		{
			motor[SENSOR_MOTOR] = SENSOR_POWER;
			wait1Msec(500);
			motor[SENSOR_MOTOR] = 0;
			flip();
			motor[SENSOR_MOTOR] = -SENSOR_POWER/2;
			wait1Msec(500);
			motor[SENSOR_MOTOR] = 0;
			wait1Msec(500);
		}
		else if(face == 3)
		{
			rotate(CCW);
			motor[SENSOR_MOTOR] = SENSOR_POWER;
			wait1Msec(500);
			motor[SENSOR_MOTOR] = 0;
			flip();
			motor[SENSOR_MOTOR] = -SENSOR_POWER/2;
			wait1Msec(500);
			motor[SENSOR_MOTOR] = 0;
			wait1Msec(500);
		}
		else if(face==4){
			motor[SENSOR_MOTOR] = SENSOR_POWER;
			wait1Msec(500);
			motor[SENSOR_MOTOR] = 0;
			flip();
			flip();
			motor[SENSOR_MOTOR] = -SENSOR_POWER/2;
			wait1Msec(500);
			motor[SENSOR_MOTOR] = 0;
			wait1Msec(500);
		}
		else{
			//return to original spot
			rotate(CW);
			motor[SENSOR_MOTOR] = SENSOR_POWER;
			wait1Msec(500);
			motor[SENSOR_MOTOR] = 0;
			flip();
			rotate(CW);
		}
	}
}

bool ScanCorner(int* curScan, int compRed, int compGreen, int compBlue)
{
	const int OFFSET = 4;
	if(abs(curScan[0] - compRed) <= OFFSET && abs(curScan[1] - compGreen) <= OFFSET && abs(curScan[2] - compBlue) <= OFFSET)
	{
		return true;
	}
	else{
		return false;
	}
}

char* intToColour(int col)
{
		switch(col)
		{
			case 0:
				return "Yellow";
			case 1:
				return "Green";
			case 2:
				return "White";
			case 3:
				return "Blue";
			case 4:
				return "Red";
			case 5:
				return "Orange";
		};
		return "Yellow";
}

void ScanCube(int* full_cube, int* colour_boundaries_red, int* colour_boundaries_green, int* colour_boundaries_blue)
{
	for(int face = 0; face < 6; face++)
	{
		for(int count = 0; count < 4; count++)
		{
			int col[3] = {0,0,0};
			wait1Msec(100);
			getColorRGB(S1, col[0], col[1],col[2]);
			wait1Msec(100);

			//Scanning Logic
			for(int count2 = 5; count2 >= 0; count2--)
			{
				if(ScanCorner(col, colour_boundaries_red[count2], colour_boundaries_green[count2], colour_boundaries_blue[count2]))
				{
					full_cube[(face * CORNERS_ON_FACE) + count] = count2;
					break;
				}
			}
			displayString(2, "Is this the correct color");
			displayString(3, "%s", intToColour(full_cube[(face * CORNERS_ON_FACE) + count]));
			while(!getButtonPress(buttonAny)){}
			bool correctColour = true;
			if(!getButtonPress(buttonEnter)){
				correctColour = false;
				//playSound(soundBeepBeep);
			}
			while(getButtonPress(buttonAny)){}
			if(!correctColour)
			{
				int colCount = 6;
				while(colCount != -1)
				{
					eraseDisplay();
					displayString(4, "Select correct colour");
					displayString(5, "%s", intToColour(colCount % 6));
					while(!getButtonPress(buttonAny)){}
					if(getButtonPress(buttonEnter))
					{
						full_cube[(face * CORNERS_ON_FACE) + count] = colCount % 6;
						colCount = -1;
					}
					else
					{
						colCount++;
					}
					while(getButtonPress(buttonAny)){}
				}
			}
			eraseDisplay();
			rotate(CW);
		}

		//Orienting Cube
		if(face < 3)
		{
			motor[SENSOR_MOTOR] = SENSOR_POWER;
			wait1Msec(500);
			motor[SENSOR_MOTOR] = 0;
			flip();
			motor[SENSOR_MOTOR] = -SENSOR_POWER/2;
			wait1Msec(500);
			motor[SENSOR_MOTOR] = 0;
			wait1Msec(500);
		}
		else if(face == 3)
		{
			rotate(CCW);
			motor[SENSOR_MOTOR] = SENSOR_POWER;
			wait1Msec(500);
			motor[SENSOR_MOTOR] = 0;
			flip();
			motor[SENSOR_MOTOR] = -SENSOR_POWER/2;
			wait1Msec(500);
			motor[SENSOR_MOTOR] = 0;
			wait1Msec(500);
		}
		else if(face==4){
			motor[SENSOR_MOTOR] = SENSOR_POWER;
			wait1Msec(500);
			motor[SENSOR_MOTOR] = 0;
			flip();
			flip();
			motor[SENSOR_MOTOR] = -SENSOR_POWER/2;
			wait1Msec(500);
			motor[SENSOR_MOTOR] = 0;
			wait1Msec(500);
		}
		else{
			//return to original spot
			rotate(CW);
			motor[SENSOR_MOTOR] = SENSOR_POWER;
			wait1Msec(500);
			motor[SENSOR_MOTOR] = 0;
			flip();
			rotate(CW);
		}
	}
}
