/** @file Circle.cpp */

#include "Circle.h"

Circle::Circle()
{
    radius = 1.0;
}

void Circle::setRadius(double newRadius)
{
    if (newRadius > 0.0)
    {
        radius = newRadius;
    }
    // else leave this circle unchanged
}

double Circle::getRadius() const
{
    return radius;
}

double Circle::getArea() const
{
    return 3.14 * radius * radius;
}