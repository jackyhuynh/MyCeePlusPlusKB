## Heap Sort Explained

Heap sort is a comparison-based sorting algorithm that leverages the properties of a binary heap data structure to efficiently sort an array. The core idea is to first transform the array into a heap (either a max-heap or a min-heap) and then repeatedly extract the root element (which is the largest or smallest, respectively) to build a sorted array.

[Heap Sort Algorithm](https://algostructure.com/sorting/heapsort.php)

### The Role of the `heapify` Function

The `heapify` function is instrumental in maintaining the heap property within a binary tree. It ensures that for any given subtree rooted at a particular node, the parent node satisfies the heap condition with respect to its children. This function is crucial for both building the initial heap and for maintaining the heap structure during the sorting process.

### Building a Max-Heap Using `heapify`

To sort an array in ascending order using heap sort, we first build a max-heap. In a max-heap, the value of each parent node is greater than or equal to the values of its children.

**Step-by-Step Process:**

Given an array, we can transform it into a max-heap by applying the `heapify` function to each non-leaf node, starting from the last non-leaf node and moving towards the root. The index of the last non-leaf node in an array of size $n$ is $\lfloor n/2 \rfloor - 1$.

**Example Array**: `[3, 5, 1, 10, 2, 7]`

1. **Initial Array**: `[3, 5, 1, 10, 2, 7]`

2. **Start with the last non-leaf node**: For an array of 6 elements, the last non-leaf node is at index $\lfloor 6/2 \rfloor - 1 = 2$ (value `1`).

3. **Apply `heapify` from right to left on non-leaf nodes**:

   a. **Index 2 (value 1)**:
      - Compare with children at indices $2 \times 2 + 1 = 5$ (value `7`).
      - Since $7 > 1$, swap them.
      - **New array**: `[3, 5, 7, 10, 2, 1]`

   b. **Index 1 (value 5)**:
      - Compare with children at indices $2 \times 1 + 1 = 3$ (value `10`) and $2 \times 1 + 2 = 4$ (value `2`).
      - The largest child is `10`. Since $10 > 5$, swap them.
      - **New array**: `[3, 10, 7, 5, 2, 1]`

   c. **Index 0 (value 3)**:
      - Compare with children at indices $2 \times 0 + 1 = 1$ (value `10`) and $2 \times 0 + 2 = 2$ (value `7`).
      - The largest child is `10`. Since $10 > 3$, swap them.
      - **New array**: `[10, 3, 7, 5, 2, 1]`
      - Now, the subtree rooted at index 1 might violate the heap property. Apply `heapify` at index 1:
        - Compare `3` with its child at index $2 \times 1 + 1 = 3$ (value `5`).
        - Since $5 > 3$, swap them.
        - **Final max-heap array**: `[10, 5, 7, 3, 2, 1]`

### Building a Min-Heap Using `heapify`

To sort an array in descending order, we would build a min-heap. In a min-heap, the value of each parent node is less than or equal to the values of its children.

**Example Array**: `[3, 5, 1, 10, 2, 7]`

**Heapify Steps**:

1. **Start from index 2 (value 1)**:
   - Compare with child at index 5 (value `7`). Since $1 < 7$, no swap needed.

2. **Move to index 1 (value 5)**:
   - Compare with children at indices 3 (value `10`) and 4 (value `2`).
   - The smallest child is `2`. Since $2 < 5$, swap them.
   - **New array**: `[3, 2, 1, 10, 5, 7]`

3. **Move to index 0 (value 3)**:
   - Compare with children at indices 1 (value `2`) and 2 (value `1`).
   - The smallest child is `1`. Since $1 < 3$, swap them.
   - **New array**: `[1, 2, 3, 10, 5, 7]`
   - Now, the subtree rooted at index 2 might violate the heap property. Apply `heapify` at index 2:
     - Compare `3` with its child at index $2 \times 2 + 1 = 5$ (value `7`). Since $3 < 7$, no swap needed.

**Final min-heap array**: `[1, 2, 3, 10, 5, 7]`

![heapify](./images/heapify.png)

### Summary of `heapify` Steps:

1. Begin at the last non-leaf node of the array and iterate towards the root. The parent of a node at index $i$ is given by $\lfloor (i-1)/2 \rfloor$.
2. For each node, compare its value with its children.
3. In a max-heap, if the parent is smaller than either child, swap it with the larger child. In a min-heap, if the parent is larger than either child, swap it with the smaller child.
4. After a swap, recursively apply `heapify` to the affected subtree to ensure the heap property is maintained.

### Visualizing the Heap Structure

The array can be visualized as a binary tree where the element at index $i$ has children at indices $2i + 1$ and $2i + 2$.

**Visualizing the Max-Heap**

Initial tree before heapifying:

```
      3
     / \
    5   1
   / \   \
  10  2   7
```

After building the max-heap:

```
      10
     /  \
    5    7
   / \   /
  3   2 1
```

**Visualizing the Min-Heap**

Initial tree before heapifying:

```
      3
     / \
    5   1
   / \   \
  10  2   7
```

After building the min-heap:

```
      1
     / \
    2   3
   / \   \
  10  5   7
```

### Heap Sort Algorithm in Detail

Heap sort utilizes a max-heap for ascending order sorting. The algorithm proceeds as follows:

1. **Build a Max-Heap**: Convert the input array into a max-heap using the `heapify` process described earlier.

2. **Extract and Sort**:
   - While the size of the heap is greater than 1:
     - Swap the root of the heap (the largest element) with the last element of the heap.
     - Decrease the heap size by 1. The largest element is now in its correct sorted position at the end of the array.
     - Call `heapify` on the root of the reduced heap to restore the max-heap property.

### Time and Space Complexity of Heap Sort

- **Time Complexity**:
  - **Best Case**: \( O(n \log n) \)
  - **Average Case**: \( O(n \log n) \)
  - **Worst Case**: \( O(n \log n) \)
- **Space Complexity**: \( O(1) \) (in-place sorting)

### Key Properties of Heap Sort

- **In-Place**: Heap sort sorts the array directly within the original array, requiring minimal additional memory.
- **Not Stable**: The relative order of elements with equal values is not guaranteed to be preserved.
- **Consistent Performance**: Heap sort provides a guaranteed \( O(n \log n) \) time complexity, making it a reliable choice when consistent performance is crucial.

### When to Choose Heap Sort

- **Memory Constraints**: Its \( O(1) \) space complexity makes it suitable for environments with limited memory.
- **Guaranteed Time Complexity**: When a guaranteed \( O(n \log n) \) sorting time is required, regardless of the input data.

### How `heapify` Underpins Heap Sort

The `heapify` function is called during the initial step of building the max-heap and subsequently after each extraction of the maximum element. This ensures that the remaining elements always satisfy the max-heap property, allowing the next largest element to be readily available at the root.

### Summary of Heap Sort

Heap sort is an efficient and in-place sorting algorithm that leverages the heap data structure. By building a max-heap and repeatedly extracting the largest element, it sorts the array with a consistent \( O(n \log n) \) time complexity. The `heapify` function is the cornerstone of this process, ensuring the integrity of the heap property throughout the algorithm.

### Use Cases and Importance of `heapify` Beyond Heap Sort

The `heapify` function is not limited to heap sort; it plays a vital role in various other applications where maintaining the heap property is essential.

1.  **Building a Heap from an Unsorted Array**:
    - **Use Case**: Converting an arbitrary array into a heap structure.
    - **Why**: This is the foundational step for using heaps in priority queues and other heap-based algorithms. The efficient \( O(n) \) time complexity of building a heap using `heapify` (compared to \( O(n \log n) \) by repeated insertion) is a significant advantage.

2.  **Priority Queue Implementation**:
    - **Use Case**: Managing a collection of elements with associated priorities, where the element with the highest (or lowest) priority needs to be accessed quickly.
    - **Why**: Priority queues often use heaps as their underlying data structure. `heapify` is crucial for maintaining the heap property after insertion or deletion of elements, ensuring that the element with the highest priority is always at the root. Operations like `push` (insertion) and `pop` (extraction) rely on `heapify` to restore the heap order.

3.  **Dynamic Data Structure for Real-Time Applications**:
    - **Use Case**: Systems where data priorities can change dynamically, and the structure needs to be reordered efficiently.
    - **Why**: In applications like task scheduling or event handling, the priority of tasks or events might be updated. `heapify` allows for efficient readjustment of the heap to reflect these changes in \( O(\log n) \) time.

4.  **Graph Algorithms**:
    - **Use Case**: Algorithms like Dijkstra's for finding the shortest paths and Prim's for finding the minimum spanning tree often use priority queues to select the next vertex to explore.
    - **Why**: When the distance to a vertex is updated in Dijkstra's or the cost to add a vertex to the MST changes in Prim's, the priority queue (often implemented as a heap) needs to be reordered. `heapify` ensures that the vertex with the smallest current distance or cost is always at the top of the priority queue.

5.  **K-th Largest/Smallest Element**:
    - **Use Case**: Finding the $k$-th largest or smallest element in an array.
    - **Why**: By building a min-heap of size $k$ from the first $k$ elements and then iterating through the rest of the array, comparing elements with the root and using `heapify` to maintain the min-heap property, we can efficiently find the $k$-th smallest element. A similar approach with a max-heap can find the $k$-th largest.

### Why is `heapify` Important?

1.  **Efficiency**: `heapify` ensures that the heap property can be restored in \( O(\log n) \) time, which is critical for maintaining the efficiency of heap-based data structures and algorithms.
2.  **Simplicity**: It provides a straightforward method for ensuring that a binary tree satisfies the heap property without the need for more complex restructuring.
3.  **Versatility**: `heapify` is applicable to both max-heaps and min-heaps, making it a fundamental operation for a wide range of applications involving ordered data.

### How `heapify` Works Internally

The `heapify` process typically involves:

1.  Starting at a given node index in the array representation of the binary tree.
2.  Comparing the node with its left and right children.
3.  For a max-heap, if a child is larger than the current node, the node is swapped with the larger child. For a min-heap, the swap occurs with the smaller child.
4.  After the swap, `heapify` is recursively called on the affected child's subtree to ensure that the heap property is maintained down the tree.
