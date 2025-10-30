#include <iostream>
#include <memory> // Required for smart pointers

// Function prototype: Uses a pointer parameter to modify the original variable (Pass-by-Reference)
void changeValue(int* ptr);

int main() {
    // 10.1 Pointers and the Address Operator (&)
    int num = 10;
    std::cout << "Original value of num: " << num << std::endl;
    std::cout << "Memory address of num (&num): " << &num << std::endl;

    // ---

    // 10.2 Pointer Variables and Indirection Operator (*)
    // Define a pointer variable and initialize it with the address of 'num'
    int* intPtr = &num;

    std::cout << "\nValue of intPtr (address of num): " << intPtr << std::endl;
    // Use the indirection operator (*) to access the value at the address
    std::cout << "Value at the address stored in intPtr (*intPtr): " << *intPtr << std::endl;

    // Use the pointer to change the value of 'num'
    *intPtr = 20;
    std::cout << "New value of num after using *intPtr: " << num << std::endl;

    // ---

    // 10.3 The Relationship Between Arrays and Pointers
    int vals[] = {4, 7, 11};
    std::cout << "\nFirst element using array notation (vals[0]): " << vals[0] << std::endl;
    // An array name 'vals' is the starting address (a pointer constant)
    std::cout << "First element using pointer notation (*vals): " << *vals << std::endl;
    // Pointer arithmetic to access the second element (vals + 1)
    std::cout << "Second element using pointer notation (*(vals + 1)): " << *(vals + 1) << std::endl;

    // ---

    // 10.4 Pointer Arithmetic (Increment/Decrement)
    int* ptr = vals; // 'ptr' points to vals[0]
    std::cout << "\nPointer points to value: " << *ptr << std::endl;
    ptr++;          // Move to the next integer (vals[1])
    std::cout << "After ptr++, pointer points to value: " << *ptr << std::endl;
    ptr--;          // Move back to the previous integer (vals[0])
    std::cout << "After ptr--, pointer points to value: " << *ptr << std::endl;

    // ---

    // 10.5 Initializing Pointers
    int* nullPtr = nullptr; // Initialize with nullptr (C++11 standard for no valid address)
    if (nullPtr == nullptr) {
        std::cout << "\nnullPtr is correctly initialized to nullptr." << std::endl;
    }

    // ---

    // 10.7 Pointers as Function Parameters
    int myVal = 50;
    std::cout << "\nValue of myVal before function call: " << myVal << std::endl;
    changeValue(&myVal); // Pass the address of myVal
    std::cout << "Value of myVal after function call (changed via pointer): " << myVal << std::endl;

    // ---

    // 10.9 Dynamic Memory Allocation (new and delete)
    // Dynamically allocate an integer and store its address in a pointer
    int* dynamicInt = new int;
    *dynamicInt = 99;
    std::cout << "\nDynamically allocated value: " << *dynamicInt << std::endl;

    // Free the dynamically allocated memory
    delete dynamicInt;
    dynamicInt = nullptr; // Prevent dangling pointer by setting it to nullptr

    // Dynamic array allocation and deallocation
    int* dynamicArray = new int[3];
    dynamicArray[0] = 1;
    // ... use the array ...
    std::cout << "Dynamically allocated array element [0]: " << dynamicArray[0] << std::endl;

    delete[] dynamicArray; // Use delete [] for arrays
    dynamicArray = nullptr;

    // ---

    // 10.13 Smart Pointers (unique_ptr for automatic memory management)
    // std::unique_ptr manages the memory, automatically deallocating it when it goes out of scope.
    std::unique_ptr<int> smartPtr = std::make_unique<int>(42);
    std::cout << "\nValue managed by smart pointer: " << *smartPtr << std::endl;
    // No need for 'delete', memory will be freed automatically

    return 0;
}

// 10.7 Pointers as Function Parameters implementation
void changeValue(int* ptr) {
    // Dereference the pointer to access and modify the original value
    *ptr = 100;
    std::cout << "Inside function, value changed to: " << *ptr << std::endl;
}
