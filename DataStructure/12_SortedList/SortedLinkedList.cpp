#include <iostream>

class SortedList {
private:
    struct Node {
        int data;
        Node* next;
        Node(int d) : data(d), next(nullptr) {}
    };
    Node* head;

public:
    SortedList() : head(nullptr) {}

    ~SortedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    void insert(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr || head->data >= value) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr && current->next->data < value) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }
    
    bool deleteByValue(int value) {
        if (head == nullptr) {
            return false;  // List is empty
        }

        // Special case: the node to delete is the head
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return true;
        }

        // Traverse the list to find the node to delete
        Node* current = head;
        while (current->next != nullptr && current->next->data != value) {
            current = current->next;
        }

        // If we found the node with the value
        if (current->next != nullptr && current->next->data == value) {
            Node* nodeToDelete = current->next;
            current->next = current->next->next;
            delete nodeToDelete;
            return true;
        }

        return false;  // Value not found
    }

    bool deleteByPosition(int position) {
        if (position < 1 || head == nullptr) {
            return false;  // Invalid position or empty list
        }

        // Special case: deleting the head
        if (position == 1) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return true;
        }

        // Traverse to the node just before the position
        Node* current = head;
        for (int i = 1; i < position - 1 && current->next != nullptr; i++) {
            current = current->next;
        }

        // If we reached the position and there is a node to delete
        if (current->next != nullptr) {
            Node* nodeToDelete = current->next;
            current->next = current->next->next;
            delete nodeToDelete;
            return true;
        }

        return false;  // Position is out of bounds
    }


    bool update(int position, int value) {
        if (position < 1) {  // Invalid position check
            return false;
        }

        Node* temp = head;
        for (int i = 1; i <= position && temp != nullptr; i++) {
            if (i == position) {
                temp->data = value;
                return true;
            }
            temp = temp->next;
        }
        return false;  // Return false if position is out of bounds
    }

    void printList() const {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    SortedList list;
    
    // Test 1
    int test_array[10]= {89,23,21,123,4,56,56,56,98,67};
    for (int i =0; i<sizeof(test_array) / sizeof(test_array[0]); ++i){
        list.insert(test_array[i]);
    }
    std::cout << "Sorted List: ";
    list.printList();

    return 0;
}
