#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Function to display the array
void displayArray(const vector<int>& arr, const string& message = "") {
    if (!message.empty()) {
        cout << message << endl;
    }
    cout << "[ ";
    for (int num : arr) {
        cout << setw(3) << num << " ";
    }
    cout << "]" << endl;
}

// Function to display array with highlighting
void displayArrayWithHighlight(const vector<int>& arr, int minIndex, int currentIndex, int sortedBoundary) {
    cout << "[ ";
    for (int i = 0; i < arr.size(); i++) {
        if (i == minIndex) {
            cout << "*" << setw(2) << arr[i] << "*";
        } else if (i == currentIndex) {
            cout << ">" << setw(2) << arr[i] << "<";
        } else if (i < sortedBoundary) {
            cout << "[" << setw(2) << arr[i] << "]";
        } else {
            cout << " " << setw(2) << arr[i] << " ";
        }
        cout << " ";
    }
    cout << "]" << endl;
}

// Selection Sort with step-by-step visualization
void selectionSort(vector<int>& arr) {
    int n = arr.size();

    // cout << "\n========== SELECTION SORT ALGORITHM ==========" << endl;
    // cout << "Legend: [sorted] *minimum* >comparing< unsorted\n" << endl;

    // displayArray(arr, "Initial array:");
    // cout << endl;

    // Outer loop: moves the boundary between sorted and unsorted
    for (int i = 0; i < n - 1; i++) {
        // cout << "--- Pass " << (i + 1) << " ---" << endl;
        // cout << "Finding minimum in positions " << i << " to " << (n - 1) << endl;

        // Assume the first element of unsorted portion is minimum
        int minIndex = i;

        // Inner loop: find the minimum element in unsorted portion
        for (int j = i + 1; j < n; j++) {
            // cout << "  Comparing arr[" << minIndex << "]=" << arr[minIndex]
            //      << " with arr[" << j << "]=" << arr[j];

            if (arr[j] < arr[minIndex]) {
                minIndex = j;
                // cout << " -> New minimum found at index " << minIndex;
            }
            // cout << endl;

            // displayArrayWithHighlight(arr, minIndex, j, i);
        }

        // Swap the minimum element with the first unsorted element
        if (minIndex != i) {
            // cout << "\n  Swapping arr[" << i << "]=" << arr[i]
            //      << " with arr[" << minIndex << "]=" << arr[minIndex] << endl;
            swap(arr[i], arr[minIndex]);
        } else {
            // cout << "\n  No swap needed (element already in correct position)" << endl;
        }

        // displayArray(arr, "  After pass " + to_string(i + 1) + ":");
        // cout << endl;
    }

    cout << "========================================" << endl;
    displayArray(arr, "Final sorted array:");
}

// Bubble Sort with step-by-step visualization
void bubbleSort(vector<int>& arr) {
    int n = arr.size();

    // cout << "\n========== BUBBLE SORT ALGORITHM ==========" << endl;
    // cout << "Compares adjacent elements and swaps if out of order\n" << endl;

    // displayArray(arr, "Initial array:");
    // cout << endl;

    for (int i = 0; i < n - 1; i++) {
        // cout << "--- Pass " << (i + 1) << " ---" << endl;
        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++) {
            // cout << "  Comparing arr[" << j << "]=" << arr[j]
            //      << " with arr[" << (j + 1) << "]=" << arr[j + 1];

            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
                // cout << " -> Swap!" << endl;
            } else {
                // cout << " -> No swap" << endl;
            }

            // displayArray(arr, "    ");
        }

        // displayArray(arr, "  After pass " + to_string(i + 1) + ":");

        if (!swapped) {
            cout << "  (No swaps made - array is sorted!)" << endl;
            break;
        }
        // cout << endl;
    }

    cout << "========================================" << endl;
    displayArray(arr, "Final sorted array:");
}

int main() {
    // Example 1: Selection Sort
    vector<int> data1 = {64, 25, 12, 22, 11};

    cout << "\n╔════════════════════════════════════════╗" << endl;
    cout << "║    DEMONSTRATION: SELECTION SORT       ║" << endl;
    cout << "╚════════════════════════════════════════╝" << endl;

    selectionSort(data1);

    cout << "\n\n";

    // Example 2: Bubble Sort
    vector<int> data2 = {64, 25, 12, 22, 11};

    cout << "\n╔════════════════════════════════════════╗" << endl;
    cout << "║      DEMONSTRATION: BUBBLE SORT        ║" << endl;
    cout << "╚════════════════════════════════════════╝" << endl;

    bubbleSort(data2);
    return 0;
}
