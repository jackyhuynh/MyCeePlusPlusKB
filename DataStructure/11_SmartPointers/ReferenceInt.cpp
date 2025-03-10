#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;

int main() {
    const int N = 1e7;
    vector<int> data(N, 42);  // Large vector for testing

    // Measure const auto&
    auto start = high_resolution_clock::now();
    for (const auto& i : data) {
        // Accessing without copying, can't modify
        int x = i;
    }
    auto end = high_resolution_clock::now();
    auto duration_const_auto_ref = duration_cast<microseconds>(end - start).count();

    // Measure auto
    start = high_resolution_clock::now();
    for (auto i : data) {
        // Copying each element
        int x = i;
    }
    end = high_resolution_clock::now();
    auto duration_auto = duration_cast<microseconds>(end - start).count();

    // Measure auto&
    start = high_resolution_clock::now();
    for (auto& i : data) {
        // Accessing without copying, can modify
        int x = i;
    }
    end = high_resolution_clock::now();
    auto duration_auto_ref = duration_cast<microseconds>(end - start).count();

    // Measure const auto
    start = high_resolution_clock::now();
    for (const auto i : data) {
        // Copying each element but can't modify
        int x = i;
    }
    end = high_resolution_clock::now();
    auto duration_const_auto = duration_cast<microseconds>(end - start).count();

    // Regular copy (same as auto)
    start = high_resolution_clock::now();
    for (int i : data) {
        // Regular copy
        int x = i;
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