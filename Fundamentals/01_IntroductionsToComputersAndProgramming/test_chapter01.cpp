#include <iostream>
#include <string>
#include <cassert>
#include <sstream>

void testHelloWorld() {
    std::cout << "Test 1: Hello World output" << std::endl;
    std::cout << "Hello, World!" << std::endl;
    std::cout << "✓ Test passed: Hello World displayed correctly\n" << std::endl;
}

void testVariables() {
    std::cout << "Test 2: Variable Declaration and Assignment" << std::endl;
    
    int num1 = 5;
    int num2 = 12;
    int sum = num1 + num2;
    
    assert(sum == 17);
    std::cout << "num1 = " << num1 << ", num2 = " << num2 << std::endl;
    std::cout << "Sum = " << sum << std::endl;
    std::cout << "✓ Test passed: Variables and arithmetic work correctly\n" << std::endl;
}

void testDataTypes() {
    std::cout << "Test 3: Basic Data Types" << std::endl;
    
    int integerVar = 42;
    double doubleVar = 3.14159;
    char charVar = 'A';
    bool boolVar = true;
    
    assert(integerVar == 42);
    assert(doubleVar > 3.14 && doubleVar < 3.15);
    assert(charVar == 'A');
    assert(boolVar == true);
    
    std::cout << "Integer: " << integerVar << std::endl;
    std::cout << "Double: " << doubleVar << std::endl;
    std::cout << "Character: " << charVar << std::endl;
    std::cout << "Boolean: " << (boolVar ? "true" : "false") << std::endl;
    std::cout << "✓ Test passed: All data types work correctly\n" << std::endl;
}

void testArithmeticOperators() {
    std::cout << "Test 4: Arithmetic Operators" << std::endl;
    
    int a = 10, b = 3;
    
    int addition = a + b;
    int subtraction = a - b;
    int multiplication = a * b;
    int division = a / b;
    int modulus = a % b;
    
    assert(addition == 13);
    assert(subtraction == 7);
    assert(multiplication == 30);
    assert(division == 3);
    assert(modulus == 1);
    
    std::cout << a << " + " << b << " = " << addition << std::endl;
    std::cout << a << " - " << b << " = " << subtraction << std::endl;
    std::cout << a << " * " << b << " = " << multiplication << std::endl;
    std::cout << a << " / " << b << " = " << division << std::endl;
    std::cout << a << " % " << b << " = " << modulus << std::endl;
    std::cout << "✓ Test passed: Arithmetic operators work correctly\n" << std::endl;
}

void testInputOutputConcept() {
    std::cout << "Test 5: Input/Output Concept Demonstration" << std::endl;
    
    std::string simulatedInput = "TestUser";
    std::cout << "Simulating user input: " << simulatedInput << std::endl;
    
    std::string name = simulatedInput;
    std::string greeting = "Hello, " + name + "!";
    
    std::cout << greeting << std::endl;
    assert(greeting == "Hello, TestUser!");
    std::cout << "✓ Test passed: I/O concept demonstrated\n" << std::endl;
}

void testProgramElements() {
    std::cout << "Test 6: Program Elements" << std::endl;
    
    const int CONSTANT_VALUE = 100;
    int variable = 50;
    
    variable = variable * 2;
    
    assert(CONSTANT_VALUE == 100);
    assert(variable == 100);
    
    std::cout << "Constant value: " << CONSTANT_VALUE << std::endl;
    std::cout << "Variable after operation: " << variable << std::endl;
    std::cout << "✓ Test passed: Program elements work correctly\n" << std::endl;
}

int main() {
    std::cout << "========================================" << std::endl;
    std::cout << "Chapter 1: Introduction to Computers and Programming" << std::endl;
    std::cout << "Test Suite" << std::endl;
    std::cout << "========================================\n" << std::endl;
    
    testHelloWorld();
    testVariables();
    testDataTypes();
    testArithmeticOperators();
    testInputOutputConcept();
    testProgramElements();
    
    std::cout << "========================================" << std::endl;
    std::cout << "All Chapter 1 tests passed successfully!" << std::endl;
    std::cout << "========================================" << std::endl;
    
    return 0;
}