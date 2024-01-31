#include <iostream>
#include <vector>
#include <algorithm> // For std::sort
#include <chrono>    // For std::chrono

// Find the value

int linearSearch(const std::vector<int>& arr, int x) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == x)
            return i;
    }
    return -1;
}

int binarySearch(const std::vector<int>& arr, int x) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main() {
    // Creating an array of 200 elements
    std::vector<int> data(200);
    for (int i = 0; i < 200; ++i) {
        data[i] = i;
    }

    // Shuffling the array to simulate unsorted data for linear search
    std::random_shuffle(data.begin(), data.end());

    // Testing linear search
    auto start = std::chrono::high_resolution_clock::now();
    int linearResult = linearSearch(data, 199); // Assuming we are searching for the last element
    auto end = std::chrono::high_resolution_clock::now();
    auto linearDuration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

    std::cout << "Linear Search Result: " << linearResult << "\n";
    std::cout << "Linear Search took " << linearDuration.count() << " nanoseconds.\n";

    // Sort the array for binary search
    std::sort(data.begin(), data.end());

    // Testing binary search
    start = std::chrono::high_resolution_clock::now();
    int binaryResult = binarySearch(data, 199); // Searching for the same element
    end = std::chrono::high_resolution_clock::now();
    auto binaryDuration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

    std::cout << "Binary Search Result: " << binaryResult << "\n";
    std::cout << "Binary Search took " << binaryDuration.count() << " nanoseconds.\n";

    return 0;
}
