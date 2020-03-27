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
	pass += assert(6, p006(), 25164150);
	pass += assert(7, p007(), 104743);
	pass += assert(8, p008(), 23514624000);
	pass += assert(9, p009(), 31875000);
	pass += assert(10, p010(), 142913828922);
	pass += assert(11, p011(), 70600674);
	pass += assert(12, p012(), 76576500);
	pass += assert(13, p013(), 5537376230);
	return pass;
}
