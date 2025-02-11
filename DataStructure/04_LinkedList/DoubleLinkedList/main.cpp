#include <iostream>
#include "DoubleLinkedList.h"  // Include the header file for your DoubleLinkedList class

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
    dll.displayList();  // Expected Output: 0 1 9 3

    std::cout << "Deleting node at position 4" << std::endl;
    dll.deleteByPosition(4);
    dll.displayList();  // Expected Output: 0 1 9

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