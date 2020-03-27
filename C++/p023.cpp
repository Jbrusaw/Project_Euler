/*https://projecteuler.net/problem=23
 
Non-abundant sums

Problem 23
A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.

A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.

As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24. By mathematical analysis,
it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers.
However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.

Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.

 */

#include <cmath>
#include <vector>

//sums up all the divisors
int d23(const int n)
{
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

	return ret;
}

//true = sum of 2 abundant numbers
bool nums[28124] = { false };

long long p023()
{
	
	std::vector<int> abundant;
	for (auto i = 12; i < 28123; i++)
	{
		//if it's an abundant number, then add it to the list, then iterator through the list summing it against every number
		//and marking nums as true for every sum
		if (d23(i) > i) {
			abundant.push_back(i);
			for (auto j = abundant.begin(); j < abundant.end(); ++j)
			{
				if (i + *j > 28124)
					break;
				nums[i + *j] = true;
			}
		}
	}

	//iterator through nums and sum all non-abundant sums
	auto ret = 0;
	for (auto i = 0; i < 28124; i++)
	{
		if (!nums[i])
			ret += i;
	}
	return ret;
}
