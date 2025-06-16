#include <iostream>
#include "Rectangle.h"
using namespace std;

void printRectangleState(const Rectangle& rect) {
    cout << "Rectangle State:" << endl;
    cout << "    Length = " << rect.getLength() << endl;
    cout << "    Width  = " << rect.getWidth() << endl;
    cout << "    Area   = " << rect.getArea() << endl;
}

void testValidDimensions() {
    cout << "\n=== Testing Valid Dimensions ===" << endl;
    try {
        Rectangle rect(5.0, 3.0);
        printRectangleState(rect);
        
        cout << "\nUpdating dimensions..." << endl;
        rect.setLength(7.0);
        rect.setWidth(4.0);
        printRectangleState(rect);
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

void testInvalidDimensions() {
    cout << "\n=== Testing Invalid Dimensions ===" << endl;
    try {
        cout << "Testing negative length..." << endl;
        Rectangle rect(-1.0, 3.0);
    } catch (const exception& e) {
        cout << "Caught expected error: " << e.what() << endl;
    }

    try {
        cout << "\nTesting negative width..." << endl;
        Rectangle rect(3.0, -1.0);
    } catch (const exception& e) {
        cout << "Caught expected error: " << e.what() << endl;
    }

    try {
        cout << "\nTesting zero dimensions..." << endl;
        Rectangle rect(0.0, 0.0);
    } catch (const exception& e) {
        cout << "Caught expected error: " << e.what() << endl;
    }
}

void testDefaultConstructor() {
    cout << "\n=== Testing Default Constructor ===" << endl;
    try {
        Rectangle rect;
        printRectangleState(rect);
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

int main() {
    cout << "Starting Rectangle Tests\n" << endl;
    
    testDefaultConstructor();
    testValidDimensions();
    testInvalidDimensions();
    
    cout << "\nAll tests completed." << endl;
    return 0;
}

