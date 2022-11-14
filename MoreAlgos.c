
	//7 functions
#include "Algos.c"


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




	else if (yellow_counter==2) //could be case 6,or 7
	{


		if(cube[4]==0 && cube[5]==0 || cube[12]==0 && cube[13]==0 ||
		   cube[16]==0 && cube[17]==0 || cube[20]==0 && cube[21]==0)
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
		if(cube[4]==0 && cube[5]==0 && cube[12]==0 && cube[13]==0 ||
		   cube[16]==0 && cube[17]==0 && cube[20]==0 && cube[21]==0)
		{
			return 3;
		}

		else
		{
			return 4;
		}

	}
		//Case 5
	else if(cube[0]==0 && cube[2]==0 || cube[1]==0 && cube[3]==0)
	{
		return 5;
	}

	else //case 1 or 2
	{
		if(cube[0]==0 && cube[13]==0 || cube[1]==0 && cube[17]==0 ||
		   cube[2]==0 && cube[5]==0 || cube[3]==0 && cube[21]==0)
		{
			return 1;
		}
		else
		{
			return 2;
		}
	}
}


//ORIENT TOP FACE

void orientFace(int* cube)
{

	if(findCase(cube)==0)
	{
	//do nothing
	}
	else if(findCase(cube)==1)
	{
		if(cube[0]==0)
		{
			alg2();
		}
		else if(cube[1]==0)
		{
			hold();
			rotate(CCW);
			returnWhacker();
			rotate(CW);
			alg2();
		}
		else if(cube[2]==0)
		{
			hold();
			rotate(CCW);
			rotate(CCW);
			returnWhacker();
			rotate(CW);
			rotate(CW);
			alg2();
		}
		else
		{
			hold();
			rotate(CW);
			returnWhacker();
			rotate(CCW);
			alg2();
		}
	}

	else if(findCase(cube)==2)
	{
			if(cube[0]==0)
		{
			hold();
			rotate(CCW);
			rotate(CCW);
			returnWhacker();
			rotate(CW);
			rotate(CW);
			alg3();
		}
		else if(cube[1]==0)
		{
			hold();
			rotate(CCW);
			rotate(CCW);
			rotate(CCW);
			returnWhacker();
			rotate(CW);
			rotate(CW);
			rotate(CW);
			alg3();
		}
		else if(cube[2]==0)
		{
			alg3();
		}
		else
		{
			hold();
			rotate(CCW);
			returnWhacker();
			rotate(CW);
			alg3();
		}
	}
	else if(findCase(cube)==3)
	{
			if(cube[0]==5)//ASSUMING ORANGE IS 5
		{
			hold();
			rotate(CW);
			returnWhacker();
			rotate(CCW);
			alg2();
			alg2();
		}
		else if(cube[1]==5)
		{
			alg2();
			alg2();
		}
		else if(cube[2]==5)
		{
		  hold();
		  rotate(CCW);
			returnWhacker();
			rotate(CW);
			alg2();
			alg2();
		}
		else
		{
			hold();
			rotate(CCW);
			rotate(CCW);
			returnWhacker();
			rotate(CW);
			rotate(CW);
			alg2();
			alg2();
		}
	}
	else if(findCase(cube)==4)
	{
		if(cube[0]==1)//Assuming 2 is green
		{
			alg2();
			U(CCW);
			alg2();

		}
		else if(cube[1]==1)
		{
			hold();
		   	rotate(CW);
			returnWhacker();
			rotate(CCW);
			alg2();
			U(CCW);
			alg2();
		}
		else if(cube[2]==1)
		{
			hold();
		   	rotate(CCW);
		   	rotate(CCW);
			returnWhacker();
			rotate(CW);
			rotate(CW);
			alg2();
			U(CCW);
			alg2();
		}
		else
		{
			hold();
		   	rotate(CCW);
			returnWhacker();
			rotate(CW);
			alg2();
			U(CCW);
			alg2();
		}
	}
	else if(findCase(cube)==5)
	{
		if(cube[21]==5)//Assuming orange is 4
		{
			alg2();
			U(CW);
			U(CW);// Up 2 CW
			alg3();
		}
		else if(cube[5]==5)
		{
			hold();
			rotate(CW);
			returnWhacker();
			rotate(CCW);
			alg2();
			U(CW);
			U(CW);// Up 2 CW
			alg3();
		}
		else if(cube[13]==5)
		{
			hold();
			rotate(CCW);
			returnWhacker();
			rotate(CW);
			alg2();
			U(CW);
			U(CW);// Up 2 CW
			alg3();
		}
		else
		{
			hold();
			rotate(CCW);
			rotate(CCW);
			returnWhacker();
			rotate(CW);
			rotate(CW);
			alg2();
			U(CW);
			U(CW);// Up 2 CW
			alg3();

		}
	}
	else if(findCase(cube)==6)
	{
			if(cube[1]==1) //ASSUMING 3 IS GREEN
			{
				alg2();
				U(CW);
				alg3();
			}
			else if(cube[2]==1)
			{
				hold();
				rotate(CCW);
				returnWhacker();
				rotate(CW);
				alg2();
				U(CW);
				alg3();
			}
			else if(cube[3]==1)
			{
				hold();
				rotate(CCW);
				rotate(CCW);
				returnWhacker();
				rotate(CW);
				rotate(CW);
				alg2();
				U(CW);
				alg3();
			}
			else
			{
				hold();
				rotate(CW);
				returnWhacker();
				rotate(CCW);
				alg2();
				U(CW);
				alg3();
			}
		}

		else //Case 7
		{
			if(cube[0]==5)
			{
				alg2();
				U(CCW);
				alg3();
			}
			else if(cube[1]==5)
			{
				hold();
				rotate(CCW);
				returnWhacker();
				rotate(CW);
				alg2();
				U(CCW);
				alg3();
			}
			else if(cube[2]==5)
			{
				hold();
				rotate(CCW);
				rotate(CCW);
				returnWhacker();
				rotate(CW);
				rotate(CW);
				alg2();
				U(CCW);
				alg3();
			}
			else
			{
				hold();
				rotate(CW);
				returnWhacker();
				rotate(CCW);
				alg2();
				U(CCW);
				alg3();
			}
		}
}


void solvingWhite(int *cube)
{

	
//FACE 1: YELLOW 0-3  // top
//FACE 2: GREEN 4-7 // left side
//FACE 3: WHITE 8-11 // bottom
//FACE 4 : BLUE 12-15 //right side
//FACE 5: RED 16-19 //front
//FACE 6: ORANGE 20-23 //back
	//FINDING FACE WITH MOST WHITE PIECES
	int whiteAccumulator[6] = {0};
	//let colour white = 7;
	int colourWhite = 7;
	
	for (int j = 0; j < 24; j++) 
		{
			if(j<4)
			{
				if(cube[j] == colourWhite)
				{
				whiteAccumulator[0] ++;
				}
			}
			
			if(j<8 && j >3)
			{
				if(cube[j] == colourWhite)
				{
				whiteAccumulator[1] ++;
				}
			}
			
			if(j<12 && j >7)
			{
				if(cube[j] == colourWhite)
				{
				whiteAccumulator[2] ++;
				}
			}
			
			if(j<16 && j >11)
			{
				if(cube[j] == colourWhite)
				{
				whiteAccumulator[3] ++;
				}
			}
			
			if(j<20 && j > 15)
			{
				if(cube[j] == colourWhite)
				{
				whiteAccumulator[4] ++;
				}
			}
			
			if(j<24 && j >19)
			{
				if(cube[j] == colourWhite)
				{
				whiteAccumulator[5] ++;
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
	printf( "Face with most white pieces is %d", indexFace);
	int tempArray[4] = {9999, 9999, 9999, 9999};
	//Face at c is bottom
	if(indexFace == 0) //if face with most white is the top
	{
		//Green and blue switch
		for (int x = 0; x < 4; x++)
		{
			tempArray[x] = cube[x+4]; //tempArray equals temp cube at green face 4-7 on index
			cube[x+4] = cube[x+12];
			cube[x+12] = tempArray[x];
		}
		
	}
	for (int x = 0; x < 24; x++)
	{
		printf( "Cube at index %d", x, " = %d", cube[x]);
	}
	
}

int main()
{
int cube[24];
cube[0]=5;	//5
cube[1]=1;	//3
cube[2]=3;
cube[3]=5;
cube[4]=6;
cube[5]=6;
cube[6]=6;
cube[7]=6;
cube[8]=2;
cube[9]=2;
cube[10]=2;
cube[11]=2;
cube[12]=3;
cube[13]=3;
cube[14]=3;
cube[15]=3;
cube[16]=0;
cube[17]=1;
cube[18]=4;
cube[19]=4;
cube[20]=3;
cube[21]=0;
cube[22]=5;
cube[23]=7;

int num = findCase(cube);
//printf("%d", num);

//CHECK COLOURS WITH ROBSON
//FACE 1: YELLOW 0-3
//FACE 2: GREEN 4-7
//FACE 3: WHITE 8-11
//FACE 4 : BLUE 12-15
//FACE 5: RED 16-19
//FACE 6: ORANGE 20-23 

solvingWhite(cube);


return 1;
}
