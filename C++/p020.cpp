//https://projecteuler.net/problem=20

//Factorial digit sum

//n! means n *(n - 1) * ... * 3 * 2 * 1

//For example, 10!= 10 * 9 * ... * 3 * 2 * 1 = 3628800,
//and the sum of the digits in the number 10!is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

//Find the sum of the digits in the number 100!


long long p020()
{
	//n[] represents 100!
	int n[200] = { 0 };
	n[199] = 1;
	for (auto i = 1; i <= 100; i++)
	{
		//multiply through n[] by i
		for (auto j = n; j < n + 200; ++j)
			(*j) *= i;

		//carry all the digits over
		for (auto j = n + 199; j >= n; --j)
		{
			*(j - 1) += (*j) / 10;
			*j = *j % 10;
		}
	}
	
	//sum the digits
	auto ret = 0;
	for (auto j = n + 199; j >= n; --j)
		ret += *j;
	
	return ret;
}
