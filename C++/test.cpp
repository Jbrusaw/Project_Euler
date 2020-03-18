#include "problems.h"
#include <iostream>

bool assert(const int p, const long long r, const long long  e)
{
	if (r == e)
		return true;
	std::cout << "Problem " << p << " test failed. Expected value: " << e << ". Returned value: " << r << std::endl;
	return false;
}

int test()
{
	auto pass = 0;
	pass += assert(1, p001(), 233168);
	pass += assert(2, p002(), 4613732);
	pass += assert(3, p003(), 6857);
	pass += assert(4, p004(), 906609);
	pass += assert(5, p005(), 232792560);
	return pass;
}
