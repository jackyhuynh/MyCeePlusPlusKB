#include <iostream>

template <typename T>
class Node {
public:
    T data;
    Node* prev;
    Node* next;

    Node(T value) : data(value), prev(nullptr), next(nullptr) {}
};

template <typename T>
class DoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int node_count;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), node_count(0) {}

    ~DoublyLinkedList() {
        while (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Insert at the front
    void push_front(T data) {
        Node<T>* new_node = new Node<T>(data);
        if (head == nullptr) {
            head = tail = new_node;
        } else {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
        node_count++;
    }

    // Insert at the back
    void push_back(T data) {
        Node<T>* new_node = new Node<T>(data);
        if (tail == nullptr) {
            head = tail = new_node;
        } else {
            new_node->prev = tail;
            tail->next = new_node;
            tail = new_node;
        }
        node_count++;
    }

    // Remove from the front
    void pop_front() {
        if (head == nullptr) return; // Empty list
        Node<T>* temp = head;
        if (head == tail) { // Single node case
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
        node_count--;
    }

    // Remove from the back
    void pop_back() {
        if (tail == nullptr) return; // Empty list
        Node<T>* temp = tail;
        if (head == tail) { // Single node case
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
        node_count--;
    }

    // Insert at specific position
    void insert_at(T data, int position) {
        if (position < 0 || position > node_count) {
            std::cerr << "Invalid position!\n";
            return;
        }
        if (position == 0) {
            push_front(data);
            return;
        }
        if (position == node_count) {
            push_back(data);
            return;
        }

        Node<T>* new_node = new Node<T>(data);
        Node<T>* current = head;
        for (int i = 0; i < position - 1; ++i) {
            current = current->next;
        }
        new_node->next = current->next;
        new_node->prev = current;
        current->next->prev = new_node;
        current->next = new_node;
        node_count++;
    }

    // Remove node at specific position
    void remove_at(int position) {
        if (position < 0 || position >= node_count) {
            std::cerr << "Invalid position!\n";
            return;
        }
        if (position == 0) {
            pop_front();
            return;
        }
        if (position == node_count - 1) {
            pop_back();
            return;
        }

        Node<T>* current = head;
        for (int i = 0; i < position; ++i) {
            current = current->next;
        }
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
        node_count--;
    }

    // Display the list from head to tail
    void display_forward() {
        Node<T>* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << "\n";
    }

    // Display the list from tail to head
    void display_backward() {
        Node<T>* current = tail;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->prev;
        }
        std::cout << "\n";
    }

    // Return the number of nodes
    int size() {
        return node_count;
    }

    // Check if the list is empty
    bool empty() {
        return node_count == 0;
    }

    // Access the front node data
    T front() {
        if (head != nullptr)
            return head->data;
        throw std::runtime_error("List is empty");
    }

    // Access the back node data
    T back() {
        if (tail != nullptr)
            return tail->data;
        throw std::runtime_error("List is empty");
    }
};

int main() {
    DoublyLinkedList<int> dll;
    
    dll.push_back(10);
    dll.push_front(20);
    dll.push_back(30);
    dll.insert_at(25, 2);

    dll.display_forward();  // Output: 20 10 25 30
    dll.display_backward(); // Output: 30 25 10 20

    dll.pop_front();
    dll.pop_back();
    dll.display_forward();  // Output: 10 25

    dll.remove_at(1);
    dll.display_forward();  // Output: 10

    return 0;
}