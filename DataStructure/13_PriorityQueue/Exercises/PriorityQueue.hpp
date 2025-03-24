// PriorityQueue.hpp

#ifndef PRIORITYQUEUE_HPP
#define PRIORITYQUEUE_HPP

#include <iostream>
#include <stdexcept>

template <class ItemType>
class Node
{
public:
    ItemType data;
    int priority;
    Node* next;

    Node(const ItemType& dataValue, int priorityValue) : data(dataValue), priority(priorityValue), next(nullptr)
    {
    }
};

template <class ItemType>
class PriorityQueue
{
private:
    Node<ItemType>* front; // Points to the front of the queue
    int itemCount;

public:
    // Constructor
    PriorityQueue() : front(nullptr), itemCount(0)
    {
    }

    // Destructor to clean up the allocated memory
    ~PriorityQueue()
    {
        while (!isEmpty())
        {
            dequeue();
        }
    }

    // Check if the priority queue is empty
    bool isEmpty() const;

    // Enqueue: Insert an item into the queue based on priority
    bool enqueue(const ItemType& newEntry, int priority);

    // Dequeue: Remove and return the highest-priority item
    bool dequeue();

    // Peek: Return the front item (highest-priority item) without removing it
    ItemType peekFront() const;

    // Get the number of items in the priority queue
    int getSize() const;
};

// Implementation of the PriorityQueue methods (can be in .cpp or inlined)

template <class ItemType>
bool PriorityQueue<ItemType>::isEmpty() const
{
    return front == nullptr;
}

template <class ItemType>
bool PriorityQueue<ItemType>::enqueue(const ItemType& newEntry, int priority)
{
    Node<ItemType>* newNode = new Node<ItemType>(newEntry, priority);
    if (isEmpty() || priority > front->priority)
    {
        // Insert at the front of the queue
        newNode->next = front;
        front = newNode;
    }
    else
    {
        // Find the appropriate position in the queue
        Node<ItemType>* prev = front;
        while (prev->next != nullptr && prev->next->priority >= priority)
        {
            prev = prev->next;
        }
        newNode->next = prev->next;
        prev->next = newNode;
    }
    itemCount++;
    return true;
}

template <class ItemType>
bool PriorityQueue<ItemType>::dequeue()
{
    if (isEmpty())
    {
        return false;
    }
    Node<ItemType>* nodeToDelete = front;
    front = front->next;
    delete nodeToDelete;
    itemCount--;
    return true;
}

template <class ItemType>
ItemType PriorityQueue<ItemType>::peekFront() const
{
    if (isEmpty())
    {
        throw std::runtime_error("Priority queue is empty.");
    }
    return front->data;
}

template <class ItemType>
int PriorityQueue<ItemType>::getSize() const
{
    return itemCount;
}

#endif // PRIORITYQUEUE_HPP