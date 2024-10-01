#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// Queue class
class Queue {
private:
    Node* front; // front of the queue
    Node* rear; // rear of the queue
public:
    // Constructor
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // Destructor
    ~Queue() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    // Enqueue function
    void enqueue(int data) {
        Node* newNode = new Node(data);
        if (rear == nullptr) {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    // Dequeue function
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        Node* temp = front;
        int data = front->data;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }

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
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(3);
    q.enqueue(2);
    q.enqueue(13);

    cout << "Front element is: " << q.peekFront() << endl;
    cout << "Removed element from queue: " << q.dequeue() << endl;
    cout << "New front element is: " << q.peekFront() << endl;

    return 0;
}
