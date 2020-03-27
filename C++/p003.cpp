//https://projecteuler.net/problem=3

//Largest prime factor
   
//The prime factors of 13195 are 5, 7, 13 and 29.
//What is the largest prime factor of the number 600851475143 ?


long long p003()
{
	auto n = 600851475143;
	for (auto i = 3; i < n; i+=2)
	{
		while (n % i == 0)
			n /= i;
	}
	return n;
}
