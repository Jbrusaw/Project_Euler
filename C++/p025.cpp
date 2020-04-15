/*https://projecteuler.net/problem=25
The Fibonacci sequence is defined by the recurrence relation:

Fn = Fn-1 + Fn-2, where F1 = 1 and F2 = 1.
Hence the first 12 terms will be:

F1 = 1
F2 = 1
F3 = 2
F4 = 3
F5 = 5
F6 = 8
F7 = 13
F8 = 21
F9 = 34
F10 = 55
F11 = 89
F12 = 144
The 12th term, F12, is the first term to contain three digits.

What is the index of the first term in the Fibonacci sequence to contain 1000 digits?

*/


//the number of digits of any number can be expressed by log10(n) + 1.

//as fibonacci numbers increase, the ratio between them approaches the golden ratio (1.618...)
//so we can express any fibonacci number as (f*1.618...^n) for a sufficiently high fibonacci number f
//we're given 144 as the 12th fibonacci number, so we can express the nth fibonacci number as
//144*1.618...^(n-12) with close enough accuracy for this problem

//combining the two concepts above, we can express the nth index of the first fibonacci number with 1000 digits as
//1000 = log10(144*1.618...^(n-12)) + 1. Using logarithmic identities and moving some pieces around, we get
//n = (999 - log10(144))/log10(1.618...) + 12. This will give us some fractional/decimal number, so we take the
//ceiling of that number to give us the integer index of the first fibonacci number with 1000 digits

#include <cmath>

long long p025()
{
	return static_cast<long long>(ceil((999 - log10(144))/log10(1.61803398875) + 12));
}
