#include <iostream>
#include <string>
#include <vector>

using namespace std;

unsigned long simpleHash(const string& input) {
    unsigned long hash = 0;
    for(char c : input) {
        hash = hash * 31 + c;
    }
    return hash%10;
}

bool isContained (const vector<string>& dataArr, string data){
    if (dataArr[simpleHash(data)]==data){
        return true;
    }
    return false;
}

int main() {
    vector<string> dataArr(10);
    for (int i = 0; i < 10; ++i) {
        dataArr[i] = " string ";
    }
    for (int i = 0; i < 10; ++i){
        cout << dataArr[i] << ", ";
    }
    cout << endl;

    string data = "Hello, world!";
    unsigned long hashValue = simpleHash(data);
    cout << "Hash Value: " << hashValue << endl;

    dataArr[hashValue] = data;

    for (int i = 0; i < 10; ++i){
        cout << dataArr[i] << ", ";
    }
    cout << endl;

    bool option = isContained(dataArr,data);

    if (option){
        cout << "data is contained";
    } else {
        cout << "not found";
    }

    return 0;
}

// Use case is Search for "Hello World" in side the data set
