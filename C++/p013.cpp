/* https://projecteuler.net/problem=13
Large sum
   
Problem 13
Work out the first ten digits of the sum of the following one-hundred 50-digit numbers.

<numbers omitted for legibility and can be found in p013.text
 */

#include <fstream>
#include <string>

long long p013()
{
    double ret = 0;

    std::fstream fin;
    fin.open("p013.txt");
	
	while (!fin.eof())
	{
        std::string in;
        fin >> in;
        ret += std::stod(in);
	}
	
    while (ret > 10000000000)
        ret /= 10;
    return static_cast<long long>(ret);
}
