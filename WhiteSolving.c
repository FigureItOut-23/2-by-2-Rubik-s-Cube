#include "MovementFunctions.c"

void setUpTop(int* cube)
{
	while(cube[22] != 2 && cube [14] != 2 && cube[3] != 2 && cube[21] != 2)
	{
		U(CW, cube);
	}
}

void whiteOnTop(int* cube, int* whiteAccumulator, int indexFace) //have function that rotates the top until in position c,j, or m)
{
int colourWhite = 2;
	if(cube[22] == colourWhite  && cube [21] == colourWhite) // if j and k
	{
		R(CCW, cube);
		whiteAccumulator[indexFace]+= 2;
	}
	else if(cube[21] == colourWhite) //if k
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
		whiteAccumulator[indexFace]++;
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

void solvingWhite(int *cube)
{


//FACE 1: YELLOW 0-3  // top
//FACE 2: GREEN 4-7 // left side
//FACE 3: WHITE 8-11 // bottom
//FACE 4 : BLUE 12-15 //right side
//FACE 5: RED 16-19 //back
//FACE 6: ORANGE 20-23 //front
	//FINDING FACE WITH MOST WHITE PIECES
	int whiteAccumulator[6] = {0,0,0,0,0,0};
	//let colour white = 7;
	int colourWhite = 2;

	for (int j = 0; j < 24; j++)
		{
			if(j<4)
			{
				if(cube[j] == colourWhite)
				{
				whiteAccumulator[0]++;
				}
			}

			if(j<8 && j >3)
			{
				if(cube[j] == colourWhite)
				{
				whiteAccumulator[1]++;
				}
			}

			if(j<12 && j >7)
			{
				if(cube[j] == colourWhite)
				{
				whiteAccumulator[2]++;
				}
			}

			if(j<16 && j >11)
			{
				if(cube[j] == colourWhite)
				{
				whiteAccumulator[3]++;
				}
			}

			if(j<20 && j > 15)
			{
				if(cube[j] == colourWhite)
				{
				whiteAccumulator[4]++;
				}
			}

			if(j<24 && j >19)
			{
				if(cube[j] == colourWhite)
				{
				whiteAccumulator[5]++;
				}
			}
		}


	int mostWhite = -9;
	int indexFace = -1;

	for (int c = 0; c < 6; c++)
	{
		if (whiteAccumulator[c]>mostWhite)
		{
			mostWhite = whiteAccumulator[c];
			indexFace = c;
		}
	}
	//THEREFORE FACE [c] has the most white pieces


  int tempArray[12] = {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9};


	if(indexFace == 0) //if face with most white is the top
	{

		trackedFlip(cube);
		trackedFlip(cube);
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
  else if(indexFace == 2)
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


	while(whiteAccumulator[indexFace] < 4)
	{
		while(cube[10] == 2) //white bottom corner top right
		{
			U(CW, cube); // rotate bottom function //make one
			rot(CCW, cube); //this is instead
	 	}
	 	setUpTop(cube);
		whiteOnTop(cube, whiteAccumulator, indexFace);
	}

}
