//https://projecteuler.net/problem=5

//Smallest multiple
   
//2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
//What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

#include "functions.h"

long long p005()
{
	std::vector<int> factors;
	factors.push_back(2);
	for (auto i = 3; i < 20; i++)
	{
		auto n = i;
		for(auto f = factors.begin(); f < factors.end() && (*f) < i; ++f)
		{
			if (n % (*f) == 0)
				n /= (*f);
		}
		if (n > 1)
			factors.push_back(n);
	}

	long long solution = 1;
	for (auto f = factors.begin(); f < factors.end(); ++f)
		solution *= (*f);
	return solution;
}
