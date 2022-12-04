#include "MovementFunctions.c";

/*
Purpose of file:
After white has been solved and bottom row of cube relative to front face has 
been set up, the face opposite to white has to be solved. This file is 
responsible for solving the top yellow face.

*/

//The manual used to find out how to solve the cube, states that at this point
//in the solving process, there are 7 possible cases for the layout of the top
//layer. This function finds which of the 7 cases the cube is in

int findCase(int* cube)
{
	int yellow_counter = 0; //accumulator to keep track of number of yellow
	//pieces on top face


	for(int num =0; num < CORNERS_ON_FACE; num++)
	{

		if(cube[num]==0)//yellow = 1
		{
			yellow_counter++;
		}

	}

	if (yellow_counter==4) //top face is all yellow (solved)...
	{
	 return 0; //do nothing and move on
	}


	else if(cube[0]==0 && cube[2]==0 || cube[1]==0 && cube[3]==0)
	{
		return 5; //case 5 layout
	}

	else if (yellow_counter==2) //could be case 6,or 7
	{

		if(cube[4]==0 && cube[7]==0 || cube[13]==0 && cube[14]==0 ||
		 			  cube[18]==0 && cube[19]==0 || cube[22]==0 && cube[23]==0)
		{
		   	return 7; //case 7 layout
		}

		else
		{
			return 6; //case 6 layout
		}
	}

	else if(yellow_counter==0)//Could be case 3 or 4
	{
		if(cube[4]==0 && cube[7]==0 && cube[13]==0 && cube[14]==0 ||
		   cube[18]==0 && cube[19]==0 && cube[22]==0 && cube[23]==0)
		{ 
			return 3; //case 3 layout
		}

		else
		{
			return 4; //case 4 layout
		}

	}


	else //case 1 or 2
	{
		if(cube[0]==0 && cube[14]==0 || cube[1]==0 && cube[19]==0 ||
		   cube[2]==0 && cube[4]==0 || cube[3]==0 && cube[23]==0)
		{
			return 1; //case 1 layout
		}
		else
		{
			return 2; //case 2 layout
		}
	}
}

//Orients the top face
void orientFace(int * cube)
{

	if(findCase(cube)==0)
	{
	//do nothing
	}
	else if(findCase(cube)==1) //if its case 1...
	{
		//from case 1 only algorithm 2 is neccessary to solve the top face.
		//However it has to be set in specific orientation for alg2 to work
		//the chain of ifs below checks scenario and rotates top face to match
		//orientation as in manual so that alg2 can work
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

else if(findCase(cube)==2) //if its case 2...
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

else if(findCase(cube)==3)//if its case 3...
{
		if(cube[23]!=0)
	{
		U(CCW, cube);
		alg2(cube);
		alg2(cube);
	}
		else
	{
		alg2(cube);
		alg2(cube);
	}

}

else if(findCase(cube)==4)//if its case 4...
{
	if(cube[4]==0 && cube[7]==0)
	{
		alg2(cube);
		U(CCW, cube);
		alg2(cube);
	}

	else if(cube[4]!=0 && cube[7]==0)
	{
		U(CCW, cube);
		alg2(cube);
		U(CCW, cube);
		alg2(cube);
	}
	else if(cube[4]!=0 && cube[7]!=0)
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
else if(findCase(cube)==5)//if its case 5...
{
	while(cube[23]!=0)
	{
		U(CW, cube);
	}
		alg2(cube);
		U(CW, cube);
		U(CW, cube);// Up 2 CW
		alg3(cube);

}


else if(findCase(cube)==6) //if its case 6...
{
		if(cube[0]!=0 && cube[1]!=0)
		{
			alg2(cube);
			U(CW, cube);
			alg3(cube);
		}
		else if(cube[0]==0 && cube[1]!=0)
		{
			U(CW, cube);
			alg2(cube);
			U(CW, cube);
			alg3(cube);
		}
		else if(cube[0]==0 && cube[1]==0)
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
		if(cube[0]!=0 && cube[1]==0)
		{
			alg2(cube);
			U(CCW, cube);
			alg3(cube);
		}
		else if(cube[0]==0 && cube[1]==0)
		{

			U(CCW, cube);
			alg2(cube);
			U(CCW, cube);
			alg3(cube);
		}
		else if(cube[0]==0 && cube[1]!=0)
		{
			U(CW, cube);
			U(CW, cube);
			alg2(cube);
			U(CCW, cube);
			alg3(cube);
		}
		else
		{
			U(CW, cube);
			alg2(cube);
			U(CCW, cube);
			alg3(cube);
		}
	}
}
