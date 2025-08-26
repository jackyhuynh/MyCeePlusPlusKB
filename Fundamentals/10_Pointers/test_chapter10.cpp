#include <iostream>
#include <cassert>
#include <memory>
#include <cstring>

void testPointerBasics() {
    std::cout << "Test 1: Pointer Basics" << std::endl;
    
    int value = 42;
    int* ptr = &value;
    
    assert(ptr == &value);
    assert(*ptr == 42);
    
    *ptr = 100;
    assert(value == 100);
    
    std::cout << "Value: " << value << std::endl;
    std::cout << "Address: " << ptr << std::endl;
    std::cout << "Dereferenced value: " << *ptr << std::endl;
    
    std::cout << "✓ Test passed: Pointer basics work correctly\n" << std::endl;
}

void testPointerArithmetic() {
    std::cout << "Test 2: Pointer Arithmetic" << std::endl;
    
    int arr[5] = {10, 20, 30, 40, 50};
    int* ptr = arr;
    
    assert(*ptr == 10);
    assert(*(ptr + 1) == 20);
    assert(*(ptr + 4) == 50);
    
    ptr++;
    assert(*ptr == 20);
    
    ptr += 2;
    assert(*ptr == 40);
    
    ptr--;
    assert(*ptr == 30);
    
    std::cout << "Array traversal with pointer arithmetic:" << std::endl;
    ptr = arr;
    for (int i = 0; i < 5; i++) {
        std::cout << "arr[" << i << "] = " << *(ptr + i) << std::endl;
    }
    
    std::cout << "✓ Test passed: Pointer arithmetic works correctly\n" << std::endl;
}

void testNullPointers() {
    std::cout << "Test 3: Null Pointers" << std::endl;
    
    int* nullPtr = nullptr;
    
    assert(nullPtr == nullptr);
    
    int value = 25;
    int* validPtr = &value;
    
    if (validPtr != nullptr) {
        assert(*validPtr == 25);
        std::cout << "Valid pointer value: " << *validPtr << std::endl;
    }
    
    if (nullPtr == nullptr) {
        std::cout << "Null pointer detected - safe to handle" << std::endl;
    }
    
    std::cout << "✓ Test passed: Null pointer handling works correctly\n" << std::endl;
}

void testPointersAndFunctions() {
    std::cout << "Test 4: Pointers and Functions" << std::endl;
    
    auto swapByPointer = [](int* a, int* b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    };
    
    auto modifyValue = [](int* ptr) {
        if (ptr != nullptr) {
            *ptr *= 2;
        }
    };
    
    int x = 10, y = 20;
    
    swapByPointer(&x, &y);
    assert(x == 20);
    assert(y == 10);
    
    modifyValue(&x);
    assert(x == 40);
    
    std::cout << "After swap and modify: x = " << x << ", y = " << y << std::endl;
    
    std::cout << "✓ Test passed: Pointers with functions work correctly\n" << std::endl;
}

void testDynamicMemoryAllocation() {
    std::cout << "Test 5: Dynamic Memory Allocation" << std::endl;
    
    int* dynamicInt = new int(75);
    assert(*dynamicInt == 75);
    
    *dynamicInt = 100;
    assert(*dynamicInt == 100);
    
    delete dynamicInt;
    
    int* dynamicArray = new int[5]{1, 2, 3, 4, 5};
    
    assert(dynamicArray[0] == 1);
    assert(dynamicArray[4] == 5);
    
    for (int i = 0; i < 5; i++) {
        std::cout << "dynamicArray[" << i << "] = " << dynamicArray[i] << std::endl;
    }
    
    delete[] dynamicArray;
    
    std::cout << "✓ Test passed: Dynamic memory allocation works correctly\n" << std::endl;
}

void testPointersToPointers() {
    std::cout << "Test 6: Pointers to Pointers" << std::endl;
    
    int value = 123;
    int* ptr = &value;
    int** ptrToPtr = &ptr;
    
    assert(*ptr == 123);
    assert(**ptrToPtr == 123);
    
    **ptrToPtr = 456;
    assert(value == 456);
    assert(*ptr == 456);
    
    std::cout << "Value: " << value << std::endl;
    std::cout << "Through ptr: " << *ptr << std::endl;
    std::cout << "Through pointer to pointer: " << **ptrToPtr << std::endl;
    
    std::cout << "✓ Test passed: Pointers to pointers work correctly\n" << std::endl;
}

void testConstPointers() {
    std::cout << "Test 7: Const Pointers" << std::endl;
    
    int value1 = 10, value2 = 20;
    
    const int* ptrToConst = &value1;
    assert(*ptrToConst == 10);
    
    ptrToConst = &value2;
    assert(*ptrToConst == 20);
    
    int* const constPtr = &value1;
    assert(*constPtr == 10);
    
    *constPtr = 30;
    assert(value1 == 30);
    assert(*constPtr == 30);
    
    const int* const constPtrToConst = &value2;
    assert(*constPtrToConst == 20);
    
    std::cout << "Pointer to const value: " << *ptrToConst << std::endl;
    std::cout << "Const pointer value: " << *constPtr << std::endl;
    std::cout << "Const pointer to const: " << *constPtrToConst << std::endl;
    
    std::cout << "✓ Test passed: Const pointers work correctly\n" << std::endl;
}

void testArraysAndPointers() {
    std::cout << "Test 8: Arrays and Pointers" << std::endl;
    
    int numbers[4] = {100, 200, 300, 400};
    int* ptr = numbers;
    
    assert(ptr == &numbers[0]);
    assert(*ptr == 100);
    assert(ptr[1] == 200);
    assert(*(ptr + 2) == 300);
    
    auto sumArray = [](int* arr, int size) {
        int sum = 0;
        for (int i = 0; i < size; i++) {
            sum += *(arr + i);
        }
        return sum;
    };
    
    int total = sumArray(numbers, 4);
    assert(total == 1000);
    
    std::cout << "Array sum using pointer: " << total << std::endl;
    
    std::cout << "✓ Test passed: Arrays and pointers work correctly\n" << std::endl;
}

void testStringPointers() {
    std::cout << "Test 9: String Pointers" << std::endl;
    
    const char* str1 = "Hello";
    const char* str2 = "World";
    
    assert(str1[0] == 'H');
    assert(*(str2 + 1) == 'o');
    
    char dynamicString[20];
    strcpy(dynamicString, "Dynamic");
    
    char* ptr = dynamicString;
    assert(*ptr == 'D');
    assert(strlen(ptr) == 7);
    
    std::cout << "String 1: " << str1 << std::endl;
    std::cout << "String 2: " << str2 << std::endl;
    std::cout << "Dynamic string: " << dynamicString << std::endl;
    
    std::cout << "✓ Test passed: String pointers work correctly\n" << std::endl;
}

void testSmartPointers() {
    std::cout << "Test 10: Smart Pointers" << std::endl;
    
    std::unique_ptr<int> uniquePtr = std::make_unique<int>(42);
    assert(*uniquePtr == 42);
    
    *uniquePtr = 84;
    assert(*uniquePtr == 84);
    
    auto sharedPtr1 = std::make_shared<int>(100);
    auto sharedPtr2 = sharedPtr1;
    
    assert(*sharedPtr1 == 100);
    assert(*sharedPtr2 == 100);
    assert(sharedPtr1.use_count() == 2);
    
    *sharedPtr1 = 200;
    assert(*sharedPtr2 == 200);
    
    std::cout << "Unique ptr value: " << *uniquePtr << std::endl;
    std::cout << "Shared ptr value: " << *sharedPtr1 << std::endl;
    std::cout << "Shared ptr use count: " << sharedPtr1.use_count() << std::endl;
    
    std::cout << "✓ Test passed: Smart pointers work correctly\n" << std::endl;
}

void testPointerAndStructures() {
    std::cout << "Test 11: Pointers and Structures" << std::endl;
    
    struct Point {
        int x, y;
    };
    
    Point point = {10, 20};
    Point* pointPtr = &point;
    
    assert(pointPtr->x == 10);
    assert(pointPtr->y == 20);
    assert((*pointPtr).x == 10);
    
    pointPtr->x = 30;
    pointPtr->y = 40;
    
    assert(point.x == 30);
    assert(point.y == 40);
    
    Point* dynamicPoint = new Point{50, 60};
    assert(dynamicPoint->x == 50);
    assert(dynamicPoint->y == 60);
    
    std::cout << "Point: (" << pointPtr->x << ", " << pointPtr->y << ")" << std::endl;
    std::cout << "Dynamic point: (" << dynamicPoint->x << ", " << dynamicPoint->y << ")" << std::endl;
    
    delete dynamicPoint;
    
    std::cout << "✓ Test passed: Pointers with structures work correctly\n" << std::endl;
}

int main() {
    std::cout << "========================================" << std::endl;
    std::cout << "Chapter 10: Pointers" << std::endl;
    std::cout << "Test Suite" << std::endl;
    std::cout << "========================================\n" << std::endl;
    
    testPointerBasics();
    testPointerArithmetic();
    testNullPointers();
    testPointersAndFunctions();
    testDynamicMemoryAllocation();
    testPointersToPointers();
    testConstPointers();
    testArraysAndPointers();
    testStringPointers();
    testSmartPointers();
    testPointerAndStructures();
    
    std::cout << "========================================" << std::endl;
    std::cout << "All Chapter 10 tests passed successfully!" << std::endl;
    std::cout << "========================================" << std::endl;
    
    return 0;
}