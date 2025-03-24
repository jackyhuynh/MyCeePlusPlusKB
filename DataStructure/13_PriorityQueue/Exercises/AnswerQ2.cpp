#include <iostream>
#include <string>
#include "Student.hpp"
#include "Queue.hpp"
#include "PriorityQueue.hpp"

using namespace std;

// PriorityStudent Class for Exercise 2
class PriorityStudent : public Student {
public:
    int priority;

    PriorityStudent(int id, const string& name, const string& major, int priority)
        : Student(id, name, major), priority(priority) {}

    friend ostream& operator<<(ostream& os, const PriorityStudent& student) {
        os << student.getName() << " (ID: " << student.getId() << ", Priority: " << student.priority << ")";
        return os;
    }
};

int main() {
    cout << "Exercise #1:";
    Queue<Student> regQueue;

    // Add students to the queue
    Student john(101, "John", "CS");
    Student alice(102, "Alice", "EE");

    regQueue.enqueue(john);
    cout << "Student John (ID: 101) added to the registration queue.\n";

    regQueue.enqueue(alice);
    cout << "Student Alice (ID: 102) added to the registration queue.\n";

    // Process students in FIFO order
    cout << "Processing registration for " << regQueue.peekFront().getName() << " (ID: " << regQueue.peekFront().getId() << ").\n";
    regQueue.dequeue();

    cout << "Processing registration for " << regQueue.peekFront().getName() << " (ID: " << regQueue.peekFront().getId() << ").\n";
    regQueue.dequeue();

    cout << "Registration queue is now empty.\n";

    // Exercise 2: Priority Queue for Urgent Registrations
    cout<<"Exercise #2: Priority Queue for Urgent Registrations\n";

    PriorityQueue<PriorityStudent> priorityQueue;

    priorityQueue.enqueue(PriorityStudent(201, "Bob", "Math", 2), 2);
    priorityQueue.enqueue(PriorityStudent(202, "Alice", "Physics", 1), 1);
    priorityQueue.enqueue(PriorityStudent(203, "John", "Chem", 3), 3);

    cout << "Processing " << priorityQueue.peekFront() << " first due to high priority.\n";
    priorityQueue.dequeue();

    cout << "Processing " << priorityQueue.peekFront() << ".\n";
    priorityQueue.dequeue();

    cout << "Processing " << priorityQueue.peekFront() << ".\n";
    priorityQueue.dequeue();

    return 0;
}