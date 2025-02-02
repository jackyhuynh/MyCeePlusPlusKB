# Map

In C++, `std::map` and `std::unordered_map` are two types of associative containers provided by the Standard Template
Library (STL). They both store key-value pairs and allow for efficient lookup, insertion, and deletion of elements, but
they have important differences in their underlying implementations and behavior.

### `std::map` (Ordered Map)

- **Implementation**: `std::map` is implemented as a balanced binary search tree (typically a Red-Black tree).
- **Order**: It maintains the elements in a sorted order based on the key. The order is determined by the comparison
  function (by default, this is `std::less<T>`).
- **Complexity**: Lookup, insertion, and deletion operations have a time complexity of \( O(\log n) \).
- **Use Case**: Use `std::map` when you need to maintain the elements in a specific order and can tolerate a slightly
  higher time complexity compared to `std::unordered_map`.

**Example Code**:

```cpp
#include <iostream>
#include <map>

int main() {
    std::map<int, std::string> orderedMap;
    orderedMap[3] = "Three";
    orderedMap[1] = "One";
    orderedMap[2] = "Two";

    // The elements are printed in key order: 1, 2, 3
    for (const auto& pair : orderedMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
```

**Output**:

```
1: One
2: Two
3: Three
```

### `std::unordered_map` (Unordered Map)

- **Implementation**: `std::unordered_map` is implemented as a hash table.
- **Order**: It does **not** maintain the elements in any specific order. The order of the elements depends on the hash
  function and how they are stored in the buckets.
- **Complexity**: Average time complexity for lookup, insertion, and deletion is \( O(1) \). However, in the worst
  case (due to hash collisions), the complexity can degrade to \( O(n) \).
- **Use Case**: Use `std::unordered_map` when you need faster access times and do not care about the order of the
  elements.

**Example Code**:

```cpp
#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<int, std::string> unorderedMap;
    unorderedMap[3] = "Three";
    unorderedMap[1] = "One";
    unorderedMap[2] = "Two";

    // The elements are printed in an unspecified order
    for (const auto& pair : unorderedMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
```

**Possible Output**:

```
3: Three
1: One
2: Two
```

(Note: The output order may vary each time you run the program.)

### Key Differences:

1. **Ordering**:
    - `std::map`: Maintains keys in sorted order.
    - `std::unordered_map`: No specific order for keys.

2. **Time Complexity**:
    - `std::map`: \( O(\log n) \) for lookup, insertion, and deletion.
    - `std::unordered_map`: \( O(1) \) on average for lookup, insertion, and deletion.

3. **Memory Usage**:
    - `std::map`: Uses more memory due to tree structures and node pointers.
    - `std::unordered_map`: May use more memory for the hash table and handle hash collisions.

4. **Use Case**:
    - Use `std::map` when order is important.
    - Use `std::unordered_map` for faster performance when order is not needed.

### Conclusion:

Choose `std::map` when you need sorted keys and can accept slightly higher time complexity. Use `std::unordered_map`
when you need faster average access time and don't need to maintain any order of keys.