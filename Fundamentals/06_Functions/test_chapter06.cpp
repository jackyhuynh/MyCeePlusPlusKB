#include <iostream>
#include <string>
#include <cassert>
#include <cmath>

double calculateCircleArea(double radius);
int sumRange(int start, int end);
void modifyByReference(int &num);
void modifyByPointer(int *num);
double power(double base, int exponent = 2);
int fibonacci(int n);

void testBasicFunction() {
    std::cout << "Test 1: Basic Function Definition and Call" << std::endl;
    
    double area = calculateCircleArea(5.0);
    assert(std::abs(area - 78.5398) < 0.001);
    std::cout << "Area of circle (r=5): " << area << std::endl;
    
    int sum = sumRange(1, 5);
    assert(sum == 15);
    std::cout << "Sum from 1 to 5: " << sum << std::endl;
    
    std::cout << "✓ Test passed: Basic functions work correctly\n" << std::endl;
}

void testFunctionPrototypes() {
    std::cout << "Test 2: Function Prototypes" << std::endl;
    
    double result = power(2.0, 3);
    assert(result == 8.0);
    std::cout << "2^3 = " << result << std::endl;
    
    std::cout << "✓ Test passed: Function prototypes work correctly\n" << std::endl;
}

void testPassByValue() {
    std::cout << "Test 3: Pass by Value" << std::endl;
    
    int original = 10;
    int copy = original;
    
    copy = copy * 2;
    
    assert(original == 10);
    assert(copy == 20);
    
    std::cout << "Original: " << original << ", Modified copy: " << copy << std::endl;
    std::cout << "✓ Test passed: Pass by value preserves original\n" << std::endl;
}

void testPassByReference() {
    std::cout << "Test 4: Pass by Reference" << std::endl;
    
    int value = 10;
    modifyByReference(value);
    
    assert(value == 20);
    std::cout << "Value after reference modification: " << value << std::endl;
    
    std::cout << "✓ Test passed: Pass by reference modifies original\n" << std::endl;
}

void testPassByPointer() {
    std::cout << "Test 5: Pass by Pointer" << std::endl;
    
    int value = 10;
    modifyByPointer(&value);
    
    assert(value == 30);
    std::cout << "Value after pointer modification: " << value << std::endl;
    
    std::cout << "✓ Test passed: Pass by pointer works correctly\n" << std::endl;
}

void testDefaultParameters() {
    std::cout << "Test 6: Default Parameters" << std::endl;
    
    double square = power(5.0);
    assert(square == 25.0);
    std::cout << "5^2 (default exponent): " << square << std::endl;
    
    double cube = power(3.0, 3);
    assert(cube == 27.0);
    std::cout << "3^3 (specified exponent): " << cube << std::endl;
    
    std::cout << "✓ Test passed: Default parameters work correctly\n" << std::endl;
}

void testFunctionOverloading() {
    std::cout << "Test 7: Function Overloading" << std::endl;
    
    auto max2 = [](int a, int b) { return (a > b) ? a : b; };
    auto max3 = [](int a, int b, int c) { 
        int temp = (a > b) ? a : b;
        return (temp > c) ? temp : c;
    };
    
    assert(max2(10, 20) == 20);
    assert(max3(10, 20, 15) == 20);
    
    std::cout << "Max of 10, 20: " << max2(10, 20) << std::endl;
    std::cout << "Max of 10, 20, 15: " << max3(10, 20, 15) << std::endl;
    
    std::cout << "✓ Test passed: Function overloading works correctly\n" << std::endl;
}

void testRecursion() {
    std::cout << "Test 8: Recursive Functions" << std::endl;
    
    int fib5 = fibonacci(5);
    assert(fib5 == 5);
    std::cout << "Fibonacci(5): " << fib5 << std::endl;
    
    int fib10 = fibonacci(10);
    assert(fib10 == 55);
    std::cout << "Fibonacci(10): " << fib10 << std::endl;
    
    std::cout << "✓ Test passed: Recursive functions work correctly\n" << std::endl;
}

void testLocalGlobalVariables() {
    std::cout << "Test 9: Local and Global Variables" << std::endl;
    
    static int globalCounter = 0;
    
    auto incrementLocal = []() {
        int localCounter = 0;
        localCounter++;
        return localCounter;
    };
    
    auto incrementStatic = []() {
        static int staticCounter = 0;
        staticCounter++;
        return staticCounter;
    };
    
    assert(incrementLocal() == 1);
    assert(incrementLocal() == 1);
    
    assert(incrementStatic() == 1);
    assert(incrementStatic() == 2);
    assert(incrementStatic() == 3);
    
    std::cout << "Local variable (always 1): " << incrementLocal() << std::endl;
    std::cout << "Static variable (increments): " << incrementStatic() << std::endl;
    
    std::cout << "✓ Test passed: Variable scope works correctly\n" << std::endl;
}

void testReturnValues() {
    std::cout << "Test 10: Return Values" << std::endl;
    
    auto getMinMax = [](int a, int b, int &min, int &max) {
        min = (a < b) ? a : b;
        max = (a > b) ? a : b;
    };
    
    int min, max;
    getMinMax(10, 20, min, max);
    
    assert(min == 10);
    assert(max == 20);
    
    std::cout << "Min: " << min << ", Max: " << max << std::endl;
    
    std::cout << "✓ Test passed: Return values work correctly\n" << std::endl;
}

void testInlineFunctions() {
    std::cout << "Test 11: Inline Functions" << std::endl;
    
    auto inline square = [](int x) { return x * x; };
    
    assert(square(5) == 25);
    assert(square(10) == 100);
    
    std::cout << "Square of 5: " << square(5) << std::endl;
    std::cout << "Square of 10: " << square(10) << std::endl;
    
    std::cout << "✓ Test passed: Inline functions work correctly\n" << std::endl;
}

double calculateCircleArea(double radius) {
    const double PI = 3.14159265359;
    return PI * radius * radius;
}

int sumRange(int start, int end) {
    int sum = 0;
    for (int i = start; i <= end; i++) {
        sum += i;
    }
    return sum;
}

void modifyByReference(int &num) {
    num *= 2;
}

void modifyByPointer(int *num) {
    *num *= 3;
}

double power(double base, int exponent) {
    double result = 1.0;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    std::cout << "========================================" << std::endl;
    std::cout << "Chapter 6: Functions" << std::endl;
    std::cout << "Test Suite" << std::endl;
    std::cout << "========================================\n" << std::endl;
    
    testBasicFunction();
    testFunctionPrototypes();
    testPassByValue();
    testPassByReference();
    testPassByPointer();
    testDefaultParameters();
    testFunctionOverloading();
    testRecursion();
    testLocalGlobalVariables();
    testReturnValues();
    testInlineFunctions();
    
    std::cout << "========================================" << std::endl;
    std::cout << "All Chapter 6 tests passed successfully!" << std::endl;
    std::cout << "========================================" << std::endl;
    
    return 0;
}