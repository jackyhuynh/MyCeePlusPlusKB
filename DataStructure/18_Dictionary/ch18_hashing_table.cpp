#include <iostream>

class HashTable {
private:
    struct Node {
        int key;
        int value;
        Node* next;

        Node(int k, int v) : key(k), value(v), next(nullptr) {}
    };

    Node** table;
    int capacity;

    int hashFunction(int key) {
        return key % capacity;
    }

public:
    HashTable(int cap) : capacity(cap) {
        table = new Node*[capacity];
        for (int i = 0; i < capacity; i++) {
            table[i] = nullptr;
        }
    }

    ~HashTable() {
        for (int i = 0; i < capacity; i++) {
            Node* entry = table[i];
            while (entry != nullptr) {
                Node* prev = entry;
                entry = entry->next;
                delete prev;
            }
        }
        delete[] table;
    }

    void insert(int key, int value) {
        int hashValue = hashFunction(key);
        Node* previous = nullptr;
        Node* entry = table[hashValue];

        while (entry != nullptr && entry->key != key) {
            previous = entry;
            entry = entry->next;
        }

        if (entry == nullptr) {
            entry = new Node(key, value);
            if (previous == nullptr) {
                // insert as first bucket
                table[hashValue] = entry;
            } else {
                previous->next = entry;
            }
        } else {
            // just update the value
            entry->value = value;
        }
    }

    bool get(int key, int& value) {
        int hashValue = hashFunction(key);
        Node* entry = table[hashValue];

        while (entry != nullptr) {
            if (entry->key == key) {
                value = entry->value;
                return true;
            }
            entry = entry->next;
        }
        return false;
    }

    bool remove(int key) {
        int hashValue = hashFunction(key);
        Node* entry = table[hashValue];
        Node* previous = nullptr;

        while (entry != nullptr && entry->key != key) {
            previous = entry;
            entry = entry->next;
        }

        if (entry == nullptr) {
            // key not found
            return false;
        } else {
            if (previous == nullptr) {
                // remove first bucket of the list
                table[hashValue] = entry->next;
            } else {
                previous->next = entry->next;
            }
            delete entry;
            return true;
        }
    }
};

int main() {
    HashTable ht(10); // Create a hash table with 10 buckets.

    // Insert some key-value pairs.
    ht.insert(1, 100);
    ht.insert(2, 200);
    ht.insert(3, 300);

    // Try retrieving a value.
    int value;
    if (ht.get(2, value)) {
        std::cout << "Value for key 2: " << value << std::endl;
    } else {
        std::cout << "Key not found." << std::endl;
    }

    // Remove a key-value pair.
    if (ht.remove(2)) {
        std::cout << "Key 2 removed successfully." << std::endl;
    } else {
        std::cout << "Failed to remove key 2." << std::endl;
    }

    // Attempt to retrieve the removed key.
    if (!ht.get(2, value)) {
        std::cout << "Key 2 not found after removal." << std::endl;
    }

    return 0;
}
