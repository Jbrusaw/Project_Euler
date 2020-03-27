//https://projecteuler.net/problem=4

//Largest palindrome product
   
//A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
//Find the largest palindrome made from the product of two 3-digit numbers.

#include <algorithm>
#include "functions.h"

long long p004()
{
	//largest possible number is 6 digits
	//if we assume the number is 9xxxx9, then the last digit
	//of each factor must be either 9*1, 3*3, or 7*7
	auto solution = 0;
	for (auto i = 999; i >= 909; i-=10)
	{
		for (auto j = 991; j >= 901; j -= 10)
		{
			if (i * j < solution)
				break;
			if (is_palindrome(static_cast<long long>(i) * static_cast<long long>(j)))
				solution = std::max(solution, i * j);
		}
	}

	for (auto i = 993; i >= 903; i-=10)
	{
		for (auto j = i; j >= 903; j -= 10)
		{
			if (i * j < solution)
				break;
			if (is_palindrome(static_cast<long long>(i) * static_cast<long long>(j)))
				solution = std::max(solution, i * j);
		}
	}

	for (auto i = 997; i >= 907; i-=10)
	{
		for (auto j = i; j >= 907; j -= 10)
		{
			if (i * j < solution)
				break;
			if (is_palindrome(static_cast<long long>(i) * static_cast<long long>(j)))
				solution = std::max(solution, i * j);
		}
	}
	return solution;
}
