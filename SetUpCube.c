#include "AlgorithmsAndCaseFinder.c" //includes all code from 
//"AlgorithmsAndCaseFinder.c" file

/*
Purpose of file:
Once the solvingWhite function is complete and the white face on the cube is 
solved and oriented on the top face, the SetUpCube function is called. This 
function progresses the cube from a state where the white face is solved to a 
state where the white face is solved with a horizontal row of solved faces 
around it.

*/


void SetUpCube(int* cube) 
{
	if (cube[22]!=cube[23] && cube[4]!=cube[7] && cube[18]!=cube[19] && 
	cube[13]!=cube[14]) //if No top face is solved...
		{
			alg1(cube); //call algorithm one which is a combination of the
			//main rotation functions
		}


	if(cube[22]==cube[23] && cube[4]==cube[7] && cube[18]==cube[19] &&
	cube[13]==cube[14]) //if All faces are solved
	{
		while(cube[22]!=5) //if bottom left corner of the front face is not 
		//orange...
		{
			U(CW, cube); //rotate top clockwise
		}
	}

	else
	{
		if(cube[22]==cube[23]) //if bottom row of the front face is solved
		//aka(same colour)
		{
				alg1(cube); //run algo1
		}
		else if(cube[4]==cube[7]) //if right column of left side is solved...
		{
			U(CCW, cube); //rotate top counterclockwise
			alg1(cube);
		}

		else if(cube[18]==cube[19]) //if bottom row of back face is solved...
		{
			U(CW, cube);
			U(CW, cube);
			alg1(cube);
		}
		else //otherwise
		{
			U(CW, cube);
			alg1(cube);
		}
	}
}
