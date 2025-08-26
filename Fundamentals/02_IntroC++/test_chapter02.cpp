#include <iostream>
#include <string>
#include <cassert>
#include <iomanip>
#include <sstream>

void testCoutObject() {
    std::cout << "Test 1: cout Object and Stream Insertion" << std::endl;
    
    std::cout << "Hello, there!" << std::endl;
    std::cout << "Line 1" << std::endl << "Line 2" << std::endl;
    
    std::cout << "✓ Test passed: cout object works correctly\n" << std::endl;
}

void testEscapeSequences() {
    std::cout << "Test 2: Escape Sequences" << std::endl;
    
    std::cout << "Tab:\tTabbed text" << std::endl;
    std::cout << "Newline:\nNext line" << std::endl;
    std::cout << "Quote: \"Hello\"" << std::endl;
    std::cout << "Backslash: \\" << std::endl;
    
    std::cout << "✓ Test passed: Escape sequences work correctly\n" << std::endl;
}

void testVariablesAndAssignment() {
    std::cout << "Test 3: Variables and Assignment" << std::endl;
    
    int age;
    age = 25;
    assert(age == 25);
    
    double price = 19.99;
    assert(price == 19.99);
    
    int x = 10, y = 20, z = 30;
    assert(x == 10 && y == 20 && z == 30);
    
    std::cout << "age = " << age << std::endl;
    std::cout << "price = " << price << std::endl;
    std::cout << "x = " << x << ", y = " << y << ", z = " << z << std::endl;
    std::cout << "✓ Test passed: Variable declaration and assignment work\n" << std::endl;
}

void testLiterals() {
    std::cout << "Test 4: Literals" << std::endl;
    
    char charLiteral = 'A';
    std::string stringLiteral = "Hello";
    int intLiteral = 12;
    double floatLiteral = 3.14;
    
    assert(charLiteral == 'A');
    assert(stringLiteral == "Hello");
    assert(intLiteral == 12);
    assert(floatLiteral == 3.14);
    
    std::cout << "Character literal: '" << charLiteral << "'" << std::endl;
    std::cout << "String literal: \"" << stringLiteral << "\"" << std::endl;
    std::cout << "Integer literal: " << intLiteral << std::endl;
    std::cout << "Floating-point literal: " << floatLiteral << std::endl;
    std::cout << "✓ Test passed: All literal types work correctly\n" << std::endl;
}

void testIntegerDataTypes() {
    std::cout << "Test 5: Integer Data Types" << std::endl;
    
    short shortNum = 32767;
    int intNum = 2147483647;
    long longNum = 2147483647L;
    
    std::cout << "short: " << shortNum << " (size: " << sizeof(short) << " bytes)" << std::endl;
    std::cout << "int: " << intNum << " (size: " << sizeof(int) << " bytes)" << std::endl;
    std::cout << "long: " << longNum << " (size: " << sizeof(long) << " bytes)" << std::endl;
    
    std::cout << "✓ Test passed: Integer data types work correctly\n" << std::endl;
}

void testFloatingPointTypes() {
    std::cout << "Test 6: Floating-Point Data Types" << std::endl;
    
    float floatNum = 3.14159f;
    double doubleNum = 3.141592653589793;
    long double longDoubleNum = 3.141592653589793238L;
    
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "float: " << floatNum << " (size: " << sizeof(float) << " bytes)" << std::endl;
    std::cout << std::setprecision(15);
    std::cout << "double: " << doubleNum << " (size: " << sizeof(double) << " bytes)" << std::endl;
    std::cout << "long double: " << longDoubleNum << " (size: " << sizeof(long double) << " bytes)" << std::endl;
    
    std::cout << "✓ Test passed: Floating-point types work correctly\n" << std::endl;
}

void testCharDataType() {
    std::cout << "Test 7: char Data Type" << std::endl;
    
    char letter = 'Z';
    char digit = '5';
    
    std::cout << "Character: " << letter << " (ASCII: " << static_cast<int>(letter) << ")" << std::endl;
    std::cout << "Digit character: " << digit << " (ASCII: " << static_cast<int>(digit) << ")" << std::endl;
    
    assert(letter == 'Z');
    assert(static_cast<int>(letter) == 90);
    
    std::cout << "✓ Test passed: char data type works correctly\n" << std::endl;
}

void testStringClass() {
    std::cout << "Test 8: string Class" << std::endl;
    
    std::string firstName = "John";
    std::string lastName = "Doe";
    std::string fullName = firstName + " " + lastName;
    
    assert(fullName == "John Doe");
    
    std::cout << "First name: " << firstName << std::endl;
    std::cout << "Last name: " << lastName << std::endl;
    std::cout << "Full name: " << fullName << std::endl;
    
    std::string empty;
    assert(empty == "");
    
    std::cout << "✓ Test passed: string class works correctly\n" << std::endl;
}

void testBoolDataType() {
    std::cout << "Test 9: bool Data Type" << std::endl;
    
    bool isTrue = true;
    bool isFalse = false;
    
    assert(isTrue == true);
    assert(isFalse == false);
    assert(isTrue == 1);
    assert(isFalse == 0);
    
    std::cout << "true value: " << isTrue << " (as bool)" << std::endl;
    std::cout << "false value: " << isFalse << " (as bool)" << std::endl;
    std::cout << std::boolalpha;
    std::cout << "true value: " << isTrue << " (with boolalpha)" << std::endl;
    std::cout << "false value: " << isFalse << " (with boolalpha)" << std::endl;
    
    std::cout << "✓ Test passed: bool data type works correctly\n" << std::endl;
}

void testArithmeticOperators() {
    std::cout << "Test 10: Arithmetic Operators" << std::endl;
    
    int a = 13, b = 5;
    
    std::cout << a << " + " << b << " = " << (a + b) << std::endl;
    std::cout << a << " - " << b << " = " << (a - b) << std::endl;
    std::cout << a << " * " << b << " = " << (a * b) << std::endl;
    std::cout << a << " / " << b << " = " << (a / b) << " (integer division)" << std::endl;
    std::cout << a << " % " << b << " = " << (a % b) << " (modulus)" << std::endl;
    
    double x = 13.0, y = 5.0;
    std::cout << x << " / " << y << " = " << (x / y) << " (floating-point division)" << std::endl;
    
    assert(a + b == 18);
    assert(a - b == 8);
    assert(a * b == 65);
    assert(a / b == 2);
    assert(a % b == 3);
    
    std::cout << "✓ Test passed: Arithmetic operators work correctly\n" << std::endl;
}

void testComments() {
    std::cout << "Test 11: Comments (Code Documentation)" << std::endl;
    
    int value = 42;
    
    value = value * 2;
    
    /* This is a multi-line comment.
       It can span multiple lines.
       The value should now be 84. */
    
    assert(value == 84);
    std::cout << "Value after operation: " << value << std::endl;
    std::cout << "✓ Test passed: Code with comments works correctly\n" << std::endl;
}

int main() {
    std::cout << "========================================" << std::endl;
    std::cout << "Chapter 2: Introduction to C++" << std::endl;
    std::cout << "Test Suite" << std::endl;
    std::cout << "========================================\n" << std::endl;
    
    testCoutObject();
    testEscapeSequences();
    testVariablesAndAssignment();
    testLiterals();
    testIntegerDataTypes();
    testFloatingPointTypes();
    testCharDataType();
    testStringClass();
    testBoolDataType();
    testArithmeticOperators();
    testComments();
    
    std::cout << "========================================" << std::endl;
    std::cout << "All Chapter 2 tests passed successfully!" << std::endl;
    std::cout << "========================================" << std::endl;
    
    return 0;
}