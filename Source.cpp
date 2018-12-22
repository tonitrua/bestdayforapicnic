#include <iostream>
#include <fstream>
using namespace std;

//converts the day of week from the .txt file into its full form
void dayofweek(int dow, int dom)
{
	if (dow == 'm')
		cout << "Monday";
	else if (dow == 't' && dom % 7 == 0)
		cout << "Tuesday";
	else if (dow == 'w')
		cout << "Wednesday";
	else if (dow == 't' && dom % 7 == 2)
		cout << "Thursday";
	else if (dow == 'f')
		cout << "Friday";
	else if (dow == 's' && dom % 7 == 4)
		cout << "Saturday";
	else if (dow == 's' && dom % 7 == 5)
		cout << "Sunday";
}

//converts the day of month from the .txt file into its ordinal form
void ordinal(int dom)
{
	if (dom == 1 || dom == 21)
	cout << "st";
	else if (dom == 2 || dom == 22)
	cout << "nd";
	else if (dom == 3 || dom == 23)
	cout << "rd";
	else
	cout << "th";
}

int main()
{
	ifstream iteration1("weather.txt");
	ifstream iteration2("weather.txt");
	int dom, high, low, pop; //day of the month, high (celsius), low (celsius), probability of precipitation
	char dow; //day of week
	int lowestpop = 100; //lowest chance of precipitation
	int days = 0; //number of days for vacation
	int n = 0; //consecutive day counter
	int firstday, vacationstart;

	//first iteration through the file to find the lowest chance of precipitation as well as number of vacation days
	iteration1.ignore(1000, '\n');
	while (iteration1 >> dom >> dow >> high >> low >> pop)
	{
		if (low > 21 && high < 29 && pop < lowestpop)
				lowestpop = pop;

		if (low > 21 && high < 29 && pop < 50)
		{
			n = n + 1;
			if (n == 1)
				firstday = dom;
			if (n > days)
			{
				days = n;
				vacationstart = firstday;
			}
		}
		else
			n = 0;

	}
	iteration1.close();

	//second iteration through the file to find all occurrences of the lowest chance of precipitation within our parameters
	iteration2.ignore(1000, '\n');
	while (iteration2 >> dom >> dow >> high >> low >> pop)
	{
		if (low > 21 && high < 29 && pop == lowestpop)
		{
			dayofweek(dow, dom);
			cout << " the " << dom;
			ordinal(dom);
			cout << " day of the month is the best day for a picnic." << endl;
		}
		if (dom == vacationstart)
		{
			cout << "Starting on ";
			dayofweek(dow, dom);
			cout << " the " << dom;
			ordinal(dom);
			cout << " day of the month, and the next " << days << " days, are the best days for a vacation." << endl;
		}
	}
	iteration2.close();
}