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
