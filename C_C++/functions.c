#include "functions.h"
#include <math.h>
#include <stdlib.h>

char is_prime(const int n)
{
	if (n == 2)
		return 1;
	if (n <= 1 || n%2 == 0)
		return 0;
	int i = 3;
	for (i = 3; i <= sqrt(n); i+=2)
	{
		if (n % i == 0)
			return 0;
	}
	return 1;
}

char is_prime_with_sieve(const int n, const int *sieve, const int sieve_length)
{
	int i = 0;
	for (i = 0; i < sieve_length && sieve[i] <= sqrt(n); i++)
	{
		if (n % sieve[i] == 0)
			return 0;
	}
	return 1;
}

int* prime_sieve_under(const int n)
{
	if (n <= 1)
		return NULL;
	int* ret = malloc(sizeof(int));
	ret[0] = 2;
	if (n == 2)
		return ret;
	ret = realloc(ret, 2 * sizeof(int));
	ret[1] = 3;
	int i = 3;
	for (i = 2; ret[i-1] < n; i++)
	{
		int p = ret[i - 1];
		for (; !is_prime_with_sieve(p, ret, i); p +=2);
		if (p <= n)
		{
			ret = realloc(ret, (i + 1) * sizeof(int));
			ret[i] = p;
		}
		else
			return ret;
	}
	return ret;
}

int* prime_sieve_first(const int n)
{
	if (n <= 0)
		return NULL;
	int* ret = (int*)malloc(n * sizeof(int));
	ret[0] = 2;
	if (n == 1)
		return ret;
	ret[1] = 3;
	int i = 2;
	for (i = 2; i < n; i++)
	{
		int p = ret[i - 1];
		for (; !is_prime_with_sieve(p, ret, i); p +=2);
		ret[i] = p;
	}
	return ret;
}
