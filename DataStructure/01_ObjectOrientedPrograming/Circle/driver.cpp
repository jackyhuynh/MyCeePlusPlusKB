/** @file driver.cpp */

#include <iostream>
#include "Circle.h"
using namespace std;

int main()
{
    Circle theCircle;

    cout << "Intital state of the circle" << endl;
    cout << "    radius = " << theCircle.getRadius() << endl;
    cout << "    area   = " << theCircle.getArea() << endl << endl;

    theCircle.setRadius(2.0);
    cout << "Current state of the circle" << endl;
    cout << "    radius = " << theCircle.getRadius() << endl;
    cout << "    area   = " << theCircle.getArea() << endl << endl;

    return 0;
}