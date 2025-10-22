// Create a program that uses different array initialization techniques and range-based for loops:
//
// Requirements:
//
// Declare and initialize an array of doubles using an initialization list with at least 8 values
// Demonstrate implicit array sizing by not specifying the size
// Use a traditional for loop to display elements with their subscripts
// Use a range-based for loop to display all elements
// Use a range-based for loop with a reference variable to multiply each element by 2
// Create a second array with partial initialization (initialize first 5 values, leaving rest as 0)
// Output should show:
//
// Original array contents with indices
// Array contents after modification
// The partially initialized array showing zeros for uninitialized elements

# include <iostream>
using namespace std;
int main() {
    double array[] = {1.2, 3.54, 4.5, 45.6, 7.7, 9.8, 1.1, 8.6};
    int n = sizeof(array) / sizeof(array[0]);
    cout<< "Display array 1: "<<endl;
    for (int i = 0; i < n; i++) {
        cout << array[i] << "; ";
    }
    cout<< endl << "Display array 1 with auto and range base: "<<endl;

    for (auto elm : array) {
        cout << elm << "; ";
    }

    cout<< endl << "Display array 1 with auto and range base and reference: "<<endl;
    for (double &elm : array) {
        elm *= 2;
        cout << elm << "; ";
    }

    double array2[10] = {1.2, 3.54, 4.5, 45.6, 7.7};

    cout<< endl << "Display array 2 with auto and range base and const: "<<endl;
    for (const auto &elm : array2) {
        cout << elm << "; ";
    }

    return 0;
}

