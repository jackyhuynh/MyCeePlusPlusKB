// ## Exercise 1: Array Basics and Processing

// Write a program that demonstrates fundamental array operations:

// **Requirements:**
// - Create an array of 10 integers
// - Use a loop to input values from the user
// - Implement functions to:
//   - Calculate and return the sum of all elements
//   - Calculate and return the average
//   - Find and return the largest element
//   - Find and return the smallest element
//   - Display the array contents
// - Handle **off-by-one errors** by ensuring subscripts range from 0 to n-1

// **Test your program by:**
// - Entering both positive and negative numbers
// - Verifying all calculations are correct
// - Ensuring no array bounds are violated

#include <iostream>
using namespace std;

const int SIZE = 10;

int main()
{
    int numbers[SIZE];
    for (int i = 0; i < SIZE; i++) {
        cout << "Enter number " << (i + 1) << ": ";
        cin >> numbers[i];
    }
    int sum = 0;
    int largest = numbers[0];
    int smallest = numbers[0];
    for (int i = 0; i < SIZE; i++) {
        sum += numbers[i];
        if (numbers[i] > largest) largest = numbers[i];
        if (numbers[i] < smallest) smallest = numbers[i];
    }

    double average = static_cast<double>(sum) / SIZE;
    for (int i = 0; i < SIZE; i++) {
        cout << "Element " << i << ": " << numbers[i] << endl;
    }
    cout << "Sum: " << sum << endl;
    cout << "Average: " << average << endl;
    cout << "Largest: " << largest << endl;
    cout << "Smallest: " << smallest << endl;  

    return 0;
}