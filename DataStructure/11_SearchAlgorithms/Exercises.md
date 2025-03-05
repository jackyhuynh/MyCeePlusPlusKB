## Search Suggestions System

You are given an array of strings `products` and a string `searchWord`.

Design a system that suggests at most three product names from `products` after each character of `searchWord` is typed. Suggested products should have a common prefix with `searchWord`. If there are more than three products with a common prefix, return the three lexicographically smallest products.

Return a list of lists of the suggested products after each character of `searchWord` is typed.

---

### Example 1:

**Input:**
```plaintext
products = ["mobile","mouse","moneypot","monitor","mousepad"], searchWord = "mouse"
```

**Output:**
```plaintext
[["mobile","moneypot","monitor"],["mobile","moneypot","monitor"],["mouse","mousepad"],["mouse","mousepad"],["mouse","mousepad"]]
```

**Explanation:**
- Products sorted lexicographically: `["mobile","moneypot","monitor","mouse","mousepad"]`.
- After typing `m` and `mo`, all products match, suggesting `["mobile","moneypot","monitor"]`.
- After typing `mou`, `mous`, and `mouse`, the system suggests `["mouse","mousepad"]`.

---

### Example 2:

**Input:**
```plaintext
products = ["havana"], searchWord = "havana"
```

**Output:**
```plaintext
[["havana"],["havana"],["havana"],["havana"],["havana"],["havana"]]
```

**Explanation:**
- The only word `"havana"` will always be suggested while typing the search word.

---

## **Approach 1: Using Trie (Prefix Tree)**
A **Trie** is a tree-like data structure that allows efficient prefix-based searching. Here’s how we can implement it:

### **Algorithm**
1. Insert all `products` into a Trie.
2. For each prefix of `searchWord`, traverse the Trie and collect at most **three lexicographically smallest suggestions**.
3. Return the results.

### **Implementation (C++ using Trie)**
```cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Trie Node Structure
struct TrieNode {
    TrieNode* children[26] = {};
    vector<string> suggestions;
};

class Trie {
public:
    TrieNode* root;
    
    Trie() { root = new TrieNode(); }
    
    void insert(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
            if (node->suggestions.size() < 3)  // Store at most 3 suggestions
                node->suggestions.push_back(word);
        }
    }
    
    vector<vector<string>> getSuggestions(string searchWord) {
        vector<vector<string>> result;
        TrieNode* node = root;
        for (char ch : searchWord) {
            int index = ch - 'a';
            if (!node || !node->children[index]) {
                // No further suggestions available
                while (result.size() < searchWord.size()) 
                    result.push_back({});
                return result;
            }
            node = node->children[index];
            result.push_back(node->suggestions);
        }
        return result;
    }
};

vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
    sort(products.begin(), products.end());  // Sort products lexicographically
    Trie trie;
    for (string& product : products)
        trie.insert(product);
    
    return trie.getSuggestions(searchWord);
}

// Driver code
int main() {
    vector<string> products = {"mobile", "mouse", "moneypot", "monitor", "mousepad"};
    string searchWord = "mouse";
    
    vector<vector<string>> result = suggestedProducts(products, searchWord);
    
    for (auto& suggestions : result) {
        cout << "[ ";
        for (const string& s : suggestions) 
            cout << "\"" << s << "\" ";
        cout << "]\n";
    }
    return 0;
}
```

### **Time Complexity:**
- **Trie Insertion:** \( O(N \cdot M) \) (where \( N \) is the number of products and \( M \) is the max length of a product)
- **Search:** \( O(W) \) (where \( W \) is the length of `searchWord`)

### **Space Complexity:** \( O(N \cdot M) \) for storing words in Trie.

---

## **Approach 2: Sorting + Binary Search**
Instead of using a Trie, we can leverage **sorting** and **binary search** (using `lower_bound` from C++ STL).

### **Algorithm**
1. Sort `products` lexicographically.
2. For each prefix of `searchWord`, use **binary search** to find the first occurrence.
3. Collect up to **three lexicographically smallest products** starting from the found position.

### **Implementation (C++ using Binary Search)**
```cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
    sort(products.begin(), products.end());  // Sort products lexicographically
    vector<vector<string>> result;
    string prefix;
    
    auto it = products.begin();  // Iterator to track search range
    for (char ch : searchWord) {
        prefix += ch;
        // Use lower_bound to find the first occurrence of prefix
        it = lower_bound(it, products.end(), prefix);
        
        // Collect up to 3 lexicographically smallest matches
        vector<string> suggestions;
        for (auto i = it; i < min(it + 3, products.end()) && i->find(prefix) == 0; ++i) {
            suggestions.push_back(*i);
        }
        
        result.push_back(suggestions);
    }
    
    return result;
}

// Driver code
int main() {
    vector<string> products = {"mobile", "mouse", "moneypot", "monitor", "mousepad"};
    string searchWord = "mouse";
    
    vector<vector<string>> result = suggestedProducts(products, searchWord);
    
    for (auto& suggestions : result) {
        cout << "[ ";
        for (const string& s : suggestions) 
            cout << "\"" << s << "\" ";
        cout << "]\n";
    }
    return 0;
}
```

### **Time Complexity:**
- **Sorting:** \( O(N \log N) \)
- **Binary Search:** \( O(W \log N) \) (for each prefix)
- **Total:** \( O(N \log N + W \log N) \)

### **Space Complexity:** \( O(1) \) (sorting modifies input in place)

---

## **Comparison of Both Approaches**
| Approach | Time Complexity | Space Complexity | When to Use |
|----------|---------------|----------------|-------------|
| **Trie (Prefix Tree)** | \( O(NM + W) \) | \( O(NM) \) | When prefixes need to be searched frequently |
| **Sorting + Binary Search** | \( O(N \log N + W \log N) \) | \( O(1) \) | When input size is small or sorting is acceptable |

---

### **Which Approach to Use?**
- **Use Trie** if **prefix searches are frequent** (e.g., autocomplete in search engines).
- **Use Sorting + Binary Search** if **one-time query suffices** (e.g., static datasets).

Below is a **tuned** solution for the classic **Word Search** problem, along with an explanation on how to incorporate **search pruning** to make it faster when dealing with larger boards.

---

# Word Search

**Problem Statement**  
Given an \(m \times n\) grid of characters `board` and a string `word`, return `true` if `word` exists in the grid.

The word can be constructed from letters of **sequentially adjacent cells**, where adjacent cells are horizontally or vertically neighboring. The same letter cell **may not be used more than once**.

---

## Example

### Example 1
**Input:**  
```
board = [
    ["A","B","C","E"],
    ["S","F","C","S"],
    ["A","D","E","E"]
]
word = "ABCCED"
```
**Output:**  
```
true
```

### Example 2
**Input:**  
```
board = [
    ["A","B","C","E"],
    ["S","F","C","S"],
    ["A","D","E","E"]
]
word = "SEE"
```
**Output:**  
```
true
```

### Example 3
**Input:**  
```
board = [
    ["A","B","C","E"],
    ["S","F","C","S"],
    ["A","D","E","E"]
]
word = "ABCB"
```
**Output:**  
```
false
```

---

## Constraints
- \( m = \text{board.length} \)
- \( n = \text{board[i].length} \)
- \( 1 \leq m, n \leq 6 \)
- \( 1 \leq \text{word.length} \leq 15 \)
- `board` and `word` consist of **only lowercase and uppercase English letters**.

---

## Standard DFS (Backtracking) Solution

1. **Iterate** over every cell \((i, j)\) in the grid.
2. **If** `board[i][j] == word[0]`, start a DFS (depth-first search) from \((i, j)\).
3. **During DFS**:
   - Mark the current cell as **visited** (so we don’t reuse the same cell in one path).
   - Check if the current character matches the corresponding character in `word`.
   - If we have matched all characters in `word`, return `true`.
   - **Recursively** explore neighbors (up, down, left, right) to match subsequent characters.
   - **Unmark** the current cell (backtrack) before returning to explore other paths.

4. If DFS from any cell returns `true`, the word exists; otherwise, it does not.

### C++ Implementation (DFS + Backtracking)
```cpp
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        // Visited array to keep track of used cells
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // Try starting DFS from each cell
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, word, i, j, 0, visited)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

private:
    bool dfs(vector<vector<char>>& board, const string& word, 
             int row, int col, int index, vector<vector<bool>>& visited) {
        
        // If we've matched the entire word
        if (index == (int)word.size()) {
            return true;
        }

        // Out of bounds or character mismatch or already visited
        if (row < 0 || row >= (int)board.size() ||
            col < 0 || col >= (int)board[0].size() ||
            board[row][col] != word[index] || visited[row][col]) {
            return false;
        }

        // Mark current cell as visited
        visited[row][col] = true;

        // Directions: Up, Down, Left, Right
        static int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        for (auto &dir : dirs) {
            int newRow = row + dir[0];
            int newCol = col + dir[1];
            if (dfs(board, word, newRow, newCol, index + 1, visited)) {
                return true;
            }
        }

        // Backtrack
        visited[row][col] = false;
        return false;
    }
};

// Example usage
int main() {
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    string word = "ABCCED";
    Solution sol;
    bool res = sol.exist(board, word);
    cout << (res ? "true" : "false") << endl; // Expected: true
    return 0;
}
```

---

## Search Pruning for Larger Boards

Although the constraints here are small \((1 \leq m,n \leq 6)\), in a **larger** grid scenario, these optimizations can help:

1. **Letter Frequency Check**  
   - If `word` has more occurrences of a certain letter than the entire `board` does, return `false` immediately. This simple check prevents wasted DFS calls.  
   ```cpp
   // Example in C++:
   vector<int> freqBoard(128, 0), freqWord(128, 0);
   for (auto &row : board) {
       for (auto &ch : row) {
           freqBoard[ch]++;
       }
   }
   for (auto &ch : word) {
       freqWord[ch]++;
   }
   for (int i = 0; i < 128; ++i) {
       if (freqWord[i] > freqBoard[i]) {
           return false; // Not enough letters on the board
       }
   }
   ```

2. **Early Stopping on Impossible Paths**  
   - During DFS, if the next character is not in any of the neighboring cells, backtrack early.  
   - For each position, you can keep track of how many of each letter is still reachable. If the required letter for the remaining word can’t be matched, prune.

3. **Memoization (Optional in Some Variants)**  
   - We can keep a memo of `(row, col, index)` to store whether the path from this state leads to a successful match or not. This prevents recalculating the same paths multiple times.

4. **Directional Pruning**  
   - Sometimes, if you know that continuing in a certain direction can’t lead to a solution (based on partial frequency checks in that region), you can skip exploring that path.

For the given constraints, **simple DFS + backtracking** is more than sufficient. But if you ever encounter a variant with larger \(m\) or \(n\), incorporating these pruning techniques can significantly reduce runtime.

---

## Complexity
- **Time Complexity**:  
  - Worst-case, we explore all possible paths in the grid for each character of `word`. In the worst case, it’s \(O(m \times n \times 4^{L})\), where \(L\) is the length of `word`.  
  - Pruning can help reduce the effective branching factor.
- **Space Complexity**:  
  - \(O(m \times n)\) for the `visited` array in DFS, plus \(O(L)\) for recursion stack space (in the worst case).

---

### Key Takeaways
- Use **DFS + Backtracking** to explore all possible paths.
- **Mark** cells as visited to avoid reusing the same cell in one path.
- **Prune** early when you detect that future paths cannot possibly match the remaining letters in `word`.
- For small boards (\(m, n \leq 6\)), the standard DFS approach is often enough. For bigger boards, apply **frequency checks** and **memoization** if needed.
