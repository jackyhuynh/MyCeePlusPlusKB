// ShoeSize1.cpp : Demonstrating a "code-centric" approach
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int MenShoeSizeEuropean(float asize)
{
	int esize = -1;
	if (esize >= 5.0 && esize <= 5.5)
		esize = 38;
	else if (esize >= 6.0 && esize <= 6.5)
		esize = 39;
	else if (esize >= 7.0 && esize <= 7.5)
		esize = 40;
	else if (esize >= 8.0 && esize <= 8.5)
		esize = 41;
	else if (esize >= 9.0 && esize <= 9.5)
		esize = 42;
	else if (esize >= 10.0 && esize <= 10.5)
		esize = 43;
	else if (esize >= 11.0 && esize <= 11.5)
		esize = 44;
	else if (esize >= 12.0 && esize <= 12.5)
		esize = 45;
	else if (esize >= 13.0 && esize <= 13.5)
		esize = 46;
	else if (esize >= 14.0 && esize <= 14.5)
		esize = 47;
	else if (esize >= 15.0 && esize <= 15.5)
		esize = 48;
	else
		esize = 49;
	return esize;
}

int MenShoeSizeAmerican(int esize)
{
	float asize = -1;
	if (esize == 38)
		asize = 5.5;
	else if (esize == 39)
		asize = 6.5;
	else if (esize == 40)
		asize = 7.5;
	else if (esize == 41)
		asize = 8.5;
	else if (esize == 42)
		asize = 9.5;
	else if (esize == 43)
		asize = 10.5;
	else if (esize == 44)
		asize = 11.5;
	else if (esize == 45)
		asize = 12.5;
	else if (esize == 46)
		asize = 13.5;
	else if (esize == 47)
		asize = 14.5;
	else
		asize = 15.5;
	return asize;
}

int WomenShoeSizeEuropean(float asize)
{
	int esize = -1;
	if (esize >= 2.0 && esize <= 2.5)
		esize = 33;
	else if (esize >= 3.0 && esize <= 3.5)
		esize = 34;
	else if (esize >= 4.0 && esize <= 4.5)
		esize = 35;
	else if (esize >= 5.0 && esize <= 5.5)
		esize = 36;
	else if (esize >= 6.0 && esize <= 6.5)
		esize = 37;
	else if (esize >= 7.0 && esize <= 7.5)
		esize = 38;
	else if (esize >= 8.0 && esize <= 8.5)
		esize = 39;
	else if (esize >= 9.0 && esize <= 9.5)
		esize = 40;
	else if (esize >= 10.0 && esize <= 10.5)
		esize = 41;
	else if (esize >= 11.0 && esize <= 11.5)
		esize = 42;
	else if (esize >= 12.0 && esize <= 12.5)
		esize = 43;
	else
		esize = 44;
	return esize;
}

int WomenShoeSizeAmerican(int esize)
{
	float asize = -1;
	if (esize == 33)
		asize = 2.5;
	else if (esize == 34)
		asize = 3.5;
	else if (esize == 35)
		asize = 4.5;
	else if (esize == 36)
		asize = 5.5;
	else if (esize == 37)
		asize = 6.5;
	else if (esize == 38)
		asize = 7.5;
	else if (esize == 39)
		asize = 8.5;
	else if (esize == 40)
		asize = 9.5;
	else if (esize == 41)
		asize = 10.5;
	else if (esize == 42)
		asize = 11.5;
	else
		asize = 12.5;
	return asize;
}

float getInput()
{
	float result = -1;
	int sextype = -1;
	cout << "Enter:\n\t1. men shoe\n\t2. women shoe"<< endl;
	cin >> sextype;
	int countrytype = -1;
	cout << "Enter:\n\t1. American\n\t2. European" << endl;
	cin >> countrytype;
	float amount;
	cout << "Enter size to convert:" << endl;
	cin >> amount;
	if (sextype == 1)
	{
		if (countrytype == 1)
			result = MenShoeSizeAmerican(amount);
		else
			result = MenShoeSizeEuropean(amount);
	}
	else
	{
		if (countrytype == 1)
			result = WomenShoeSizeAmerican(amount);
		else
			result = WomenShoeSizeEuropean(amount);
	}
	return result;
}

void main()
{
	int result = getInput();
	cout << "Size = " << result << endl;
}


