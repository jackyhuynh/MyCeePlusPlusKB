#include <iostream>

template<class ItemType>
class SortedListInterface {
public:
    virtual bool insertSorted(const ItemType& newEntry) = 0;
    virtual bool removeSorted(const ItemType& anEntry) = 0;
    virtual int getPosition(const ItemType& anEntry) const = 0;
    virtual ItemType getEntry(int position) const = 0;
    virtual bool isEmpty() const = 0;
    virtual int getLength() const = 0;
    virtual void clear() = 0;
};

// Node class definition
template<class ItemType>
class Node {
public:
    ItemType data;
    Node* next;

    Node(const ItemType& dataValue) : data(dataValue), next(nullptr) {}
};

// Sorted Linked List Implementation using pointers
template<class ItemType>
class LinkedSortedList : public SortedListInterface<ItemType> {
private:
    Node<ItemType>* head;
    int itemCount;

    // Private helper to find the node before the target value for insertion or removal
    Node<ItemType>* getNodeBefore(const ItemType& anEntry) const {
        Node<ItemType>* cur = head;
        Node<ItemType>* prev = nullptr;

        while (cur != nullptr && cur->data < anEntry) {
            prev = cur;
            cur = cur->next;
        }
        return prev;
    }

    // Private helper to get the node at a specific position
    Node<ItemType>* getNodeAt(int position) const {
        Node<ItemType>* cur = head;
        for (int i = 1; cur != nullptr && i < position; i++) {
            cur = cur->next;
        }
        return cur;
    }

public:
    LinkedSortedList() : head(nullptr), itemCount(0) {}

    // Inserts the newEntry in a sorted manner
    bool insertSorted(const ItemType& newEntry) override {
        Node<ItemType>* newNode = new Node<ItemType>(newEntry);
        Node<ItemType>* prev = getNodeBefore(newEntry);

        if (prev == nullptr) {  // Insert at the head
            newNode->next = head;
            head = newNode;
        } else {  // Insert in the middle or at the end
            newNode->next = prev->next;
            prev->next = newNode;
        }
        itemCount++;
        return true;
    }

    // Removes the first occurrence of anEntry
    bool removeSorted(const ItemType& anEntry) override {
        Node<ItemType>* prev = getNodeBefore(anEntry);
        Node<ItemType>* cur = nullptr;

        if (prev == nullptr) {  // anEntry might be at the head
            if (head != nullptr && head->data == anEntry) {
                cur = head;
                head = head->next;
            }
        } else if (prev->next != nullptr && prev->next->data == anEntry) {
            cur = prev->next;
            prev->next = cur->next;
        }

        if (cur != nullptr) {
            delete cur;
            itemCount--;
            return true;
        }
        return false;
    }

    // Returns the position of the first occurrence of anEntry
    int getPosition(const ItemType& anEntry) const override {
        Node<ItemType>* cur = head;
        int position = 1;
        while (cur != nullptr && cur->data < anEntry) {
            cur = cur->next;
            position++;
        }

        if (cur != nullptr && cur->data == anEntry) {
            return position;
        }
        return -1;  // Item not found
    }

    // Retrieves an entry at a specific position
    ItemType getEntry(int position) const override {
        if (position < 1 || position > itemCount) {
            throw std::out_of_range("Position out of range");
        }

        Node<ItemType>* node = getNodeAt(position);
        return node->data;
    }

    // Checks if the list is empty
    bool isEmpty() const override {
        return itemCount == 0;
    }

    // Returns the length of the list
    int getLength() const override {
        return itemCount;
    }

    // Clears the list
    void clear() override {
        Node<ItemType>* cur = head;
        while (cur != nullptr) {
            Node<ItemType>* toDelete = cur;
            cur = cur->next;
            delete toDelete;
        }
        head = nullptr;
        itemCount = 0;
    }

    // Destructor to ensure all memory is freed
    ~LinkedSortedList() {
        clear();
    }
};

// Driver to demonstrate the usage
int main() {
    LinkedSortedList<int> sortedList;
    
    sortedList.insertSorted(30);
    sortedList.insertSorted(10);
    sortedList.insertSorted(20);
    sortedList.insertSorted(40);

    std::cout << "List after insertions (should be sorted): ";
    for (int i = 1; i <= sortedList.getLength(); i++) {
        std::cout << sortedList.getEntry(i) << " ";
    }
    std::cout << std::endl;

    sortedList.removeSorted(20);
    std::cout << "List after removing 20: ";
    for (int i = 1; i <= sortedList.getLength(); i++) {
        std::cout << sortedList.getEntry(i) << " ";
    }
    std::cout << std::endl;

    std::cout << "Position of 30: " << sortedList.getPosition(30) << std::endl;

    return 0;
}
