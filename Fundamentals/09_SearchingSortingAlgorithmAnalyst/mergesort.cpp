#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

// Global counter to track recursion depth
int recursionDepth = 0;

// Helper function to create indentation based on recursion depth
string indent() {
    return string(recursionDepth * 2, ' ');
}

// Function to display a portion of the array
void displaySubArray(const vector<int>& arr, int left, int right, const string& message = "") {
    if (!message.empty()) {
        cout << indent() << message;
    }
    cout << "[ ";
    for (int i = left; i <= right; i++) {
        cout << setw(3) << arr[i];
        if (i < right) cout << ", ";
    }
    cout << " ]" << endl;
}

// Function to display the entire array
void displayArray(const vector<int>& arr, const string& message = "") {
    if (!message.empty()) {
        cout << message << endl;
    }
    cout << "[ ";
    for (size_t i = 0; i < arr.size(); i++) {
        cout << setw(3) << arr[i];
        if (i < arr.size() - 1) cout << ", ";
    }
    cout << " ]" << endl;
}

// Merge function - combines two sorted subarrays
void merge(vector<int>& arr, int left, int mid, int right) {
    cout << indent() << "┌─ MERGING:" << endl;
    cout << indent() << "│  Left half:  ";
    for (int i = left; i <= mid; i++) {
        cout << setw(3) << arr[i] << " ";
    }
    cout << endl;

    cout << indent() << "│  Right half: ";
    for (int i = mid + 1; i <= right; i++) {
        cout << setw(3) << arr[i] << " ";
    }
    cout << endl;

    // Create temporary arrays
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> leftArr(n1);
    vector<int> rightArr(n2);

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back
    int i = 0, j = 0, k = left;

    cout << indent() << "│" << endl;
    cout << indent() << "│  Merge process:" << endl;

    while (i < n1 && j < n2) {
        cout << indent() << "│  Compare " << leftArr[i] << " vs " << rightArr[j] << " → ";
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            cout << "Take " << leftArr[i] << " from left";
            i++;
        } else {
            arr[k] = rightArr[j];
            cout << "Take " << rightArr[j] << " from right";
            j++;
        }
        cout << endl;
        k++;
    }

    // Copy remaining elements from left array
    while (i < n1) {
        cout << indent() << "│  Take remaining " << leftArr[i] << " from left" << endl;
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy remaining elements from right array
    while (j < n2) {
        cout << indent() << "│  Take remaining " << rightArr[j] << " from right" << endl;
        arr[k] = rightArr[j];
        j++;
        k++;
    }

    cout << indent() << "└─ Result:     ";
    for (int idx = left; idx <= right; idx++) {
        cout << setw(3) << arr[idx] << " ";
    }
    cout << endl << endl;
}

// Merge Sort function with visualization
void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) {
        return; // Base case: 0 or 1 element
    }

    cout << indent() << "╔═ DIVIDE: ";
    displaySubArray(arr, left, right, "");

    int mid = left + (right - left) / 2;

    cout << indent() << "║  Split at index " << mid << " (value=" << arr[mid] << ")" << endl;
    cout << indent() << "║" << endl;

    // Left half
    cout << indent() << "╠─ LEFT:  ";
    displaySubArray(arr, left, mid, "");
    recursionDepth++;
    mergeSort(arr, left, mid);
    recursionDepth--;

    // Right half
    cout << indent() << "╠─ RIGHT: ";
    displaySubArray(arr, mid + 1, right, "");
    recursionDepth++;
    mergeSort(arr, mid + 1, right);
    recursionDepth--;

    cout << indent() << "╚═ CONQUER (Merge back):" << endl;
    recursionDepth++;
    merge(arr, left, mid, right);
    recursionDepth--;
}

// Wrapper function to start merge sort
void mergeSortWrapper(vector<int>& arr) {
    cout << "\n╔════════════════════════════════════════════════╗" << endl;
    cout << "║          MERGE SORT ALGORITHM                  ║" << endl;
    cout << "║    (Divide and Conquer Strategy)               ║" << endl;
    cout << "╚════════════════════════════════════════════════╝\n" << endl;

    cout << "CONCEPT:" << endl;
    cout << "1. DIVIDE: Split array into two halves recursively" << endl;
    cout << "2. CONQUER: Merge sorted halves back together" << endl;
    cout << "3. Time Complexity: O(n log n) - much faster!\n" << endl;

    displayArray(arr, "Initial array:");
    cout << "\n" << string(60, '=') << endl;
    cout << "STARTING MERGE SORT...\n" << string(60, '=') << endl << endl;

    recursionDepth = 0;
    mergeSort(arr, 0, arr.size() - 1);

    cout << string(60, '=') << endl;
    displayArray(arr, "FINAL SORTED ARRAY:");
    cout << string(60, '=') << endl;
}

// Visual tree representation of the merge sort process
void showMergeSortTree(const vector<int>& arr) {
    cout << "\n\n╔════════════════════════════════════════════════╗" << endl;
    cout << "║       MERGE SORT TREE VISUALIZATION            ║" << endl;
    cout << "╚════════════════════════════════════════════════╝\n" << endl;

    cout << "This shows how the array is divided and merged:\n" << endl;

    // For a small example array
    if (arr.size() == 5) {
        cout << "                [38, 27, 43, 3, 9]" << endl;
        cout << "                       |" << endl;
        cout << "           ┌───────────┴───────────┐" << endl;
        cout << "      [38, 27, 43]              [3, 9]" << endl;
        cout << "           |                        |" << endl;
        cout << "      ┌────┴────┐              ┌───┴───┐" << endl;
        cout << "   [38, 27]   [43]           [3]     [9]" << endl;
        cout << "       |        |              |       |" << endl;
        cout << "   ┌───┴──┐    [43]          [3]     [9]" << endl;
        cout << "  [38]  [27]                  |       |" << endl;
        cout << "    |     |                   └───┬───┘" << endl;
        cout << "    └──┬──┘                    [3, 9]" << endl;
        cout << "   [27, 38]                       |" << endl;
        cout << "       |                          |" << endl;
        cout << "       └──────┬───────────────────┘" << endl;
        cout << "       [27, 38, 43]                |" << endl;
        cout << "              |                    |" << endl;
        cout << "              └────────┬───────────┘" << endl;
        cout << "                [3, 9, 27, 38, 43]" << endl;
    }
}

int main() {
    // Example 1: Small array
    cout << "\n┌────────────────────────────────────────┐" << endl;
    cout << "│  EXAMPLE 1: Small Array (5 elements)  │" << endl;
    cout << "└────────────────────────────────────────┘" << endl;

    vector<int> data1 = {38, 27, 43, 3, 9};
    mergeSortWrapper(data1);
    showMergeSortTree(data1);

    cout << "\n\n";

    // Example 2: Larger array
    cout << "\n┌────────────────────────────────────────┐" << endl;
    cout << "│  EXAMPLE 2: Larger Array (8 elements) │" << endl;
    cout << "└────────────────────────────────────────┘" << endl;

    vector<int> data2 = {64, 25, 12, 22, 11, 90, 88, 45};
    mergeSortWrapper(data2);

    // Interactive section
    cout << "\n\n╔════════════════════════════════════════╗" << endl;
    cout << "║      YOUR TURN: CUSTOM ARRAY           ║" << endl;
    cout << "╚════════════════════════════════════════╝" << endl;

    cout << "\nEnter the number of elements: ";
    int n;
    cin >> n;

    vector<int> customArray(n);
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) {
        cin >> customArray[i];
    }

    mergeSortWrapper(customArray);

    // Summary comparison
    cout << "\n\n╔════════════════════════════════════════════════╗" << endl;
    cout << "║         ALGORITHM COMPARISON                   ║" << endl;
    cout << "╚════════════════════════════════════════════════╝" << endl;
    cout << "\n┌────────────────┬──────────────┬──────────────┐" << endl;
    cout << "│  Algorithm     │ Time (avg)   │ Space        │" << endl;
    cout << "├────────────────┼──────────────┼──────────────┤" << endl;
    cout << "│ Selection Sort │ O(n²)        │ O(1)         │" << endl;
    cout << "│ Bubble Sort    │ O(n²)        │ O(1)         │" << endl;
    cout << "│ Merge Sort     │ O(n log n)   │ O(n)         │" << endl;
    cout << "└────────────────┴──────────────┴──────────────┘" << endl;
    cout << "\nMerge Sort is MUCH faster for large datasets!" << endl;
    cout << "Example: For 1000 elements:" << endl;
    cout << "  - Bubble/Selection: ~1,000,000 operations" << endl;
    cout << "  - Merge Sort:       ~10,000 operations" << endl;

    return 0;
}
