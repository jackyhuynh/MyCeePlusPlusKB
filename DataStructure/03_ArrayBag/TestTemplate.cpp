#include <iostream>
#include "ArrayBag.hpp"

int main() {
    ArrayBag<int> myBag;
    
    std::cout << "Adding items to the bag..." << std::endl;
    myBag.add(1);
    myBag.add(2);
    myBag.add(3);
    
    std::cout << "Current size of the bag: " << myBag.getCurrentSize() << std::endl;
    
    std::cout << "Bag contains 2? " << (myBag.contains(2) ? "Yes" : "No") << std::endl;
    
    std::cout << "Removing item 2 from the bag..." << std::endl;
    myBag.remove(2);
    
    std::cout << "Bag contains 2? " << (myBag.contains(2) ? "Yes" : "No") << std::endl;
    std::cout << "Current size of the bag: " << myBag.getCurrentSize() << std::endl;
    
    std::cout << "Clearing the bag..." << std::endl;
    myBag.clear();
    
    std::cout << "Bag is empty? " << (myBag.isEmpty() ? "Yes" : "No") << std::endl;
    
    return 0;
}
