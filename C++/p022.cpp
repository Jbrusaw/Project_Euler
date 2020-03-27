/*https://projecteuler.net/problem=22
Names scores
   
Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names,
begin by sorting it into alphabetical order. Then working out the alphabetical value for each name,
multiply this value by its alphabetical position in the list to obtain a name score.

For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53,
is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.

What is the total of all the name scores in the file?
 */

#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

long long value(std::string name)
{
	auto ret = 0;
	//iterate through the name to calc the value. The +1 and -1 in the range is to exclude the quotation marks
	for (auto c = name.begin() + 1; c < name.end() - 1; ++c)
		ret += (*c) - 'A' + 1;
	return ret;
}

long long p022()
{
    std::ifstream fin;
    fin.open("p022.txt");
    std::vector<std::string> names;
	while (!fin.eof())
	{
		std::string temp;
		std::getline(fin, temp, ',');
		names.push_back(temp);
	}

	sort(names.begin(), names.end());

	long long ret = 0;
	
	for (long long i = 0; i < names.size(); i++) 
		ret += (i+1) * value(names[i]);

	return ret;
}