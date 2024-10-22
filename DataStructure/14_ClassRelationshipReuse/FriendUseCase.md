x# Friend Use-case

## 1. **Operator Overloading for Non-Member Functions**

Certain binary operators (like `<<` or `==`) need access to private members but are best implemented as **non-member
functions** for symmetry. Making them `friend` allows access to private data without breaking encapsulation.

### Example: `friend` for `<<` Operator Overload

```cpp
#include <iostream>
#include <string>

class UserDetails {
private:
    std::string name;
    int age;

public:
    UserDetails(const std::string& name, int age) : name(name), age(age) {}

    // Friend function for stream insertion operator to access private members.
    friend std::ostream& operator<<(std::ostream& os, const UserDetails& user);
};

std::ostream& operator<<(std::ostream& os, const UserDetails& user) {
    os << "Name: " << user.name << ", Age: " << user.age;
    return os;
}

int main() {
    UserDetails user("Alice", 25);
    std::cout << user << std::endl;
    return 0;
}
```

### Justification:

- The `operator<<` function needs access to private members (`name` and `age`).
- If implemented as a member function, it would require asymmetric calls like `user.operator<<(std::cout)`. Making it
  `friend` allows natural usage of `std::cout << user`.

---

## 2. **Tight Collaboration Between Classes**

In cases where two classes need **tight collaboration**, granting one class access to the internals of another via
`friend` can be justified. This is common in **implementations of iterators** or **builder patterns**.

### Example: Iterator Class as a Friend

```cpp
#include <iostream>
#include <vector>

class Container {
private:
    std::vector<int> data;

public:
    Container(const std::initializer_list<int>& list) : data(list) {}

    class Iterator {
    private:
        const Container& container;
        size_t index;

    public:
        Iterator(const Container& c, size_t i) : container(c), index(i) {}

        bool operator!=(const Iterator& other) const {
            return index != other.index;
        }

        int operator*() const {
            return container.data[index];  // Access private data.
        }

        Iterator& operator++() {
            ++index;
            return *this;
        }

        friend class Container;
    };

    Iterator begin() const { return Iterator(*this, 0); }
    Iterator end() const { return Iterator(*this, data.size()); }
};

int main() {
    Container container = {1, 2, 3, 4, 5};
    for (auto it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }
    return 0;
}
```

### Justification:

- The `Iterator` class needs access to the `data` member of `Container`. Making it a `friend` class allows the iterator
  to access private members without exposing them publicly.
- This design follows the **iterator pattern** and maintains encapsulation since the `Iterator` class is part of the
  internal mechanism of `Container`.

---

## 3. **Builder Pattern for Complex Object Construction**

A **Builder class** often requires direct access to the private members of the class it builds. This design simplifies
construction without exposing internal members.

### Example: Builder Pattern Using `friend`

```cpp
#include <iostream>
#include <string>

class House {
private:
    std::string foundation;
    std::string structure;
    std::string roof;

public:
    // Private constructor to force use of the Builder.
    House(const std::string& foundation, const std::string& structure, const std::string& roof)
        : foundation(foundation), structure(structure), roof(roof) {}

    // Friend class to grant access to private constructor.
    friend class HouseBuilder;

    void display() const {
        std::cout << "House with " << foundation << ", " << structure << ", and " << roof << ".\n";
    }
};

class HouseBuilder {
private:
    std::string foundation = "Default Foundation";
    std::string structure = "Default Structure";
    std::string roof = "Default Roof";

public:
    HouseBuilder& setFoundation(const std::string& f) {
        foundation = f;
        return *this;
    }

    HouseBuilder& setStructure(const std::string& s) {
        structure = s;
        return *this;
    }

    HouseBuilder& setRoof(const std::string& r) {
        roof = r;
        return *this;
    }

    House build() {
        return House(foundation, structure, roof);  // Access private constructor.
    }
};

int main() {
    House house = HouseBuilder()
                      .setFoundation("Concrete")
                      .setStructure("Wooden")
                      .setRoof("Shingle")
                      .build();
    house.display();
    return 0;
}
```

### Justification:

- The `House` class constructor is private to enforce controlled construction via the `HouseBuilder` class.
- Granting `HouseBuilder` friendship allows it to construct `House` objects without exposing the constructor publicly.

---

## 4. **Testing Frameworks with Direct Access to Internals**

Sometimes, **unit tests** need access to private members for effective testing. Using `friend` in a test suite ensures
that the test code can verify behavior without compromising the class’s design.

### Example: Granting Friend Access to a Test Suite

```cpp
#include <iostream>
#include <string>
#include <cassert>

class UserDetails {
private:
    std::string name;
    int age;

public:
    UserDetails(const std::string& name, int age) : name(name), age(age) {}

    friend class UserDetailsTest;  // Grant test suite access to private members.
};

class UserDetailsTest {
public:
    static void runTests() {
        UserDetails user("Alice", 30);
        assert(user.name == "Alice");  // Direct access to private members.
        assert(user.age == 30);
        std::cout << "All tests passed.\n";
    }
};

int main() {
    UserDetailsTest::runTests();
    return 0;
}
```

### Justification:

- Granting `UserDetailsTest` access to private members ensures **thorough testing**.
- This avoids unnecessary public getters that exist solely for testing purposes, maintaining encapsulation while
  enabling effective tests.

---

## Conclusion

These examples demonstrate valid scenarios where the `friend` keyword is justified and useful:

1. **Operator Overloading:** Non-member operators require access to private members.
2. **Tight Collaboration:** Iterators or other tightly bound classes need private access.
3. **Builder Pattern:** Controlled object construction through a friend builder class.
4. **Testing:** Unit tests gain direct access without compromising encapsulation.

Using `friend` wisely enhances code clarity, enforces encapsulation , and maintains separation of concerns, but it
should be applied with care. Overusing it can lead to tightly coupled
code, but when used appropriately—as shown in the examples above—it solves specific design problems elegantly.