#include <iostream>
#include <vector>

using namespace std;  // Use the entire standard namespace

// Returns the left child index of the element at index `position`
int getLeftChildIndex(int position) {
    return 2 * position;
}

// Returns the right child index of the element at index `position`
int getRightChildIndex(int position) {
    return 2 * position + 1;
}

// Returns the parent index of the element at index `position`
int getParentIndex(int position) {
    return position / 2;
}

// Maintains the max-heap property for the subtree rooted at index `position`
void maintainMaxHeap(vector<int>& heap, int heapSize, int position) {
    int leftChildIndex = getLeftChildIndex(position);
    int rightChildIndex = getRightChildIndex(position);
    int largestPosition = position;

    if (leftChildIndex < heapSize && heap[leftChildIndex] > heap[position]) {
        largestPosition = leftChildIndex;
    }

    if (rightChildIndex < heapSize && heap[rightChildIndex] > heap[largestPosition]) {
        largestPosition = rightChildIndex;
    }

    if (largestPosition != position) {
        swap(heap[position], heap[largestPosition]);  // Swap to maintain max-heap
        maintainMaxHeap(heap, heapSize, largestPosition);  // Recursively maintain the max-heap property
    }
}

// Builds a max-heap from an unsorted vector
void buildMaxHeap(vector<int>& heap) {
    int startIndex = heap.size() / 2;

    for (int i = startIndex; i >= 1; i--) {
        maintainMaxHeap(heap, heap.size(), i);
    }
}

// Performs heap sort on the vector `heap`
void heapSort(vector<int>& heap) {
    buildMaxHeap(heap);
    int currentHeapSize = heap.size();

    for (int i = currentHeapSize - 1; i >= 2; i--) {
        swap(heap[1], heap[i]);  // Move max to the end of the heap
        currentHeapSize--;  // Reduce the heap size
        maintainMaxHeap(heap, currentHeapSize, 1);  // Restore max-heap property
    }
}

// Main function to demonstrate heap sort
int main() {
    // Using dummy zero index for 1-based indexing
    vector<int> data = {0, 99, 0, 5, 20, 123, 0, -1, 72, 21, 22, 13, 8, 7, 67, 29, 1, 2, 4};

    heapSort(data);

    // Output the sorted data, skipping the dummy zero index
    for (int i = 1; i < data.size(); ++i) {
        cout << data[i] << " ";
    }
    cout << endl;

    // Another example
    vector<int> moreData = {0, 3, 9, 2, 1};
    heapSort(moreData);
    for (int i = 1; i < moreData.size(); ++i) {
        cout << moreData[i] << " ";
    }
    cout << endl;

    return 0;
}
