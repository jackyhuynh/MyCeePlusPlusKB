// Bits.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <bitset>

using namespace std;

void Example5()
{
	bitset<8> first = 0x0F;
	bitset<8> second = 0xF0;
	cout << first << '\t' << second << endl;
	first ^= second;
	second ^= first;
	first ^= second;
	cout << first << '\t' << second << endl;
}


void Example4()
{
	unsigned char first = 0x0F;
	unsigned char second = 0xF0;
	cout << first << '\t' << second << endl;
	first ^= second;
	second ^= first;
	first ^= second;
	cout << first << '\t' << second << endl;
}

void Example3()
{
	bitset<8> bits = 0x01;
	for (char c=0; c<8; c++)
		cout << (bits << c) << endl;
}

void Example2()
{
	unsigned char bits = 0x1;
	for (char c=0; c<8; c++)
		cout << (bits << c) << endl;
}

void Example1()
{
	unsigned char first = 0xF;
	unsigned char second = 0xA;
	cout << bitset<4>(first & second) << endl;
	cout << bitset<4>(first | second) << endl;
	cout << bitset<4>(first ^ second) << endl;
}

void Example0()
{
	unsigned char first = 0xF;
	unsigned char second = 0xA;

	cout << (first & second) << endl;
	cout << (first | second) << endl;
	cout << (first ^ second) << endl;
}

void main()
{
	Example0();
	Example1();
	Example2();
	Example3();
	Example4();
	Example5();
}

