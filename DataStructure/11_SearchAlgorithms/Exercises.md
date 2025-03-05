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

### Constraints:

- \( 1 \leq \) `products.length` \( \leq 1000 \)
- \( 1 \leq \) `products[i].length` \( \leq 3000 \)
- \( 1 \leq \) `\sum(products[i].length)` \( \leq 2 \times 10^4 \)
- All strings in `products` are unique.
- `products[i]` consists of lowercase English letters.
- \( 1 \leq \) `searchWord.length` \( \leq 1000 \)
- `searchWord` consists of lowercase English letters.

Yes! We can solve this problem efficiently in C++ using **Trie (Prefix Tree)** or **Sorting + Binary Search**. Below are both approaches:

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

# Word Search

Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

### Example 1:
- Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
- Output: true

```bash

["A","B","C","E"]
["S","F","C","S"]
["A","D","E","E"]

```
### Example 2:
- Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
- Output: true

```bash

["A","B","C","E"]
["S","F","C","S"]
["A","D","E","E"]

```
### Example 3:
- Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
- Output: false
 

### Constraints:

m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.
 

Follow up: Could you use search pruning to make your solution faster with a larger board?
