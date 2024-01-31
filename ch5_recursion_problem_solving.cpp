#include <iostream>
#include <vector>
#include <string>
using namespace std;

class RecursiveAlgorithms {
public:
    // 1. Factorial of a Number
    // Calculate the factorial of a number n (n!), which is the product of all positive integers less than or equal to n.
    static int factorial(int n) {
        cout << n << ", " ;
        if (n <= 1) return 1; // base case
        return n * factorial(n - 1); // recursive case
    }

    // 2. Fibonacci Sequence
    // Find the nth number in the Fibonacci sequence, where each number is the sum of the two preceding ones.
    static int fibonacci(int n) {
        cout << n << ", " ;
        if (n <= 1)
        {
            cout << endl;
            return n;
        }
        return fibonacci(n-1) + fibonacci(n-2); 
    }

    // 3. Sum of Natural Numbers
    // Calculate the sum of the first n natural numbers.
    static int sumOfNaturalNumbers(int n) {
        cout << n << ", ";
        if (n == 0)
        {
            cout << endl;
            return 0; 
        } 
        return n + sumOfNaturalNumbers(n - 1);
    }

    // 4. Power of a Number
    // Calculate x raised to the power y.
    static int power(int x, int y) {
        cout << "; x: " << x << " and y: " << y;
        if (y == 0) 
        {
            cout << endl;
            return 1;
        }
        return x * power(x, y - 1);
    }

    // 5. Greatest Common Divisor (GCD)
    // Find the GCD of two numbers using Euclid's algorithm
    static int gcd(int a, int b) {
        cout << "a: " << a << ", b: " << b;
        if (b == 0) 
        {
            cout << endl;
            return a; 
        }
        return gcd(b, a % b);
    }

    // 6. Reverse a String
    // Reverse a given string s.
    static void reverseString(string& s, int start, int end) {
        if (start >= end) return;
        swap(s[start], s[end]);
        reverseString(s, start + 1, end - 1);
    }

    // 7. Check Palindrome
    // Check if a string s is a palindrome.
    static bool isPalindrome(const string& s, int start, int end) {
        if (start >= end) return true;
        if (s[start] != s[end]) return false;
        return isPalindrome(s, start + 1, end - 1);
    }

    // 8. Tower of Hanoi
    // Solve the Tower of Hanoi puzzle with n disks.
    static void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) {
        if (n == 0) return;
        towerOfHanoi(n-1, from_rod, aux_rod, to_rod);
        cout << "Move disk " << n << " from rod " << from_rod << " to rod " << to_rod << endl;
        towerOfHanoi(n-1, aux_rod, to_rod, from_rod);
    }

    // 9. Binary Search
    // Perform binary search on a sorted array.
    static int binarySearch(const vector<int>& arr, int l, int r, int x) {
        if (r >= l) {
            int mid = l + (r - l) / 2;
            if (arr[mid] == x) return mid;
            if (arr[mid] > x) return binarySearch(arr, l, mid - 1, x);
            return binarySearch(arr, mid + 1, r, x);
        }
        return -1;
    }
};

int main() {
    // Demonstrating the factorial function 
    cout << "Factorial of 5: " << endl;
    cout << RecursiveAlgorithms::factorial(5) << endl;

    // Demonstrating the Fibonacci function
    cout << "Fibonacci of 5: " << endl;
    cout << RecursiveAlgorithms::fibonacci(5) << endl;

    // Demonstrating the sum of natural numbers
    cout << "Sum of first 5 natural numbers: " << endl;
    cout << endl << RecursiveAlgorithms::sumOfNaturalNumbers(5) << endl;

    // Demonstrating power calculation
    cout << "2 raised to the power 3: " << endl;
    cout << RecursiveAlgorithms::power(2, 3) << endl;

    // Demonstrating GCD (Greatest Common Divisor) calculation
    cout << "GCD of 48 and 18: " << endl;
    cout << RecursiveAlgorithms::gcd(48, 18) << endl;

    // Demonstrating string reversal
    string str = "hello";
    RecursiveAlgorithms::reverseString(str, 0, str.length() - 1);
    cout << "Reversed string: " << str << endl;

    // Checking if a string is a palindrome
    string palindrome = "radar";
    cout << "Is 'radar' a palindrome? " << RecursiveAlgorithms::isPalindrome(palindrome, 0, palindrome.length() - 1) << endl;

    // Demonstrating the Tower of Hanoi puzzle solution
    cout << "Tower of Hanoi for 3 disks: " << endl;
    RecursiveAlgorithms::towerOfHanoi(3, 'A', 'C', 'B');

    // Demonstrating Binary Search in a sorted array
    vector<int> searchArr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int x = 7;
    int result = RecursiveAlgorithms::binarySearch(searchArr, 0, searchArr.size() - 1, x);
    cout << "Element " << x << " is at index: " << result << endl;

    return 0;
}
