#include <iostream>

// Node class for double linked list
class Node {
public:
    int data;
    Node* next;
    Node* prev; // Reintroduced for double linking

    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

// DoubleLinkedList class
class DoubleLinkedList {
private:
    Node* head;

public:
    DoubleLinkedList() : head(nullptr) {}

    // Method to insert a node at the beginning of the list
    void insertAtBeginning(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        }
        head = newNode;
    }

    // Method to insert a node at the end of the list
    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    // Method to insert a node at a specified location
    void insertAtLocation(int data, int position) {
        if (position <= 0) {
            std::cerr << "Invalid position\n";
            return;
        }

        Node* newNode = new Node(data);
        if (position == 1) {
            newNode->next = head;
            if (head != nullptr) {
                head->prev = newNode;
            }
            head = newNode;
        } else {
            Node* temp = head;
            for (int i = 1; temp != nullptr && i < position - 1; i++) {
                temp = temp->next;
            }

            if (temp == nullptr) {
                std::cerr << "Invalid position\n";
                return;
            }

            newNode->next = temp->next;
            newNode->prev = temp;
            if (temp->next != nullptr) {
                temp->next->prev = newNode;
            }
            temp->next = newNode;
        }
    }

    // Method to update a node's value by position
    void update(int position, int newData) {
        Node* temp = head;
        for (int i = 1; temp != nullptr && i < position; i++) {
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
        // Special case
        if (head == nullptr) return;

        Node* temp = head; // Traversal

        if (position == 1) {
            head = temp->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            delete temp;
            return;
        }

        for (int i = 1; temp != nullptr && i < position; i++) {
            temp = temp->next;
        }
        // Special case tails or you do st wrong
        if (temp == nullptr) {
            std::cerr << "Invalid position\n";
            return;
        }
        
        if (temp->next != nullptr) {
            temp->next->prev = temp->prev;
        }
        if (temp->prev != nullptr) {
            temp->prev->next = temp->next;
        }

        delete temp;
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
            if (temp->data == value) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    // Method to display the contents of the list
    void displayList() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << "\n";
    }
};

int main() {
    // Example usage of the enhanced DoubleLinkedList class
    DoubleLinkedList dll;

    // Your test cases here
    // Use insert, update, delete, isEmpty, clear, search methods to demonstrate their functionality.
    std::cout << "Inserting at the end: 1, 2, 3" << std::endl;
    dll.insertAtEnd(1);
    dll.insertAtEnd(2);
    dll.insertAtEnd(3);
    dll.displayList();  // Expected Output: 1 2 3

    std::cout << "Inserting at the beginning: 0" << std::endl;
    dll.insertAtBeginning(0);
    dll.displayList();  // Expected Output: 0 1 2 3

    std::cout << "Updating value at position 3 to 9" << std::endl;
    dll.update(3, 9);
    dll.displayList();  // Expected Output: 0 1 9 2 3

    std::cout << "Deleting node at position 4" << std::endl;
    dll.deleteByPosition(4);
    dll.displayList();  // Expected Output: 0 1 9 3

    std::cout << "Is the list empty? " << (dll.isEmpty() ? "Yes" : "No") << std::endl;
    // Expected Output: No

    std::cout << "Searching for value 3 in the list: " << (dll.search(3) ? "Found" : "Not Found") << std::endl;
    // Expected Output: Found

    std::cout << "Searching for value 5 in the list: " << (dll.search(5) ? "Found" : "Not Found") << std::endl;
    // Expected Output: Not Found

    std::cout << "Clearing the list." << std::endl;
    dll.clear();
    dll.displayList();  // Expected Output: (nothing)

    std::cout << "Is the list empty now? " << (dll.isEmpty() ? "Yes" : "No") << std::endl;
    // Expected Output: Yes
    return 0;
}
