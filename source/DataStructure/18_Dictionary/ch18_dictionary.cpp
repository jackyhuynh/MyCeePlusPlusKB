#include <iostream>
#include <string>

// Custom hash table class
class MyDictionary {
    private:
        static const int TABLE_SIZE = 10007; // Choose a prime number for the table size
        struct Node {
            std::string key;
            std::string value;
            Node* next;
            Node(const std::string& k, const std::string& v) : key(k), value(v), next(nullptr) {}
        };
        Node* table[TABLE_SIZE];

        // Hash function (simple example)
        int hash(const std::string& key) {
            int hashValue = 0;
            for (char c : key) {
                hashValue = (hashValue * 31 + c) % TABLE_SIZE;
            }
            return hashValue;
        }

    public:
        MyDictionary() {
            for (int i = 0; i < TABLE_SIZE; ++i) {
                table[i] = nullptr;
            }
        }

        // Insert a key-value pair
        void insert(const std::string& key, const std::string& value) {
            int index = hash(key);
            Node* newNode = new Node(key, value); // create new node
            newNode->next = table[index]; 
            table[index] = newNode;
        }

        // Search for a key and return its value
        std::string search(const std::string& key) {
            int index = hash(key); // get the index
            Node* curr = table[index];
            while (curr) {
                if (curr->key == key) {
                    return curr->value;
                }
                curr = curr->next;
            }
            return "Not found"; // Modify as needed
        }

        // Remove a key-value pair
        void remove(const std::string& key) {
            int index = hash(key);
            Node* curr = table[index];
            Node* prev = nullptr;
            while (curr) {
                if (curr->key == key) {
                    if (prev) {
                        prev->next = curr->next;
                    } else {
                        table[index] = curr->next;
                    }
                    delete curr;
                    return;
                }
                prev = curr;
                curr = curr->next;
            }
        }
};

// Example usage
int main() {
    MyDictionary dict;
    dict.insert("apple", "fruit");
    dict.insert("banana", "fruit");
    std::cout << dict.search("banana") << std::endl; // Output: "fruit"
    dict.remove("apple");
    std::cout << dict.search("apple") << std::endl; // Output: "Not found"
    return 0;
}
