# Abstract Data Type (ADT) List in C++

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Operations](#operations)
- [Implementation](#implementation)
- [Example Usage](#example-usage)
- [Complexity Analysis](#complexity-analysis)
- [Conclusion](#conclusion)

## Introduction

An **Abstract Data Type (ADT) List** is a collection of ordered elements where duplicates are allowed. This README
provides an overview of the ADT List, its operations, and how to implement it in C++ using an array-based and a linked
list-based approach.

## Features

- Maintains an ordered collection of elements.
- Allows duplicate values.
- Supports dynamic size management (for linked list implementation).
- Efficient insertions and deletions in linked list implementation.

## Operations

An ADT List typically supports the following operations:

| Operation                 | Description                                                |
|---------------------------|------------------------------------------------------------|
| `insert(position, value)` | Inserts a value at a specific position in the list.        |
| `remove(position)`        | Removes an element at a specific position.                 |
| `get(position)`           | Retrieves the value at a given position.                   |
| `size()`                  | Returns the number of elements in the list.                |
| `isEmpty()`               | Checks if the list is empty.                               |
| `clear()`                 | Removes all elements from the list.                        |
| `find(value)`             | Searches for a value in the list and returns its position. |
| `print()`                 | Displays all elements in the list.                         |

## Implementation

### Array-Based Implementation

The array-based list is implemented using a dynamically allocated array. It has a fixed capacity, which can be resized
when needed.

```cpp
#include <iostream>

class ArrayList {
private:
    int *arr;
    int capacity;
    int count;

public:
    ArrayList(int size = 10) : capacity(size), count(0) {
        arr = new int[capacity];
    }

    ~ArrayList() { delete[] arr; }

    void insert(int pos, int value) {
        if (pos < 0 || pos > count || count == capacity) return;
        for (int i = count; i > pos; --i) {
            arr[i] = arr[i - 1];
        }
        arr[pos] = value;
        count++;
    }

    void remove(int pos) {
        if (pos < 0 || pos >= count) return;
        for (int i = pos; i < count - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        count--;
    }

    int get(int pos) {
        if (pos < 0 || pos >= count) return -1;
        return arr[pos];
    }

    int size() { return count; }
    bool isEmpty() { return count == 0; }
    void print() {
        for (int i = 0; i < count; i++) std::cout << arr[i] << " ";
        std::cout << std::endl;
    }
};
```

### Linked List Implementation

A **singly linked list** is a more dynamic approach that avoids resizing issues.

```cpp
#include <iostream>

class LinkedList {
private:
    struct Node {
        int data;
        Node *next;
        Node(int value) : data(value), next(nullptr) {}
    };
    Node *head;
    int count;

public:
    LinkedList() : head(nullptr), count(0) {}

    void insert(int pos, int value) {
        if (pos < 0 || pos > count) return;
        Node *newNode = new Node(value);
        if (pos == 0) {
            newNode->next = head;
            head = newNode;
        } else {
            Node *temp = head;
            for (int i = 0; i < pos - 1; i++) temp = temp->next;
            newNode->next = temp->next;
            temp->next = newNode;
        }
        count++;
    }

    void remove(int pos) {
        if (pos < 0 || pos >= count || !head) return;
        Node *temp = head;
        if (pos == 0) {
            head = head->next;
            delete temp;
        } else {
            Node *prev = nullptr;
            for (int i = 0; i < pos; i++) {
                prev = temp;
                temp = temp->next;
            }
            prev->next = temp->next;
            delete temp;
        }
        count--;
    }

    void print() {
        Node *temp = head;
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};
```

## Example Usage

```cpp
int main() {
    LinkedList list;
    list.insert(0, 10);
    list.insert(1, 20);
    list.insert(2, 30);
    list.print(); // Output: 10 20 30

    list.remove(1);
    list.print(); // Output: 10 30
    return 0;
}
```

## Complexity Analysis

| Operation                 | Array-Based | Linked List |
|---------------------------|-------------|-------------|
| `insert(position, value)` | O(n)        | O(n)        |
| `remove(position)`        | O(n)        | O(n)        |
| `get(position)`           | O(1)        | O(n)        |
| `size()`                  | O(1)        | O(1)        |
| `isEmpty()`               | O(1)        | O(1)        |
| `clear()`                 | O(1)        | O(n)        |

## Conclusion

The **ADT List** provides a flexible and useful data structure for maintaining ordered collections. While array-based
lists offer constant-time access but require resizing, linked lists provide dynamic memory allocation but have slower
element access. The choice depends on the application requirements.

