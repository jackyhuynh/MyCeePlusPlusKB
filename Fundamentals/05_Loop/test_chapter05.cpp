#include <iostream>
#include <cassert>
#include <sstream>
#include <fstream>
#include <string>

void testWhileLoop() {
    std::cout << "Test 1: while Loop" << std::endl;
    
    int counter = 1;
    int sum = 0;
    
    while (counter <= 5) {
        sum += counter;
        counter++;
    }
    
    assert(sum == 15);
    assert(counter == 6);
    
    std::cout << "Sum of 1 to 5 using while loop: " << sum << std::endl;
    
    int factorial = 1;
    int n = 5;
    int i = 1;
    
    while (i <= n) {
        factorial *= i;
        i++;
    }
    
    assert(factorial == 120);
    std::cout << "5! = " << factorial << std::endl;
    
    std::cout << "✓ Test passed: while loop works correctly\n" << std::endl;
}

void testDoWhileLoop() {
    std::cout << "Test 2: do-while Loop" << std::endl;
    
    int num = 1;
    int sum = 0;
    
    do {
        sum += num;
        num++;
    } while (num <= 5);
    
    assert(sum == 15);
    std::cout << "Sum of 1 to 5 using do-while: " << sum << std::endl;
    
    int x = 10;
    bool executedOnce = false;
    
    do {
        executedOnce = true;
    } while (x < 5);
    
    assert(executedOnce == true);
    std::cout << "do-while executes at least once: " << (executedOnce ? "Yes" : "No") << std::endl;
    
    std::cout << "✓ Test passed: do-while loop works correctly\n" << std::endl;
}

void testForLoop() {
    std::cout << "Test 3: for Loop" << std::endl;
    
    int sum = 0;
    for (int i = 1; i <= 10; i++) {
        sum += i;
    }
    
    assert(sum == 55);
    std::cout << "Sum of 1 to 10 using for loop: " << sum << std::endl;
    
    int product = 1;
    for (int j = 1; j <= 5; j++) {
        product *= j;
    }
    
    assert(product == 120);
    std::cout << "5! using for loop: " << product << std::endl;
    
    std::cout << "✓ Test passed: for loop works correctly\n" << std::endl;
}

void testIncrementDecrementOperators() {
    std::cout << "Test 4: Increment and Decrement Operators" << std::endl;
    
    int a = 5;
    int b = ++a;
    assert(a == 6 && b == 6);
    std::cout << "Prefix ++: a = " << a << ", b = " << b << std::endl;
    
    int c = 5;
    int d = c++;
    assert(c == 6 && d == 5);
    std::cout << "Postfix ++: c = " << c << ", d = " << d << std::endl;
    
    int e = 10;
    int f = --e;
    assert(e == 9 && f == 9);
    std::cout << "Prefix --: e = " << e << ", f = " << f << std::endl;
    
    int g = 10;
    int h = g--;
    assert(g == 9 && h == 10);
    std::cout << "Postfix --: g = " << g << ", h = " << h << std::endl;
    
    std::cout << "✓ Test passed: Increment/decrement operators work correctly\n" << std::endl;
}

void testNestedLoops() {
    std::cout << "Test 5: Nested Loops" << std::endl;
    
    int rows = 3, cols = 4;
    int count = 0;
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            count++;
        }
    }
    
    assert(count == 12);
    std::cout << "Nested loop iterations (3x4): " << count << std::endl;
    
    std::cout << "Multiplication table (3x3):" << std::endl;
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            std::cout << i * j << "\t";
        }
        std::cout << std::endl;
    }
    
    std::cout << "✓ Test passed: Nested loops work correctly\n" << std::endl;
}

void testRunningTotal() {
    std::cout << "Test 6: Running Total (Accumulator)" << std::endl;
    
    int numbers[] = {10, 20, 30, 40, 50};
    int total = 0;
    
    for (int i = 0; i < 5; i++) {
        total += numbers[i];
    }
    
    assert(total == 150);
    std::cout << "Sum of array elements: " << total << std::endl;
    
    double average = total / 5.0;
    assert(average == 30.0);
    std::cout << "Average: " << average << std::endl;
    
    std::cout << "✓ Test passed: Running total works correctly\n" << std::endl;
}

void testCounter() {
    std::cout << "Test 7: Counter Variable" << std::endl;
    
    int countEvens = 0;
    int countOdds = 0;
    
    for (int i = 1; i <= 10; i++) {
        if (i % 2 == 0) {
            countEvens++;
        } else {
            countOdds++;
        }
    }
    
    assert(countEvens == 5);
    assert(countOdds == 5);
    
    std::cout << "Even numbers (1-10): " << countEvens << std::endl;
    std::cout << "Odd numbers (1-10): " << countOdds << std::endl;
    
    std::cout << "✓ Test passed: Counter variables work correctly\n" << std::endl;
}

void testSentinel() {
    std::cout << "Test 8: Sentinel Value" << std::endl;
    
    std::istringstream input("10 20 30 -1");
    int value;
    int sum = 0;
    int count = 0;
    const int SENTINEL = -1;
    
    while (input >> value && value != SENTINEL) {
        sum += value;
        count++;
    }
    
    assert(sum == 60);
    assert(count == 3);
    
    std::cout << "Sum until sentinel (-1): " << sum << std::endl;
    std::cout << "Count: " << count << std::endl;
    
    std::cout << "✓ Test passed: Sentinel value works correctly\n" << std::endl;
}

void testBreakContinue() {
    std::cout << "Test 9: break and continue Statements" << std::endl;
    
    int sumBeforeBreak = 0;
    for (int i = 1; i <= 10; i++) {
        if (i > 5) {
            break;
        }
        sumBeforeBreak += i;
    }
    
    assert(sumBeforeBreak == 15);
    std::cout << "Sum with break at i>5: " << sumBeforeBreak << std::endl;
    
    int sumWithContinue = 0;
    for (int i = 1; i <= 10; i++) {
        if (i % 2 == 0) {
            continue;
        }
        sumWithContinue += i;
    }
    
    assert(sumWithContinue == 25);
    std::cout << "Sum of odd numbers (using continue): " << sumWithContinue << std::endl;
    
    std::cout << "✓ Test passed: break and continue work correctly\n" << std::endl;
}

void testInputValidationLoop() {
    std::cout << "Test 10: Input Validation with Loop" << std::endl;
    
    std::istringstream input("-5 -10 25");
    int userInput;
    
    input >> userInput;
    while (userInput < 0) {
        std::cout << "Invalid input: " << userInput << " (negative)" << std::endl;
        input >> userInput;
    }
    
    assert(userInput == 25);
    std::cout << "Valid input received: " << userInput << std::endl;
    
    std::cout << "✓ Test passed: Input validation loop works correctly\n" << std::endl;
}

void testFileOperations() {
    std::cout << "Test 11: File Operations with Loops" << std::endl;
    
    std::ofstream outFile("test_numbers.txt");
    for (int i = 1; i <= 5; i++) {
        outFile << i * 10 << std::endl;
    }
    outFile.close();
    
    std::ifstream inFile("test_numbers.txt");
    int value, sum = 0, count = 0;
    
    while (inFile >> value) {
        sum += value;
        count++;
    }
    inFile.close();
    
    assert(sum == 150);
    assert(count == 5);
    
    std::cout << "File sum: " << sum << ", Count: " << count << std::endl;
    
    std::remove("test_numbers.txt");
    
    std::cout << "✓ Test passed: File operations with loops work correctly\n" << std::endl;
}

int main() {
    std::cout << "========================================" << std::endl;
    std::cout << "Chapter 5: Loops" << std::endl;
    std::cout << "Test Suite" << std::endl;
    std::cout << "========================================\n" << std::endl;
    
    testWhileLoop();
    testDoWhileLoop();
    testForLoop();
    testIncrementDecrementOperators();
    testNestedLoops();
    testRunningTotal();
    testCounter();
    testSentinel();
    testBreakContinue();
    testInputValidationLoop();
    testFileOperations();
    
    std::cout << "========================================" << std::endl;
    std::cout << "All Chapter 5 tests passed successfully!" << std::endl;
    std::cout << "========================================" << std::endl;
    
    return 0;
}