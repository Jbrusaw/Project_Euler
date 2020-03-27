//https://projecteuler.net/problem=10

//Summation of primes

//The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

//Find the sum of all the primes below two million.


#include "functions.h"

long long p010()
{
	auto primes = prime_sieve_under(2000000);
	long long ret = 0;
	for (auto p = primes.begin(); p < primes.end(); ++p)
		ret += *p;
	return ret;
}