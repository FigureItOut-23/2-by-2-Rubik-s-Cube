#include "MovementFunctions.c" //includes the library of Movement Functions
/*
Purpose of File:
Code to solve the white face. Begins by finding which face holds the most white
pieces and sets it as the bottom. 

Note:
R(), U(), trackedFlip(), rot() are functions imported from the 
"MovementFunctions.c" file.

*/

//function to move white pieces from top to be in corners directly above index 
//10 (top right corner of the bottom face)
void setUpTop(int* cube)
{
	if(cube[15] == 2) //if beside k - ind 15
	{
    //Rotation algorithm that sets a white piece from bottom row to top
    //For set up doesn't solve anything
		R(CW, cube); //rotate right face clockwise 90 degrees and change indices
		U(CCW, cube);//rotate top face counterclockwise 90 deg and change indice
		R(CCW, cube);
		//sets up top piece so no need to add to accumulator as doesnt solve
	}
	//if there is no white piece above the top right corner of the bottom face
	//index 10, rotates the top of the cube until one gets lined up
	while(cube[22] != 2 && cube [14] != 2 && cube[3] != 2 && cube[21] != 2)
	{
		U(CW, cube);
	}
}

void whiteOnTop(int* cube, int* whiteAccumulator, int indexFace) //have function 
//that rotates the top until in position c,j, or m) 
//c, j, m being letter variants of cube indices
{
int colourWhite = 2;
	if(cube[22] == colourWhite  && cube [21] == colourWhite) // if j and k
	{
		R(CCW, cube);
		whiteAccumulator[indexFace]+= 2; //add two to the accumulator because
		//the if condition checks for the case were there is 2 white pieces on
		//the column of the front face. Solving for this puts 2 white pieces 
		//to the bottom
	}
	else if(cube[21] == colourWhite) //if k being and index of cube 
	{
		R(CW, cube);
		U(CCW, cube);
		R(CCW, cube);
		//sets up top piece so no need to add to accumulator as doesnt solve
	}
	else if(cube[22] == colourWhite) //if j
	{
		U(CW, cube);
		R(CW, cube);
		U(CCW, cube);
		R(CCW, cube);
		whiteAccumulator[indexFace]++; //adds one to white accumulator at 
		//indexFace which was chosen to represent the bottom face as the 
		//algorithm in this else if solves for a white piece 
		
		
	}
	else if(cube[3] == colourWhite) // if c
	{
		U(CW, cube);
		R(CW, cube);
		R(CW, cube);
		U(CCW, cube);
		R(CW, cube);
		R(CW, cube);
		whiteAccumulator[indexFace]++;
	}
	else if (cube[14] = colourWhite) //if m
	{
		R(CW, cube);
		U(CW, cube);
		R(CCW, cube);
		whiteAccumulator[indexFace]++;
	}
}

//Main function that is responsible for the set up. Only has cube as parameter
//Starting point of the file
void solvingWhite(int *cube)
{
//Indices of the faces and what default orientation of cube is
//FACE 1: YELLOW 0-3  // top
//FACE 2: GREEN 4-7 // left side
//FACE 3: WHITE 8-11 // bottom
//FACE 4 : BLUE 12-15 //right side
//FACE 5: RED 16-19 //back
//FACE 6: ORANGE 20-23 //front

	//FINDING FACE WITH MOST WHITE PIECES
	int whiteAccumulator[6] = {0,0,0,0,0,0}; //whiteAccumulator to keep track
	//of face with most white pieces
	
	int colourWhite = 2; //variable to represent the colour white of value 2

	for (int j = 0; j < 24; j++) //goes through all 24 indices of cube array
		{
			if(j<4) // if between indices 0-3 it is top face
			{
				if(cube[j] == colourWhite) //if there is a piece of the top face
				//that equals the colourWhite
				{
				whiteAccumulator[0]++; //add 1 to the accumulator at this face
				}
			}

			if(j<8 && j >3) //if left side
			{
				if(cube[j] == colourWhite)
				{
				whiteAccumulator[1]++;
				}
			}

			if(j<12 && j >7) //if bottom
			{
				if(cube[j] == colourWhite)
				{
				whiteAccumulator[2]++;
				}
			}

			if(j<16 && j >11) //if right side
			{
				if(cube[j] == colourWhite)
				{
				whiteAccumulator[3]++;
				}
			}

			if(j<20 && j > 15) //if back
			{
				if(cube[j] == colourWhite)
				{
				whiteAccumulator[4]++;
				}
			}

			if(j<24 && j >19) //if front
			{
				if(cube[j] == colourWhite)
				{
				whiteAccumulator[5]++;
				}
			}
		}


	int mostWhite = -9; //This variable will be used to find the index at which
	//whiteAccumulator is the highest. Because we are looking for the largest 
	//value, negative number is used as it is out of range of counting so 
	//conditional logic works 
	int indexFace = -1;//same idea. Chooses array out of bounds and compares 
	//until desired index is found

	for (int c = 0; c < 6; c++) //for each face of cube. (each index of 
	//whiteAccumulator
	{
		if (whiteAccumulator[c]>mostWhite) 
		{
			mostWhite = whiteAccumulator[c];
			indexFace = c;
		}
	}
	//THEREFORE FACE [c] has the most white pieces

  	//int tempArray[12] = {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9};

	if(indexFace == 0) //if face with most white is the top
	{

		trackedFlip(cube); //method that flips cube and changes all indices
		//accordingly
		trackedFlip(cube);
		
		//Below is what was done before. Changing all idices of cube for each 
		//case. Harder to trouble shoot as there were 5 cases for this, while 
		//with the function there's only 1 thing to worry about
		/*
	    tempArray[0] = cube[9];
	    tempArray[1] = cube[10];
	    tempArray[2] = cube[11];
	    tempArray[3] = cube[12];
	    tempArray[4] = cube[13];
	    tempArray[5] = cube[14];
	    tempArray[6] = cube[15];
	    tempArray[7] = cube[8];
	    tempArray[8] = cube[18];
	    tempArray[9] = cube[19];
	    tempArray[10] = cube[22];
	    tempArray[11] = cube[23];
	    cube[9] = cube[3];
	    cube[3] = tempArray[0]; // 9 <--> 3
	    cube[10] = cube[0];
	    cube[0] = tempArray[1]; // 10 <--> 0
	    cube[11] = cube[1];
	    cube[1] = tempArray[2]; // 11 <--> 1
	    cube[12] = cube[4];
	    cube[4] = tempArray[3]; // 4 <--> 12
	    cube[13] = cube[5];
	    cube[5] = tempArray[4]; // 5 <--> 13
	    cube[14] = cube[6];
	    cube[6] = tempArray[5]; // 6 <--> 14
	    cube[15] = cube[6];
	    cube[7] = tempArray[6]; // 7 <--> 15
	    cube[8] = cube[2];
	    cube[2] = tempArray[7]; // 8 <--> 2
	    cube[18] = cube[16];
	    cube[16] = tempArray[8]; // 16 <--> 18
	    cube[19] = cube[17];
	    cube[17] = tempArray[9]; // 17 <--> 19
	    cube[22] = cube[20];
	    cube[20] = tempArray[10]; // 20 <--> 22
	    cube[23] = cube[21];
	    cube[21] = tempArray[11]; // 21 <--> 23
		*/
	}
  else if(indexFace == 1) //if face with most white is left
	{
		trackedFlip(cube);
		trackedFlip(cube);
		trackedFlip(cube);

		/*
	    tempArray[0] = cube[12];
	    tempArray[1] = cube[13];
	    tempArray[2] = cube[14];
	    tempArray[3] = cube[15];
	    for (int j = 8; j < 12; j++)
	    {
	      cube [j+4] = cube [j];
	    }
	    for (int j = 4; j < 8; j++)
	    {
	      cube [j+4] = cube [j];
	    }
	    for (int j = 0; j < 4; j++)
	    {
	      cube [j+4] = cube [j];
	    }
	    for (int j=0; j < 4; j++)
	    {
	      cube[j] = tempArray[j];
	    }
	    */
	
	
	    //Green and blue switch
			/*
	    8 --> 12
	    9 --> 13
	    10 --> 14
	    11 --> 15
	    4 --> 8
	    5 --> 9
	    6 --> 10
	    7 --> 11
	    12 --> 0
	    13 --> 1
	    14 --> 2
	    15 --> 3
	    0 --> 4
	    1 --> 5
	    2 --> 6
	    3 --> 7
	    23 --> 20
	    20 --> 21
	    21 --> 22
	    22 --> 23
	    17 --> 16
	    16 --> 19
	    19 --> 18
	    18 --> 17
    */
	}
  else if(indexFace == 2) //if face with most white bottom pieces is bottom face
  {
    // do nothing
  }
  else if (indexFace == 3)//if right
  {
  	trackedFlip(cube);
    /*
  	for (int i = 0; i < 4; i++)
    {
      tempArray[i] = cube[i];
    }
    for (int j = 0; j < 12 ;j++)
    {
      cube[j] = cube[j+4];
    }
    for (int k = 12; k < 16; k++)
    {
      cube[k] = tempArray[k-12];
    }

    tempArray[0] = cube[23];
    tempArray[1] = cube[18];
    cube[23] = cube[20];
    cube[20] = cube[21];
    cube[21] = cube[22];
    cube[22] = tempArray[0];
    cube[18] = cube[17];
    cube[17] = cube[16];
    cube[16] = cube[19];
    cube[19] = tempArray[1];
		*/

    /*
    8 --> 4
    9 --> 5
    10 --> 6
    11 --> 7
    13 --> 9
    12 --> 8
    14 --> 10
    15 --> 11
    0 --> 12
    1 --> 13
    2 --> 14
    3 --> 15
    4 --> 0
    5 --> 1
    6 --> 2
    7 --> 3
    21 --> 20
    22 --> 21
    23 --> 22
    20 --> 23
    19 --> 16
    16 --> 17
    17 --> 18
    18 --> 19
    */
  }
  else if (indexFace == 4) //if back
  {
  	rot(CW, cube);
  	trackedFlip(cube);
  	rot(CCW, cube);
  	/*
    for (int i = 0; i < 8; i++)
    {
      tempArray[i] = cube[i+16];
    }
    cube[18] = cube[8];
    cube[19] = cube[9];
    cube[16] = cube[10];
    cube[17] = cube[11];
    for(int j = 8; j<12; j++)
    {
      cube[j] = tempArray[j-4];
    }
    cube[20] = cube[2];
    cube[21] = cube[3];
    cube[22] = cube[0];
    cube[23] = cube[1];
    for (int k =0; k <4; k++)
    {
      cube[k] = tempArray[k];
    }
    tempArray[8] = cube[6];
    tempArray[9] = cube[15];
    cube[6] = cube[7];
    cube[7] = cube[4];
    cube[4] = cube[5];
    cube[5] = tempArray[8];
    cube[15] = cube[14];
    cube[14] = cube [13];
    cube[13] = cube[12];
    cube[12] = tempArray[9];
	*/

    /*
    8 --> 18
    9 --> 19
    10 --> 16
    11 --> 17
    20 --> 8
    21 --> 9
    22 --> 10
    23 --> 11
    2 --> 20
    3 --> 21
    0 --> 22
    1 --> 23
    17 --> 1
    18 --> 2
    16 --> 0
    19 --> 3
    7 --> 6
    6 --> 5
    5 --> 4
    4 --> 7
    14 --> 15
    15 --> 12
    12 --> 13
    13 --> 14
    */
  }
  else // if front
  {
  	rot(CCW, cube);
  	trackedFlip(cube);
  	rot(CCW, cube);
  	/*
    for (int i = 0; i < 4; i ++)
    {
      tempArray[i] = cube[i+20];

    }
    for (int j = 20; j < 24; j++)
    {
      cube[j] = cube[j-12];
    }
    for (int k = 16; k < 20; k++)
    {
      tempArray[k-12] = cube[k];
    }
    cube[18] = cube[2];
    cube[19] = cube[3];
    cube[16] = cube[0];
    cube[17] = cube[1];
    cube[0] = tempArray[2];
    cube[1] = tempArray[3];
    cube[2] = tempArray[0];
    cube[3] = tempArray[1];
    cube[8] = tempArray[6];
    cube[9] = tempArray[7];
    cube[10] = tempArray[4];
    cube[11] = tempArray[5];

    tempArray[8] = cube[4];
    cube[4] = cube[7];
    cube[7] = cube[6];
    cube[6] = cube[5];
    cube[5] = tempArray[8];
    tempArray[9] = cube[15];
    cube[15] = cube[12];
    cube[12] = cube[13];
    cube[13] = cube[14];
    cube[14] = tempArray[9];
		*/

    /*
    8 --> 20
    9 --> 21
    10 --> 22
    11 --> 23
    21 --> 3
    20 --> 2
    22 --> 0
    23 --> 1
    2 --> 18
    3 --> 19
    0 --> 16
    1 --> 17
    18 --> 8
    19 --> 9
    16 --> 10
    17 --> 11
    4 --> 5
    5 --> 6
    6 --> 7
    7 --> 4
    13 --> 12
    14 --> 13
    15 --> 14
    12 --> 15
    */
  }


	while(whiteAccumulator[indexFace] < 4) //while bottom face does not have
	//4 white pieces...
	{
		while(cube[10] == 2) //while bottom piece we solve from is already
		//solved... 
		{
			//rotate bottom of cube until that index moves to an unsolved piece
			
			//there is no rotate bottom function so a combination of these 
			//rotation functions was used to accomplish that 
			U(CW, cube); // rotate top
			rot(CCW, cube); //rotates entire cube counterclockwise and 
			//changes all indices accordingly
	 	}
	 	setUpTop(cube); //calls setUpTop
		whiteOnTop(cube, whiteAccumulator, indexFace); //calls whiteOnTop
		//ends and goes to big loop to continue if condition is met
	}//end of big while
} //end of solvingWhite function
