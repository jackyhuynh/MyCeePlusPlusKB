#include <iostream>
#include <vector>
#include <array>
#include <cassert>
#include <algorithm>
#include <numeric>

void testArrayBasics() {
    std::cout << "Test 1: Array Declaration and Initialization" << std::endl;
    
    int numbers[5] = {10, 20, 30, 40, 50};
    
    assert(numbers[0] == 10);
    assert(numbers[4] == 50);
    
    numbers[2] = 35;
    assert(numbers[2] == 35);
    
    std::cout << "Array elements: ";
    for (int i = 0; i < 5; i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "✓ Test passed: Array basics work correctly\n" << std::endl;
}

void testArrayIteration() {
    std::cout << "Test 2: Array Iteration" << std::endl;
    
    int data[6] = {1, 2, 3, 4, 5, 6};
    int sum = 0;
    
    for (int i = 0; i < 6; i++) {
        sum += data[i];
    }
    assert(sum == 21);
    
    int sum2 = 0;
    for (int value : data) {
        sum2 += value;
    }
    assert(sum2 == 21);
    
    std::cout << "Sum using index loop: " << sum << std::endl;
    std::cout << "Sum using range-based loop: " << sum2 << std::endl;
    
    std::cout << "✓ Test passed: Array iteration works correctly\n" << std::endl;
}

void testArrayFunctions() {
    std::cout << "Test 3: Arrays and Functions" << std::endl;
    
    auto findMax = [](int arr[], int size) {
        int max = arr[0];
        for (int i = 1; i < size; i++) {
            if (arr[i] > max) max = arr[i];
        }
        return max;
    };
    
    auto modifyArray = [](int arr[], int size) {
        for (int i = 0; i < size; i++) {
            arr[i] *= 2;
        }
    };
    
    int numbers[5] = {15, 3, 42, 7, 28};
    
    int max = findMax(numbers, 5);
    assert(max == 42);
    
    modifyArray(numbers, 5);
    assert(numbers[0] == 30);
    assert(numbers[2] == 84);
    
    std::cout << "Original max: " << max << std::endl;
    std::cout << "Modified first element: " << numbers[0] << std::endl;
    
    std::cout << "✓ Test passed: Array functions work correctly\n" << std::endl;
}

void testMultidimensionalArrays() {
    std::cout << "Test 4: Multidimensional Arrays" << std::endl;
    
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    assert(matrix[1][1] == 5);
    assert(matrix[2][0] == 7);
    
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            sum += matrix[i][j];
        }
    }
    assert(sum == 45);
    
    std::cout << "Matrix sum: " << sum << std::endl;
    std::cout << "Center element: " << matrix[1][1] << std::endl;
    
    std::cout << "✓ Test passed: Multidimensional arrays work correctly\n" << std::endl;
}

void testCharArraysStrings() {
    std::cout << "Test 5: Character Arrays and Strings" << std::endl;
    
    char name[20] = "Hello";
    char greeting[] = "World!";
    
    assert(name[0] == 'H');
    assert(greeting[5] == '!');
    
    int len = 0;
    for (int i = 0; name[i] != '\0'; i++) {
        len++;
    }
    assert(len == 5);
    
    name[5] = ' ';
    name[6] = '\0';
    
    std::cout << "Name length: " << len << std::endl;
    std::cout << "Name: '" << name << "'" << std::endl;
    std::cout << "Greeting: '" << greeting << "'" << std::endl;
    
    std::cout << "✓ Test passed: Character arrays work correctly\n" << std::endl;
}

void testVectorBasics() {
    std::cout << "Test 6: Vector Basics" << std::endl;
    
    std::vector<int> numbers = {10, 20, 30, 40, 50};
    
    assert(numbers.size() == 5);
    assert(numbers[0] == 10);
    assert(numbers.at(4) == 50);
    
    numbers.push_back(60);
    assert(numbers.size() == 6);
    assert(numbers.back() == 60);
    
    numbers.pop_back();
    assert(numbers.size() == 5);
    
    std::cout << "Vector size: " << numbers.size() << std::endl;
    std::cout << "Last element: " << numbers.back() << std::endl;
    
    std::cout << "✓ Test passed: Vector basics work correctly\n" << std::endl;
}

void testVectorMethods() {
    std::cout << "Test 7: Vector Methods" << std::endl;
    
    std::vector<int> vec;
    
    assert(vec.empty() == true);
    
    for (int i = 1; i <= 5; i++) {
        vec.push_back(i * 10);
    }
    
    assert(vec.empty() == false);
    assert(vec.front() == 10);
    assert(vec.back() == 50);
    
    vec.insert(vec.begin() + 2, 25);
    assert(vec[2] == 25);
    assert(vec.size() == 6);
    
    vec.erase(vec.begin());
    assert(vec[0] == 20);
    assert(vec.size() == 5);
    
    std::cout << "Vector after operations: ";
    for (int val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    
    std::cout << "✓ Test passed: Vector methods work correctly\n" << std::endl;
}

void testArrayClass() {
    std::cout << "Test 8: std::array Class" << std::endl;
    
    std::array<int, 5> arr = {1, 2, 3, 4, 5};
    
    assert(arr.size() == 5);
    assert(arr[0] == 1);
    assert(arr.at(4) == 5);
    
    arr.fill(0);
    for (int val : arr) {
        assert(val == 0);
    }
    
    arr = {10, 20, 30, 40, 50};
    int sum = std::accumulate(arr.begin(), arr.end(), 0);
    assert(sum == 150);
    
    std::cout << "Array sum: " << sum << std::endl;
    std::cout << "✓ Test passed: std::array works correctly\n" << std::endl;
}

void testArrayAlgorithms() {
    std::cout << "Test 9: Array Algorithms" << std::endl;
    
    std::vector<int> numbers = {5, 2, 8, 1, 9, 3};
    
    std::sort(numbers.begin(), numbers.end());
    assert(numbers[0] == 1);
    assert(numbers[5] == 9);
    
    auto it = std::find(numbers.begin(), numbers.end(), 5);
    assert(it != numbers.end());
    assert(*it == 5);
    
    int count = std::count_if(numbers.begin(), numbers.end(), 
                              [](int x) { return x > 5; });
    assert(count == 2);
    
    std::cout << "Sorted numbers: ";
    for (int val : numbers) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    std::cout << "Numbers > 5: " << count << std::endl;
    
    std::cout << "✓ Test passed: Array algorithms work correctly\n" << std::endl;
}

void testArrayBoundsChecking() {
    std::cout << "Test 10: Array Bounds and Safety" << std::endl;
    
    std::vector<int> vec = {1, 2, 3, 4, 5};
    
    assert(vec.size() == 5);
    
    try {
        int val = vec.at(10);
        assert(false);
    } catch (const std::out_of_range& e) {
        std::cout << "Caught expected out_of_range exception" << std::endl;
    }
    
    auto safeAccess = [&vec](size_t index) -> int {
        return (index < vec.size()) ? vec[index] : -1;
    };
    
    assert(safeAccess(2) == 3);
    assert(safeAccess(10) == -1);
    
    std::cout << "Safe access result: " << safeAccess(2) << std::endl;
    std::cout << "✓ Test passed: Bounds checking works correctly\n" << std::endl;
}

int main() {
    std::cout << "========================================" << std::endl;
    std::cout << "Chapter 8: Arrays and Vectors" << std::endl;
    std::cout << "Test Suite" << std::endl;
    std::cout << "========================================\n" << std::endl;
    
    testArrayBasics();
    testArrayIteration();
    testArrayFunctions();
    testMultidimensionalArrays();
    testCharArraysStrings();
    testVectorBasics();
    testVectorMethods();
    testArrayClass();
    testArrayAlgorithms();
    testArrayBoundsChecking();
    
    std::cout << "========================================" << std::endl;
    std::cout << "All Chapter 8 tests passed successfully!" << std::endl;
    std::cout << "========================================" << std::endl;
    
    return 0;
}