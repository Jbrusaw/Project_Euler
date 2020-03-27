//https://projecteuler.net/problem=6

//Sum square difference

//The sum of the squares of the first ten natural numbers is,
//1^2 + 2^2 + ... + 10^2 = 385

//The square of the sum of the first ten natural numbers is,
//(1 + 2 + ... + 10)^2 = 552 = 3025

//Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025-385 = 2640

//Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

long long p006()
{
	long long sq_sum = 0, sum_sq = 0;
	for (auto i = 1; i <= 100; i++)
	{
		sum_sq += static_cast<long long>(i) * i;
		sq_sum += i;
	}

	return sq_sum*sq_sum - sum_sq;
}
