 
#include <iostream>
#include <vector>

const bool _DEBUG_ = false;

/*
    O(1) - Constant Time
    An operation is O(1) if it takes the same amount of time to complete regardless of the input size.
*/
void printFirstElement(int arr[]) {
    std::cout << "First element: " << arr[0] << std::endl;
}

/*
    O(n) - Linear Time
    An algorithm is O(n) if the time it takes to complete is directly proportional to the input size.
*/
void printAllElements(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// O(n^2) - Quadratic Time
/*
    O(n^2) - Quadratic Time
    An algorithm is O(n^2) if the time is proportional to the square of the input size. This is common with nested loops.
*/
void printAllPairs(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << "(" << arr[i] << ", " << arr[j] << ") ";
        }
        std::cout << std::endl;
    }
}

// O(log n) - Logarithmic Time
/*
O(log n) - Logarithmic Time
An algorithm is O(log n) if the time it takes to complete reduces with each step, 
typically seen in algorithms that break the problem in half every iteration, like binary search.
*/
int binarySearch(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        std::cout << arr[mid];
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1; // Target not found
}

void displayVector(const std::vector<int>& arr) {
    for (int elem : arr) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

void display_arr(int arr[], int size){
    for(int i=0; i<size; i++){
        std::cout << arr[i] << " ";
    }
}
// Helper functions for Merge Sort (O(n log n))
// Devide and conquer algorithm
void merge(std::vector<int>& arr, int left, int mid, int right) {
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;
    
    if (_DEBUG_ == true){
        std::cout << "new merge call" << std::endl; 
        displayVector(arr); //1
    }

    std::vector<int> leftArray(subArrayOne), rightArray(subArrayTwo);

    for (auto i = 0; i < subArrayOne; i++){
        leftArray[i] = arr[left + i];
        if (_DEBUG_ == true){
            displayVector(arr); //2
        }
    }

    for (auto j = 0; j < subArrayTwo; j++){
        rightArray[j] = arr[mid + 1 + j];
        if (_DEBUG_ == true){
            displayVector(arr); //3
        }
    }


    auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        } else {
            arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
        if (_DEBUG_ == true){
            displayVector(arr);
        }
    }

    while (indexOfSubArrayOne < subArrayOne) {
        arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
        if (_DEBUG_ == true){
            displayVector(arr);
        }
    }

    while (indexOfSubArrayTwo < subArrayTwo) {
        arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
        if (_DEBUG_ == true){
            displayVector(arr);
        }
    }
}

void mergeSort(std::vector<int>& arr, int begin, int end) {
    if (begin >= end)
        return;

    auto mid = begin + (end - begin) / 2;
    mergeSort(arr, begin, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, begin, mid, end);
}

int main() {
    int arr[] = {8, 3, 5, 7, 2, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Test O(1)
    std::cout << "O(1) - Constant Time Example: " << std::endl;
    printFirstElement(arr);

    // Test O(n)
    std::cout << "\nO(n) - Linear Time Example: " << std::endl;
    printAllElements(arr, size);

    // Test O(n^2)
    std::cout << "\nO(n^2) - Quadratic Time Example: " << std::endl;
    printAllPairs(arr, size);

    // Test O(log n)
    std::cout << "\nO(log n) - Logarithmic Time Example (Binary Search): " << std::endl;
    int array[] = {8, 3, 7, 2, 6, 11, 14, 8, 9};
    int array2[] = {2,3,6,7,8,8,9,11,14};
    int target = 14;
    size = sizeof(array2)/sizeof(array2[0]);
    int result = binarySearch(array2, size, target);
    if (result != -1) 
        std::cout << "Element found at index: " << result << std::endl;
    else 
        std::cout << "Element not found." << std::endl;

    // Test O(n log n)
    std::cout << "\nO(n log n) - Linearithmic Time Example (Merge Sort): " << std::endl;
    std::vector<int> vec = {8, 3, 5, 7, 2, 6, 4, 1};
    std::cout << "Original array: ";
    for (int i : vec) std::cout << i << " ";
    std::cout << std::endl;

    mergeSort(vec, 0, vec.size() - 1);

    std::cout << "Sorted array: ";
    for (int i : vec) std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}
   