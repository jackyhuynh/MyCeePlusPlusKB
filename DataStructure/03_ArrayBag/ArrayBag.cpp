#include "ArrayBag.h"

template<class T>
ArrayBag<T>::ArrayBag() : itemCount(0), maxItems(DEFAULT_CAPACITY) {}

template<class T>
int ArrayBag<T>::getCurrentSize() const {
    return itemCount;
}

template<class T>
bool ArrayBag<T>::isEmpty() const {
    return itemCount == 0;
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

// This isn't possible for templates because the implementation must remain visible in the header file. 
