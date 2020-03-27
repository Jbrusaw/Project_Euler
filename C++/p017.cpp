/*https://projecteuler.net/problem=17

Number letter counts
   
If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?


NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.
 */

#include <iostream>

long long p017()
{
    int letters[1000] = {0};
    letters[1] = 3;
    letters[2] = 3;
    letters[3] = 5;
    letters[4] = 4;
    letters[5] = 4;
    letters[6] = 3;
    letters[7] = 5;
    letters[8] = 5;
    letters[9] = 4;
    letters[10] = 3;
    letters[11] = 6;
    letters[12] = 6;
    letters[13] = 8;
    letters[14] = 8;
    letters[15] = 7;
    letters[16] = 7;
    letters[17] = 9;
    letters[18] = 8;
    letters[19] = 8;

    letters[20] = 6;
    letters[30] = 6;
    letters[40] = 5;
    letters[50] = 5;
    letters[60] = 5;
    letters[70] = 7;
    letters[80] = 6;
    letters[90] = 6;

	//the 7 here represents "hundred"
    letters[100] = 7 + letters[1];
    letters[200] = 7 + letters[2];
    letters[300] = 7 + letters[3];
    letters[400] = 7 + letters[4];
    letters[500] = 7 + letters[5];
    letters[600] = 7 + letters[6];
    letters[700] = 7 + letters[7];
    letters[800] = 7 + letters[8];
    letters[900] = 7 + letters[9];

	//represents "one thousand"
    letters[0] = 11;

    auto ret = 0;
	for (auto i = 0; i < 1000; i++)
	{
        if (letters[i] == 0) {
            if (i < 100)
                // 91 = "ninety one" = "ninety" + "one"
                letters[i] = letters[i - i % 10] + letters[i % 10];
            else
                //234 = "two hundred" + "and" + "thirty four". The 34 should've have been pre-calculated by this point
                letters[i] = letters[i - i % 100] + 3 + letters[i % 100];
        }
        ret += letters[i];
	}
    return ret;
}