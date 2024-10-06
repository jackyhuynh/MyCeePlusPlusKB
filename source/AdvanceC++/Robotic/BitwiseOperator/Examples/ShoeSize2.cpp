// ShoeSize2.cpp : Using objects to implement "Data Centric"
//

#include "stdafx.h"
#include <iostream>
using namespace std;

enum misc { male = 1, quantity=12, mid=20 };  // data < mid is american and data > mid is european

class Conversion
{
	int asize;
	double esize;
public:
	int GetAmerican() { return asize; }
	int GetEuropean() { return esize; }
	void SetAmerican(int a) { asize = a; }
	void SetEuropean(int e) { esize = e; }
};

class Sizes
{
	Conversion sizes[quantity];
	int american;
	int european;
public:
	Sizes(int,int);
	double GetSize(double);
	Conversion* GetSizes() { return sizes; }
};

Sizes::Sizes(int a, int e) : american(a), european(e)
{
	for (int index=0; index<quantity; index++)
	{
		sizes[index].SetAmerican(american + index);
		sizes[index].SetEuropean(european + index);	
	}
}

double Sizes::GetSize(double size)
{
	return (size > mid) ? sizes[((int)size)-european].GetAmerican() : sizes[((int)size)-american].GetEuropean();
}

class ShoeData
{
	Sizes* men;
	Sizes* women;
public:
	ShoeData(int,int,int,int);
	ShoeData() { delete men; delete women; }
	double GetSize(int itype,double size);
	double GetSize(Sizes* sex,double size);
};

ShoeData::ShoeData(int aa, int ae, int ba, int be) 
{
	men = new Sizes(aa,ae);
	women = new Sizes(ba,be);
}

double ShoeData::GetSize(int itype, double amount)
{
	return (itype == male) ? GetSize(men,amount) : GetSize(women,amount);
}

double ShoeData::GetSize(Sizes* sex, double size)
{
	return sex->GetSize(size);
}

double getInput(ShoeData& sdata)
{
	double result = -1;
	int sextype = -1;
	cout << "Enter:\n\t1. men shoe\n\t2. women shoe"<< endl;
	cin >> sextype;
	float amount;
	cout << "Enter size to convert:" << endl;
	cin >> amount;
	result = sdata.GetSize(sextype,amount);
	return result;
}

void main()
{
	ShoeData shoes(5,38,2,33);
	double result = getInput(shoes);
	cout << "Size = " << result << endl;
}

