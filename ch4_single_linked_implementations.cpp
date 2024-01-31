#include <iostream>

// Updated Node class for single linked list
class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

// SingleLinkedList class
class SingleLinkedList {
private:
    Node* head;

public:
    SingleLinkedList() : head(nullptr) {}

    // Method to insert a node at the beginning of the list
    void insertAtBeginning(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    // Method to insert a node at the end of the list
    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Method to update a node's value by position
    void update(int position, int newData) {
        Node* temp = head;
        for (int i = 1; i < position && temp != nullptr; i++) {
            temp = temp->next;
        }
        if (temp != nullptr) {
            temp->data = newData;
        } else {
            std::cerr << "Invalid position\n";
        }
    }

    // Method to delete a node by position
    void deleteByPosition(int position) {
        if (head == nullptr) return; // Empty list

        Node* temp = head;
        if (position == 1) {
            head = head->next;
            delete temp;
            return;
        }

        for (int i = 1; temp != nullptr && i < position - 1; i++) {
            temp = temp->next;
        }

        if (temp == nullptr || temp->next == nullptr) {
            std::cerr << "Invalid position\n";
            return;
        }

        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        delete nodeToDelete;
    }

    // Method to check if the list is empty
    bool isEmpty() const {
        return head == nullptr;
    }

    // Method to clear the list
    void clear() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }

    // Method to search for a value in the list
    bool search(int value) const {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == value) return true;
            temp = temp->next;
        }
        return false;
    }

    // Method to display the contents of the list
    void displayList() {
        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

#include <iostream>

// Place the SingleLinkedList class definition here

int main() {
    SingleLinkedList sll;

    std::cout << "Inserting at the end: 1, 2, 3" << std::endl;
    sll.insertAtEnd(1);
    sll.insertAtEnd(2);
    sll.insertAtEnd(3);
    sll.displayList();  // Expected Output: 1 2 3

    std::cout << "Inserting at the beginning: 0" << std::endl;
    sll.insertAtBeginning(0);
    sll.displayList();  // Expected Output: 0 1 2 3

    std::cout << "Updating value at position 3 to 9" << std::endl;
    sll.update(3, 9);
    sll.displayList();  // Expected Output: 0 1 9 2 3

    std::cout << "Deleting node at position 4" << std::endl;
    sll.deleteByPosition(4);
    sll.displayList();  // Expected Output: 0 1 9 3

    std::cout << "Is the list empty? " << (sll.isEmpty() ? "Yes" : "No") << std::endl;
    // Expected Output: No

    std::cout << "Searching for value 3 in the list: " << (sll.search(3) ? "Found" : "Not Found") << std::endl;
    // Expected Output: Found

    std::cout << "Searching for value 5 in the list: " << (sll.search(5) ? "Found" : "Not Found") << std::endl;
    // Expected Output: Not Found

    std::cout << "Clearing the list." << std::endl;
    sll.clear();
    sll.displayList();  // Expected Output: (nothing)

    std::cout << "Is the list empty now? " << (sll.isEmpty() ? "Yes" : "No") << std::endl;
    // Expected Output: Yes

    return 0;
}
