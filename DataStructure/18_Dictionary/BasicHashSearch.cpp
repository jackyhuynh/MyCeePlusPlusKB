#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Hash function that maps a string to an index (modulus 10 for simplicity)
unsigned long simpleHash(const string& input) {
    unsigned long hash = 0;
    for (char c : input) {
        hash = hash * 31 + c;
    }
    return hash % 10; // Returns index in the range [0, 9]
}

// Function to check if a given data is present in the vector at the hashed index
bool isContained(const vector<string>& dataArr, const string& data) {
    return dataArr[simpleHash(data)] == data;
}

int main() {
    // Initialize a vector of size 10 with placeholder strings
    vector<string> dataArr(10, "empty");

    // Print initial dataArr state
    cout << "Initial data array: ";
    for (const auto& entry : dataArr) {
        cout << entry << ", ";
    }
    cout << endl;

    // Data to insert and search
    string data = "Hello, world!";
    unsigned long hashValue = simpleHash(data);
    cout << "Hash Value: " << hashValue << endl;

    // Insert data at the computed hash index
    dataArr[hashValue] = data;

    // Print updated dataArr state
    cout << "Updated data array: ";
    for (const auto& entry : dataArr) {
        cout << entry << ", ";
    }
    cout << endl;

    // Search for data in the array and print result
    if (isContained(dataArr, data)) {
        cout << "Data is contained" << endl;
    } else {
        cout << "Not found" << endl;
    }

    return 0;
}