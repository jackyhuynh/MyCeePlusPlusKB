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
    bool isEmpty() const
    {
        return front == nullptr;
    }

    // Enqueue: Insert an item into the queue based on priority
    bool enqueue(const ItemType& newEntry, int priority)
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

    // Dequeue: Remove and return the highest-priority item
    bool dequeue()
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

    // Peek: Return the front item (highest-priority item) without removing it
    ItemType peekFront() const
    {
        if (isEmpty())
        {
            throw std::runtime_error("Priority queue is empty.");
        }
        return front->data;
    }

    // Get the number of items in the priority queue
    int getSize() const
    {
        return itemCount;
    }
};

// Driver code to demonstrate the Priority Queue
int main()
{
    PriorityQueue<std::string> pq;

    pq.enqueue("Task A", 2);
    pq.enqueue("Task B", 5); // Highest priority
    pq.enqueue("Task C", 1);
    pq.enqueue("Task D", 4);

    std::cout << "Priority Queue Front: " << pq.peekFront() << std::endl;

    pq.dequeue();
    std::cout << "After Dequeue, Front: " << pq.peekFront() << std::endl;

    pq.dequeue();
    std::cout << "After Dequeue, Front: " << pq.peekFront() << std::endl;

    return 0;
}
