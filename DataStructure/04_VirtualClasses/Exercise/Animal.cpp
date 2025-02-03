//
// Created by truc huynh on 2/2/25.
//


//**Objective:** Implement an `Animal` base class with a virtual function `makeSound()`. Create derived classes (`Dog`, `Cat`, `Cow`) that override `makeSound()`.
//### **Exercise 2: Animal Sounds (Virtual Function Override)**
//**Requirements:**
//- Define a base class `Animal` with a virtual function `makeSound()`.
//- Create derived classes `Dog`, `Cat`, and `Cow`.
//- Override `makeSound()` in each derived class.
//- Use a loop to call `makeSound()` on an array of animals.

#include <iostream>

class Animal {
public:
    virtual void makeSound() const = 0; // Pure virtual function
    virtual ~Animal() {}
};

class Dog : public Animal {
public:
    void makeSound() const override {
        std::cout << "Dog barks: Woof! Woof!\n";
    }
};

class Cat : public Animal {
public:
    // std::cout << "Cat meows: Meow! Meow!\n";
};


int main() {
    Animal* animals[] = {new Dog(), new Cat(), new Cow()};

    for (Animal* animal : animals) {
        animal->makeSound();
        delete animal;
    }

    return 0;
}

//### **Expected Output**
//Dog barks: Woof! Woof!
//Cat meows: Meow! Meow!
//Cow moos: Moo! Moo!
