/** @file Circle.h */

#ifndef CIRCLE_
#define CIRCLE_

#include "CircleInterface.h"

class Circle : public CircleInterface
{
public:
    Circle();
    void setRadius(double newRadius);
    double getRadius() const;
    double getArea() const;
private:
    double radius;
};
#endif