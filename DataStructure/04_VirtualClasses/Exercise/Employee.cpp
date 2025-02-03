//
// Created by truc huynh on 2/2/25.
//

//### **Exercise 3: Employee Payroll System (Abstract Base Class)**
//**Objective:** Implement an abstract `Employee` class with a pure virtual function `calculateSalary()`. Create derived classes (`FullTimeEmployee`, `PartTimeEmployee`) that override `calculateSalary()`.
//- Define an abstract `Employee` class with a `calculateSalary()` function.
//- Create `FullTimeEmployee` and `PartTimeEmployee` with different salary calculations.
//- Use polymorphism to call `calculateSalary()`.

#include <iostream>

class Employee {
protected:
    std::string name;
    double baseSalary;
public:
    Employee(std::string n, double salary) : name(n), baseSalary(salary) {}
    virtual double calculateSalary() const = 0; // Pure virtual function
    virtual void display() const {
        std::cout << name << " earns $" << calculateSalary() << " per month.\n";
    }
    virtual ~Employee() {}
};

class FullTimeEmployee : public Employee {
};

// Define class PartTimeEmployee : public FullTimeEmployee {}

int main() {
    Employee* employees[] = {
        new FullTimeEmployee("Alice", 5000),
        new PartTimeEmployee("Bob", 20, 25),
        new PartTimeEmployee("Charlie", 30, 30)
    };

    for (Employee* emp : employees) {
        emp->display();
        delete emp;
    }

    return 0;
}

//### **Expected Output**
//Alice earns $5000 per month.
//Bob earns $500 per month.
//Charlie earns $900 per month.