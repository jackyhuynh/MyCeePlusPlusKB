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

    std::cout << "All tests passed!" << std::endl;

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
