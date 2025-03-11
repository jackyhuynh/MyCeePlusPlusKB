#include <iostream>
#include <vector>
#include <chrono>
#include <string>

using namespace std;
using namespace chrono;

int main() {
    const int N = 1e6;  // Reduced size since strings take more memory
    vector<string> data(N, "HelloWorld");  // Large vector of strings

    // Measure const auto&
    auto start = high_resolution_clock::now();
    for (const auto& str : data) {
        string x = str; // Still making a copy inside loop
    }
    auto end = high_resolution_clock::now();
    auto duration_const_auto_ref = duration_cast<microseconds>(end - start).count();

    // Measure auto
    start = high_resolution_clock::now();
    for (auto str : data) {  // Copying each string
        string x = str;
    }
    end = high_resolution_clock::now();
    auto duration_auto = duration_cast<microseconds>(end - start).count();

    // Measure auto&
    start = high_resolution_clock::now();
    for (auto& str : data) {  // Accessing without copying, can modify
        string x = str;
    }
    end = high_resolution_clock::now();
    auto duration_auto_ref = duration_cast<microseconds>(end - start).count();

    // Measure const auto
    start = high_resolution_clock::now();
    for (const auto str : data) {  // Copying each string but read-only
        string x = str;
    }
    end = high_resolution_clock::now();
    auto duration_const_auto = duration_cast<microseconds>(end - start).count();

    // Regular copy (same as auto)
    start = high_resolution_clock::now();
    for (string str : data) {  // Copying each string
        string x = str;
    }
    end = high_resolution_clock::now();
    auto duration_regular_copy = duration_cast<microseconds>(end - start).count();

    // Output the results
    cout << "const auto&: " << duration_const_auto_ref << " microseconds\n";
    cout << "auto: " << duration_auto << " microseconds\n";
    cout << "auto&: " << duration_auto_ref << " microseconds\n";
    cout << "const auto: " << duration_const_auto << " microseconds\n";
    cout << "Regular copy: " << duration_regular_copy << " microseconds\n";

    return 0;
}
