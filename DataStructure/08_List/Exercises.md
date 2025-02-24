# Exercises

## Problem 1: Maximum Subarray (Kadane’s Algorithm)

**Problem Statement:**
Given an array of integers, find the contiguous subarray (containing at least one number) which has the largest sum. This is a classic problem solved efficiently by Kadane’s algorithm.

**Approach:**
1. Read the array of integers into a `std::vector<int>`. 
2. Iterate through the vector and keep track of the current subarray sum. 
3. Update the maximum sum found so far.

**Code:**
```cpp
#include <iostream>
#include <vector>
#include <algorithm> // for std::max
#include <cstdlib>   // for rand() and srand()
#include <ctime>     // for time()

using namespace std;

int main() {
    const int array_size = 20;  // Fixed size of 20
    vector<int> random_array(array_size);

    // Seed the random number generator
    srand(static_cast<unsigned>(time(0)));
    
    // Fill the vector with random integers between -50 and 50
    for (int i = 0; i < array_size; i++) {
        random_array[i] = rand() % 101 - 50; // Generates numbers in the range -50 to 50
    }
    
    // Display the randomly generated array
    cout << "Random array:\n";
    for (int num : random_array) {
        cout << num << " ";
    }
    cout << "\n\n";

    // Apply Kadane's algorithm to find the maximum subarray sum
    int current_max_sum = random_array[0];
    int overall_max_sum = random_array[0];

    for (int i = 1; i < array_size; i++) {
        current_max_sum = max(random_array[i], current_max_sum + random_array[i]);
        overall_max_sum = max(overall_max_sum, current_max_sum);
    }

    cout << "Maximum subarray sum is: " << overall_max_sum << endl;
    return 0;
}
```

---

## Problem 2: Rotate a Vector

**Problem Statement:**
Given a vector of integers and an integer k, rotate the vector to the right by k positions.

**Approach:**
1. Use a std::vector<int> to store the elements. 
2. Normalize k by taking k % n (where n is the number of elements). 
3. Reverse the entire vector. 
4. Reverse the first k elements. 
5. Reverse the remaining elements.

**Code:**
```cpp
#include <iostream>
#include <vector>
#include <algorithm> // for std::reverse
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    const int vector_size = 20;  // Vector size
    vector<int> random_vector(vector_size);
    
    srand(static_cast<unsigned>(time(0)));
    
    // Fill the vector with random integers between 0 and 99
    for (int i = 0; i < vector_size; i++) {
        random_vector[i] = rand() % 100;
    }
    
    // Display the original vector
    cout << "Original vector:\n";
    for (int num : random_vector) {
        cout << num << " ";
    }
    cout << "\n\n";

    // Generate a random rotation count between 0 and vector_size - 1
    int rotation_count = rand() % vector_size;
    cout << "Rotating vector by " << rotation_count << " positions.\n";

    // Rotate the vector using the reverse method:
    reverse(random_vector.begin(), random_vector.end());
    reverse(random_vector.begin(), random_vector.begin() + rotation_count);
    reverse(random_vector.begin() + rotation_count, random_vector.end());

    // Display the rotated vector
    cout << "\nRotated vector:\n";
    for (int num : random_vector) {
        cout << num << " ";
    }
    cout << "\n";
    
    return 0;
}
```

---

## Problem 3: Merge Two Sorted Vectors 

**Problem Statement:**
Given two sorted vectors, merge them into a single sorted vector.

**Approach:**
1. Read two sorted `std::vector<int>` inputs. 
2. Use two indices (pointers) to iterate through both vectors simultaneously. 
3. Compare elements from both vectors and push the smaller one into the merged vector. 
4. Append any remaining elements from either vector.

**Code:**

```cpp
#include <iostream>
#include <vector>
#include <algorithm> // for std::sort
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    const int first_vector_size = 10;
    const int second_vector_size = 10;
    vector<int> first_vector(first_vector_size), second_vector(second_vector_size);
    
    srand(static_cast<unsigned>(time(0)));
    
    // Fill each vector with random integers between 0 and 100
    for (int i = 0; i < first_vector_size; i++) {
        first_vector[i] = rand() % 101;
    }
    for (int i = 0; i < second_vector_size; i++) {
        second_vector[i] = rand() % 101;
    }
    
    // Sort both vectors
    sort(first_vector.begin(), first_vector.end());
    sort(second_vector.begin(), second_vector.end());
    
    // Display the sorted vectors
    cout << "First sorted vector:\n";
    for (int num : first_vector) {
        cout << num << " ";
    }
    cout << "\n\n";
    
    cout << "Second sorted vector:\n";
    for (int num : second_vector) {
        cout << num << " ";
    }
    cout << "\n\n";
    
    // Merge the two sorted vectors
    vector<int> merged_vector;
    merged_vector.reserve(first_vector_size + second_vector_size);
    
    int index_first = 0, index_second = 0;
    while (index_first < first_vector_size && index_second < second_vector_size) {
        if (first_vector[index_first] < second_vector[index_second])
            merged_vector.push_back(first_vector[index_first++]);
        else
            merged_vector.push_back(second_vector[index_second++]);
    }
    while (index_first < first_vector_size) {
        merged_vector.push_back(first_vector[index_first++]);
    }
    while (index_second < second_vector_size) {
        merged_vector.push_back(second_vector[index_second++]);
    }
    
    // Display the merged sorted vector
    cout << "Merged sorted vector:\n";
    for (int num : merged_vector) {
        cout << num << " ";
    }
    cout << "\n";
    
    return 0;
}
```

---

## Problem 4: Count Frequency of Elements in a List 

**Problem Statement:**
Given a list of integers, count the frequency of each distinct element and print the result.

**Approach:**
1. Use a `std::list<int>` to store the input integers. 
2. Use an auxiliary `std::unordered_map<int, int>` to count the frequency of each element. 
3. Iterate through the list to populate the map. 
4. Output each element and its frequency.

**Code:**
```cpp
#include <iostream>
#include <list>
#include <unordered_map>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    const int list_size = 20;  // List size
    list<int> random_list;
    
    srand(static_cast<unsigned>(time(0)));
    
    // Fill the list with random integers between 1 and 10
    for (int i = 0; i < list_size; i++) {
        random_list.push_back(rand() % 10 + 1);
    }
    
    // Display the randomly generated list
    cout << "Random list:\n";
    for (int num : random_list) {
        cout << num << " ";
    }
    cout << "\n\n";
    
    // Count frequency using an unordered_map
    unordered_map<int, int> frequency;
    for (int num : random_list) {
        frequency[num]++;
    }
    
    // Display the frequency of each element
    cout << "Frequency of each element:\n";
    for (const auto &pair : frequency) {
        cout << pair.first << " occurs " << pair.second << " times.\n";
    }
    
    return 0;
}
```

---

## Problem 5: Removing Duplicates from a List Using std::list

**Problem Statement:**  
Given a list of integers, remove duplicate elements while preserving the order of the first occurrences.

**Approach:**
1. Use a `std::list<int>` to store the input values.
2. Utilize an auxiliary container (`std::unordered_set`) to track seen values.
3. Iterate over the list and erase any element that has already been encountered.

**Code:**
```cpp
#include <iostream>
#include <list>
#include <unordered_set>

using namespace std;

int main() {
    // Example list with duplicates
    list<int> numbers = {1, 2, 3, 2, 4, 1, 5};
    unordered_set<int> seen;

    // Iterate over the list and remove duplicates
    for(auto it = numbers.begin(); it != numbers.end(); ) {
        if (seen.find(*it) != seen.end()) {
            it = numbers.erase(it); // erase returns the next iterator
        } else {
            seen.insert(*it);
            ++it;
        }
    }

    cout << "List after removing duplicates: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
```
**Explanation:**
- The `std::list<int>` container holds the numbers.
- An `std::unordered_set<int>` keeps track of numbers that have been seen already.
- As you iterate through the list, if a number is found in the set, it is removed from the list; otherwise, it is inserted into the set.
- This method preserves the order of the first occurrences.

---

### Kadane’s Algorithm
Kadane’s Algorithm is a dynamic programming approach used to solve the "maximum subarray problem" in an array of numbers. The goal of the problem is to find the contiguous subarray that has the largest possible sum.

#### How It Works

1. **Initialization:**  
   You start by setting two variables:
    - **current_max:** the maximum sum of a subarray ending at the current position.
    - **overall_max:** the highest sum found across all subarrays examined so far.

2. **Iteration:**  
   For each element in the array (starting from the second element), you decide whether to:
    - **Extend the current subarray:** Add the current element to the running sum (`current_max + element`).
    - **Start a new subarray:** Use the current element as the start of a new subarray.

   Mathematically, for each element `a[i]`:
   ```cpp
   current_max = max(a[i], current_max + a[i]);
   overall_max = max(overall_max, current_max);
   ```

3. **Result:**  
   After processing all elements, `overall_max` holds the sum of the maximum subarray.

#### Key Points

- **Time Complexity:**  
  Kadane’s Algorithm runs in O(n) time, making it very efficient for large arrays.

- **Dynamic Programming:**  
  The algorithm is based on the idea that the best solution for a subarray ending at a given index can be built from the best solution of the previous index.

- **Handling Negative Numbers:**  
  It works well even if all numbers are negative, because it will still pick the largest (least negative) number as the maximum subarray.

### Example

Consider the array: `[−2, 1, −3, 4, −1, 2, 1, −5, 4]`
- Start with the first element: `current_max = overall_max = −2`.
- Process the array by deciding at each step whether to start fresh or continue the previous subarray.
- The maximum subarray in this case is `[4, −1, 2, 1]` with a sum of `6`.