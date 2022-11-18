#include "AlgorithmsAndCaseFinder.c"


void SetUpCube(int* cube)
{
	if (cube[22]!=cube[23] && cube[4]!=cube[7] && cube[18]!=cube[19] && cube[13]!=cube[14]) //No top face is solved
		{
			alg1(cube);
		}


	if(cube[22]==cube[23] && cube[4]==cube[7] && cube[18]==cube[19] && cube[13]==cube[14]) //All faces are solved
	{
		while(cube[22]!=5)
		{
			U(CW, cube);
		}
	}

	else
	{
			if(cube[22]==cube[23])
		{
				alg1(cube);
		}
		else if(cube[4]==cube[7])
		{
			U(CCW, cube);
			alg1(cube);
		}

		else if(cube[18]==cube[19])
		{
			U(CW, cube);
			U(CW, cube);
			alg1(cube);
		}
		else
		{
			U(CW, cube);
			alg1(cube);
		}
	}
}
