#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include <iostream>

// Node class for double linked list
class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val);
};

// DoubleLinkedList class
class DoubleLinkedList {
private:
    Node* head;

public:
    DoubleLinkedList();

    void insertAtBeginning(int data);
    void insertAtEnd(int data);
    void insertAtLocation(int data, int position);
    void update(int position, int newData);
    void deleteByPosition(int position);
    bool isEmpty() const;
    void clear();
    bool search(int value) const;
    void displayList();
};

#endif
