// Student.hpp

#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <iostream>
#include <string>

class Student {
public:
    // Default Constructor (Optional, but good practice to include)
    Student();

    // Parameterized Constructor
    Student(int id, const std::string& name, const std::string& major);

    // Getters (Accessors)
    int getId() const;
    std::string getName() const;
    std::string getMajor() const;

    // Setters (Mutators) - If you need to modify student data
    void setId(int id);
    void setName(const std::string& name);
    void setMajor(const std::string& major);

private:
    int id;
    std::string name;
    std::string major;
};

// Implementation (Student.cpp) - You can put this in a separate .cpp file
// or inline in the .hpp file (less common for larger classes)

// Default Constructor
Student::Student() : id(0), name(""), major("") {}

// Parameterized Constructor
Student::Student(int id, const std::string& name, const std::string& major) : id(id), name(name), major(major) {}

// Getters
int Student::getId() const { return id; }
std::string Student::getName() const { return name; }
std::string Student::getMajor() const { return major; }

// Setters
void Student::setId(int id) { this->id = id; }
void Student::setName(const std::string& name) { this->name = name; }
void Student::setMajor(const std::string& major) { this->major = major; }

#endif // STUDENT_HPP