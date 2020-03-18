int p002()
{
	auto solution = 2, fib1 = 1, fib2 = 2;

	while (fib1 + fib2 < 4000000)
	{
		const auto fib3 = fib1 + fib2;
		if (fib3 % 2 == 0)
			solution += fib3;
		fib1 = fib2;
		fib2 = fib3;
	}

	return solution;
}