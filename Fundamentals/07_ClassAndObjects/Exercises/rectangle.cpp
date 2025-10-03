#include <iostream>
using namespace std;

class Rectangle {
private:
    double length;
    double width;

public:
    // Default constructor
    Rectangle() : length(1.0), width(1.0) {
        cout << "Default constructor called - Rectangle created with dimensions 1.0 x 1.0" << endl;
    }
    
    // Parameterized constructor
    Rectangle(double l, double w) {
        length = (l > 0) ? l : 1.0;
        width = (w > 0) ? w : 1.0;
        cout << "Parameterized constructor called - Rectangle created with dimensions " 
             << length << " x " << width << endl;
    }
    
    // Destructor
    ~Rectangle() {
        cout << "Destructor called - Rectangle with dimensions " 
             << length << " x " << width << " is being destroyed" << endl;
    }
    
    // Accessor methods
    double getLength() const {
        return length;
    }
    
    double getWidth() const {
        return width;
    }
    
    // Mutator methods with validation
    void setLength(double l) {
        if (l > 0) {
            length = l;
            cout << "Length set to " << l << endl;
        } else {
            cout << "Error: Length must be positive. Length not changed." << endl;
        }
    }
    
    void setWidth(double w) {
        if (w > 0) {
            width = w;
            cout << "Width set to " << w << endl;
        } else {
            cout << "Error: Width must be positive. Width not changed." << endl;
        }
    }
    
    // Member functions
    double getArea() const {
        return length * width;
    }
    
    double getPerimeter() const {
        return 2 * (length + width);
    }
};

int main() {
    cout << "=== Creating Rectangle with default constructor ===" << endl;
    Rectangle rect1;
    cout << "Area: " << rect1.getArea() << endl;
    cout << "Perimeter: " << rect1.getPerimeter() << endl << endl;
    
    cout << "=== Creating Rectangle with parameterized constructor ===" << endl;
    Rectangle rect2(5.0, 3.0);
    cout << "Area: " << rect2.getArea() << endl;
    cout << "Perimeter: " << rect2.getPerimeter() << endl << endl;
    
    cout << "=== Testing mutator methods ===" << endl;
    rect2.setLength(7.0);
    rect2.setWidth(4.0);
    cout << "New Area: " << rect2.getArea() << endl;
    cout << "New Perimeter: " << rect2.getPerimeter() << endl << endl;
    
    cout << "=== Testing invalid dimensions ===" << endl;
    rect2.setLength(-5.0);
    rect2.setWidth(-3.0);
    cout << "Current dimensions: " << rect2.getLength() << " x " << rect2.getWidth() << endl << endl;
    
    cout << "=== Program ending - destructors will be called ===" << endl;
    return 0;
}