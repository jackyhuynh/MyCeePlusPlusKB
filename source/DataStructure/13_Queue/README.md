# Chapter 13: Queues and Priority Queues

---

## **1. The ADT Queue**

A **Queue** is a data structure that follows the **First In, First Out (FIFO)** principle. New elements are added at the back of the queue, and elements are removed from the front. It's like a line of people waiting to be served—first come, first served.

### **Key Operations**:
- **enqueue**: Add an element to the back of the queue.
- **dequeue**: Remove the element at the front of the queue.
- **peekFront**: Access the element at the front without removing it.
- **isEmpty**: Check if the queue is empty.

### **Example Interface (C++):**

```cpp
template<class ItemType>
class QueueInterface {
public:
    virtual bool enqueue(const ItemType& newEntry) = 0;
    virtual bool dequeue() = 0;
    virtual ItemType peekFront() const = 0;
    virtual bool isEmpty() const = 0;
    virtual ~QueueInterface() {}
};
```

### **Use Case**:
Queues are used in real-world applications like job scheduling, printer queues, and customer service lines. For example, in a **print queue**, print jobs are processed in the order they are received.

---

## **2. Recognizing a Palindrome Using a Queue and Stack**

To recognize a palindrome, you can insert characters into both a **queue** and a **stack**. By comparing characters removed from the front of the queue and the top of the stack, you can determine if the word is the same forwards and backwards.

### **Use Case**:
This is used in text processing, such as checking if a user’s input string is a palindrome.

---

## **3. The ADT Priority Queue**

A **Priority Queue** organizes elements based on their priority rather than the order they were added. Elements with higher priority are dequeued first.

### **Key Operations**:
- **enqueue**: Add an element to the queue based on its priority.
- **dequeue**: Remove the element with the highest priority.
- **peekFront**: Access the element with the highest priority without removing it.
- **isEmpty**: Check if the queue is empty.

### **Example Interface (C++):**

```cpp
template<class ItemType>
class PriorityQueueInterface {
public:
    virtual bool enqueue(const ItemType& newEntry, int priority) = 0;
    virtual bool dequeue() = 0;
    virtual ItemType peekFront() const = 0;
    virtual bool isEmpty() const = 0;
    virtual ~PriorityQueueInterface() {}
};
```

### **Use Case**:
Priority queues are used in task scheduling where certain tasks must be executed first, like CPU scheduling or emergency room triage.

---

## **4. Application: Bank Simulation Using a Queue**

A **bank simulation** models customers arriving at a bank and waiting in a line to be served. The goal of the simulation is to approximate the average wait time for customers based on the number of tellers available.

### **Pseudocode for Simulation**:
1. Create a queue to represent the line of customers.
2. Add customer arrival events to the queue.
3. For each event:
   - If it is an arrival event, add the customer to the queue.
   - If it is a departure event, remove the customer from the queue.

### **Use Case**:
This type of simulation can be used by banks to determine how many tellers they need to minimize customer wait time.

---

## **5. Position-Oriented and Value-Oriented ADTs**

- **Position-Oriented ADTs**: These data structures (like **stack**, **queue**, and **list**) operate on elements based on their position.
- **Value-Oriented ADTs**: These data structures (like **sorted lists** and **priority queues**) organize elements based on their values.

### **Comparison of Stack and Queue**:
- **Stack**: Operates on a **Last In, First Out (LIFO)** basis, with `push` and `pop` operations.
- **Queue**: Operates on a **First In, First Out (FIFO)** basis, with `enqueue` and `dequeue` operations.

---

## **6. Code Example: Queue Implementation Using Pointers**

```cpp
template<class ItemType>
class Node {
public:
    ItemType data;
    Node* next;

    Node(ItemType dataValue) : data(dataValue), next(nullptr) {}
};

template<class ItemType>
class LinkedQueue : public QueueInterface<ItemType> {
private:
    Node<ItemType>* front;
    Node<ItemType>* back;
    int itemCount;

public:
    LinkedQueue() : front(nullptr), back(nullptr), itemCount(0) {}

    bool enqueue(const ItemType& newEntry) override {
        Node<ItemType>* newNode = new Node<ItemType>(newEntry);
        if (isEmpty()) {
            front = newNode;
        } else {
            back->next = newNode;
        }
        back = newNode;
        itemCount++;
        return true;
    }

    bool dequeue() override {
        if (!isEmpty()) {
            Node<ItemType>* nodeToDelete = front;
            front = front->next;
            delete nodeToDelete;
            itemCount--;
            if (isEmpty()) {
                back = nullptr;
            }
            return true;
        }
        return false;
    }

    ItemType peekFront() const override {
        if (!isEmpty()) {
            return front->data;
        } else {
            throw std::runtime_error("Queue is empty");
        }
    }

    bool isEmpty() const override {
        return itemCount == 0;
    }

    ~LinkedQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};
```

### **Use Case**:
This linked queue implementation can be used in real-time systems where dynamic memory allocation is necessary, such as managing network requests or task processing.

---

## **Conclusion**

- **Queues** are useful when processing tasks in order of their arrival, while **priority queues** allow processing tasks based on their priority.
- Both are fundamental in various real-world systems, such as simulations, operating systems, and real-time processing environments.

---

This summary provides an overview of the ADT queue and priority queue, code examples for implementing a queue with pointers, and practical use cases.