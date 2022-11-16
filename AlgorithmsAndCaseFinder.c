#include "MovementFunctions.c";



int findCase(int* cube)
{
	int yellow_counter = 0;

	for(int num =0; num < CORNERS_ON_FACE; num++)
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

else if(findCase(cube)==4)
{
	if(cube[4]==0 && cube[7]==0)//Assuming 1 is green
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


else if(findCase(cube)==6) //CHECKED
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

	else //Case 7 CHECKED
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
