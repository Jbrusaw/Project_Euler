/* https://projecteuler.net/problem=24
 
Lexicographic permutations
 
A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4.
If all of the permutations are listed numerically or alphabetically, we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:

012   021   102   120   201   210

What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
 */


#include <iostream>
#include "functions.h"

//If we fix the first digit, the number of permutations for the remaining digits is (n-1)!
//by dividing the target number by the number of permutations, we can deduced the first digit
//For example, our target is 1000000 and we have 10 digits. The number of permutations of
//9 digits is 362880. 1000000/362880 = 2.xxx, so we know the 1000000th permutation must
//start with 2. We remove 2 from the list of available digits and repeat until done
long long p024()
{
	long target = 1000000;
	bool used[10] = { false };
	long long answer = 0;
	for (auto i = 0; i <= 9; i++)
	{
		int digit;
		if (i < 9) {
			const auto fact = factorial(9 - i);
			digit = target / fact;

			//in the special case where the target divides exactly, then we subtract 1.
			//otherwise that would leave 0 permutations available for the rest of the digits
			if (target == digit * fact)
				digit--;
			target -= digit * fact;
		}
		//if there's only one digit left, then we just take the 0th digit
		else
			digit = 0;

		//find the nth digit remaining
		int count;
		for (count = 0; digit >= 0; count++)
			digit -= !used[count];

		//count should always be between 1 and 10, but an if statement is here just in case
		if (count >= 1 && count <= 10)
			used[count-1] = true;

		//add count-1 to the answer. We do count-1 because if we start at 0, then
		//the nth digit is actually n-1;
		answer = 10*answer + count-1;
	}
	return answer;
}
