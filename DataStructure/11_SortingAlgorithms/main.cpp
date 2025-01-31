#include <vector>
using namespace std;

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
- Time Complexity: Average case: O(n log n), Worst case: O(n^2).
- Space Complexity: O(log n).
- Use Case: Quick Sort is a popular choice for sorting large datasets, as it has good average-case performance. 
It's often used in applications where average-case performance matters more than worst-case performance, 
such as in sorting massive datasets in databases.
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
- Time Complexity: Average case: O(n^2), Worst case: O(n^2).
- Space Complexity: O(1).
- Use Case: Insertion Sort is efficient for sorting small datasets or nearly sorted datasets.
It's often used in scenarios where the input size is small or the list is almost sorted.
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
- Time Complexity: O(n log n) in all cases.
- Space Complexity: O(n).
- Use Case: Merge Sort is preferred for sorting linked lists and arrays with large data sets, as it guarantees O(n log n) time complexity in all cases. 
It's suitable for external sorting where data is too large to fit into memory.
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
- Time Complexity: O(n log n) in all cases.
- Space Complexity: O(1).
- Use Case: Heap Sort is used when a guaranteed O(n log n) performance is required. 
It's often used in scenarios where memory usage needs to be optimized, as it has a space complexity of O(1).
*/

/*
**Selection Sort**:
- **Logic**:
  - Selection Sort works by dividing the array into two sub-arrays: sorted and unsorted.
  - Initially, the sorted sub-array is empty, and the unsorted sub-array contains all the elements.
  - In each iteration, Selection Sort finds the smallest (or largest, depending on the sorting order) element from the unsorted sub-array and swaps it with the first element of the unsorted sub-array.
  - By doing this, the smallest (or largest) element gets placed at its correct position in the sorted sub-array.
  - This process is repeated until the entire array is sorted.

- **Time Complexity**:
  - Selection Sort has a time complexity of O(n^2), where n is the number of elements in the array.
  - This is because, in each iteration, it scans the unsorted part of the array to find the minimum or maximum element, resulting in nested loops.

- **Space Complexity**:
  - Selection Sort has a space complexity of O(1), meaning it requires constant extra space for temporary variables or swapping elements.
  - It does not require additional memory proportional to the size of the input array.

- **Use Case**:
  - Selection Sort is suitable for small datasets or scenarios where simplicity and minimal memory usage are more important than sorting speed.
  - It's often used for educational purposes due to its simplicity in implementation.
  - However, Selection Sort is not efficient for large datasets due to its quadratic time complexity. Other sorting algorithms like Quick Sort, Merge Sort, or Heap Sort are preferred for larger datasets.

- **Example**:
  - Consider an array [5, 3, 8, 2, 1].
  - In the first iteration, Selection Sort finds the smallest element (1) and swaps it with the first element, resulting in [1, 3, 8, 2, 5].
  - In the second iteration, it finds the next smallest element (2) and swaps it with the second element, resulting in [1, 2, 8, 3, 5].
  - This process continues until the entire array is sorted.

Selection Sort is straightforward to implement and understand but is not efficient for large datasets due to its quadratic time complexity. It's generally used for educational purposes or in scenarios where simplicity and minimal memory usage are prioritized over sorting speed.
*/