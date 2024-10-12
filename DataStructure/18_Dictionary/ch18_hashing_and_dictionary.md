# Hashing

## What is Hashing:

Hashing is a process used to transform a given input (or 'message') into a fixed-size string of bytes. The output, known as the hash value, digest, or hash code, typically is a sequence of numbers and letters that uniquely represents the input data. Hashing is used in various applications like data retrieval, integrity verification, and cryptography. 


**Use Case**: Hashing is primarily used for securely storing data like passwords. When a password is hashed, the hash value is stored instead of the plaintext password. Upon authentication, the provided password is hashed again, and the resulting hash is compared with the stored hash.

Here's a simple example of a hashing algorithm in C++ that uses a basic hash function to convert a string into an integer hash value.

```cpp
#include <iostream>
#include <string>

unsigned long simpleHash(const std::string& input) {
    unsigned long hash = 0;
    for(char c : input) {
        hash = hash * 31 + c;
    }
    return hash;
}

int main() {
    std::string data = "Hello, world!";
    unsigned long hashValue = simpleHash(data);
    std::cout << "Hash Value: " << hashValue << std::endl;
    return 0;
}
```


## Map vs. Unordermap

In C++, both `std::map` and `std::unordered_map` are associative containers that store elements formed by a combination of a key value and a mapped value, following a specific order. However, there are fundamental differences in their internal workings, performance characteristics, and the order in which elements are stored.

### `std::map`
- **Internal Structure**: `std::map` is typically implemented as a balanced binary tree (like a Red-Black Tree). 
- **Ordering**: It stores elements in a sorted order based on the key. The sorting criteria can be specified by a comparison function (less than by default).
- **Search Time**: Lookup operations (find, insert, delete) have logarithmic complexity (`O(log n)`).
- **Usage Scenario**: Use `std::map` when you need ordered data, or you frequently perform operations that require the container to be sorted.

### `std::unordered_map`
- **Internal Structure**: `std::unordered_map` is implemented using a hash table.
- **Ordering**: It does not store elements in any specific order. The order depends on the hash function and may change when rehashing occurs.
- **Search Time**: Provides average constant-time complexity (`O(1)`) for search operations, although this can degrade to linear (`O(n)`) in the worst case if there are many hash collisions.
- **Usage Scenario**: Use `std::unordered_map` when you need faster access and insertion and the order of elements is not important.

### Sample Code (NOT ON TEST)

#### Using `std::map`

```cpp
#include <iostream>
#include <map>

int main() {
    std::map<std::string, int> phoneBook;
    phoneBook["Alice"] = 1234;
    phoneBook["Bob"] = 5678;
    phoneBook["Charlie"] = 91011;

    // Elements will be printed in alphabetical order based on the key
    for(const auto& pair : phoneBook) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
```

Output:
```
Alice: 1234
Bob: 5678
Charlie: 91011
```

#### Using `std::unordered_map`

```cpp
#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<std::string, int> phoneBook;
    phoneBook["Alice"] = 1234;
    phoneBook["Bob"] = 5678;
    phoneBook["Charlie"] = 91011;

    // The order of elements is not guaranteed
    for(const auto& pair : phoneBook) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
```

The output order may vary because `std::unordered_map` does not maintain the order of its elements.

When deciding between `std::map` and `std::unordered_map`, consider whether the order of elements is important for your application and the performance characteristics you require. `std::unordered_map` is generally faster for accessing elements by key, but `std::map` maintains a sorted order which can be beneficial for certain algorithms or when you need to print elements in order.

## Relationship Between Hashing and Dictionaries

In summary, hashing is a process or technique, while a dictionary is a data structure. Hashing enables the efficient operation of dictionaries, especially in terms of data retrieval, addition, and deletion based on keys.

## Open Addressing

Open addressing stores all entries directly within the array slots of the hash table itself. When a collision occurs, open addressing finds another slot for the colliding entry through a process called probing. There are several probing techniques, including linear probing, quadratic probing, and double hashing.

Implementing a complete hash table with linear probing, quadratic probing, and double hashing in C++ can be quite involved, but I'll provide simplified examples to illustrate the concepts. These examples are educational and meant to demonstrate the probing techniques. A fully-featured hash table suitable for production use would need more comprehensive error handling, dynamic resizing, and possibly templating for general-purpose use.

### Linear Probing (NO CODE)

Linear probing resolves collisions by moving sequentially through the hash table until an empty slot is found.

```cpp
#include <iostream>
#include <vector>
#include <optional>

class LinearProbingHashTable {
    std::vector<std::optional<int>> table;
    int capacity;

public:
    LinearProbingHashTable(int size) : capacity(size) {
        table.resize(size);
    }

    int hash(int key) {
        return key % capacity;
    }

    void insert(int key) {
        int index = hash(key);
        while (table[index].has_value()) {
            index = (index + 1) % capacity;
        }
        table[index] = key;
    }

    bool search(int key) {
        int index = hash(key);
        int start = index;
        while (table[index].has_value()) {
            if (table[index] == key) {
                return true;
            }
            index = (index + 1) % capacity;
            if (index == start) break; // Avoid infinite loop
        }
        return false;
    }
};
```

### Quadratic Probing (NO CODE)

Quadratic probing reduces clustering by using a quadratic function to calculate the probe sequence.

```cpp
#include <vector>
#include <optional>

class QuadraticProbingHashTable {
    std::vector<std::optional<int>> table;
    int capacity;

public:
    QuadraticProbingHashTable(int size) : capacity(size) {
        table.resize(size);
    }

    int hash(int key) {
        return key % capacity;
    }

    void insert(int key) {
        int index = hash(key);
        int i = 0;
        while (table[index].has_value()) {
            index = (index + i * i) % capacity;
            i++;
        }
        table[index] = key;
    }

    bool search(int key) {
        int index = hash(key);
        int i = 0;
        while (table[(index + i * i) % capacity].has_value()) {
            if (table[(index + i * i) % capacity] == key) {
                return true;
            }
            i++;
        }
        return false;
    }
};
```

### Double Hashing

Double hashing uses a second hash function to determine the step size after a collision.

```cpp
#include <vector>
#include <optional>

class DoubleHashingHashTable {
    std::vector<std::optional<int>> table;
    int capacity;

    int hash1(int key) {
        return key % capacity;
    }

    int hash2(int key) {
        return 1 + (key % (capacity - 1));
    }

public:
    DoubleHashingHashTable(int size) : capacity(size) {
        table.resize(size);
    }

    void insert(int key) {
        int index = hash1(key);
        int stepSize = hash2(key);
        while (table[index].has_value()) {
            index = (index + stepSize) % capacity;
        }
        table[index] = key;
    }

    bool search(int key) {
        int index = hash1(key);
        int stepSize = hash2(key);
        while (table[index].has_value()) {
            if (table[index] == key) {
                return true;
            }
            index = (index + stepSize) % capacity;
        }
        return false;
    }
};
```


## Hash Table vs Dictionary:
 
The terms "hash table" and "dictionary" are often used interchangeably in the context of data structures, but they can have distinct meanings depending on the programming language or the specific implementation context. Here's a breakdown of how they are generally understood and used:

### Hash Table

- **Definition**: A hash table is a data structure that implements an associative array abstract data type, a structure that can map keys to values. It uses a hash function to compute an index into an array of buckets or slots, from which the desired value can be found.
- **Key Characteristics**:
    - Uses a hash function to determine where to store each key-value pair.
    - Handles collisions through various methods like chaining (where each bucket is a linked list of entries that hash to the same index) or open addressing (where a collision triggers a search for another bucket according to a predefined sequence).
    - Efficiency: Ideally offers \(O(1)\) average time complexity for insert, delete, and search operations, although this can degrade to \(O(n)\) in the worst case (e.g., when all keys hash to the same index).
- **Use Cases**: Used internally by many programming languages for their dictionary or map implementations. Directly used in low-level programming or when specific customizations are needed.

### Dictionary

- **Definition**: A dictionary is an abstract data type that represents a collection of keys and values, with each key being unique within the collection. In many languages, dictionaries are implemented using hash tables, but this is not universally true.
- **Key Characteristics**:
    - Provides a high-level interface to add, remove, and access elements by keys.
    - The implementation may vary: while many languages use hash tables, others might use trees or other data structures to ensure order or provide different performance guarantees.
    - Efficiency: The performance of a dictionary depends on its underlying implementation but often aims for \(O(1)\) average time complexity for standard operations.
- **Use Cases**: Dictionaries are used in a wide range of applications, from storing simple configurations to complex data processing. They are a fundamental data structure in many high-level programming languages like Python (`dict`), JavaScript (objects as associative arrays), and C# (`Dictionary`).