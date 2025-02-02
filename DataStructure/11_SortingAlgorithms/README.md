# Chapter 11: Sorting Algorithms and Their Efficiency

---

## Resources:

- [W3 School Search and Sort Algorithm](https://www.w3schools.com/dsa/index.php)

## **1. Basic Sorting Algorithms**

Sorting refers to organizing a collection of data into either ascending or descending order. There are two types of
sorting:

- **Internal sort**: All data fits in memory.
- **External sort**: Data resides on secondary storage due to its size.

### **Three Basic Sorting Algorithms**:

1. **Selection Sort**
2. **Bubble Sort**
3. **Insertion Sort**

---

### **1.1 Selection Sort**

Selection sort repeatedly selects the smallest (or largest) element from the unsorted portion of the array and moves it
to its correct position.

### **Code Example**:

```cpp
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        std::swap(arr[i], arr[minIndex]);
    }
}
```

### **Efficiency**:

- **Time Complexity**: O(n²)
- Suitable for small arrays, especially when data moves are costly but comparisons are not.

---

### **1.2 Bubble Sort**

Bubble sort compares adjacent elements and swaps them if they are out of order. Multiple passes are made over the data,
with larger items "bubbling" to the end of the array.

### **Code Example**:

```cpp
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}
```

### **Efficiency**:

- **Worst-case time complexity**: O(n²)
- **Best-case time complexity** (already sorted array): O(n)

---

### **1.3 Insertion Sort**

Insertion sort takes one element from the unsorted part of the array and inserts it into the correct position in the
sorted part.

### **Code Example**:

```cpp
void insertionSort(int arr[], int n) {
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
```

### **Efficiency**:

- **Worst-case time complexity**: O(n²)
- **Best-case time complexity**: O(n), making it appropriate for small, nearly sorted arrays.

---

## **2. Faster Sorting Algorithms**

### **2.1 Merge Sort**

Merge sort is a divide-and-conquer algorithm that recursively splits an array in half, sorts each half, and merges them
back together.

### **Code Example**:

```cpp
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
```

### **Efficiency**:

- **Time complexity**: O(n log n) in all cases.
- Merge sort uses extra memory for the temporary arrays.

---

### **2.2 Quick Sort**

Quick sort is another divide-and-conquer algorithm. It selects a **pivot** element and partitions the array into
elements less than or equal to the pivot and those greater than the pivot. The process is recursively applied to each
partition.

### **Code Example**:

```cpp
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
```

### **Efficiency**:

- **Best and average-case time complexity**: O(n log n)
- **Worst-case time complexity**: O(n²), occurs when the smallest or largest element is always chosen as the pivot.

---

### **2.3 Radix Sort**

Radix sort is a non-comparative algorithm that sorts integers by processing individual digits. It groups numbers based
on their digits and reorders them.

### **Code Example** (Pseudocode):

```cpp
void radixSort(int arr[], int n) {
    // Assumes all numbers have the same number of digits
    for (int digit = 1; mostSignificantDigit <= d; digit++) {
        // Use a stable sort to sort numbers based on the current digit
        countingSort(arr, digit);
    }
}
```

### **Efficiency**:

- **Time complexity**: O(n) when the number of digits is constant.
- **Best suited for large datasets of integers** or strings with a fixed number of digits/characters.

---

## **3. Comparison of Sorting Algorithms**

### **Growth Rates**:

- **Selection Sort, Bubble Sort, Insertion Sort**: O(n²)
- **Merge Sort, Quick Sort, Radix Sort**: O(n log n) or better for certain cases.

---

## **Conclusion**

- **Basic sorting algorithms** (selection, bubble, insertion) are easier to implement but inefficient for large
  datasets.
- **Faster sorting algorithms** (merge sort, quick sort, radix sort) offer significantly better performance for large
  datasets but come with additional complexity.
- Choosing the right sorting algorithm depends on the size of the dataset and specific needs, such as memory usage or
  whether the dataset is nearly sorted.