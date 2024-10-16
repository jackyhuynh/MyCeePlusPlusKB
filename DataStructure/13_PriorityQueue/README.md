### Priority Queue Implementation Using Raw Pointers

```cpp
#include <iostream>
#include <stdexcept>

template <class ItemType>
class Node {
public:
    ItemType data;
    int priority;
    Node* next;

    Node(const ItemType& dataValue, int priorityValue) : data(dataValue), priority(priorityValue), next(nullptr) {}
};

template <class ItemType>
class PriorityQueue {
private:
    Node<ItemType>* front;  // Points to the front of the queue
    int itemCount;

public:
    // Constructor
    PriorityQueue() : front(nullptr), itemCount(0) {}

    // Destructor to clean up the allocated memory
    ~PriorityQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    // Check if the priority queue is empty
    bool isEmpty() const {
        return front == nullptr;
    }

    // Enqueue: Insert an item into the queue based on priority
    bool enqueue(const ItemType& newEntry, int priority) {
        Node<ItemType>* newNode = new Node<ItemType>(newEntry, priority);
        if (isEmpty() || priority > front->priority) {
            // Insert at the front of the queue
            newNode->next = front;
            front = newNode;
        } else {
            // Find the appropriate position in the queue
            Node<ItemType>* prev = front;
            while (prev->next != nullptr && prev->next->priority >= priority) {
                prev = prev->next;
            }
            newNode->next = prev->next;
            prev->next = newNode;
        }
        itemCount++;
        return true;
    }

    // Dequeue: Remove and return the highest-priority item
    bool dequeue() {
        if (isEmpty()) {
            return false;
        }
        Node<ItemType>* nodeToDelete = front;
        front = front->next;
        delete nodeToDelete;
        itemCount--;
        return true;
    }

    // Peek: Return the front item (highest-priority item) without removing it
    ItemType peekFront() const {
        if (isEmpty()) {
            throw std::runtime_error("Priority queue is empty.");
        }
        return front->data;
    }

    // Get the number of items in the priority queue
    int getSize() const {
        return itemCount;
    }
};

// Driver code to demonstrate the Priority Queue
int main() {
    PriorityQueue<std::string> pq;

    pq.enqueue("Task A", 2);
    pq.enqueue("Task B", 5);  // Highest priority
    pq.enqueue("Task C", 1);
    pq.enqueue("Task D", 4);

    std::cout << "Priority Queue Front: " << pq.peekFront() << std::endl;

    pq.dequeue();
    std::cout << "After Dequeue, Front: " << pq.peekFront() << std::endl;

    pq.dequeue();
    std::cout << "After Dequeue, Front: " << pq.peekFront() << std::endl;

    return 0;
}
```

### Key Components of the Priority Queue Implementation:

1. **Node Class**:
    - Each node stores the item (`data`) and its associated `priority`. It also contains a `next` pointer to the next
      node in the queue.

2. **PriorityQueue Class**:
    - **enqueue(const ItemType& newEntry, int priority)**: Adds a new entry into the priority queue based on its
      priority. The highest-priority item is always at the front.
    - **dequeue()**: Removes the highest-priority item from the queue.
    - **peekFront()**: Returns the highest-priority item without removing it.
    - **isEmpty()**: Checks whether the queue is empty.
    - **getSize()**: Returns the number of items currently in the queue.

### Example Output:

```bash
Priority Queue Front: Task B
After Dequeue, Front: Task D
After Dequeue, Front: Task A
```

### Explanation:

1. **Task B** is enqueued with the highest priority (5), so it is at the front of the queue.
2. After calling `dequeue()`, **Task D** becomes the front since it has the next highest priority (4).
3. After another `dequeue()`, **Task A** is now at the front with priority 2.

### Use Case:

A priority queue is useful in real-time scheduling systems, like an operating system where tasks with higher priority (
e.g., interrupts) need to be processed before lower-priority tasks. This implementation using raw pointers is
lightweight and dynamically adjusts as tasks are added or removed.