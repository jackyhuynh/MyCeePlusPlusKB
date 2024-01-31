#include <iostream>
using namespace std;

// Node class remains the same
class Node {
public:
    int data; // In a real priority queue, you might have a separate 'priority' field.
    Node* next;

    // Constructor
    Node(int data) : data(data), next(nullptr) {}
};

// Priority Queue class
class PriorityQueue {
private:
    Node* front; // front of the queue
public:
    // Constructor
    PriorityQueue() : front(nullptr) {}

    // Destructor
    ~PriorityQueue() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    // Enqueue function modified for priority insertion
    void enqueue(int data) {
        Node* newNode = new Node(data);
        // If the queue is empty or the new node's data is less than the front node's data,
        // insert the new node at the front
        if (front == nullptr || newNode->data < front->data) {
            newNode->next = front;
            front = newNode;
        } else {
            Node* temp = front;
            // Find the insertion point
            while (temp->next != nullptr && temp->next->data <= newNode->data) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    // Dequeue function remains the same (removes the front element)
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        Node* temp = front;
        int data = front->data;
        front = front->next;

        delete temp;
        return data;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Peek at the front of the queue
    int peekFront() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return front->data;
    }
};

int main() {
    PriorityQueue pq;
    pq.enqueue(30);
    pq.enqueue(10);
    pq.enqueue(20);
    pq.enqueue(5);
    pq.enqueue(30);
    pq.enqueue(-100);
    pq.enqueue(1);
    pq.enqueue(0);

    cout << "Front element (highest priority) is: " << pq.peekFront() << endl;
    cout << "Removed element from queue: " << pq.dequeue() << endl;
    cout << "New front element (next highest priority) is: " << pq.peekFront() << endl;

    return 0;
}
