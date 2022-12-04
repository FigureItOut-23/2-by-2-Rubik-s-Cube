#include "MovementFunctions.c"; //includes library of movement functions

/*
Purpose of File:
To calibrate the colour sensors, and get the colour values of the physical cube
and to mimic them in order to create a virtual cube of the same orientation
(scramble).

This file also implements a menu system so that we can double check the colour
values chosen by the code so that the cube array does not come out wrong. Very
essential to have such a system in place as even one wrong colour value
completely ruins the solving process.

*/

//Function to calibrate colour sensor
void CalibrateColourSensor(int* colour_boundaries_red,
int* colour_boundaries_green, int* colour_boundaries_blue)
{
	for(int face = 0; face < 6; face++) //for loop to go through all faces of
	//cube
	{
		int col_blue, col_red, col_green = 0;
		//Updates the current angle of the frame (will be rotated by 360 degrees)
		cur_angle -= 360;
		int highest_RGB[3] = {0,0,0};
		//Begins rotating the frame at a slower than usual speed
		motor[ROTATOR_MOTOR] = -TURN_POW/2;
		//While the frame rotates 360 degrees
		while(getMotorEncoder(ROTATOR_MOTOR) > cur_angle)
		{
			//Gets the red, green and blue colour values from the sensor
			//and stores the information in temporary variables
			getColorRGB(S1, col_red, col_green,col_blue);
			//For each value checks if it is highest value
			//scanned so far and if so updates the highest value array
			if(col_red > highest_RGB[0])
				highest_RGB[0] = col_red;
			if(col_green > highest_RGB[1])
				highest_RGB[1] = col_green;
			if(col_blue > highest_RGB[2])
				highest_RGB[2] = col_blue;
		}
		//stops the frame rotation
		motor[ROTATOR_MOTOR] = 0;

		//Updates the array of colour boundaries with
		//the boundaries for the scanned face
		//Y, G, W, B, R, O is the order of scanning faces
		colour_boundaries_red[face] = col_red;
		colour_boundaries_green[face] = col_green;
		colour_boundaries_blue[face] = col_blue;

		//Orienting Cube
		//For the first 3 faces the robot simply needs to
		//flip the cube to get to the next face
		if(face < 3)
		{
			//Brings the sensor attachment back
			//so the cube can be flipped
			motor[SENSOR_MOTOR] = SENSOR_POWER;
			wait1Msec(500);
			motor[SENSOR_MOTOR] = 0;
			//Flips cube
			flip();
			//brings the sensor attachment back
			//to scanning position
			motor[SENSOR_MOTOR] = -SENSOR_POWER/2;
			wait1Msec(500);
			motor[SENSOR_MOTOR] = 0;
			wait1Msec(500);
		}
		//To get the from the 4th scanned face
		//to the 5th face
		else if(face == 3)
		{
			rotate(CCW); //rotates cube counterclockwise
			//Brings the sensor attachment back
			//so the cube can be flipped
			motor[SENSOR_MOTOR] = SENSOR_POWER;
			wait1Msec(500);
			motor[SENSOR_MOTOR] = 0;
			//Flips cube
			flip();
			//brings the sensor attachment back
			//to scanning position
			motor[SENSOR_MOTOR] = -SENSOR_POWER/2;
			wait1Msec(500);
			motor[SENSOR_MOTOR] = 0;
			wait1Msec(500);
		}
		//To get from the 5th scanned face
		//to the 6th (final face)
		else if(face==4){
			//Brings the sensor attachment back
			//so the cube can be flipped
			motor[SENSOR_MOTOR] = SENSOR_POWER;
			wait1Msec(500);
			motor[SENSOR_MOTOR] = 0;
			//Flips cube twice
			flip();
			flip();
			//brings the sensor attachment back
			//to scanning position
			motor[SENSOR_MOTOR] = -SENSOR_POWER/2;
			wait1Msec(500);
			motor[SENSOR_MOTOR] = 0;
			wait1Msec(500);
		}
		//After scanning the final (6th) face
		//the robot brings the cube back to the
		//orientation it started in
		else{
			rotate(CW); //rotate clockwise
			//Folds sensor attachment back
			//So that the cube can be removed
			//for scrambling
			motor[SENSOR_MOTOR] = SENSOR_POWER;
			wait1Msec(500);
			motor[SENSOR_MOTOR] = 0;
			flip(); //Flips cube
			rotate(CW); //rotates cube
		}
	}
}

//function that returns a boolean indicating whether the two colours are the
//same
bool ScanCorner(int* curScan, int compRed, int compGreen, int compBlue)
{
	//Sets a tolerance value for comparing the values
	const int TOL = 4;
	//Checks if the values are within the tolerance for red, green and blue
	if(abs(curScan[0] - compRed) <= TOL && abs(curScan[1] - compGreen)
	<= TOL && abs(curScan[2] - compBlue) <= TOL)
	{
		return true;
	}
	else{
		return false;
	}
}

//helper function that takes an integer and returns a string value of the
//corresponding colour
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
		//Required default case for function to compile (not important)
		return "Yellow";
}
// the function that scans the cube and updates the cube array
void ScanCube(int* full_cube, int* colour_boundaries_red,
int* colour_boundaries_green, int* colour_boundaries_blue)
{
	//Loops through each face on the cube
	for(int face = 0; face < 6; face++)
	{
		for(int count = 0; count < 4; count++) //for each block of a face...
		{
			int col[3] = {0,0,0};
			wait1Msec(100);
			//Puts the scanned red, green and blue values into a temp array
			getColorRGB(S1, col[0], col[1],col[2]);
			wait1Msec(100);

			//Scanning Logic
			/*
			Loops through each colour starting from orange
			This is as colours are frequently confused with
			yellow, so keeping it as the last value compared
			helps prevent erroneous scans
			*/
			for(int count2 = 5; count2 >= 0; count2--)
			{
				//Checks if the scanned colour matches the colour
				//boundary
				if(ScanCorner(col, colour_boundaries_red[count2],
				colour_boundaries_green[count2],
				colour_boundaries_blue[count2]))
				{
					//If the colours are the "same" then updates the
					//cube array with that colour
					full_cube[(face * CORNERS_ON_FACE) + count] = count2;
					break;
				}
			}
			//menus system to confirm colour
			displayString(2, "Is this the correct color");
			//Displays the colour (converted to string) that the robot
			//scanned
			displayString(3, "%s",
			intToColour(full_cube[(face * CORNERS_ON_FACE) + count]));
			//Waits for any button press
			while(!getButtonPress(buttonAny)){}
			bool correctColour = true;
			if(!getButtonPress(buttonEnter)){
				//If the user did not select enter the colour the robot scanned
				//is incorrect
				correctColour = false;
			}
			while(getButtonPress(buttonAny)){}
			//Checks if the user indicated the colour selected was wrong
			if(!correctColour)
			{
				//A temp variable to help cycle through the colours
				int colCount = 6;
				while(colCount != -1)
				{
					eraseDisplay(); //erases display
					//Code to select correct colour if wrong one was picked
					//Prints a colour (using colCount and converted to string)
					displayString(4, "Select correct colour");
					displayString(5, "%s", intToColour(colCount % 6));
					//Waits for any button press
					while(!getButtonPress(buttonAny)){}
					if(getButtonPress(buttonEnter))
					{
						//If the user presses it enter that colour is
						//inputted into the cube array
						full_cube[(face * CORNERS_ON_FACE) + count] =colCount%6;
						//Sets colCount to -1 to break out of the while loop
						colCount = -1;
					}
					else
					{
						//Adds 1 to colCount to display the next colour
						colCount++;
					}
					//Waits for button to be released
					while(getButtonPress(buttonAny)){}
				}
			}
			eraseDisplay(); //erases display
			rotate(CW); //rotates cube to next corner
		}

		//Same logice to orient cube to the next face as when calibrating
		//For the first 3 faces the robot simply needs to
		//flip the cube to get to the next face
		if(face < 3)
		{
			//Brings the sensor attachment back
			//so the cube can be flipped
			motor[SENSOR_MOTOR] = SENSOR_POWER;
			wait1Msec(500);
			motor[SENSOR_MOTOR] = 0;
			//Flips cube
			flip();
			//brings the sensor attachment back
			//to scanning position
			motor[SENSOR_MOTOR] = -SENSOR_POWER/2;
			wait1Msec(500);
			motor[SENSOR_MOTOR] = 0;
			wait1Msec(500);
		}
		//To get the from the 4th scanned face
		//to the 5th face
		else if(face == 3)
		{
			rotate(CCW); //rotates cube counterclockwise
			//Brings the sensor attachment back
			//so the cube can be flipped
			motor[SENSOR_MOTOR] = SENSOR_POWER;
			wait1Msec(500);
			motor[SENSOR_MOTOR] = 0;
			//Flips cube
			flip();
			//brings the sensor attachment back
			//to scanning position
			motor[SENSOR_MOTOR] = -SENSOR_POWER/2;
			wait1Msec(500);
			motor[SENSOR_MOTOR] = 0;
			wait1Msec(500);
		}
		//To get from the 5th scanned face
		//to the 6th (final face)
		else if(face==4){
			//Brings the sensor attachment back
			//so the cube can be flipped
			motor[SENSOR_MOTOR] = SENSOR_POWER;
			wait1Msec(500);
			motor[SENSOR_MOTOR] = 0;
			//Flips cube twice
			flip();
			flip();
			//brings the sensor attachment back
			//to scanning position
			motor[SENSOR_MOTOR] = -SENSOR_POWER/2;
			wait1Msec(500);
			motor[SENSOR_MOTOR] = 0;
			wait1Msec(500);
		}
		//After scanning the final (6th) face
		//the robot brings the cube back to the
		//orientation it started in
		else{
			rotate(CW); //rotate clockwise
			//Folds sensor attachment back
			//So that the cube can be removed
			//for scrambling
			motor[SENSOR_MOTOR] = SENSOR_POWER;
			wait1Msec(500);
			motor[SENSOR_MOTOR] = 0;
			flip(); //Flips cube
			rotate(CW); //rotates cube
		}
	}
}
