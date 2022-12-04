const int TURN_POW = 12;
const int CCW = 90;
const int CW = -90;
const int WACKER_OFFSET = 6;
const int CORNERS_ON_FACE = 4;
int cur_angle = 0;
int SENSOR_POWER = 30;




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
*/
}

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
//Rotation functions

//Right face rotation
void R(int direction, int* cube)
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
		rotate(CW);
		rotate(CW);//Rotate 180 degrees
		flip();
		hold();
		rotate(CW - WACKER_OFFSET);
    returnWhacker();
		rotate(CW + WACKER_OFFSET);
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



//Upper face
void U(int direction, int* cube)
{
	if(direction==CW)
	{
		hold();
		rotate(CCW + WACKER_OFFSET);
		returnWhacker();
		rotate(CW - WACKER_OFFSET);

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
		hold();
		rotate(CW - WACKER_OFFSET);
		returnWhacker();
		rotate(CCW + WACKER_OFFSET);

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
		rotate(CW - WACKER_OFFSET);
		returnWhacker();
		flip();
		rotate(CW + WACKER_OFFSET);

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
    rotate(CW);
		flip();
		hold();
		rotate(CCW + WACKER_OFFSET);
		returnWhacker();
		rotate(CCW - WACKER_OFFSET);
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
		rotate(CW - WACKER_OFFSET);
		returnWhacker();
		rotate(CW + WACKER_OFFSET);
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

void CalibrateColourSensor(int* colour_boundaries_red, int* colour_boundaries_green, int* colour_boundaries_blue)
{
	for(int face = 0; face < 6; face++)
	{
		int col_blue, col_red, col_green = 0;

		cur_angle -= 360;
		int highest_RGB[3] = {0,0,0};
		motor[motorD] = -TURN_POW/2;
		while(getMotorEncoder(motorD) > cur_angle)
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

		//Y, G, W, B, R, O
		colour_boundaries_red[face] = col_red;
		colour_boundaries_green[face] = col_green;
		colour_boundaries_blue[face] = col_blue;

		//Orienting Cube
		if(face < 3)
		{
			motor[motorC] = SENSOR_POWER;
			wait1Msec(500);
			motor[motorC] = 0;
			flip();
			motor[motorC] = -SENSOR_POWER/2;
			wait1Msec(500);
			motor[motorC] = 0;
			wait1Msec(500);
		}
		else if(face == 3)
		{
			rotate(CCW);
			motor[motorC] = SENSOR_POWER;
			wait1Msec(500);
			motor[motorC] = 0;
			flip();
			motor[motorC] = -SENSOR_POWER/2;
			wait1Msec(500);
			motor[motorC] = 0;
			wait1Msec(500);
		}
		else if(face==4){
			motor[motorC] = SENSOR_POWER;
			wait1Msec(500);
			motor[motorC] = 0;
			flip();
			flip();
			motor[motorC] = -SENSOR_POWER/2;
			wait1Msec(500);
			motor[motorC] = 0;
			wait1Msec(500);
		}
		else{
			//return to original spot
			rotate(CW);
			motor[motorC] = SENSOR_POWER;
			wait1Msec(500);
			motor[motorC] = 0;
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

int cube_test_red[6][4];
int cube_test_green[6][4];
int cube_test_blue[6][4];
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
				playSound(soundBeepBeep);
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
			cube_test_red[face][count] = col[0];
			cube_test_green[face][count] = col[1];
			cube_test_blue[face][count] = col[2];
			rotate(CCW);
		}

		//Orienting Cube
		if(face < 3)
		{
			motor[motorC] = SENSOR_POWER;
			wait1Msec(500);
			motor[motorC] = 0;
			flip();
			motor[motorC] = -SENSOR_POWER/2;
			wait1Msec(500);
			motor[motorC] = 0;
			wait1Msec(500);
		}
		else if(face == 3)
		{
			rotate(CCW);
			motor[motorC] = SENSOR_POWER;
			wait1Msec(500);
			motor[motorC] = 0;
			flip();
			motor[motorC] = -SENSOR_POWER/2;
			wait1Msec(500);
			motor[motorC] = 0;
			wait1Msec(500);
		}
		else if(face==4){
			motor[motorC] = SENSOR_POWER;
			wait1Msec(500);
			motor[motorC] = 0;
			flip();
			flip();
			motor[motorC] = -SENSOR_POWER/2;
			wait1Msec(500);
			motor[motorC] = 0;
			wait1Msec(500);
		}
		else{
			//return to original spot
			rotate(CW);
			motor[motorC] = SENSOR_POWER;
			wait1Msec(500);
			motor[motorC] = 0;
			flip();
			rotate(CW);
		}
	}
}

task EmergencyStop()
{
	while(SensorValue[S3] < 10)
	{
		wait1Msec(500);
	}
	stopAllTasks();
}



int findCase(int* cube)
{
	int yellow_counter = 0;

	for(int num =0; num<4; num++)
	{

		if(cube[num]==0)//yellow = 1
		{
			yellow_counter++;
		}

	}

	if (yellow_counter==4)
	{
	 return 0; //do nothing and move on
	}

			//Case 5
	else if(cube[0]==0 && cube[2]==0 || cube[1]==0 && cube[3]==0)
	{
		return 5;
	}


	else if (yellow_counter==2) //could be case 6,or 7
	{


		if(cube[4]==0 && cube[7]==0 || cube[13]==0 && cube[14]==0 ||
		   cube[18]==0 && cube[19]==0 || cube[22]==0 && cube[23]==0)
		{
		   	return 7;
		}

		else
		{
			return 6;
		}
	}

	else if(yellow_counter==0)//Could be case 3 or 4
	{
		if(cube[4]==0 && cube[7]==0 && cube[13]==0 && cube[14]==0 ||
		   cube[18]==0 && cube[19]==0 && cube[22]==0 && cube[23]==0)
		{
			return 3;
		}

		else
		{
			return 4;
		}

	}


	else //case 1 or 2
	{
		if(cube[0]==0 && cube[14]==0 || cube[1]==0 && cube[19]==0 ||
		   cube[2]==0 && cube[4]==0 || cube[3]==0 && cube[23]==0)
		{
			return 1;
		}
		else
		{
			return 2;
		}
	}
}

void orientFace(int * cube)
{

	if(findCase(cube)==0)
	{
	//do nothing
	}
	else if(findCase(cube)==1)
	{
		if(cube[0]==0)
		{
			alg2(cube);
		}
		else if(cube[1]==0)
		{
			U(CW, cube);
			alg2(cube);
		}
		else if(cube[2]==0)
		{
			U(CW, cube);
			U(CW, cube);
			alg2(cube);
		}
		else
		{
			U(CCW, cube);
			alg2(cube);
		}
	}
else if(findCase(cube)==2)
{
		if(cube[0]==0)
	{
		U(CCW, cube);
		U(CCW, cube);
		alg3(cube);
	}
	else if(cube[1]==0)
	{
		U(CCW, cube);
		alg3(cube);
	}
	else if(cube[2]==0)
	{
		alg3(cube);
	}
	else
	{
		U(CW, cube);
		alg3(cube);
	}
}

else if(findCase(cube)==3)
{
		if(cube[0]==5)//ASSUMING ORANGE IS 5
	{
		U(CCW, cube);
		alg2(cube);
		alg2(cube);
	}
	else if(cube[1]==5)
	{
		alg2(cube);
		alg2(cube);
	}
	else if(cube[2]==5)
	{
		U(CW, cube);
		alg2(cube);
		alg2(cube);
	}
	else
	{
		U(CW, cube);
		U(CW, cube);
		alg2(cube);
		alg2(cube);
	}
}

else if(findCase(cube)==4)
{
	if(cube[0]==1)//Assuming 1 is green
	{
		alg2(cube);
		U(CCW, cube);
		alg2(cube);

	}
	else if(cube[1]==1)
	{
		U(CCW, cube);
		alg2(cube);
		U(CCW, cube);
		alg2(cube);
	}
	else if(cube[2]==1)
	{
		U(CCW, cube);
		alg2(cube);
		U(CCW, cube);
		alg2(cube);
	}
	else
	{
		U(CW, cube);
		alg2(cube);
		U(CCW, cube);
		alg2(cube);
	}
}
else if(findCase(cube)==5)
{
	if(cube[23]==5)//Assuming orange is 5
	{
		alg2(cube);
		U(CW, cube);
		U(CW, cube);// Up 2 CW
		alg3(cube);
	}
	else if(cube[7]==5)
	{
		U(CCW, cube);
		alg2(cube);
		U(CW, cube);
		U(CW, cube);// Up 2 CW
		alg3(cube);
	}
	else if(cube[14]==5)
	{
		U(CW, cube);
		U(CW, cube);
		U(CW, cube);// Up 2 CW
		alg3(cube);
	}
	else
	{
		U(CW, cube);
		U(CW, cube);
		alg2(cube);
		U(CW, cube);
		U(CW, cube);// Up 2 CW
		alg3(cube);

	}
}


else if(findCase(cube)==6)
{
		if(cube[1]==1) //ASSUMING 3 IS GREEN
		{
			alg2(cube);
			U(CW, cube);
			alg3(cube);
		}
		else if(cube[2]==1)
		{
			U(CW, cube);
			alg2(cube);
			U(CW, cube);
			alg3(cube);
		}
		else if(cube[3]==1)
		{
			U(CW, cube);
			U(CW, cube);
			alg2(cube);
			U(CW, cube);
			alg3(cube);
		}
		else
		{
			U(CCW, cube);
			alg2(cube);
			U(CW, cube);
			alg3(cube);
		}
	}

	else //Case 7
	{
		if(cube[0]==5)
		{
			alg2(cube);
			U(CCW, cube);
			alg3(cube);
		}
		else if(cube[1]==5)
		{

			U(CW, cube);
			alg2(cube);
			U(CCW, cube);
			alg3(cube);
		}
		else if(cube[2]==5)
		{
			U(CW, cube);
			U(CW, cube);
			alg2(cube);
			U(CCW, cube);
			alg3(cube);
		}
		else
		{
			U(CCW, cube);
			alg2(cube);
			U(CCW, cube);
			alg3(cube);
		}
	}






}
