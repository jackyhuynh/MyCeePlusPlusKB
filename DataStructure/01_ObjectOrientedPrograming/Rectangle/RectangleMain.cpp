#include <iostream>
#include "Rectangle.h"

int main() {
    std::cout << "\n=== Exception-based Rectangle Demo ===" << std::endl;
    try {
        Rectangle rectangle(2.0, 3.0);
        
        std::cout << "Initial state of the Rectangle:" << std::endl;
        std::cout << "    Length = " << rectangle.getLength() << std::endl;
        std::cout << "    Width  = " << rectangle.getWidth() << std::endl;
        std::cout << "    Area   = " << rectangle.getArea() << std::endl << std::endl;
        
        rectangle.setLength(4.0);
        rectangle.setWidth(5.0);
        
        std::cout << "Updated state of the Rectangle:" << std::endl;
        std::cout << "    Length = " << rectangle.getLength() << std::endl;
        std::cout << "    Width  = " << rectangle.getWidth() << std::endl;
        std::cout << "    Area   = " << rectangle.getArea() << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
} 