#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <stdexcept>

/**
 * @brief Interface for Rectangle operations
 */
class RectangleInterface {
public:
    virtual void setLength(double newLength) = 0;
    virtual void setWidth(double newWidth) = 0;
    virtual double getLength() const = 0;
    virtual double getWidth() const = 0;
    virtual double getArea() const = 0;
    virtual ~RectangleInterface() = default;
};

/**
 * @brief Rectangle class implementation
 */
class Rectangle : public RectangleInterface {
public:
    Rectangle(double initialLength = 1.0, double initialWidth = 1.0);
    double getLength() const;
    double getWidth() const;
    double getArea() const;
    void setLength(double newLength);
    void setWidth(double newWidth);

private:
    double length;
    double width;
};

#endif // RECTANGLE_H 