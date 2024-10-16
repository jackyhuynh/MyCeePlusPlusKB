# Weak Pointer

`std::weak_ptr` in C++ is a type of smart pointer that provides a **non-owning** "weak" reference to an object that is
managed by `std::shared_ptr`. It is used to break reference cycles and prevent memory leaks in cases where objects
mutually reference each other.

### Key Concepts:

1. **Non-Owning Pointer**:
    - A `std::weak_ptr` does not affect the reference count of the object it points to. It holds a reference to the
      object managed by a `std::shared_ptr`, but it doesn't increase the reference count.
    - This is useful when you want to observe or access an object managed by `std::shared_ptr` without extending its
      lifetime.

2. **Breaking Cyclic Dependencies**:
    - One of the main use cases for `std::weak_ptr` is to break reference cycles. A reference cycle occurs when two or
      more objects hold `std::shared_ptr` instances pointing to each other, preventing the reference count from reaching
      zero and thus causing a memory leak.
    - `std::weak_ptr` breaks this cycle by allowing one or more objects to refer to each other without ownership, so
      when all the `std::shared_ptr` instances go out of scope, the memory is properly released.

3. **`expired()` and `lock()`**:
    - Since `std::weak_ptr` does not keep the object alive, you need to check if the object still exists before
      accessing it.
    - `expired()`: This function returns `true` if the `std::weak_ptr` no longer points to a valid object (i.e., the
      object has been destroyed because all owning `std::shared_ptr` instances were destroyed).
    - `lock()`: This function creates a temporary `std::shared_ptr` from the `std::weak_ptr`, if the object still
      exists. If the object has already been destroyed, it returns a `nullptr`.

### Example:

Let's see an example of how `std::weak_ptr` works:

```cpp
#include <iostream>
#include <memory>

class Node {
public:
    std::shared_ptr<Node> next;
    std::weak_ptr<Node> prev;  // weak_ptr to prevent cyclic reference
    int value;

    Node(int val) : value(val) {
        std::cout << "Node created with value: " << value << std::endl;
    }

    ~Node() {
        std::cout << "Node with value " << value << " destroyed" << std::endl;
    }
};

int main() {
    std::shared_ptr<Node> node1 = std::make_shared<Node>(1);
    std::shared_ptr<Node> node2 = std::make_shared<Node>(2);

    node1->next = node2;
    node2->prev = node1;  // weak_ptr breaks cyclic reference

    // Accessing weak_ptr via lock()
    if (auto sharedPrev = node2->prev.lock()) {
        std::cout << "node2's prev value: " << sharedPrev->value << std::endl;
    }

    return 0;
}
```

### Explanation:

1. **Node Class**:
    - Each `Node` object has a `std::shared_ptr` to its `next` node and a `std::weak_ptr` to its `prev` node. This is a
      common pattern in doubly linked lists to avoid reference cycles.
    - If we had used `std::shared_ptr` for both `next` and `prev`, it would create a cyclic dependency, causing the
      reference count to never drop to zero, and thus, the nodes would never be destroyed.

2. **`node1` and `node2`**:
    - `node1` holds a `std::shared_ptr` to `node2`, and `node2` holds a `std::weak_ptr` to `node1`.
    - Since `std::weak_ptr` does not increase the reference count of `node1`, when `node1` and `node2` go out of scope,
      both nodes will be properly destroyed.

3. **Using `lock()`**:
    - We use `node2->prev.lock()` to access the `prev` node of `node2`. If `node1` still exists, `lock()` returns a
      `std::shared_ptr` to `node1`; otherwise, it returns `nullptr`.

### Output:

```
Node created with value: 1
Node created with value: 2
node2's prev value: 1
Node with value 2 destroyed
Node with value 1 destroyed
```

### When to Use `std::weak_ptr`:

- **Breaking Cyclic Dependencies**: The most common use case for `std::weak_ptr` is when two or more objects reference
  each other, but you want to prevent a reference cycle.
- **Observing an Object**: If you want a non-owning reference to an object managed by a `std::shared_ptr`, and you don't
  want to prolong the object's lifetime, use a `std::weak_ptr`.

### Summary:

- `std::weak_ptr` is a non-owning reference to an object managed by `std::shared_ptr`.
- It does not increase the reference count, helping to avoid cyclic dependencies.
- Use `lock()` to get a `std::shared_ptr` if the object still exists and `expired()` to check if the object has been
  destroyed.