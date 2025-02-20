#include <iostream>
using namespace std;

// You do not need include "Rectangle.h" and extend  : public Rectangle
// I will put in 1 file to explain the flow
// First you create an Interface

class RectangleInterface {
public:
    virtual bool set( double newLength, double newWidth) = 0;
    virtual double getLength() const = 0;
    virtual double getWidth() const = 0;
    virtual double getArea() const = 0;

    //destroys this Rectangle and frees assigned memory
    virtual ~RectangleInterface() {}
}; //end RectangleInterface

// Then you create the class from the interface

class Rectangle 
{
    private:
        double length;
        double width;
    public:
        Rectangle();
        bool set( double newLength, double newWidth);
        double getLength() const;
        double getWidth() const;
        double getArea() const;
};


// Then you create the definition from each 

Rectangle::Rectangle(){

    double width = 1.0;
    double length = 1.0;
}

bool Rectangle::set(double newLength, double newWidth){
    if(newLength <= 0 || newWidth <= 0){
        return false;
    }
    width = newWidth;
    length = newLength;
    return true;
}

double Rectangle::getLength() const {
    return length;
}

double Rectangle::getWidth() const {
    return width;
}

double Rectangle::getArea() const {
    return (length * width);
};


void stateOut(Rectangle myRectangle){
    cout << "Area:" << myRectangle.getArea() << endl;
    cout << "Width:" << myRectangle.getWidth() << endl;
    cout << "Length:" << myRectangle.getLength() << endl;
}

int main()
{
    Rectangle rectangle1;

    cout << "Initial state of the rectangle" << endl;
    stateOut(rectangle1);
    cout << "After some changes" << endl;
    rectangle1.set(7, 2);
    stateOut(rectangle1);
    cout << "Trying a negative value"<< endl;
    rectangle1.set(-1, 7);
    stateOut(rectangle1);
    
}

