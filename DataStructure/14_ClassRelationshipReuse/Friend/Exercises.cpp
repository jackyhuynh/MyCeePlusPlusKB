/*
1.  **Friend Function (Exercise 1):**
    * Demonstrates how a regular function can be declared as a friend of a class to access its private members.
2.  **Friend Class (Exercise 2):**
    * Shows how an entire class can be declared as a friend, allowing all its member functions to access the private members of the target class.
3.  **Friend Function with Multiple Classes (Exercise 3):**
    * Illustrates how a friend function can access the private members of multiple classes.
4.  **Friend Member Function (Exercise 4):**
    * Demonstrates how a member function of one class can be declared as a friend of another class.
5.  **Friend Template Function (Exercise 5):**
    * Shows how a template function can be declared as a friend of a template class.
6.  **Friend Template Class (Exercise 6):**
    * Illustrates how a template class can be declared as a friend of another template class. This example also shows how to pass a second template type to the friend class.
 * */

#include <iostream>
#include <vector>
#include <string>

// Exercise 1: Friend Function to Access Private Members
class MyClass1 {
private:
    int privateData = 10;

public:
    friend void friendFunction1(const MyClass1& obj);
};

void friendFunction1(const MyClass1& obj) {
    std::cout << "Friend function accessing private data: " << obj.privateData << std::endl;
}

// Exercise 2: Friend Class to Access Private Members
class MyClass2 {
private:
    int privateData = 20;

public:
    friend class FriendClass2;
};

class FriendClass2 {
public:
    void accessPrivateData(const MyClass2& obj) {
        std::cout << "Friend class accessing private data: " << obj.privateData << std::endl;
    }
};

// Exercise 3: Friend Function with Multiple Classes
class ClassA {
private:
    int a = 30;

public:
    friend void combinedFriendFunction(const ClassA& objA, const ClassB& objB);
};

class ClassB {
private:
    std::string b = "Hello";

public:
    friend void combinedFriendFunction(const ClassA& objA, const ClassB& objB);
};

void combinedFriendFunction(const ClassA& objA, const ClassB& objB) {
    std::cout << "Friend function accessing A: " << objA.a << ", B: " << objB.b << std::endl;
}

// Exercise 4: Friend Member Function
class MyClass4; // Forward declaration

class FriendClass4 {
public:
    void accessPrivateData(const MyClass4& obj);
};

class MyClass4 {
private:
    int privateData = 40;

public:
    friend void FriendClass4::accessPrivateData(const MyClass4& obj);
};

void FriendClass4::accessPrivateData(const MyClass4& obj) {
    std::cout << "Friend member function accessing private data: " << obj.privateData << std::endl;
}

// Exercise 5: Friend Template Function
template <typename T>
class MyClass5 {
private:
    T privateData;

public:
    MyClass5(T data) : privateData(data) {}
    friend void templateFriendFunction(const MyClass5<T>& obj);
};

template <typename T>
void templateFriendFunction(const MyClass5<T>& obj) {
    std::cout << "Friend template function accessing private data: " << obj.privateData << std::endl;
}

// Exercise 6: Friend Template Class
template <typename T>
class MyClass6 {
private:
    T privateData;

public:
    MyClass6(T data) : privateData(data) {}
    template <typename U>
    friend class FriendTemplateClass6;
};

template <typename T, typename U>
class FriendTemplateClass6 {
public:
    void accessPrivateData(const MyClass6<T>& obj, U extraData) {
        std::cout << "Friend template class accessing private data: " << obj.privateData << ", extra data: " << extraData << std::endl;
    }
};

int main() {
    // Exercise 1
    MyClass1 obj1;
    friendFunction1(obj1);

    // Exercise 2
    MyClass2 obj2;
    FriendClass2 friendObj2;
    friendObj2.accessPrivateData(obj2);

    // Exercise 3
    ClassA objA;
    ClassB objB;
    combinedFriendFunction(objA, objB);

    // Exercise 4
    MyClass4 obj4;
    FriendClass4 friendObj4;
    friendObj4.accessPrivateData(obj4);

    // Exercise 5
    MyClass5<std::string> obj5("Hello Friend");
    templateFriendFunction(obj5);

    // Exercise 6
    MyClass6<int> obj6(123);
    FriendTemplateClass6<int, std::string> friendObj6;
    friendObj6.accessPrivateData(obj6, "Extra Data");

    return 0;
}