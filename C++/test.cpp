//This is just to make sure all solutions still work after modifying any shared functions

#include "problems.h"
#include <iostream>
#include <chrono>

using namespace std::chrono;

bool assert(const int p, long long (*f)(), const long long  e)
{
	const auto start = high_resolution_clock::now();
	const auto r = f();
	const auto stop= high_resolution_clock::now();
	const auto elapsed = duration_cast<milliseconds>(stop - start).count() * 1e-3;
	if (r == e) {
		if (elapsed > 0)
			std::cout << "Problem " << p << " test passed.\t Elapsed time: " << elapsed << "s" << std::endl;
		else
			std::cout << "Problem " << p << " test passed.\t Elapsed time: < 1ms" << std::endl;
	}
	else
		std::cout << "Problem " << p << " test failed. Expected value: " << e << ". Returned value: " << r << std::endl;
	return (r==e);
}

int test()
{
	const auto start = high_resolution_clock::now();
	
	auto pass = 0;
	pass += assert(1, p001, 233168);
	pass += assert(2, p002, 4613732);
	pass += assert(3, p003, 6857);
	pass += assert(4, p004, 906609);
	pass += assert(5, p005, 232792560);
	pass += assert(6, p006, 25164150);
	pass += assert(7, p007, 104743);
	pass += assert(8, p008, 23514624000);
	pass += assert(9, p009, 31875000);
	pass += assert(10, p010, 142913828922);
	pass += assert(11, p011, 70600674);
	pass += assert(12, p012, 76576500);
	pass += assert(13, p013, 5537376230);
	pass += assert(14, p014, 837799);
	pass += assert(15, p015, 137846528820);
	pass += assert(16, p016, 1366);
	pass += assert(17, p017, 21124);
	pass += assert(18, p018, 1074);
	pass += assert(19, p019, 171);
	pass += assert(20, p020, 648);
	pass += assert(21, p021, 31626);
	pass += assert(22, p022, 871198282);
	pass += assert(23, p023, 4179871);
	pass += assert(24, p024, 2783915460);
	pass += assert(25, p025, 4782);

	const auto stop = high_resolution_clock::now();
	const auto elapsed = duration_cast<milliseconds>(stop - start).count() * 1e-3;
	std::cout << "Total time elapsed for all tests: " << elapsed << "s" << std:: endl;
	
	return pass;
}
