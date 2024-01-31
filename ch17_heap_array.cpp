#include <iostream>
using namespace std;
/*
* - Heap? 
* - Max Heap, Min Heap
* - Heap Sort?
* - Reference Only: https://www.codingdrills.com/tutorial/heap-data-structure/introduction-to-heap-data-structure
* - https://www.youtube.com/watch?v=Dvq-YKeuO9Y 
*/
// Function to swap two elements
void swap(int &first, int &second) {
    int temp = first;
    first = second;
    second = temp;
}

// Function to maintain max heap property for a subtree rooted at index
void heapify(int heapArray[], int heapSize, int index) {
    int largestIndex = index; // Assume root of the subtree is the largest
    int leftChildIndex = 2 * index + 1; // Index of left child
    int rightChildIndex = 2 * index + 2; // Index of right child

    // If left child exists and is larger than current largest
    if (leftChildIndex < heapSize && heapArray[leftChildIndex] > heapArray[largestIndex])
        largestIndex = leftChildIndex;

    // If right child exists and is larger than current largest
    if (rightChildIndex < heapSize && heapArray[rightChildIndex] > heapArray[largestIndex])
        largestIndex = rightChildIndex;

    // If the largest is not the initial root index, swap and continue heapifying
    if (largestIndex != index) {
        swap(heapArray[index], heapArray[largestIndex]);
        heapify(heapArray, heapSize, largestIndex);
    }
}

// Function to extract the maximum element from the heap
int extractMax(int heapArray[], int &heapSize) {
    if (heapSize <= 0) return -1; // Return -1 if heap is empty
    if (heapSize == 1) {
        heapSize--;
        return heapArray[0];
    }

    // The root of the heap is the maximum element
    int maxElement = heapArray[0];
    heapArray[0] = heapArray[heapSize - 1];
    heapSize--;
    heapify(heapArray, heapSize, 0);

    return maxElement;
}

// Main function to perform heap sort
void heapSort(int heapArray[], int heapSize) {
    // Build max heap from unordered array
    for (int i = heapSize / 2 - 1; i >= 0; i--)
        heapify(heapArray, heapSize, i);

    // Extract elements one by one from the heap
    while (heapSize > 0) {
        int maxElement = extractMax(heapArray, heapSize);
        heapArray[heapSize] = maxElement;  // Place max element at the end of the array
    }
}

// Function to print an array
void printArray(int heapArray[], int arraySize) {
    for (int i = 0; i < arraySize; ++i)
        cout << heapArray[i] << " ";
    cout << "\n";
}

// Driver program to test above functions
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7, 45, 71, 9, 12, 111, 45, 8, 15};
    int arraySize = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, arraySize);

    cout << "Sorted array is \n";
    printArray(arr, arraySize);
}
