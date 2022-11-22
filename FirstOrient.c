void FirstOrient(int* cube)
{
	while(cube[22]!=5)
	{
		U(CW, cube);
	}

trackedflip(cube);
trackedflip(cube);

}
