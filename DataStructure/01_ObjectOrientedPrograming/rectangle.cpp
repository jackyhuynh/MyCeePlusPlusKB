#include <iostream>
using namespace std;

class RectangleInterface
{
public:
	virtual void setlength(double newRadius) = 0;
	
    virtual void setwidth(double newRadius) = 0;

	virtual double getArea() const = 0;

	virtual ~RectangleInterface() {}
};

class Rectangle : public RectangleInterface
{
public:
	Rectangle();
	void setRadius(double newRadius);
	double getArea() const;

private:
	double length;
    double width;
};

Rectangle::Rectangle()
{
	radius = 1.0;
}

void Rectangle::setRadius(double newRadius)
{
	if (newRadius > 0.0)
	{
		radius = newRadius;
	}
	// else leave this Rectangle unchanged
}

double Rectangle::getArea() const
{
	return 3.14 * radius * radius;
}


int main()
{
	Rectangle theRectangle;
	
	cout << "Intital state of the Rectangle" << endl;
	cout << "    area   = " << theRectangle.getArea() << endl << endl;
	
	theRectangle.setRadius(2.0);
	cout << "Current state of the Rectangle" << endl;
	cout << "    area   = " << theRectangle.getArea() << endl << endl;
	
	return 0;
}