
void FinishCube(int * cube)
{
	if (cube[22]!=cube[23] || cube[4]!=cube[7] || cube[18]!=cube[19] || cube[13]!=cube[14]) //No top face is solved
		{
			while(cube[22]!=cube[21])
			{
				U(CW);
			}

			alg1();
	}


	if(cube[22]==cube[23] && cube[4]==cube[7] && cube[18]==cube[19] && cube[13]==cube[14]) //All faces are solved
	{
		while(cube[22]!=cube[21])
		{
			U(CW);
		}
	}

	else
	{
		if(cube[22]==cube[23])
		{

			if(cube[22]==1) //Green
			{
				U(CW);
				rot(CW) //NEED TO UPDATE INDICES
				alg1();
				U(CW);
			}

			else if(cube[22]==4) //Red
			{
				U(CW);
				U(CW);
				rot(CW);
				rot(CW);
				alg1();
				U(CW);
		}
		else if(cube[22]==3) //Blue
		{
				U(CCW);
				rot(CCW);
				alg1();
				U(CW);
		}
		else //Already in right spot
		{
				alg1();
				U(CW);
		}

	}

	else if(cube[4]==[7])
	{
		if(cube[4]==4) //Red
		{
			U(CW);
			rot(CW)
			alg1();
			U(CW);
		}
		else if(cube[4]==3) //Blue
		{
			U(CW);
			U(CW);
			rot(CW);
			rot(CW);
			alg1();
			U(CW);
		}
		else if(cube[4]==5) //Orange
		{
			U(CCW);
			rot(CCW);
			alg1();
			U(CW);
		}
		else //Already in right spot
		{
			alg1();
			U(CW);
		}

	}

	else if(cube[18]==cube[19])
	{
		if(cube[18]==3) //Red
		{
			U(CW);
			rot(CW)
			alg1();
			U(CW);
		}
		else if(cube[18]==5) //Orange
		{
			U(CW);
			U(CW);
			rot(CW);
			rot(CW);
			alg1();
			U(CW);
		}
		else if(cube[18]==1) //Green
		{
			U(CCW);
			rot(CCW);
			alg1();
			U(CW);
		}
		else //Already in right spot
		{
			alg1();
			U(CW);
		}

	}


	else
	{
		if(cube[13]==5) //Orange
		{
			U(CW);
			rot(CW)
			alg1();
			U(CW);
		}
		else if(cube[13]==1) //Green
		{
			U(CW);
			U(CW);
			rot(CW);
			rot(CW);
			alg1();
			U(CW);
		}
		else if(cube[13]==4) //Red
		{
			U(CCW);
			rot(CCW);
			alg1();
			U(CW);
		}
		else //Already in right spot
		{
			alg1();
			U(CW);
		}
	}
}
