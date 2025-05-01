#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <cmath>

using namespace std;
using namespace std::chrono;

// Helper function to print a vector
void printVector(const vector<int>& arr) {
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;
}

/*
1. **Quick Sort**:
   - Quick Sort is a divide-and-conquer algorithm.
   - It selects a pivot element from the array and partitions the other elements into two sub-arrays according to whether they are less than or greater than the pivot.
   - It then recursively sorts the sub-arrays.
*/
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
/*
- **Time Complexity**:
  - **Average Case**: O(n log n)
  - **Worst Case**: O(n^2) (occurs when the pivot selection consistently results in unbalanced partitions, e.g., when the array is already sorted or reverse sorted and the pivot is always the first or last element).
- **Space Complexity**:
  - **Average Case**: O(log n) (due to the recursive call stack).
  - **Worst Case**: O(n) (in the worst-case scenario of unbalanced partitions, the recursion depth can reach n).
- **Use Case**: Quick Sort is generally very efficient in practice for large datasets due to its good average-case performance. However, its worst-case performance can be a concern in some applications. Randomized Quick Sort, which selects a random pivot, helps to mitigate the risk of hitting the worst-case scenario.
*/

/*
2. **Insertion Sort**:
   - Insertion Sort builds the final sorted array one element at a time.
   - It iterates through each element in the array, moving it backwards through the array until it's in its correct sorted position.
   - It repeats this process for each element until the entire array is sorted.
*/
void insertionSort(vector<int>& arr) {
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
/*
- **Time Complexity**:
  - **Best Case**: O(n) (when the array is already sorted, the inner loop never executes).
  - **Average Case**: O(n^2)
  - **Worst Case**: O(n^2) (when the array is reverse sorted).
- **Space Complexity**: O(1) (Insertion sort is an in-place sorting algorithm).
- **Use Case**: Insertion Sort is efficient for small datasets or nearly sorted datasets because of its low overhead. It's often used as a subroutine in more complex algorithms like hybrid sorting (e.g., Timsort) when the sub-arrays become small.
*/

/*
3. **Merge Sort**:
   - Merge Sort divides the array into two halves, sorts each half recursively, and then merges the sorted halves.
   - It continuously divides the array in half until it's left with single elements.
   - It then merges these single elements back together into sorted sub-arrays until the entire array is sorted.
*/
void merge(vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}
/*
- **Time Complexity**: O(n log n) in all cases (best, average, and worst). The division and merging steps ensure consistent performance regardless of the initial order of elements.
- **Space Complexity**: O(n) (due to the extra space required for the temporary arrays `L` and `R` during the merge operation).
- **Use Case**: Merge Sort is a stable sorting algorithm (maintains the relative order of equal elements) and performs consistently well. It's preferred for sorting linked lists (where random access is slow) and for external sorting (where data is too large to fit in memory) due to its sequential data access patterns.
*/

/*
4. **Heap Sort**:
   - Heap Sort is based on the heap data structure, specifically the binary heap.
   - It first builds a heap from the input array.
   - It repeatedly extracts the maximum (for max-heap) element from the heap and puts it at the end of the array.
   - It then reduces the size of the heap and heapifies the heap to maintain the heap property.

*/
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

/*
- **Time Complexity**: O(n log n) in all cases (best, average, and worst). The heap construction takes O(n) time, and the extraction and heapify operations take O(log n) for each of the n elements.
- **Space Complexity**: O(1) (Heap Sort is an in-place sorting algorithm).
- **Use Case**: Heap Sort is a good choice when a guaranteed O(n log n) time complexity is needed and in-place sorting is desirable (minimal extra memory usage). It's used in applications like priority queues.
*/

/*
5. **Selection Sort**:
- **Logic**:
  - Selection Sort works by dividing the array into two sub-arrays: sorted and unsorted.
  - Initially, the sorted sub-array is empty, and the unsorted sub-array contains all the elements.
  - In each iteration, Selection Sort finds the smallest (or largest, depending on the sorting order) element from the unsorted sub-array and swaps it with the first element of the unsorted sub-array.
  - By doing this, the smallest (or largest) element gets placed at its correct position in the sorted sub-array.
  - This process is repeated until the entire array is sorted.
*/
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}
/*
- **Time Complexity**: O(n^2) in all cases (best, average, and worst). The nested loops result in a quadratic number of comparisons regardless of the initial order of the elements.
- **Space Complexity**: O(1) (Selection Sort is an in-place sorting algorithm).
- **Use Case**: Selection Sort is simple to implement and performs a minimal number of swaps (O(n)). However, due to its poor time complexity for larger datasets, it's generally not used in practice except for very small arrays or educational purposes. Its stability depends on the implementation.
*/

int main() {
    vector<int> data = {5, 2, 8, 1, 9, 4, 7, 11, 23, 32, 45, 98, 3, 6,5, 2, 8, 1, 9, 4, 7, 11, 23, 32, 45, 98, 3, 6};
    vector<int> data_copy;

    cout << "Original array: ";
    printVector(data);
    cout << endl;

    // --- Quick Sort ---
    data_copy = data;
    auto start = high_resolution_clock::now();
    quickSort(data_copy, 0, data_copy.size() - 1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Quick Sorted array: ";
    printVector(data_copy);
    cout << "Time taken by Quick Sort: " << duration.count() << " microseconds" << endl;
    cout << "Time Complexity: Average O(n log n), Worst O(n^2)" << endl;
    cout << "Space Complexity: Average O(log n), Worst O(n)" << endl << endl;

    // --- Insertion Sort ---
    data_copy = data;
    start = high_resolution_clock::now();
    insertionSort(data_copy);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Insertion Sorted array: ";
    printVector(data_copy);
    cout << "Time taken by Insertion Sort: " << duration.count() << " microseconds" << endl;
    cout << "Time Complexity: Best O(n), Average O(n^2), Worst O(n^2)" << endl;
    cout << "Space Complexity: O(1)" << endl << endl;

    // --- Merge Sort ---
    data_copy = data;
    start = high_resolution_clock::now();
    mergeSort(data_copy, 0, data_copy.size() - 1);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Merge Sorted array: ";
    printVector(data_copy);
    cout << "Time taken by Merge Sort: " << duration.count() << " microseconds" << endl;
    cout << "Time Complexity: O(n log n) in all cases" << endl;
    cout << "Space Complexity: O(n)" << endl << endl;

    // --- Heap Sort ---
    data_copy = data;
    start = high_resolution_clock::now();
    heapSort(data_copy);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Heap Sorted array: ";
    printVector(data_copy);
    cout << "Time taken by Heap Sort: " << duration.count() << " microseconds" << endl;
    cout << "Time Complexity: O(n log n) in all cases" << endl;
    cout << "Space Complexity: O(1)" << endl << endl;

    // --- Selection Sort ---
    data_copy = data;
    start = high_resolution_clock::now();
    selectionSort(data_copy);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Selection Sorted array: ";
    printVector(data_copy);
    cout << "Time taken by Selection Sort: " << duration.count() << " microseconds" << endl;
    cout << "Time Complexity: O(n^2) in all cases" << endl;
    cout << "Space Complexity: O(1)" << endl << endl;

    return 0;
}
