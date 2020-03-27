/*https://projecteuler.net/problem=19

Counting Sundays

You are given the following information, but you may prefer to do some research for yourself.

1 Jan 1900 was a Monday.
Thirty days has September,
April, June and November.
All the rest have thirty-one,
Saving February alone,
Which has twenty-eight, rain or shine.
And on leap years, twenty-nine.
A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
 */

long long p019()
{
	int days_in_month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	
	//let sunday = 0, saturday = 6. We start on Monday, Jan 1 1900
	auto day = 1;

	//this gets us to Jan 1 1901;
	day = (day + 365) % 7;

	auto ret = 0;
	ret += (day == 0);
	
	//for each year in range
	for (auto i = 1901; i <= 2000; i++)
	{
		//for each month
		for (auto j = 0; j < 12; j++)
		{
			//advance the calender to the first of the month
			day += days_in_month[j];

			//add a day for leap days
			if (j == 1 && (i % 4 == 0) && (i % 100 > 0 || i % 400 == 0))
				day++;

			//see if it's a sunday
			day %= 7;
			ret += (day == 0);
		}

	}
	return ret;
}