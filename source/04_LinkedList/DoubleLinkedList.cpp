// DoubleLinkedList.cpp
#include "DoubleLinkedList.h"

// Node class constructor
Node::Node(int val) : data(val), next(nullptr), prev(nullptr) {}

// DoubleLinkedList class constructor
DoubleLinkedList::DoubleLinkedList() : head(nullptr) {}

void DoubleLinkedList::insertAtBeginning(int data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    if (head != nullptr) {
        head->prev = newNode;
    }
    head = newNode;
}

void DoubleLinkedList::insertAtEnd(int data) {
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

void DoubleLinkedList::insertAtLocation(int data, int position) {
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

void DoubleLinkedList::update(int position, int newData) {
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

void DoubleLinkedList::deleteByPosition(int position) {
    if (head == nullptr) return;

    Node* temp = head;

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

bool DoubleLinkedList::isEmpty() const {
    return head == nullptr;
}

void DoubleLinkedList::clear() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
}

bool DoubleLinkedList::search(int value) const {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == value) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void DoubleLinkedList::displayList() {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << "\n";
}
