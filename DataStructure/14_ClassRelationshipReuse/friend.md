# **Friend Function in C++**

---

In C++, a **friend function** is a special function that is allowed to access the private and protected members of a
class, even though it is not a member of that class. It is typically used when two or more classes need to share
information, but you don't want to expose internal details to other parts of the program.

## Resources:

- [Wrongful use](./FriendBadUse.cpp)
- [Best Practice](./FriendBestPractice.cpp)

## **Key Points**:

- **Friend functions** are declared inside the class but are defined outside of it.
- It can access **private** and **protected** members of the class.
- A friend function is **not a member** of the class, but it has access privileges.

## **Code Example (Friend Function)**:

```cpp
#include <iostream>
using namespace std;

class Box {
private:
    double length;

public:
    Box() : length(0.0) {}

    // Declare friend function
    friend void setLength(Box& box, double len);
};

// Define friend function
void setLength(Box& box, double len) {
    box.length = len;
}

int main() {
    Box b;
    setLength(b, 10.5);  // Set private member using friend function
    return 0;
}
```

## **Use Case**:

Friend functions are typically used in situations where an external function needs access to the internal state of a
class, such as when performing operations between two classes that need intimate access to each other's data but you
don't want to provide public methods.

## **Summary**:

- **Friend functions** allow external functions to access private and protected members of a class.