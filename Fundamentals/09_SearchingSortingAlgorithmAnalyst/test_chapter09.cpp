#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <chrono>

int linearSearch(const std::vector<int>& arr, int target) {
    for (size_t i = 0; i < arr.size(); i++) {
        if (arr[i] == target) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

int binarySearch(const std::vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void selectionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        std::swap(arr[i], arr[minIdx]);
    }
}

void insertionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void testLinearSearch() {
    std::cout << "Test 1: Linear Search" << std::endl;
    
    std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    
    int index1 = linearSearch(arr, 22);
    assert(index1 == 4);
    
    int index2 = linearSearch(arr, 99);
    assert(index2 == -1);
    
    int index3 = linearSearch(arr, 64);
    assert(index3 == 0);
    
    std::cout << "Found 22 at index: " << index1 << std::endl;
    std::cout << "Search for 99 result: " << index2 << " (not found)" << std::endl;
    
    std::cout << "✓ Test passed: Linear search works correctly\n" << std::endl;
}

void testBinarySearch() {
    std::cout << "Test 2: Binary Search" << std::endl;
    
    std::vector<int> sortedArr = {11, 12, 22, 25, 34, 64, 90};
    
    int index1 = binarySearch(sortedArr, 25);
    assert(index1 == 3);
    
    int index2 = binarySearch(sortedArr, 99);
    assert(index2 == -1);
    
    int index3 = binarySearch(sortedArr, 11);
    assert(index3 == 0);
    
    int index4 = binarySearch(sortedArr, 90);
    assert(index4 == 6);
    
    std::cout << "Found 25 at index: " << index1 << std::endl;
    std::cout << "Found 11 at index: " << index3 << std::endl;
    std::cout << "Found 90 at index: " << index4 << std::endl;
    
    std::cout << "✓ Test passed: Binary search works correctly\n" << std::endl;
}

void testBubbleSort() {
    std::cout << "Test 3: Bubble Sort" << std::endl;
    
    std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    std::vector<int> expected = {11, 12, 22, 25, 34, 64, 90};
    
    bubbleSort(arr);
    
    assert(arr == expected);
    
    std::cout << "Sorted array: ";
    for (int val : arr) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    
    std::cout << "✓ Test passed: Bubble sort works correctly\n" << std::endl;
}

void testSelectionSort() {
    std::cout << "Test 4: Selection Sort" << std::endl;
    
    std::vector<int> arr = {29, 10, 14, 37, 13};
    std::vector<int> expected = {10, 13, 14, 29, 37};
    
    selectionSort(arr);
    
    assert(arr == expected);
    
    std::cout << "Sorted array: ";
    for (int val : arr) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    
    std::cout << "✓ Test passed: Selection sort works correctly\n" << std::endl;
}

void testInsertionSort() {
    std::cout << "Test 5: Insertion Sort" << std::endl;
    
    std::vector<int> arr = {5, 2, 4, 6, 1, 3};
    std::vector<int> expected = {1, 2, 3, 4, 5, 6};
    
    insertionSort(arr);
    
    assert(arr == expected);
    
    std::cout << "Sorted array: ";
    for (int val : arr) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    
    std::cout << "✓ Test passed: Insertion sort works correctly\n" << std::endl;
}

void testSTLAlgorithms() {
    std::cout << "Test 6: STL Algorithms" << std::endl;
    
    std::vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6};
    
    std::sort(arr.begin(), arr.end());
    assert(std::is_sorted(arr.begin(), arr.end()));
    
    auto it = std::binary_search(arr.begin(), arr.end(), 5);
    assert(it == true);
    
    it = std::binary_search(arr.begin(), arr.end(), 7);
    assert(it == false);
    
    auto pos = std::lower_bound(arr.begin(), arr.end(), 4);
    assert(*pos == 4);
    
    std::cout << "STL sorted array: ";
    for (int val : arr) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    
    std::cout << "✓ Test passed: STL algorithms work correctly\n" << std::endl;
}

void testAlgorithmComplexity() {
    std::cout << "Test 7: Algorithm Complexity Analysis" << std::endl;
    
    std::vector<int> smallData = {5, 2, 8, 1, 9};
    std::vector<int> largeData;
    
    for (int i = 1000; i >= 1; i--) {
        largeData.push_back(i);
    }
    
    auto start = std::chrono::high_resolution_clock::now();
    bubbleSort(smallData);
    auto end = std::chrono::high_resolution_clock::now();
    
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    
    std::cout << "Small data bubble sort time: " << duration.count() << " microseconds" << std::endl;
    
    int comparisons = 0;
    auto customLinearSearch = [&](const std::vector<int>& arr, int target) {
        comparisons = 0;
        for (size_t i = 0; i < arr.size(); i++) {
            comparisons++;
            if (arr[i] == target) return static_cast<int>(i);
        }
        return -1;
    };
    
    customLinearSearch(largeData, 500);
    std::cout << "Linear search comparisons for target 500: " << comparisons << std::endl;
    
    std::cout << "✓ Test passed: Complexity analysis completed\n" << std::endl;
}

void testSearchingEdgeCases() {
    std::cout << "Test 8: Searching Edge Cases" << std::endl;
    
    std::vector<int> empty;
    assert(linearSearch(empty, 5) == -1);
    assert(binarySearch(empty, 5) == -1);
    
    std::vector<int> singleElement = {42};
    assert(linearSearch(singleElement, 42) == 0);
    assert(binarySearch(singleElement, 42) == 0);
    assert(linearSearch(singleElement, 99) == -1);
    assert(binarySearch(singleElement, 99) == -1);
    
    std::vector<int> duplicates = {1, 2, 2, 2, 3};
    int found = binarySearch(duplicates, 2);
    assert(found >= 1 && found <= 3);
    
    std::cout << "Empty array search: handled correctly" << std::endl;
    std::cout << "Single element search: works correctly" << std::endl;
    
    std::cout << "✓ Test passed: Edge cases handled correctly\n" << std::endl;
}

void testSortingStability() {
    std::cout << "Test 9: Sorting Stability" << std::endl;
    
    struct Student {
        std::string name;
        int grade;
        
        bool operator==(const Student& other) const {
            return name == other.name && grade == other.grade;
        }
    };
    
    std::vector<Student> students = {
        {"Alice", 85}, {"Bob", 90}, {"Charlie", 85}, {"David", 90}
    };
    
    std::stable_sort(students.begin(), students.end(), 
                    [](const Student& a, const Student& b) {
                        return a.grade > b.grade;
                    });
    
    assert(students[0].name == "Bob");
    assert(students[1].name == "David");
    assert(students[2].name == "Alice");
    assert(students[3].name == "Charlie");
    
    std::cout << "Stable sort preserved order for equal grades" << std::endl;
    std::cout << "✓ Test passed: Sorting stability works correctly\n" << std::endl;
}

void testPartialSorting() {
    std::cout << "Test 10: Partial Sorting" << std::endl;
    
    std::vector<int> arr = {9, 5, 2, 7, 1, 8, 3, 6, 4};
    
    std::partial_sort(arr.begin(), arr.begin() + 3, arr.end());
    
    assert(arr[0] == 1);
    assert(arr[1] == 2);
    assert(arr[2] == 3);
    
    std::cout << "First 3 elements after partial sort: ";
    for (int i = 0; i < 3; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    
    std::vector<int> arr2 = {9, 5, 2, 7, 1, 8, 3, 6, 4};
    std::nth_element(arr2.begin(), arr2.begin() + 4, arr2.end());
    
    assert(arr2[4] == 5);
    
    std::cout << "5th smallest element: " << arr2[4] << std::endl;
    std::cout << "✓ Test passed: Partial sorting works correctly\n" << std::endl;
}

int main() {
    std::cout << "========================================" << std::endl;
    std::cout << "Chapter 9: Searching and Sorting Algorithm Analysis" << std::endl;
    std::cout << "Test Suite" << std::endl;
    std::cout << "========================================\n" << std::endl;
    
    testLinearSearch();
    testBinarySearch();
    testBubbleSort();
    testSelectionSort();
    testInsertionSort();
    testSTLAlgorithms();
    testAlgorithmComplexity();
    testSearchingEdgeCases();
    testSortingStability();
    testPartialSorting();
    
    std::cout << "========================================" << std::endl;
    std::cout << "All Chapter 9 tests passed successfully!" << std::endl;
    std::cout << "========================================" << std::endl;
    
    return 0;
}