# Recursive

Fill in the ****************

### **1. Count Digits of a Number**
Write a recursive function to count the number of digits in a given integer.

```cpp
int countDigits(int n) {
    if (n == 0) return 0;
    return ****************;
}
```
**Example Input:** `countDigits(12345)`  
**Example Output:** `5`

---

### **2. Sum of Digits**
Write a recursive function that returns the sum of the digits of a given integer.

```cpp
int sumOfDigits(int n) {
    if ****************;
    return ****************;
}
```
**Example Input:** `sumOfDigits(1234)`  
**Example Output:** `10`

---

### **3. Decimal to Binary Conversion**
Write a recursive function that converts a decimal number to binary.

```cpp
void decimalToBinary(int n) {
    if (n == 0) return;
    ****************;
    cout << (n % 2);
}
```
**Example Input:** `decimalToBinary(10)`  
**Example Output:** `1010`

---

### **4. Generate All Subsets of a String**
Write a recursive function that prints all subsets of a given string.

```cpp
void generateSubsets(string s, string current, int index) {
    if (index == s.length()) {
        cout << current << endl;
        return;
    }
    generateSubsets(s, current, index + 1);
    generateSubsets(s, current + s[index], index + 1);
}
```
**Example Input:** `generateSubsets("abc", "", 0);`  
**Example Output:**
```
(empty)
c
b
bc
a
ac
ab
abc
```

---

### **5. Print All Permutations of a String**
Write a recursive function that generates all permutations of a given string.

```cpp
void permute(string s, int l, int r) {
    if (l == r) {
        cout << s << endl;
        return;
    }
    for (int i = l; i <= r; i++) {
        swap(s[l], s[i]);
        permute(s, l + 1, r);
        swap(s[l], s[i]); // Backtrack
    }
}
```
**Example Input:** `permute("abc", 0, 2);`  
**Example Output:**
```
abc
acb
bac
bca
cab
cba
```

---

### **6. Find the Minimum Element in an Array**
Write a recursive function that finds the smallest element in an array.

```cpp
int findMin(vector<int>& arr, int n) {
    if (n == 1) return arr[0];
    return min(arr[n-1], findMin(arr, n-1));
}
```
**Example Input:** `findMin({3, 1, 4, 1, 5, 9}, 6);`  
**Example Output:** `1`

---

### **7. Check if an Array is Sorted**
Write a recursive function that checks if an array is sorted in ascending order.

```cpp
bool isSorted(vector<int>& arr, int n) {
    if (n == 1) return true;
    return arr[n-1] >= arr[n-2] && isSorted(arr, n-1);
}
```
**Example Input:** `isSorted({1, 2, 3, 4, 5}, 5);`  
**Example Output:** `true`

---

### **8. Josephus Problem**
The Josephus problem is a famous theoretical problem related to a group of people standing in a circle, where every kth person is eliminated until only one remains.

```cpp
int josephus(int n, int k) {
    if (n == 1) return 0;
    return (josephus(n - 1, k) + k) % n;
}
```
**Example Input:** `josephus(7, 3);`  
**Example Output:** `3`

---

### **9. Merge Sort (Recursive)**
Write a recursive function to implement Merge Sort.

```cpp
void merge(vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}
```
**Example Input:** `mergeSort({5, 2, 9, 1, 5, 6}, 0, 5);`  
**Example Output:** `{1, 2, 5, 5, 6, 9}`

---

### **10. Generate Balanced Parentheses**
Write a recursive function to generate all valid balanced parentheses of length `2n`.

```cpp
void generateParentheses(int open, int close, string str) {
    if (open == 0 && close == 0) {
        cout << str << endl;
        return;
    }
    if (open > 0) generateParentheses(open - 1, close, str + "(");
    if (close > open) generateParentheses(open, close - 1, str + ")");
}
```
**Example Input:** `generateParentheses(3, 3, "");`  
**Example Output:**
```
((()))
(()())
(())()
()(())
()()()
```

---

### **Bonus Challenge: N-Queens Problem**
Write a recursive function that solves the N-Queens problem, where `N` queens are placed on an `N × N` chessboard such that no two queens attack each other.

```cpp
bool isSafe(vector<vector<int>>& board, int row, int col, int n) {
    for (int i = 0; i < row; i++)
        if (board[i][col]) return false;
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]) return false;
    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
        if (board[i][j]) return false;
    return true;
}

void solveNQueens(vector<vector<int>>& board, int row, int n) {
    if (row == n) {
        for (const auto& r : board) {
            for (int c : r) cout << (c ? "Q " : ". ");
            cout << endl;
        }
        cout << endl;
        return;
    }
    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 1;
            solveNQueens(board, row + 1, n);
            board[row][col] = 0;
        }
    }
}
```
**Example Input:** `solveNQueens(vector<vector<int>>(4, vector<int>(4, 0)), 0, 4);`  
**Example Output:**
```
Q . . .
. . Q .
. Q . .
. . . Q
```