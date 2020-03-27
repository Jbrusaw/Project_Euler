//https://projecteuler.net/problem=10

//Summation of primes

//The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

//Find the sum of all the primes below two million.

#include <cmath>
#include <iostream>

bool is_prime(const int n, const int* last, const int* primes)
{
	for (auto i = primes; (*i) <= sqrt(n) && i <= last; ++i)
	{
		if (n % (*i) == 0)
			return false;
	}
	return true;
}


long long p010()
{
	const auto primes = new int[1000000];
	primes[0] = 2;
	long long ret = 2;
	auto last = primes;
	for (auto i = 3; i < 2000000; i+=2)
	{
		if(is_prime(i,last,primes))
		{
			last++;
			*last = i;
			ret += i;
		}
	}
	delete[] primes;
	return ret;
}