//https://projecteuler.net/problem=16

//Power digit sum

//2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

//What is the sum of the digits of the number 2^1000 ?

long long p016()
{
	//n[] represents 2^1000. 2^1000 =~ (2^3)^333 == 8^333. 8^333 < 10^333, so we know 333 is an upper bound for number of digits
	int n[333] = { 0 };
	auto ret = 0;
	n[332] = 1;
	for (auto i = 0; i < 1000; i++)
	{
		//multiply through n[] by 2
		for (auto j = n; j < n + 333; ++j)
			(*j) *= 2;
		//when we get too close to overflow, carry all the digits over
		if (n[332] > 1000000)
		{
			for (auto j = n + 332; j >= n; --j)
			{
				*(j - 1) += (*j) / 10;
				*j = *j % 10;
			}
		}
	}
	//digit-carry and sum one last time
	for (auto j = n + 332; j >= n; --j)
	{
		*(j - 1) += (*j) / 10;
		*j = *j % 10;
		ret += *j;
	}
	return ret;
}