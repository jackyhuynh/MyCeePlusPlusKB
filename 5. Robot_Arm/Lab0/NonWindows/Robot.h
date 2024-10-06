
#include <iostream>
#include <queue>
#include <string>

using namespace std;

#define ROBOT_SDK_DEFINES(name) enum name {AAA = 0x00,BBB = 0x01,CCC = 0x02,DDD = 0x04,EEE = 0x08,FFF = 0x10,GGG = 0x20,HHH = 0x40,JJJ = 0x80,KKK = 0xFF};

#define ROBOT_SDK_CONTAINER(name,container,type) class name : container<type> { public: type get() { type t = front(); pop(); return t; } void set( type t ) { push(t); } bool empty() { return container::empty(); } };

#define ROBOT_SDK_AUTO(name,type) class name { bool b; public: name(bool f=false) : b(f) { cout<<"Robot starting..."<< endl; } void exeute(Container& c) { type t=0; while(!c.empty()){ type tt=c.get(); if(tt==KKK) { action(t); t=0; } else { t += tt; if (b) { string s = bits(t); string ss = bits(tt); cout << "command " << s << "\topcode " << ss << endl; }}}} ~Robot() { cout << "Robot stopped...." << endl; } void action(type t){ if ( t & BBB ) { cout << "Executing BBB" << endl; return; } switch (t) { case CCC+DDD+FFF:cout << "Executing Low speed 90" << endl; break; case CCC+EEE+FFF:cout << "Executing High speed 90" << endl; break;case CCC+DDD+GGG:cout << "Executing Low speed 180" << endl; break;case CCC+EEE+GGG:cout << "Executing High speed 180" << endl; break;case CCC+DDD+HHH:cout << "Executing Low speed 270" << endl; break;case CCC+EEE+HHH:cout << "Executing High speed 270" << endl; break;case CCC+DDD+JJJ:cout << "Executing Low speed 360" << endl; break;case CCC+EEE+JJJ:cout << "Executing High speed 360" << endl; break;default:cout << "Invalid command " << (int)t << endl; }} string bits(unsigned char cmd){string s = "00000000";int i = 0x01;for (int x=0; x<0x08; x++){ if ( i & cmd )s[0x07-x] = 0x31;i <<= 0x01;}return s;} };

