/*https://projecteuler.net/problem=14

The following iterative sequence is defined for the set of positive integers:

n -> n/2 (n is even)
n -> 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:

13 -> 40 -> 20 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1
It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.
 */

//for memoization
int seq[1000000] ={0};

int collatz(const long long n, int length)
{
	//if seq[n] can be stored/accessed
	if (n < 1000000) {
		//if we don't know what seq[n] is
		if (seq[n] == 0) {
			//if n is odd
			if (n & 1)
				seq[n] = collatz(3 * n + 1, ++length) + 1;
			//if n is even
			else
				seq[n] = collatz(n / 2, ++length) + 1;
		}
		return seq[n];
	}
	//if n is odd
	if (n & 1)
		return collatz(3 * n + 1, ++length) + 1;
	//if n is even
	return collatz(n / 2, ++length) + 1;
}


long long p014()
{
	seq[1] = 1;
	auto ret = 0;
	auto longest = 0;
	for (auto i = 2; i < 1000000; i++)
	{
		const auto c = collatz(i, 1);
		if (c > longest)
		{
			longest = c;
			ret = i;
		}
	}
	return ret;
}
