# Test-Driven Development (TDD)

Test-Driven Development (TDD) is a software development process that emphasizes writing tests before writing the actual code. It follows a short, iterative cycle known as "Red-Green-Refactor." Here's a breakdown:

**The TDD Cycle:**

* **Red:**
    * Write a test for a small piece of functionality.
    * Run the test. It should fail because the functionality doesn't exist yet.
* **Green:**
    * Write the minimum amount of code necessary to make the test pass.
    * Run the test again. It should now pass.
* **Refactor:**
    * Improve the code's structure, readability, and efficiency without changing its behavior.
    * Run all tests again to ensure no regressions were introduced.

**Key Principles:**

* **Write tests first:** This forces you to think about the desired behavior before implementation.
* **Small steps:** Focus on implementing small, incremental changes.
* **Frequent testing:** Run tests often to catch errors early.
* **Refactoring:** Continuously improve the code's design.

**Example in C++ (using a hypothetical simple example, and conceptual test code):**

Let's say we want to create a simple `Calculator` class with an `add` function.

**1. Red (Write a Failing Test):**

```c++
// Hypothetical test code (using a test framework like Google Test)
#include "gtest/gtest.h"
#include "calculator.h" // Assuming calculator.h will contain the class.

TEST(CalculatorTest, AddTwoNumbers) {
  Calculator calc;
  EXPECT_EQ(5, calc.add(2, 3)); // Test will fail initially.
}
```

**2. Green (Make the Test Pass):**

```c++
// calculator.h
class Calculator {
public:
  int add(int a, int b) {
    return a + b;
  }
};
```

Now, the test will pass.

**3. Refactor (Improve the Code):**

In this simple example, there might not be much to refactor. However, if the `Calculator` class grew more complex, we could refactor it for better readability or efficiency.

**Important considerations:**

* For actual c++ TDD, using a testing framework like Google Test, or Catch2 is very important.
* TDD helps to create cleaner, more maintainable code.
* TDD can increase developer confidence.

# Binary Tree Insert TDD

```cpp
// binary_tree.h
#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <memory>

template <typename T>
class BinaryTree {
public:
    struct Node {
        T data;
        std::shared_ptr<Node> left;
        std::shared_ptr<Node> right;
        Node(T data) : data(data), left(nullptr), right(nullptr) {}
    };

    BinaryTree() : root_(nullptr) {}
    ~BinaryTree() {}

    void insert(T data);
    bool find(T data);
    // Add other functions like traversal, deletion, etc. later.

private:
    std::shared_ptr<Node> root_;
};

template <typename T>
void BinaryTree<T>::insert(T data) {
  if (!root_) {
    root_ = std::make_shared<Node>(data);
    return;
  }
  std::shared_ptr<Node> current = root_;
  while(true){
    if(data < current->data){
      if(!current->left){
        current->left = std::make_shared<Node>(data);
        return;
      }
      current = current->left;
    } else {
      if(!current->right){
        current->right = std::make_shared<Node>(data);
        return;
      }
      current = current->right;
    }
  }
}

template <typename T>
bool BinaryTree<T>::find(T data) {
    std::shared_ptr<Node> current = root_;
    while (current) {
        if (current->data == data) {
            return true;
        } else if (data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return false;
}

#endif // BINARY_TREE_H

// binary_tree_test.cpp
#include "gtest/gtest.h"
#include "binary_tree.h"

TEST(BinaryTreeTest, InsertAndFindSingleNode) {
    BinaryTree<int> tree;
    tree.insert(10);
    EXPECT_TRUE(tree.find(10));
    EXPECT_FALSE(tree.find(5));
}

TEST(BinaryTreeTest, InsertMultipleNodesAndFind) {
    BinaryTree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);

    EXPECT_TRUE(tree.find(10));
    EXPECT_TRUE(tree.find(5));
    EXPECT_TRUE(tree.find(15));
    EXPECT_TRUE(tree.find(3));
    EXPECT_TRUE(tree.find(7));
    EXPECT_TRUE(tree.find(12));
    EXPECT_TRUE(tree.find(18));
    EXPECT_FALSE(tree.find(20));
}

TEST(BinaryTreeTest, EmptyTreeFind) {
    BinaryTree<int> tree;
    EXPECT_FALSE(tree.find(10));
}
```

**Explanation and TDD Process:**

1.  **Red:**
    * We start by writing the tests (`binary_tree_test.cpp`) before implementing the `BinaryTree` class (`binary_tree.h`).
    * The first test (`InsertAndFindSingleNode`) checks if inserting a single node and then finding it works. At this point, the tests will fail because the `BinaryTree` class and its `insert` and `find` methods don't exist yet.
    * The test `EmptyTreeFind`, tests the find function on an empty tree.
    * The test `InsertMultipleNodesAndFind` tests the insert and find functions with a more complex tree.

2.  **Green:**
    * We then implement the `BinaryTree` class and its `insert` and `find` methods in `binary_tree.h`.
    * The implementation is made as simple as possible to make the current failing test pass.
    * We re-run the tests, and they should now pass.

3.  **Refactor:**
    * After the tests pass, we can refactor the code to improve its readability, efficiency, or maintainability.
    * In this example, the initial implementation is relatively simple, but in a real-world scenario, we might refactor to handle edge cases, improve performance, or add more functionality.
    * As we add more functionality to the Binary tree, we would add more tests, and refactor the code as needed.

**How to compile and run:**

1.  **Install Google Test:**
    * You'll need to have the Google Test framework installed.
2.  **Compile:**
    * g++ binary_tree.h binary_tree_test.cpp -o binary_tree_test -lgtest -lgtest_main -pthread
3.  **Run:**
    * ./binary_tree_test

