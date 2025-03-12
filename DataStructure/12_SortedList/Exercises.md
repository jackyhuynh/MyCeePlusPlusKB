# Exercises

## First Iteration:

```cpp
#include <iostream>
#include <string>

struct Student {
    int id;
    std::string name;
    double mathGrade;
    double readingGrade;
    double scienceGrade;
    double avgGrade;

    Student(int id, const std::string& name, double math, double reading, double science)
        : id(id), name(name), mathGrade(math), readingGrade(reading), scienceGrade(science) {
        updateAvgGrade();
    }

    void updateAvgGrade() {
        avgGrade = (mathGrade + readingGrade + scienceGrade) / 3.0;
    }

    void updateMathGrade(double grade) {
        mathGrade = grade;
        updateAvgGrade();
    }

    void updateReadingGrade(double grade) {
        readingGrade = grade;
        updateAvgGrade();
    }

    void updateScienceGrade(double grade) {
        scienceGrade = grade;
        updateAvgGrade();
    }

    void display() const {
        std::cout << "ID: " << id << ", Name: " << name << ", Math: " << mathGrade
                  << ", Reading: " << readingGrade << ", Science: " << scienceGrade
                  << ", Avg: " << avgGrade << std::endl;
    }
};

struct Node {
    Student student;
    Node* next;

    Node(const Student& student) : student(student), next(nullptr) {}
};

class SortedLinkedList {
private:
    Node* head;

public:
    SortedLinkedList() : head(nullptr) {}

    ~SortedLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    void insert(const Student& student) {
        Node* newNode = new Node(student);

        if (head == nullptr || student.avgGrade > head->student.avgGrade) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr && current->next->student.avgGrade > student.avgGrade) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    void displayList() const {
        Node* current = head;
        while (current != nullptr) {
            current->student.display();
            current = current->next;
        }
    }

    void updateStudentGrade(int studentId, char subject, double newGrade) {
        Node* current = head;
        while (current != nullptr) {
            if (current->student.id == studentId) {
                switch (subject) {
                    case 'M':
                        current->student.updateMathGrade(newGrade);
                        break;
                    case 'R':
                        current->student.updateReadingGrade(newGrade);
                        break;
                    case 'S':
                        current->student.updateScienceGrade(newGrade);
                        break;
                    default:
                        std::cout << "Invalid subject." << std::endl;
                        return;
                }
                // Re-sort the list since the grade has changed.
                reSort();
                return;
            }
            current = current->next;
        }
        std::cout << "Student not found." << std::endl;
    }

    void reSort()
    {
        std::vector<Student> students;
        Node* current = head;
        while(current != nullptr)
        {
            students.push_back(current->student);
            current = current->next;
        }
        head = nullptr;
        for(const auto& student : students)
        {
            insert(student);
        }
    }

};

int main() {
    SortedLinkedList studentList;

    studentList.insert(Student(1, "Alice", 90.0, 85.0, 92.0));
    studentList.insert(Student(2, "Bob", 78.0, 95.0, 88.0));
    studentList.insert(Student(3, "Charlie", 95.0, 90.0, 80.0));

    std::cout << "Initial Student List:" << std::endl;
    studentList.displayList();

    std::cout << "\nUpdating Alice's Math Grade to 98.0:" << std::endl;
    studentList.updateStudentGrade(1, 'M', 98.0);
    studentList.displayList();

    std::cout << "\nUpdating Bob's Reading Grade to 80.0:" << std::endl;
    studentList.updateStudentGrade(2, 'R', 80.0);
    studentList.displayList();

    std::cout << "\nUpdating Charlie's Science Grade to 99.0:" << std::endl;
    studentList.updateStudentGrade(3, 'S', 99.0);
    studentList.displayList();

    return 0;
}
```

**Key improvements and explanations:**

1.  **`Student` Struct:**
    * Includes `mathGrade`, `readingGrade`, and `scienceGrade` as `double` for accurate average calculation.
    * `updateAvgGrade()` function is called whenever a grade is updated, ensuring the average is always current.
    * `updateMathGrade`, `updateReadingGrade`, and `updateScienceGrade` functions for updating specific grades.
    * `display()` function for clean output.

2.  **`SortedLinkedList` Class:**
    * `insert()` function now correctly inserts students based on their `avgGrade` in descending order (highest average first).
    * `updateStudentGrade()` function. Finds the student by ID, updates the grade, and calls `reSort()`.
    * `reSort()` function. This is the most important part of the update. Because just changing the average does not change the list's order, we must resort. To do this, we copy the students into a vector. Then we clear the list, and then we insert the students back into the list. This will resort the list.
    * `displayList()` function iterates through the list and displays each student's information.
    * Destructor `~SortedLinkedList()` to prevent memory leaks.

3.  **Main Function:**
    * Demonstrates how to create and populate the sorted linked list.
    * Shows how to update student grades and observe the list's re-sorting.
    * Provides example student data.

4.  **Clarity and Readability:**
    * Added comments to explain the code's logic.
    * Used descriptive variable names.
    * Formatted the code for better readability.

5.  **Subject Code:**
    * The update function now takes a char to designate the subject to be updated.

This improved version addresses the requirements of maintaining a sorted linked list of students based on their average grades, with the ability to update individual grades and re-sort the list.

## Second Iteration:

**This is not efficient, why I need to resort if I only update one person, is there any robust way.**

You are absolutely correct. The `reSort()` method, while functional, is highly inefficient, especially for large lists. It requires traversing the entire list, copying data, clearing the list, and re-inserting everything, even when only one student's grade changes.

Here's a more efficient and robust approach that avoids a full re-sort:

```cpp
#include <iostream>
#include <string>

// ... (Student and Node structs remain the same) ...

class SortedLinkedList {
private:
    Node* head;

public:
    // ... (Constructor, destructor, insert(), and displayList() remain the same) ...

    void updateStudentGrade(int studentId, char subject, double newGrade) {
        Node* current = head;
        Node* previous = nullptr; // Track the previous node
        while (current != nullptr) {
            if (current->student.id == studentId) {
                double oldAvg = current->student.avgGrade; // store the old average.
                switch (subject) {
                    case 'M':
                        current->student.updateMathGrade(newGrade);
                        break;
                    case 'R':
                        current->student.updateReadingGrade(newGrade);
                        break;
                    case 'S':
                        current->student.updateScienceGrade(newGrade);
                        break;
                    default:
                        std::cout << "Invalid subject." << std::endl;
                        return;
                }

                if (current->student.avgGrade != oldAvg) { // Only re-sort if the average changed
                    // Remove the node from its current position
                    if (previous == nullptr) {
                        head = current->next; // If it's the head
                    } else {
                        previous->next = current->next;
                    }

                    // Re-insert the node in the correct sorted position
                    insert(current->student);
                    delete current; // delete the old node, insert creates a new node.
                }

                return;
            }
            previous = current;
            current = current->next;
        }
        std::cout << "Student not found." << std::endl;
    }
};

// ... (main function remains the same) ...
```

**Key improvements:**

1.  **Tracking the Previous Node:**
    * The `previous` pointer is introduced to keep track of the node before the current node. This is crucial for removing a node from its current position in the linked list.

2.  **Removing and Re-inserting:**
    * If the student's average grade has changed after the update, the node is removed from its current position.
    * The `insert()` function is then used to re-insert the node into the correct sorted position based on the updated average grade.
    * The original node that was removed is deleted, to avoid memory leaks. The insert function creates a new node.

3.  **Efficiency:**
    * This approach is much more efficient because it only modifies the list around the node that was updated.
    * It avoids a full re-sort of the entire list.
    * It only resorts if the grade actually changed.

4.  **Robustness:**
    * Handles the case where the updated node was the head of the list.
    * Correctly updates the `next` pointers to maintain the list's integrity.
    * Only resorts when needed.

This revised `updateStudentGrade()` function is significantly more efficient and robust, providing a practical solution for maintaining a sorted linked list of students based on their average grades.

## Third Iteration:

**There is 2 task: 1- Can you make the most efficient of this application 2 - Rewrite the students grading system using any C++ std library.**

Absolutely. Let's tackle both tasks:

**1. Most Efficient Sorted Linked List**

The previous solution was already a significant improvement. To further optimize, we can focus on minimizing unnecessary operations and memory allocations.

```cpp
#include <iostream>
#include <string>

struct Student {
    int id;
    std::string name;
    double mathGrade;
    double readingGrade;
    double scienceGrade;
    double avgGrade;

    Student(int id, const std::string& name, double math, double reading, double science)
        : id(id), name(name), mathGrade(math), readingGrade(reading), scienceGrade(science) {
        updateAvgGrade();
    }

    void updateAvgGrade() {
        avgGrade = (mathGrade + readingGrade + scienceGrade) / 3.0;
    }

    void updateMathGrade(double grade) {
        mathGrade = grade;
        updateAvgGrade();
    }

    void updateReadingGrade(double grade) {
        readingGrade = grade;
        updateAvgGrade();
    }

    void updateScienceGrade(double grade) {
        scienceGrade = grade;
        updateAvgGrade();
    }

    void display() const {
        std::cout << "ID: " << id << ", Name: " << name << ", Math: " << mathGrade
                  << ", Reading: " << readingGrade << ", Science: " << scienceGrade
                  << ", Avg: " << avgGrade << std::endl;
    }
};

struct Node {
    Student student;
    Node* next;

    Node(const Student& student) : student(student), next(nullptr) {}
};

class SortedLinkedList {
private:
    Node* head;

public:
    SortedLinkedList() : head(nullptr) {}

    ~SortedLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    void insert(Node* newNode) { // insert now accepts a Node*
        if (head == nullptr || newNode->student.avgGrade > head->student.avgGrade) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr && current->next->student.avgGrade > newNode->student.avgGrade) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    void insert(const Student& student) { // Overloaded insert for student object.
        Node* newNode = new Node(student);
        insert(newNode);
    }

    void displayList() const {
        Node* current = head;
        while (current != nullptr) {
            current->student.display();
            current = current->next;
        }
    }

    void updateStudentGrade(int studentId, char subject, double newGrade) {
        Node* current = head;
        Node* previous = nullptr;
        while (current != nullptr) {
            if (current->student.id == studentId) {
                double oldAvg = current->student.avgGrade;
                switch (subject) {
                    case 'M':
                        current->student.updateMathGrade(newGrade);
                        break;
                    case 'R':
                        current->student.updateReadingGrade(newGrade);
                        break;
                    case 'S':
                        current->student.updateScienceGrade(newGrade);
                        break;
                    default:
                        std::cout << "Invalid subject." << std::endl;
                        return;
                }

                if (current->student.avgGrade != oldAvg) {
                    if (previous == nullptr) {
                        head = current->next;
                    } else {
                        previous->next = current->next;
                    }
                    Node* temp = current; //store current Node.
                    current = current->next; //advance current to avoid infinite loop.
                    temp->next = nullptr; //remove the node's next pointer.
                    insert(temp); // reinsert the node.
                    return;
                }
                return; // Return if no average change.
            }
            previous = current;
            current = current->next;
        }
        std::cout << "Student not found." << std::endl;
    }
};

int main() {
    // ... (main function remains the same) ...
}
```

**Efficiency Improvements:**

* **Direct Node Insertion:** The `insert(Node* newNode)` function now directly accepts a `Node*`, avoiding unnecessary node creation in the `updateStudentGrade()` function. This saves memory allocation and deallocation.
* **Reduced Node Operations:** the current Node is directly moved into the correct place, avoiding the creation and deletion of a new node.
* **Early Return:** The `updateStudentGrade` function returns immediately if the average grade hasn't changed, preventing unnecessary re-insertion.

**2. Using C++ Standard Library**

For the grading system, we can leverage `std::vector` and `std::map` for efficient data management.

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

struct Student {
    int id;
    std::string name;
    std::map<std::string, double> grades; // Using map for grades
    double avgGrade;

    Student(int id, const std::string& name) : id(id), name(name), avgGrade(0.0) {}

    void updateGrade(const std::string& subject, double grade) {
        grades[subject] = grade;
        updateAvgGrade();
    }

    void updateAvgGrade() {
        if (grades.empty()) {
            avgGrade = 0.0;
            return;
        }
        double sum = 0.0;
        for (const auto& pair : grades) {
            sum += pair.second;
        }
        avgGrade = sum / grades.size();
    }

    void display() const {
        std::cout << "ID: " << id << ", Name: " << name << ", Avg: " << avgGrade << std::endl;
        for (const auto& pair : grades) {
            std::cout << "  " << pair.first << ": " << pair.second << std::endl;
        }
    }
};

int main() {
    std::vector<Student> students;

    students.emplace_back(1, "Alice");
    students.emplace_back(2, "Bob");
    students.emplace_back(3, "Charlie");

    students[0].updateGrade("Math", 90.0);
    students[0].updateGrade("Reading", 85.0);
    students[0].updateGrade("Science", 92.0);

    students[1].updateGrade("Math", 78.0);
    students[1].updateGrade("Reading", 95.0);
    students[1].updateGrade("Science", 88.0);

    students[2].updateGrade("Math", 95.0);
    students[2].updateGrade("Reading", 90.0);
    students[2].updateGrade("Science", 80.0);

    std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.avgGrade > b.avgGrade;
    });

    for (const auto& student : students) {
        student.display();
    }

    return 0;
}
```

**Standard Library Advantages:**

* **`std::vector`:** Provides dynamic resizing and efficient storage of students.
* **`std::map`:** Stores grades with subject names as keys, allowing for flexible grading systems.
* **`std::sort`:** Efficiently sorts students based on their average grades.
* **Readability and Maintainability:** The code is more concise and easier to understand.
* **Flexibility:** Easily add or remove subjects without changing the core data structure.

## Fourth Iteration:

Yes, let's add timing mechanisms to both solutions to compare their performance. We'll use `std::chrono` for accurate timing.

**1. Timing the Optimized Linked List Solution**

```cpp
#include <iostream>
#include <string>
#include <chrono>
#include <random>

// ... (Student and Node structs and SortedLinkedList class as in the optimized version) ...

int main() {
    SortedLinkedList studentList;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 100.0);

    // Generate a large number of students with random grades
    int numStudents = 10000;
    for (int i = 0; i < numStudents; ++i) {
        studentList.insert(Student(i, "Student" + std::to_string(i), dis(gen), dis(gen), dis(gen)));
    }

    // Time the update operations
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 1000; ++i) {
        int studentId = gen() % numStudents;
        char subject = "MRS"[gen() % 3];
        double newGrade = dis(gen);
        studentList.updateStudentGrade(studentId, subject, newGrade);
    }
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

    std::cout << "Optimized Linked List Update Time: " << duration.count() << " ms" << std::endl;

    return 0;
}
```

**2. Timing the Standard Library Solution**

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <chrono>
#include <random>

// ... (Student struct as in the standard library version) ...

int main() {
    std::vector<Student> students;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 100.0);

    // Generate a large number of students with random grades
    int numStudents = 10000;
    for (int i = 0; i < numStudents; ++i) {
        students.emplace_back(i, "Student" + std::to_string(i));
        students[i].updateGrade("Math", dis(gen));
        students[i].updateGrade("Reading", dis(gen));
        students[i].updateGrade("Science", dis(gen));
    }

    // Time the update and sort operations
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 1000; ++i) {
        int studentId = gen() % numStudents;
        char subject = "MRS"[gen() % 3];
        double newGrade = dis(gen);
        std::string subjectStr(1, subject); //convert char to string.
        students[studentId].updateGrade(subjectStr, newGrade);
        std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
            return a.avgGrade > b.avgGrade;
        });
    }
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

    std::cout << "Standard Library Update and Sort Time: " << duration.count() << " ms" << std::endl;

    return 0;
}
```

**Explanation of Timing:**

1.  **`std::chrono`:**
    * `std::chrono::high_resolution_clock::now()` captures the current time.
    * `std::chrono::duration_cast<std::chrono::milliseconds>()` converts the time difference to milliseconds.

2.  **Random Data:**
    * `std::random_device` and `std::mt19937` are used to generate random numbers for student IDs and grades.
    * `std::uniform_real_distribution` creates a distribution for generating random grades between 0 and 100.

3.  **Test Setup:**
    * Both tests generate a large number of students (e.g., 10,000).
    * A loop performs a large number of random grade updates (e.g., 1,000).
    * The total time taken for these updates is measured.
    * The sorting of the std::vector is included in the timing of the std library version, since it is required to keep the data sorted.

4.  **Comparison:**
    * Run both programs and compare the outputted times.
    * The faster time indicates the more efficient solution for the given test scenario.

**Important Notes:**

* The results can vary depending on your hardware and compiler.
* Increase the number of students and update operations for more accurate results.
* The standard library version's time includes the sorting time, which is significant. If you don't need the vector to be constantly sorted, the update time would be much faster.
* The linked list solution will have a greater advantage when there are many updates, but only a few changes to the sort order.
* The vector solution has a greater advantage when there are only a few updates, or if the vector must be completely sorted after every update.

