int p001_c(){
	int solution = 0;
	int i = 3;
	for (i = 3; i < 1000; i++)
	{
		if (i % 3 == 0 || i % 5 == 0)
			solution += i;
	}
	return solution;
}