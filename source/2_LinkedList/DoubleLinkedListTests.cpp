#include <iostream>
#include <cassert>
#include "DoubleLinkedList.h"  // Include the header file for your DoubleLinkedList class

void testInsertAtBeginning() {
    DoubleLinkedList list;
    list.insertAtBeginning(10);
    list.insertAtBeginning(20);
    list.insertAtBeginning(30);
    
    list.displayList();  // Expected output: 30 20 10
    assert(list.search(10));
    assert(list.search(20));
    assert(list.search(30));
}

void testInsertAtEnd() {
    DoubleLinkedList list;
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    
    list.displayList();  // Expected output: 10 20 30
    assert(list.search(10));
    assert(list.search(20));
    assert(list.search(30));
}

void testInsertAtLocation() {
    DoubleLinkedList list;
    list.insertAtEnd(10);
    list.insertAtEnd(30);
    list.insertAtLocation(20, 2);
    
    list.displayList();  // Expected output: 10 20 30
    assert(list.search(20));
    
    list.insertAtLocation(5, 1);
    list.displayList();  // Expected output: 5 10 20 30
    assert(list.search(5));
    
    list.insertAtLocation(40, 5);
    list.displayList();  // Expected output: 5 10 20 30 40
    assert(list.search(40));
}

void testUpdate() {
    DoubleLinkedList list;
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    
    list.update(2, 25);
    list.displayList();  // Expected output: 10 25 30
    assert(list.search(25));
    assert(!list.search(20));
}

void testDeleteByPosition() {
    DoubleLinkedList list;
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    
    list.deleteByPosition(2);
    list.displayList();  // Expected output: 10 30
    assert(!list.search(20));
    
    list.deleteByPosition(1);
    list.displayList();  // Expected output: 30
    assert(!list.search(10));
    
    list.deleteByPosition(1);
    list.displayList();  // Expected output: (empty list)
    assert(list.isEmpty());
}

void testIsEmpty() {
    DoubleLinkedList list;
    assert(list.isEmpty());
    
    list.insertAtEnd(10);
    assert(!list.isEmpty());
}

void testClear() {
    DoubleLinkedList list;
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    
    list.clear();
    assert(list.isEmpty());
    list.displayList();  // Expected output: (empty list)
}

void testSearch() {
    DoubleLinkedList list;
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    
    assert(list.search(10));
    assert(list.search(20));
    assert(list.search(30));
    assert(!list.search(40));
}

int main() {

    // My unit test 
    testInsertAtBeginning();
    testInsertAtEnd();
    testInsertAtLocation();
    testUpdate();
    testDeleteByPosition();
    testIsEmpty();
    testClear();
    testSearch();
}
