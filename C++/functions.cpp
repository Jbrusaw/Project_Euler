//Some common functions that a lot of problems use

#include "functions.h"
#include <cmath>
#include <string>
#include <vector>
#include <iostream>

bool is_prime(const long long n)
{
	if (n <= 1)
		return false;
	const auto sieve = prime_sieve_under(static_cast<long long> (sqrt(n)));
	return is_prime(n, sieve);
}

bool is_prime(const long long n, std::vector<long long> sieve)
{
	for (auto i = sieve.begin(); i < sieve.end() && (*i) <= sqrt(n); ++i)
	{
		if (n % (*i) == 0)
			return false;
	}
	return true;
}

std::vector<long long> prime_sieve_under(const long long n)
{
	std::vector<long long> ret;
	
	if (n <= 1)
		return ret;
	
	ret.push_back(2);
	
	if (n == 2)
		return ret;
	
	ret.push_back(3);
	
	for (auto i = 2; ret[static_cast<__int64>(i) - 1] < n; i++)
	{
		auto p = ret[static_cast<__int64>(i) - 1] + 2;
		while (!is_prime(p, ret) && p <= n)
			p += 2;
		if (p <= n)
			ret.push_back(p);
		else
			return ret;
	}
	return ret;
}

std::vector<long long> prime_sieve_first(const int n)
{
	std::vector<long long> ret;
	
	if (n <= 0)
		return ret;
	
	ret.push_back(2);
	
	if (n == 1)
		return ret;
	
	ret.push_back(3);
	
	for (auto i = 2; i < n; i++)
	{
		auto p = ret[static_cast<__int64>(i) - 1] + 2;
		while (!is_prime(p, ret))
			p += 2;
		ret.push_back(p);
	}
	
	return ret;
}

bool is_palindrome(const long long n)
{
	const auto digits = num_digits(n);
	const auto s = std::to_string(n);
	for (auto i = 0; i <= digits / 2; i++)
	{
		if (s[i] != s[digits - static_cast<__int64>(i) - 1])
			return false;
	}
	return true;
}

int num_digits(const long long n)
{
	return ceil(log10(n));
}

std::vector<long long> prime_factorization(long long n)
{
	if (is_prime(n))
		return std::vector<long long> {n};
	std::vector<long long> ret;
	const auto sieve = prime_sieve_under(static_cast<long long>(sqrt(n)));
	for (auto p = sieve.begin(); p < sieve.end() && n > 1; ++p)
	{
		while (n%(*p) == 0)
		{
			n /= *p;
			ret.push_back(*p);
		}
	}
	return ret;
}

long long factorial(const int n)
{
	auto ret = 1;
	for (auto i = 2; i <= n; i++)
		ret *= i;
	return ret;
}
