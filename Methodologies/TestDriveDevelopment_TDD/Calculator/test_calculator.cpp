// complete_calculator.cpp
// A single file with everything needed - just compile and run!

#include <iostream>
#include <stdexcept>
#include <functional>
#include <cmath>
#include <string>

// ============================================================================
// CALCULATOR CLASS IMPLEMENTATION
// ============================================================================

class Calculator {
public:
    int add(int a, int b) {
        return a+b;
    }
    
    int subtract(int a, int b) {
        return a-b;
    }
    
    int multiply(int a, int b) {
        return a*b;
    }
    
    double divide(double a, double b) {
        if (b == 0.0) {
            throw std::invalid_argument("Division by zero is not allowed");
        }
        return a/b;
    }
};

// ============================================================================
// SIMPLE TEST RUNNER
// ============================================================================

class TestRunner {
private:
    int total_tests = 0;
    int passed_tests = 0;
    
public:
    void assert_equal(int expected, int actual, const std::string& test_name) {
        total_tests++;
        if (expected == actual) {
            std::cout << "✓ PASS: " << test_name << std::endl;
            passed_tests++;
        } else {
            std::cout << "✗ FAIL: " << test_name 
                      << " - Expected: " << expected 
                      << ", Got: " << actual << std::endl;
        }
    }
    
    void assert_double_equal(double expected, double actual, const std::string& test_name, double tolerance = 0.001) {
        total_tests++;
        if (std::abs(expected - actual) < tolerance) {
            std::cout << "✓ PASS: " << test_name << std::endl;
            passed_tests++;
        } else {
            std::cout << "✗ FAIL: " << test_name 
                      << " - Expected: " << expected 
                      << ", Got: " << actual << std::endl;
        }
    }
    
    void assert_throws(std::function<void()> func, const std::string& test_name) {
        total_tests++;
        try {
            func();
            std::cout << "✗ FAIL: " << test_name << " - Expected exception but none was thrown" << std::endl;
        } catch (const std::exception&) {
            std::cout << "✓ PASS: " << test_name << std::endl;
            passed_tests++;
        }
    }
    
    void print_summary() {
        std::cout << "\n=== TEST SUMMARY ===" << std::endl;
        std::cout << "Total tests: " << total_tests << std::endl;
        std::cout << "Passed: " << passed_tests << std::endl;
        std::cout << "Failed: " << (total_tests - passed_tests) << std::endl;
        
        if (passed_tests == total_tests) {
            std::cout << "🎉 ALL TESTS PASSED!" << std::endl;
        } else {
            std::cout << "❌ SOME TESTS FAILED!" << std::endl;
        }
    }
};

// ============================================================================
// YOUR ORIGINAL SIMPLE TESTS
// ============================================================================

void testCalculator() {
    std::cout << "=== ORIGINAL SIMPLE TESTS ===" << std::endl;
    Calculator calc;

    // Test addition
    if (calc.add(2, 3) != 5) {
        std::cerr << "✗ Addition test failed!" << std::endl;
    } else {
        std::cout << "✓ Addition test passed: 2 + 3 = 5" << std::endl;
    }

    // Test subtraction
    if (calc.subtract(5, 3) != 2) {
        std::cerr << "✗ Subtraction test failed!" << std::endl;
    } else {
        std::cout << "✓ Subtraction test passed: 5 - 3 = 2" << std::endl;
    }

    // Test multiplication
    if (calc.multiply(4, 3) != 12) {
        std::cerr << "✗ Multiplication test failed!" << std::endl;
    } else {
        std::cout << "✓ Multiplication test passed: 4 * 3 = 12" << std::endl;
    }

    // Test division
    if (calc.divide(10, 2) != 5.0) {
        std::cerr << "✗ Division test failed!" << std::endl;
    } else {
        std::cout << "✓ Division test passed: 10 / 2 = 5" << std::endl;
    }

    // Test division by zero
    try {
        calc.divide(10, 0);
        std::cerr << "✗ Division by zero test failed!" << std::endl;
    } catch (const std::invalid_argument&) {
        std::cout << "✓ Division by zero test passed: Exception caught" << std::endl;
    }
    
    std::cout << "Original tests completed.\n" << std::endl;
}

// ============================================================================
// IMPROVED TESTS WITH BETTER REPORTING
// ============================================================================

void testCalculatorImproved() {
    TestRunner runner;
    Calculator calc;
    
    std::cout << "=== IMPROVED CALCULATOR TESTS ===" << std::endl;
    
    // Test addition - multiple cases
    runner.assert_equal(5, calc.add(2, 3), "Add positive numbers");
    runner.assert_equal(0, calc.add(-2, 2), "Add positive and negative");
    runner.assert_equal(-5, calc.add(-2, -3), "Add negative numbers");
    runner.assert_equal(0, calc.add(0, 0), "Add zeros");
    
    // Test subtraction  
    runner.assert_equal(2, calc.subtract(5, 3), "Subtract basic case");
    runner.assert_equal(-2, calc.subtract(3, 5), "Subtract larger from smaller");
    runner.assert_equal(0, calc.subtract(5, 5), "Subtract equal numbers");
    
    // Test multiplication
    runner.assert_equal(12, calc.multiply(4, 3), "Multiply positive numbers");
    runner.assert_equal(-6, calc.multiply(-2, 3), "Multiply negative and positive");
    runner.assert_equal(6, calc.multiply(-2, -3), "Multiply negative numbers");
    runner.assert_equal(0, calc.multiply(0, 5), "Multiply by zero");
    
    // Test division - using double comparison
    runner.assert_double_equal(5.0, calc.divide(10.0, 2.0), "Divide evenly");
    runner.assert_double_equal(2.5, calc.divide(5.0, 2.0), "Divide with decimal result");
    runner.assert_double_equal(-2.5, calc.divide(-5.0, 2.0), "Divide negative number");
    
    // Test division by zero
    runner.assert_throws([&calc]() { calc.divide(10.0, 0.0); }, "Division by zero throws exception");
    
    runner.print_summary();
}

// ============================================================================
// INTERACTIVE CALCULATOR DEMO
// ============================================================================

void interactive_demo() {
    std::cout << "\n=== INTERACTIVE CALCULATOR DEMO ===" << std::endl;
    Calculator calc;
    
    std::cout << "Demonstrating calculator operations:" << std::endl;
    std::cout << "2 + 3 = " << calc.add(2, 3) << std::endl;
    std::cout << "10 - 4 = " << calc.subtract(10, 4) << std::endl;
    std::cout << "6 * 7 = " << calc.multiply(6, 7) << std::endl;
    std::cout << "15.0 / 3.0 = " << calc.divide(15.0, 3.0) << std::endl;
    std::cout << "7.0 / 2.0 = " << calc.divide(7.0, 2.0) << std::endl;
    
    std::cout << "\nTrying division by zero:" << std::endl;
    try {
        double result = calc.divide(5.0, 0.0);
        std::cout << "Result: " << result << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
}

// ============================================================================
// MAIN FUNCTION - RUNS ALL TESTS
// ============================================================================

int main() {
    std::cout << "🧮 CALCULATOR TDD DEMONSTRATION\n" << std::endl;
    
    // Run your original simple tests
    testCalculator();
    
    // Run improved tests with better reporting
    testCalculatorImproved();
    
    // Show interactive demo
    interactive_demo();
    
    std::cout << "\n✨ TDD Demo completed successfully!" << std::endl;
    std::cout << "\nThis demonstrates the TDD cycle:" << std::endl;
    std::cout << "1. 🔴 RED: Write failing tests first" << std::endl;
    std::cout << "2. 🟢 GREEN: Write minimal code to pass tests" << std::endl;
    std::cout << "3. 🔄 REFACTOR: Improve code while keeping tests green" << std::endl;
    
    return 0;
}

// ============================================================================
// COMPILATION INSTRUCTIONS
// ============================================================================

/*
COMPILE AND RUN:

1. Save this code as "complete_calculator.cpp"
2. Compile: g++ -std=c++17 complete_calculator.cpp -o calculator
3. Run: ./calculator

EXPECTED OUTPUT:
🧮 CALCULATOR TDD DEMONSTRATION

=== ORIGINAL SIMPLE TESTS ===
✓ Addition test passed: 2 + 3 = 5
✓ Subtraction test passed: 5 - 3 = 2
✓ Multiplication test passed: 4 * 3 = 12
✓ Division test passed: 10 / 2 = 5
✓ Division by zero test passed: Exception caught
Original tests completed.

=== IMPROVED CALCULATOR TESTS ===
✓ PASS: Add positive numbers
✓ PASS: Add positive and negative
... (more tests)

=== TEST SUMMARY ===
Total tests: 15
Passed: 15
Failed: 0
🎉 ALL TESTS PASSED!

=== INTERACTIVE CALCULATOR DEMO ===
Demonstrating calculator operations:
2 + 3 = 5
10 - 4 = 6
6 * 7 = 42
15.0 / 3.0 = 5
7.0 / 2.0 = 3.5

Trying division by zero:
Caught exception: Division by zero is not allowed

✨ TDD Demo completed successfully!
*/