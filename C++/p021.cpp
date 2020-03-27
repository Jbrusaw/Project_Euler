/*https://projecteuler.net/problem=21

Amicable numbers

Let d(n) be defined as the sum of proper divisors of n(numbers less than n which divide evenly into n).
If d(a) = b and d(b) = a, where a != b, then a and b are an amicable pair and each of a and b are called amicable numbers.

For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

Evaluate the sum of all the amicable numbers under 10000.

*/

#include <cmath>

//for memoization
int divisors[10000] = { 0 };

int d(const int n)
{
	if (n <= 1 || n >= 10000)
		return 0;
	if (divisors[n] > 0)
		return divisors[n];
	
	//sum up all the divisors
	auto ret = 1;
	for (auto i = 2; i < sqrt(n); i++)
	{
		if (n % i == 0) {
			ret += i;
			ret += n / i;
		}
	}
	if (static_cast<int>(sqrt(n)) == sqrt(n))
		ret += static_cast<int>(sqrt(n));

	//store it and return it
	divisors[n] = ret;
	return ret;
}

long long p021()
{
	auto ret = 0;
	for (auto i = 2; i < 10000; i++)
	{
		if (i == d(d(i)) && i != d(i))
			ret += i;
	}
	return ret;
}
