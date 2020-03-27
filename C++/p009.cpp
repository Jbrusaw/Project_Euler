//https://projecteuler.net/problem=9

//Special Pythagorean triplet

//A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,

//	a^2 + b^2 = c^2
//	For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.

//	There exists exactly one Pythagorean triplet for which a + b + c = 1000.
//	Find the product abc.


//simple brute-force solution with some constraints
long long p009()
{
	for (long long a = 1; a < 333; a++)
	{
		for (auto b = a+1; b < 500 ; b++)
		{
			const auto c = 1000 - a - b;
			if (c < b)
				break;
			if (a * a + b * b == c * c)
				return a * b * c;
		}
	}
	return 0;
}