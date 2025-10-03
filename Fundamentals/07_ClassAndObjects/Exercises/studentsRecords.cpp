// Exercise 3: Student Record with Nested Structures
// Create a program using structures to manage student records:
//
// Requirements:
//
// Define a Date structure with members: day, month, year
// Define a Student structure containing:
// name (string)
// studentID (int)
// birthDate (Date structure)
// gpa (double)
// Implement a constructor for the Student structure
// Write functions that:
// Accept a const reference to a Student and display all information
// Accept a Student by reference and update the GPA
// Return a Student structure with user-provided data
// Test your program by:
//
// Creating an array of at least 3 students
// Displaying all student information
// Updating GPAs for specific students

#include <iostream>
#include <string>
using namespace std;

struct Date {
    int day;
    int month;
    int year;

    Date(int d = 1, int m = 1, int y = 2000):day(d), month(m), year(y) {}
};

struct Student {
    string name;
    int studentID;
    Date birthday;
    double gpa;

    Student(string s = "", int id=0, Date bd = Date(), double g = 0.0):name(s), studentID(id), birthday(bd), gpa(g) {}
};

// Write functions that:
// Accept a const reference to a Student and display all information
void display(const Student & s) {
    cout << "Student Information:" << endl;
    cout << "Name: " << s.name << endl;
    cout << "Student ID: " << s.studentID << endl;
    cout << "Birthday:" << s.birthday.month << "/" << s.birthday.day<< "/" <<s.birthday.year << endl;
    cout << "GPA: " << s.gpa << endl;
}

// Accept a Student by reference and update the GPA
void updateGpa(Student & s, double newGpa) {
    if (newGpa >= 0.0 && newGpa <= 4.0) {
        s.gpa = newGpa;
        cout << "Student GPA: " << s.gpa << endl;
    } else {
        cout << "Error update GPA" << endl;
    }
}

// Return a Student structure with user-provided data


// Creating an array of at least 3 students
// Displaying all student information
// Updating GPAs for specific students

int main() {
    const int NUM_STUDENTS = 3;
    Student students[NUM_STUDENTS];
    students[0] = Student("John", 1999, Date(15,3,2006), 3.0);
    students[1] = Student("Jane", 2001, Date(22,7,2002), 4.0);
    students[2] = Student("Truc", 1888, Date(15,3,2006), 3.0);

    for (const auto & student : students) {
        display(student);
    }

    updateGpa(students[2], 4.0);
    display(students[2]);

    return 0;
}