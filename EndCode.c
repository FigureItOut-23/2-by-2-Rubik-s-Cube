#include "AlgorithmsAndCaseFinder.c"


void FinishCube(int * cube)
{
//How to finish if no top face is solved
	if (cube[22]!=cube[23] && cube[4]!=cube[7] && cube[18]!=cube[19] 
      && cube[13]!=cube[14]) 
		{
			while(cube[22]!=cube[21])
			{
				U(CW, cube);
			}

			alg1(cube);

	}

//How to finish if all faces are solved
	if(cube[22]==cube[23] && cube[4]==cube[7] && cube[18]==cube[19] 
     && cube[13]==cube[14]) 
	{
		while(cube[22]!=1)
		{
			U(CW, cube);
		}
	}

	else
	{
		if(cube[22]==cube[23])
		{
			if(cube[22]==1) //Green.
			{
				U(CW, cube);
				rot(CCW, cube);
				alg1(cube);
				//U(CW, cube);
			}

			else if(cube[22]==4) //Red.
			{
				U(CW, cube);
				U(CW, cube);
				rot(CW, cube);
				rot(CW, cube);
				alg1(cube);
				//U(CW, cube);
			}
			else if(cube[22]==3) //Blue.
			{
					U(CCW, cube);
					rot(CW, cube);
					alg1(cube);
					//U(CW, cube);
			}
			else //Already in right spot.
			{
					alg1(cube);
					//U(CW, cube);
			}
		}
		else if(cube[4]==cube[7])
		{
			if(cube[4]==4) //Red.
			{
				U(CW, cube);
				rot(CW, cube);
				rot(CW, cube);
				alg1(cube);
				//U(CW, cube);
			}
			else if(cube[4]==3) //Blue.
			{
				U(CW, cube);
				U(CW, cube);
				rot(CW, cube);
				alg1(cube);
				//U(CW, cube);
			}
			else if(cube[4]==5) //Orange.
			{
				U(CCW, cube);
				alg1(cube);
				//U(CW, cube);
			}
			else //Already in right spot.
			{
				rot(CCW, cube);
				alg1(cube);
				//U(CW, cube);
			}

		}

		else if(cube[18]==cube[19])
		{
			if(cube[18]==3) //Blue.
			{
				U(CW, cube);
				rot(CW,cube);
				alg1(cube);
				//U(CW, cube);
			}
			else if(cube[18]==5) //Orange.
			{
				U(CW, cube);
				U(CW, cube);
				alg1(cube);
				//U(CW, cube);
			}
			else if(cube[18]==1) //Green.
			{
				U(CCW, cube);
				rot(CCW, cube);
				alg1(cube);
				//U(CW, cube);
			}
			else //Already in right spot.
			{
				rot(CW,cube);
				rot(CW,cube);
				alg1(cube);
				//U(CW, cube);
			}

		}


		else
		{
			if(cube[13]==5) //Orange.
			{
				U(CW, cube);
				alg1(cube);
				//U(CW, cube);
			}
			else if(cube[13]==1) //Green.
			{
				U(CW, cube);
				U(CW, cube);
				rot(CCW, cube);
				alg1(cube);
				//U(CW, cube);
			}
			else if(cube[13]==4) //Red.
			{
				U(CCW, cube);
				rot(CW, cube);
				rot(CW, cube);
				alg1(cube);
				//U(CW, cube);
			}
			else //Already in right spot Blue .
			{
				rot(CW, cube);
				alg1(cube);
				//U(CW, cube);
			}
		}
	}
}
