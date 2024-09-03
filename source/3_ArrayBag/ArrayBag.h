#ifndef ARRAY_BAG_H
#define ARRAY_BAG_H

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

#endif
