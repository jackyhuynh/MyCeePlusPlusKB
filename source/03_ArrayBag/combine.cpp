#include <iostream>
#include <vector>

template<class T>
class ArrayBag {
private:
    static const int DEFAULT_CAPACITY = 100;
    T items[DEFAULT_CAPACITY];
    int itemCount;
    int maxItems;

public:
    ArrayBag();

    int getCurrentSize() const;
    bool isEmpty() const;
    bool add(const T& newEntry);
    bool remove(const T& anEntry);
    void clear();
    int getFrequencyOf(const T& anEntry) const;
    bool contains(const T& anEntry) const;
    std::vector<T> toVector() const;
};

template<class T>
ArrayBag<T>::ArrayBag() : itemCount(0), maxItems(DEFAULT_CAPACITY) {}

template<class T>
int ArrayBag<T>::getCurrentSize() const {
    // check if the array size is more than 0
    return itemCount;
}

template<class T>
bool ArrayBag<T>::isEmpty() const {
    return itemCount == 0; // && check Array size is equal to 0
}

template<class T>
bool ArrayBag<T>::add(const T& newEntry) {
    bool hasRoomToAdd = (itemCount < maxItems);
    if (hasRoomToAdd) {
        items[itemCount] = newEntry;
        itemCount++;
    }
    return hasRoomToAdd;
}

template<class T>
bool ArrayBag<T>::remove(const T& anEntry) {
    int locatedIndex = -1;
    for (int i = 0; i < itemCount; i++) {
        if (items[i] == anEntry) {
            locatedIndex = i;
            break;
        }
    }
    
    bool canRemoveItem = (locatedIndex > -1);
    if (canRemoveItem) {
        itemCount--;
        items[locatedIndex] = items[itemCount];
    }
    return canRemoveItem;
}

template<class T>
void ArrayBag<T>::clear() {
    itemCount = 0;
    // Have to Delete the whole array
    // Memory leak
}

template<class T>
int ArrayBag<T>::getFrequencyOf(const T& anEntry) const {
    int frequency = 0;
    for (int i = 0; i < itemCount; i++) {
        if (items[i] == anEntry) {
            frequency++;
        }
    }
    return frequency;
}

template<class T>
bool ArrayBag<T>::contains(const T& anEntry) const {
    return getFrequencyOf(anEntry) > 0;
}

template<class T>
std::vector<T> ArrayBag<T>::toVector() const {
    std::vector<T> bagContents;
    for (int i = 0; i < itemCount; i++) {
        bagContents.push_back(items[i]);
    }
    return bagContents;
}

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
    
    std::cout << "Current size of the bag: " << myBag.getCurrentSize() << std::endl;
    return 0;
}
