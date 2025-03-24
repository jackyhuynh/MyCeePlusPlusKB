#include <iostream>
#include <string>
#include "PriorityQueue.hpp" // Include the header file

using namespace std;

class Student {
public:
    int id;
    string name;
    string major;

    Student(int id, const string& name, const string& major) : id(id), name(name), major(major) {}

    friend ostream& operator<<(ostream& os, const Student& student) {
        os << student.name << " (ID: " << student.id << ")";
        return os;
    }
};

int main() {
    // Test the PriorityQueue
    PriorityQueue<Student> studentQueue;

    // Enqueue some students with different priorities
    studentQueue.enqueue(Student(101, "Alice", "CS"), 3);
    studentQueue.enqueue(Student(102, "Bob", "EE"), 1);
    studentQueue.enqueue(Student(103, "Charlie", "ME"), 2);
    studentQueue.enqueue(Student(104, "David", "Bio"), 1); // Another high priority

    // Test isEmpty() and getSize()
    cout << "Is the queue empty? " << (studentQueue.isEmpty() ? "Yes" : "No") << endl;
    cout << "Queue size: " << studentQueue.getSize() << endl;

    // Test peekFront()
    cout << "Next student: " << studentQueue.peekFront() << endl;

    // Test dequeue()
    cout << "Processing: " << studentQueue.peekFront() << endl;
    studentQueue.dequeue();
    cout << "Queue size: " << studentQueue.getSize() << endl;
    cout << "Next student: " << studentQueue.peekFront() << endl;
    cout << "Processing: " << studentQueue.peekFront() << endl;
    studentQueue.dequeue();
    cout << "Queue size: " << studentQueue.getSize() << endl;
    cout << "Next student: " << studentQueue.peekFront() << endl;

    // Dequeue the rest
    while (!studentQueue.isEmpty()) {
        cout << "Processing: " << studentQueue.peekFront() << endl;
        studentQueue.dequeue();
    }

    // Test isEmpty() again
    cout << "Is the queue empty? " << (studentQueue.isEmpty() ? "Yes" : "No") << endl;
    cout << "Queue size: " << studentQueue.getSize() << endl;

    return 0;
}