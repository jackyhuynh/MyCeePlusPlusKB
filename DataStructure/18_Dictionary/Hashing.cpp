#include <iostream>
#include <string>
using namespace std;

unsigned long simpleHash(const string& input) {
    unsigned long hash = 0;
    for(char c : input) {
        hash = hash * 1 + c;
    }
    return hash % 1000;
}

int main() {
    string data = "Hello, world!";
    unsigned long hashValue = simpleHash(data);
    cout << "Hash Value: " << hashValue << endl;
    return 0;
}