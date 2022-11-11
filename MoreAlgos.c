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
			rotate(ccw);
			returnWhacker();
			rotate(cw);
			alg2();
		}
		else if(cube[2]==0)
		{
			hold();
			rotate(ccw);
			rotate(ccw);
			returnWhacker();
			rotate(cw);
			rotate(cw);
			alg2();
		}
		else
		{
			hold();
			rotate(ccw);
			rotate(ccw);
			rotate(ccw);
			returnWhacker();
			rotate(cw);
			rotate(cw);
			rotate(cw);
			alg2();
		}
	}

	else if(findCase(cube)==2)
	{
			if(cube[0]==0)
		{
			hold();
			rotate(ccw);
			rotate(ccw);
			returnWhacker();
			rotate(cw);
			rotate(cw);
			alg3();
		}
		else if(cube[1]==0)
		{
			hold();
			rotate(ccw);
			rotate(ccw);
			rotate(ccw);
			returnWhacker();
			rotate(cw);
			rotate(cw);
			rotate(cw);
			alg3();
		}
		else if(cube[2]==0)
		{
			alg3();
		}
		else
		{
			hold();
			rotate(ccw);
			returnWhacker();
			rotate(cw);
			alg3();
		}
	}
	else if(findCase(cube)==3)
	{
			if(cube[0]==5)//ASSUMING ORANGE IS 5
		{
			hold();
			rotate(cw);
			returnWhacker();
			rotate(ccw);
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
		   	rotate(ccw);
			returnWhacker();
			rotate(cw);
			alg2();
			alg2();
		}
		else
		{
			hold();
			rotate(ccw);
			rotate(ccw);
			returnWhacker();
			rotate(cw);
			rotate(cw);
			alg2();
			alg2();
		}
	}
	else if(findCase(cube)==4)
	{
		if(cube[0]==1)//Assuming 2 is green
		{
			alg2();
			U(ccw);
			alg2();

		}
		else if(cube[1]==1)
		{
			hold();
		   	rotate(cw);
			returnWhacker();
			rotate(ccw);
			alg2();
			U(ccw);
			alg2();
		}
		else if(cube[2]==1)
		{
			hold();
		   	rotate(ccw);
		   	rotate(ccw);
			returnWhacker();
			rotate(cw);
			rotate(cw);
			alg2();
			U(ccw);
			alg2();
		}
		else
		{
			hold();
		   	rotate(ccw);
			returnWhacker();
			rotate(cw);
			alg2();
			U(ccw);
			alg2();
		}
	}
	else if(findCase(cube)==5)
	{
		if(cube[21]==5)//Assuming orange is 4
		{
			alg2();
			U();
			U();// Up 2 cw
			alg3();
		}
		else if(cube[5]==5)
		{
			hold();
			rotate(cw);
			returnWhacker();
			rotate(ccw);
			alg2();
			U();
			U();// Up 2 cw
			alg3();
		}
		else if(cube[13]==5)
		{
			hold();
			rotate(ccw);
			returnWhacker();
			rotate(cw);
			alg2();
			U();
			U();// Up 2 cw
			alg3();
		}
		else
		{
			hold();
			rotate(ccw);
			rotate(ccw);
			returnWhacker();
			rotate(cw);
			rotate(cw);
			alg2();
			U(cw);
			U(cw);// Up 2 cw
			alg3();

		}
	}
	else if(findCase(cube)==6)
	{
			if(cube[1]==1) //ASSUMING 3 IS GREEN
			{
				alg2();
				U(cw)
				alg3();
			}
			else if(cube[2]==1)
			{
				hold();
				rotate(ccw);
				returnWhacker();
				rotate(cw);
				alg2();
				U(cw)
				alg3();
			}
			else if(cube[3]==1)
			{
				hold();
				rotate(ccw);
				rotate(ccw);
				returnWhacker();
				rotate(cw);
				rotate(cw);
				alg2();
				U(cw)
				alg3();
			}
			else
			{
				hold();
				rotate(cw);
				returnWhacker();
				rotate(ccw);
				alg2();
				U(cw)
				alg3();
			}
		}

		else //Case 7
		{
			if(cube[0]==5)
			{
				alg2();
				U(ccw);
				alg3();
			}
			else if(cube[1]==5)
			{
				hold();
				rotate(ccw);
				returnWhacker();
				rotate(cw);
				alg2();
				U(ccw);
				alg3();
			}
			else if(cube[2]==5)
			{
				hold();
				rotate(ccw);
				rotate(ccw);
				returnWhacker();
				rotate(cw);
				rotate(cw);
				alg2();
				U(ccw);
				alg3();
			}
			else
			{
				hold();
				rotate(cw);
				returnWhacker();
				rotate(ccw);
				alg2();
				U(ccw);
				alg3();
			}
		}
}


int main()
{
int cube[24];
cube[0]=5;	//5
cube[1]=1;	//3
cube[2]=3;
cube[3]=5;
cube[4]=4;
cube[5]=4;
cube[6]=1;
cube[7]=1;
cube[8]=2;
cube[9]=2;
cube[10]=2;
cube[11]=2;
cube[12]=0;
cube[13]=0;
cube[14]=3;
cube[15]=3;
cube[16]=0;
cube[17]=1;
cube[18]=4;
cube[19]=4;
cube[20]=3;
cube[21]=0;
cube[22]=5;
cube[23]=5;

int num = findCase(cube);
//printf("%d", num);

}





