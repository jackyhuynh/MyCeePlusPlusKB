#include <iostream>
#include <queue>
#include <list>
#include <vector>
#include <chrono>
#include <random>
#include <stdexcept>
#include "PriorityQueue.hpp"
#include "Student.hpp"

int main() {
    int numOperations = 10000;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 100);

    // 1. Test your upgraded PriorityQueue
    {
        PriorityQueue<Student> myQueue;
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < numOperations; ++i) {
            myQueue.enqueue(Student(i, "Student" + std::to_string(i), "Major" + std::to_string(i)), dist(gen));
        }
        while (!myQueue.isEmpty()) {
            myQueue.dequeue();
        }
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        std::cout << "My PriorityQueue (upgraded): " << duration.count() << " seconds\n";
    }

    // 2. Test std::priority_queue
    {
        auto comparator = [](const Student& a, const Student& b) { return a.getId() < b.getId(); }; // Store the lambda
        std::priority_queue<Student, std::vector<Student>, decltype(comparator)> stdQueue(comparator); // use decltype

        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < 10000; ++i) {
            stdQueue.push(Student(i, "Student" + std::to_string(i), "Major" + std::to_string(i)));
        }
        while (!stdQueue.empty()) {
            stdQueue.pop();
        }
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        std::cout << "std::priority_queue: " << duration.count() << " seconds\n";

    }

    // 3. Test std::list (for basic queue)
    {
        std::list<Student> stdList;
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < numOperations; ++i) {
            stdList.push_back(Student(i, "Student" + std::to_string(i), "Major" + std::to_string(i)));
        }
        while (!stdList.empty()) {
            stdList.pop_front();
        }
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        std::cout << "std::list (basic queue): " << duration.count() << " seconds\n";
    }

    // 4. Test std::vector (for circular queue simulation)
    {
        std::vector<Student> stdVector(numOperations);
        int front = 0, rear = 0;
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < numOperations; ++i) {
            stdVector[rear] = Student(i, "Student" + std::to_string(i), "Major" + std::to_string(i));
            rear = (rear + 1) % numOperations;
        }
        for (int i = 0; i < numOperations; ++i) {
            front = (front + 1) % numOperations;
        }
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        std::cout << "std::vector (circular queue simulation): " << duration.count() << " seconds\n";
    }

    return 0;
}