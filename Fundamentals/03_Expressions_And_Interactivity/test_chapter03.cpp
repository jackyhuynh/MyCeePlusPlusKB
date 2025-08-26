#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cassert>
#include <sstream>

void testMathematicalExpressions() {
    std::cout << "Test 1: Mathematical Expressions" << std::endl;
    
    int a = 10, b = 3, c = 2;
    
    int result1 = a + b * c;
    assert(result1 == 16);
    
    int result2 = (a + b) * c;
    assert(result2 == 26);
    
    double x = 5.5, y = 2.0;
    double result3 = x / y + 1;
    assert(result3 == 3.75);
    
    std::cout << "10 + 3 * 2 = " << result1 << std::endl;
    std::cout << "(10 + 3) * 2 = " << result2 << std::endl;
    std::cout << "5.5 / 2.0 + 1 = " << result3 << std::endl;
    std::cout << "✓ Test passed: Mathematical expressions work correctly\n" << std::endl;
}

void testTypeCasting() {
    std::cout << "Test 2: Type Casting" << std::endl;
    
    int intVal = 10;
    double doubleVal = static_cast<double>(intVal) / 3;
    assert(doubleVal > 3.33 && doubleVal < 3.34);
    
    double pi = 3.14159;
    int truncated = static_cast<int>(pi);
    assert(truncated == 3);
    
    char letter = 'A';
    int asciiValue = static_cast<int>(letter);
    assert(asciiValue == 65);
    
    std::cout << "10 / 3 (with casting) = " << doubleVal << std::endl;
    std::cout << "3.14159 truncated = " << truncated << std::endl;
    std::cout << "'A' as ASCII = " << asciiValue << std::endl;
    std::cout << "✓ Test passed: Type casting works correctly\n" << std::endl;
}

void testMathLibraryFunctions() {
    std::cout << "Test 3: Math Library Functions" << std::endl;
    
    double sqrtResult = sqrt(16.0);
    assert(sqrtResult == 4.0);
    
    double powResult = pow(2.0, 3.0);
    assert(powResult == 8.0);
    
    double absResult = abs(-5);
    assert(absResult == 5);
    
    double ceilResult = ceil(4.3);
    assert(ceilResult == 5.0);
    
    double floorResult = floor(4.7);
    assert(floorResult == 4.0);
    
    std::cout << "sqrt(16) = " << sqrtResult << std::endl;
    std::cout << "pow(2, 3) = " << powResult << std::endl;
    std::cout << "abs(-5) = " << absResult << std::endl;
    std::cout << "ceil(4.3) = " << ceilResult << std::endl;
    std::cout << "floor(4.7) = " << floorResult << std::endl;
    std::cout << "✓ Test passed: Math library functions work correctly\n" << std::endl;
}

void testFormattedOutput() {
    std::cout << "Test 4: Formatted Output" << std::endl;
    
    double price = 19.99;
    double pi = 3.14159265359;
    
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Price: $" << price << std::endl;
    
    std::cout << std::setprecision(4);
    std::cout << "Pi to 4 decimals: " << pi << std::endl;
    
    std::cout << std::setw(10) << std::right << "Right";
    std::cout << std::setw(10) << std::left << "Left" << std::endl;
    
    std::cout << "✓ Test passed: Formatted output works correctly\n" << std::endl;
}

void testInputSimulation() {
    std::cout << "Test 5: Input Simulation with cin" << std::endl;
    
    std::istringstream input("42 3.14 Hello");
    
    int intInput;
    double doubleInput;
    std::string stringInput;
    
    input >> intInput >> doubleInput >> stringInput;
    
    assert(intInput == 42);
    assert(doubleInput == 3.14);
    assert(stringInput == "Hello");
    
    std::cout << "Simulated inputs: " << intInput << ", " << doubleInput << ", " << stringInput << std::endl;
    std::cout << "✓ Test passed: Input simulation works correctly\n" << std::endl;
}

void testGetlineFunction() {
    std::cout << "Test 6: getline Function" << std::endl;
    
    std::istringstream input("John Doe\n25\n");
    std::string fullName;
    std::string ageStr;
    
    std::getline(input, fullName);
    std::getline(input, ageStr);
    
    assert(fullName == "John Doe");
    assert(ageStr == "25");
    
    std::cout << "Full name: " << fullName << std::endl;
    std::cout << "Age string: " << ageStr << std::endl;
    std::cout << "✓ Test passed: getline function works correctly\n" << std::endl;
}

void testNamedConstants() {
    std::cout << "Test 7: Named Constants" << std::endl;
    
    const double PI = 3.14159;
    const int MAX_SIZE = 100;
    const char GRADE = 'A';
    
    double circumference = 2 * PI * 5;
    
    assert(PI == 3.14159);
    assert(MAX_SIZE == 100);
    assert(GRADE == 'A');
    
    std::cout << "PI = " << PI << std::endl;
    std::cout << "MAX_SIZE = " << MAX_SIZE << std::endl;
    std::cout << "GRADE = " << GRADE << std::endl;
    std::cout << "Circumference (r=5) = " << circumference << std::endl;
    std::cout << "✓ Test passed: Named constants work correctly\n" << std::endl;
}

void testMultipleAssignments() {
    std::cout << "Test 8: Multiple and Combined Assignments" << std::endl;
    
    int x, y, z;
    x = y = z = 10;
    assert(x == 10 && y == 10 && z == 10);
    
    int a = 5;
    a += 3;
    assert(a == 8);
    
    a *= 2;
    assert(a == 16);
    
    a -= 6;
    assert(a == 10);
    
    a /= 2;
    assert(a == 5);
    
    a %= 3;
    assert(a == 2);
    
    std::cout << "x = y = z = 10: x=" << x << ", y=" << y << ", z=" << z << std::endl;
    std::cout << "Combined assignments final value: " << a << std::endl;
    std::cout << "✓ Test passed: Multiple and combined assignments work\n" << std::endl;
}

void testRandomNumberConcept() {
    std::cout << "Test 9: Random Number Concept" << std::endl;
    
    int min = 1, max = 10;
    int range = max - min + 1;
    
    int simulatedRandom = (7 % range) + min;
    
    assert(simulatedRandom >= min && simulatedRandom <= max);
    
    std::cout << "Simulated random number between " << min << " and " << max << ": " << simulatedRandom << std::endl;
    std::cout << "✓ Test passed: Random number concept demonstrated\n" << std::endl;
}

void testMixedTypeExpressions() {
    std::cout << "Test 10: Mixed Type Expressions" << std::endl;
    
    int intNum = 5;
    double doubleNum = 2.5;
    
    double result1 = intNum + doubleNum;
    assert(result1 == 7.5);
    
    double result2 = intNum / 2;
    assert(result2 == 2);
    
    double result3 = intNum / 2.0;
    assert(result3 == 2.5);
    
    std::cout << "5 + 2.5 = " << result1 << std::endl;
    std::cout << "5 / 2 = " << result2 << " (integer division)" << std::endl;
    std::cout << "5 / 2.0 = " << result3 << " (floating-point division)" << std::endl;
    std::cout << "✓ Test passed: Mixed type expressions work correctly\n" << std::endl;
}

int main() {
    std::cout << "========================================" << std::endl;
    std::cout << "Chapter 3: Expressions and Interactivity" << std::endl;
    std::cout << "Test Suite" << std::endl;
    std::cout << "========================================\n" << std::endl;
    
    testMathematicalExpressions();
    testTypeCasting();
    testMathLibraryFunctions();
    testFormattedOutput();
    testInputSimulation();
    testGetlineFunction();
    testNamedConstants();
    testMultipleAssignments();
    testRandomNumberConcept();
    testMixedTypeExpressions();
    
    std::cout << "========================================" << std::endl;
    std::cout << "All Chapter 3 tests passed successfully!" << std::endl;
    std::cout << "========================================" << std::endl;
    
    return 0;
}