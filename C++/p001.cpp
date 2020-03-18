int p001()
{
	auto solution = 0;
	for (auto i = 3; i < 1000; i++)
	{
		if (i % 3 == 0 || i % 5 == 0)
			solution += i;
	}
	return solution;
}