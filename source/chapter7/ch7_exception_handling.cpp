#include <iostream>
#include <stdexcept> // Includes std::runtime_error

using namespace std;

int main() {
    int divisor, dividend, quotient;

    // First example: Division by zero using string literal exception
    dividend = 10;
    divisor = 0; // This will cause a division by zero error

    cout << "Attempting division by zero example:" << endl;
    try {
        if (divisor == 0) {
            throw "Division by zero condition!"; // Throwing an exception, is is used to manually throw an exception
        } else {
            quotient = dividend / divisor;
            cout << "The quotient is " << quotient << endl;
        }
    } catch (const char* e) {
        cerr << "Error: " << e << endl; // Handling the exception
    }
    
    cout << "-----------------------------------------" <<endl;
    cout << "Attempting division by zero example manually:" << endl;
    try {
            quotient = dividend / divisor;
            cout << "The quotient is " << quotient << endl;
    } catch (const char* e) {
        cerr << "Error: " << e << endl; // Handling the exception
    }
    cout << "-----------------------------------------" <<endl;

    cout << "\nAttempting runtime error example:" << endl;
    // Second example: Using std::runtime_error
    try {
        // Simulate an error
        throw runtime_error(" Nothing happen jst a test!");
    } catch (exception& e) {
        cout << "Caught an exception: " << e.what() << endl;
    }

    return 0;
}
