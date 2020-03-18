int p003()
{
	auto n = 600851475143;
	for (auto i = 3; i < n; i+=2)
	{
		while (n % i == 0)
			n /= i;
	}
	return n;
}