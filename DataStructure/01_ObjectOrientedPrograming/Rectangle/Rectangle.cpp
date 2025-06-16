#include "Rectangle.h"

// Rectangle Implementation
Rectangle::Rectangle(double initialLength, double initialWidth) {
	if (initialLength <= 0.0 || initialWidth <= 0.0) {
		throw std::invalid_argument("Length and width must be positive");
	}
	length = initialLength;
	width = initialWidth;
}

double Rectangle::getLength() const {
	return length;
}

double Rectangle::getWidth() const {
	return width;
}

double Rectangle::getArea() const {
	return length * width;
}

void Rectangle::setLength(double newLength) {
	if (newLength <= 0.0) {
		throw std::invalid_argument("Length must be positive");
	}
	length = newLength;
}

void Rectangle::setWidth(double newWidth) {
	if (newWidth <= 0.0) {
		throw std::invalid_argument("Width must be positive");
	}
	width = newWidth;
}