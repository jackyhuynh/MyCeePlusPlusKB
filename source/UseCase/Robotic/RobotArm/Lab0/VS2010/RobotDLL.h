#pragma once
#ifdef ROBOTDLL_EXPORTS
#define ROBOTDLL_API __declspec(dllexport) 
#else
#define ROBOTDLL_API __declspec(dllimport) 
#endif

enum opcode
{
	ZERO = 0x00,
	OFF = 0x01,
	ON = 0x02,
	LOW = 0x04,
	HIGH = 0x08,
	x90 = 0x10,
	x180 = 0x20,
	x270 = 0x40,
	x360 = 0x80,
	EXEC = 0xFF
};

#include <iostream>
#include <windows.h>
#include <queue>
using namespace std;

class Container : queue<unsigned char>
{
public:
	unsigned char get() { unsigned char oc = front(); pop(); return oc; }
	void set(unsigned char uc) { push(uc); }
	bool empty() { return queue::empty(); }
};

inline ostream& blue(ostream &s)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE); 
    SetConsoleTextAttribute(hStdout, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    return s;
}

inline ostream& red(ostream &s)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE); 
    SetConsoleTextAttribute(hStdout, FOREGROUND_RED|FOREGROUND_INTENSITY);
    return s;
}

inline ostream& green(ostream &s)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE); 
    SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    return s;
}

inline ostream& yellow(ostream &s)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE); 
    SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
    return s;
}

inline ostream& white(ostream &s)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE); 
    SetConsoleTextAttribute(hStdout, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
    return s;
}

struct color 
{
    color(WORD attribute) : m_color(attribute) { };
    WORD m_color;
};

template <class _Elem, class _Traits>
basic_ostream<_Elem,_Traits>& operator<<(basic_ostream<_Elem,_Traits>& s, color& c)
{
    HANDLE hStdout=GetStdHandle(STD_OUTPUT_HANDLE); 
    SetConsoleTextAttribute( hStdout, c.m_color );
    return s;
}

class Robot
{
	bool debug;
public:
	ROBOTDLL_API Robot(bool b=false);
	ROBOTDLL_API void execute(Container&);
	ROBOTDLL_API ~Robot();
private:
	ROBOTDLL_API void action(unsigned char);
	ROBOTDLL_API string bits(unsigned char);
};
