// Queue.hpp

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <deque>
#include <iostream>
#include <string>

template <class ItemType>
class Queue {
private:
    std::deque<ItemType> queue; // Use std::deque for efficiency

public:
    // Constructor
    Queue() {}

    // Destructor (std::deque handles memory management)
    ~Queue() {}

    // Check if the queue is empty
    bool isEmpty() const {
        return queue.empty();
    }

    // Enqueue: Add an item to the back of the queue
    void enqueue(const ItemType& item) {
        queue.push_back(item);
    }

    // Dequeue: Remove and return the front item
    ItemType dequeue() {
        if (isEmpty()) {
            throw std::runtime_error("Queue is empty");
        }
        ItemType frontItem = queue.front();
        queue.pop_front();
        return frontItem;
    }

    // Peek: Return the front item without removing it
    ItemType peekFront() const {
        if (isEmpty()) {
            throw std::runtime_error("Queue is empty");
        }
        return queue.front();
    }

    // Get the number of items in the queue
    int getSize() const {
        return queue.size();
    }
};

#endif // QUEUE_HPP