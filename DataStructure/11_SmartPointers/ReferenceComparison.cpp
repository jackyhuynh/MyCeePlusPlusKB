#include <iostream>
#include <chrono>
#include <vector>

// Function to simulate some operations
void processByConstRef(const std::vector<int>& v) {
    volatile int sum = 0;
    for (const auto& i : v) {
        sum += i;
    }
}

void processByCopy(std::vector<int> v) {
    volatile int sum = 0;
    for (const auto& i : v) {
        sum += i;
    }
}

int main() {
    // Create a large vector of integers
    std::vector<int> largeVector(1e7, 42); // 10 million elements

    // Measure time for const auto& (passing by reference)
    auto start = std::chrono::high_resolution_clock::now();
    processByConstRef(largeVector);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Time for const auto& (pass by reference): " << elapsed.count() << " seconds\n";

    // Measure time for regular copy
    start = std::chrono::high_resolution_clock::now();
    processByCopy(largeVector);
    end = std::chrono::high_resolution_clock::now();
    elapsed = end - start;
    std::cout << "Time for regular copy: " << elapsed.count() << " seconds\n";

    return 0;
}
