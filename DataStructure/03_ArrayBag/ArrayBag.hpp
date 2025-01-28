#ifndef ARRAY_BAG_H
#define ARRAY_BAG_H

#include <vector>

template<class T>
class ArrayBag {
private:
    T* items;  // Pointer to a dynamically allocated array
    int itemCount;
    int maxItems;

public:
    static const int DEFAULT_CAPACITY = 100;

    // Default constructor
    ArrayBag();

    // Custom constructor
    explicit ArrayBag(int capacity);

    // Destructor to release allocated memory
    ~ArrayBag();

    int getCurrentSize() const;
    bool isEmpty() const;
    bool add(const T& newEntry);
    bool remove(const T& anEntry);
    void clear();
    int getFrequencyOf(const T& anEntry) const;
    bool contains(const T& anEntry) const;
    std::vector<T> toVector() const;
};

// Implementation of default constructor
template<class T>
ArrayBag<T>::ArrayBag() : items(new T[DEFAULT_CAPACITY]), itemCount(0), maxItems(DEFAULT_CAPACITY) {}

// Implementation of custom constructor
template<class T>
ArrayBag<T>::ArrayBag(int capacity) : items(new T[capacity]), itemCount(0), maxItems(capacity) {}

// Implementation of destructor
template<class T>
ArrayBag<T>::~ArrayBag() {
    delete[] items;
}

// Implementation of getCurrentSize
template<class T>
int ArrayBag<T>::getCurrentSize() const {
    return itemCount;
}

// Implementation of isEmpty
template<class T>
bool ArrayBag<T>::isEmpty() const {
    return itemCount == 0;
}

// Implementation of add
template<class T>
bool ArrayBag<T>::add(const T& newEntry) {
    if (itemCount < maxItems) {
        items[itemCount++] = newEntry;
        return true;
    }
    return false;
}

// Implementation of remove
template<class T>
bool ArrayBag<T>::remove(const T& anEntry) {
    for (int i = 0; i < itemCount; ++i) {
        if (items[i] == anEntry) {
            items[i] = items[itemCount - 1];  // Replace with last item
            --itemCount;
            return true;
        }
    }
    return false;
}

// Implementation of clear
template<class T>
void ArrayBag<T>::clear() {
    itemCount = 0;
}

// Implementation of getFrequencyOf
template<class T>
int ArrayBag<T>::getFrequencyOf(const T& anEntry) const {
    int frequency = 0;
    for (int i = 0; i < itemCount; ++i) {
        if (items[i] == anEntry) {
            ++frequency;
        }
    }
    return frequency;
}

// Implementation of contains
template<class T>
bool ArrayBag<T>::contains(const T& anEntry) const {
    for (int i = 0; i < itemCount; ++i) {
        if (items[i] == anEntry) {
            return true;
        }
    }
    return false;
}

// Implementation of toVector
template<class T>
std::vector<T> ArrayBag<T>::toVector() const {
    std::vector<T> bagContents;
    for (int i = 0; i < itemCount; ++i) {
        bagContents.push_back(items[i]);
    }
    return bagContents;
}

#endif
