# Programming Concepts: Chunk of Code, Procedural Programming, Abstract Data Types, and Object-Oriented Programming

This document explains key programming concepts using **C++**. Each section includes sample code to illustrate the
principles.

---

## Chunk of Code

A "chunk of code" refers to a self-contained block that performs a specific task. It may include loops, conditionals,
and statements.

### Example: Printing Prime Numbers

```cpp
#include <iostream>
using namespace std;

void printPrimes(int n) {
    for (int i = 2; i <= n; i++) {
        bool isPrime = true;
        for (int j = 2; j <= i / 2; j++) {
            if (i % j == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    int limit;
    cout << "Enter the limit: ";
    cin >> limit;
    printPrimes(limit);
    return 0;
}
```

### Explanation

- This chunk of code uses nested loops to determine and print prime numbers up to a given limit.
- Functions allow modularity and reuse.

---

## Procedural Programming

Procedural programming is a paradigm that organizes code into procedures or functions. It focuses on breaking tasks into
subroutines.

### Example: Simple Calculator

```cpp
#include <iostream>
using namespace std;

float add(float a, float b) {
    return a + b;
}

float subtract(float a, float b) {
    return a - b;
}

float multiply(float a, float b) {
    return a * b;
}

float divide(float a, float b) {
    if (b != 0) return a / b;
    else {
        cout << "Error: Division by zero!" << endl;
        return 0;
    }
}

int main() {
    float num1, num2;
    char op;

    cout << "Enter two numbers and an operator (+, -, *, /): ";
    cin >> num1 >> op >> num2;

    switch (op) {
        case '+':
            cout << "Result: " << add(num1, num2) << endl;
            break;
        case '-':
            cout << "Result: " << subtract(num1, num2) << endl;
            break;
        case '*':
            cout << "Result: " << multiply(num1, num2) << endl;
            break;
        case '/':
            cout << "Result: " << divide(num1, num2) << endl;
            break;
        default:
            cout << "Invalid operator!" << endl;
    }

    return 0;
}
```

### Explanation

- The program separates operations into functions (`add`, `subtract`, etc.).
- Main function acts as a controller, invoking specific procedures based on user input.

---

## Abstract Data Types (ADT)

An Abstract Data Type defines a data structure and its operations independently of implementation details.

### Example: Stack Implementation

```cpp
#include <iostream>
using namespace std;

class Stack {
private:
    int* arr;
    int top;
    int capacity;

public:
    Stack(int size) {
        arr = new int[size];
        capacity = size;
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    void push(int x) {
        if (top == capacity - 1) {
            cout << "Stack overflow!" << endl;
            return;
        }
        arr[++top] = x;
    }

    int pop() {
        if (top == -1) {
            cout << "Stack underflow!" << endl;
            return -1;
        }
        return arr[top--];
    }

    bool isEmpty() {
        return top == -1;
    }

    int peek() {
        if (!isEmpty()) return arr[top];
        cout << "Stack is empty!" << endl;
        return -1;
    }
};

int main() {
    Stack stack(5);

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Top element: " << stack.peek() << endl;

    cout << "Popped element: " << stack.pop() << endl;
    cout << "Popped element: " << stack.pop() << endl;

    if (stack.isEmpty()) cout << "Stack is empty!" << endl;

    return 0;
}
```

### Explanation

- The `Stack` class provides operations (`push`, `pop`, `peek`) while encapsulating implementation details.
- Encapsulation ensures data integrity and abstraction.

---

## Object-Oriented Programming (OOP)

OOP organizes code into objects that combine state (attributes) and behavior (methods). Core principles are
encapsulation, inheritance, and polymorphism.

### Example: Inheritance and Polymorphism

```cpp
#include <iostream>
using namespace std;

class Animal {
public:
    virtual void sound() {
        cout << "Some generic animal sound" << endl;
    }
};

class Dog : public Animal {
public:
    void sound() override {
        cout << "Woof Woof" << endl;
    }
};

class Cat : public Animal {
public:
    void sound() override {
        cout << "Meow" << endl;
    }
};

int main() {
    Animal* animal;
    Dog dog;
    Cat cat;

    animal = &dog;
    animal->sound();

    animal = &cat;
    animal->sound();

    return 0;
}
```

### Explanation

- **Encapsulation**: Each class defines its behavior independently.
- **Inheritance**: `Dog` and `Cat` inherit from `Animal`.
- **Polymorphism**: The `sound` method behaves differently depending on the object.

---

## Summary

- **Chunk of Code**: A standalone block for a specific task.
- **Procedural Programming**: Organizes code into procedures/functions.
- **Abstract Data Types**: Defines a data structure and its operations, hiding implementation details.
- **Object-Oriented Programming**: Combines data and behavior into objects, emphasizing principles like encapsulation,
  inheritance, and polymorphism.
