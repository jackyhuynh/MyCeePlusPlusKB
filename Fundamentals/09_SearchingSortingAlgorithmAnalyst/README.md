# Chapter 9: Searching, Sorting, and Algorithm Analysis

This chapter explores common algorithms for searching and sorting data, as well as methods for analyzing the efficiency
of algorithms. 🔍📈

---

## 9.1 Introduction to Search Algorithms

A **search** algorithm is a method for locating a specific item within a list of information, like an array or vector.
This chapter discusses two search algorithms: **linear search** and **binary search**.

### Linear Search

Also known as a sequential search, a linear search checks each element in a list one by one until the target value is
found or the end of the list is reached.

* **Algorithm**: The process involves initializing a `found` flag to false and a `position` variable to -1. A loop then
  iterates through the elements. If the search value is found, `found` is set to true, `position` is set to the current
  index, and the loop terminates. The function then returns the `position`.
* **Tradeoffs**: Linear search is easy to understand and implement. It works on unsorted arrays. However, it's
  inefficient; on average, it checks half the elements ($N/2$) for a found value and all elements ($N$) for a value that
  is not in the array.

### Binary Search

A **binary search** is a more efficient algorithm that requires the array to be **sorted**.

* **Algorithm**: It starts by examining the middle element of the array. If the middle element is the desired value, the
  search is complete. If not, the algorithm determines which half of the array may contain the value and discards the
  other half. This process of halving the search area repeats until the value is found or no elements are left to check.
* **Tradeoffs**: Binary search is much more efficient than linear search. For an array of $N$ elements, the number of
  comparisons is the smallest integer $x$ where $2^x > N$. This makes it significantly faster for large datasets. The
  main disadvantage is that it requires the array to be sorted beforehand.

---

## 9.2 Searching an Array of Objects

Searching algorithms aren't limited to arrays of primitive data types like integers. When searching an array of objects
or structures, you search for a specific value within a member of the object or structure, not the entire object itself.
The member used for the search is called the **key field**, and the value being sought is the **search key**.

---

## 9.3 Introduction to Sorting Algorithms

A **sort** algorithm arranges values into a specific order, such as alphabetical, ascending numeric, or descending
numeric. This chapter covers two sorting algorithms: **bubble sort** and **selection sort**.

### Bubble Sort

The **bubble sort** algorithm repeatedly steps through the list, compares adjacent elements, and swaps them if they are
in the wrong order. This process is repeated until an entire pass is made without any exchanges.

* **Tradeoffs**: Bubble sort is easy to understand and implement. However, it is inefficient for large arrays due to the
  high number of exchanges. An improved version can stop early if a pass completes with no exchanges, indicating the
  array is sorted.

### Selection Sort

The **selection sort** algorithm works by repeatedly finding the smallest element from the unsorted portion of the array
and moving it to the beginning.

* **Tradeoffs**: Selection sort is generally considered more efficient than bubble sort because it performs fewer
  exchanges, even though it doesn't have an early termination ability.

---

## 9.4 Sorting an Array of Objects

When sorting an array of objects or structures, the sorting is based on a **key field** within each object or structure.
It is important to exchange the **entire** objects or structures, not just the key fields, to maintain the data's
integrity.

---

## 9.5 Sorting and Searching Vectors

The search and sort algorithms discussed in this chapter can also be applied to **vectors** with minor modifications.
For example, the function prototype for a vector parameter would be `vector <type> &`. You don't need a separate
parameter for the size since a function can use the vector's `size()` member function.

---

## 9.6 Introduction to Analysis of Algorithms

**Analysis of algorithms** is the study of an algorithm's efficiency in terms of the computer memory used (space) and
the time it takes to execute. This provides a more effective way to compare algorithms than empirical testing.

### Terminology

* **Computational Problem**: A problem that an algorithm is designed to solve.
* **Instance of the Problem**: A specific set of data for the problem.
* **Size of an Instance ($N$)**: The amount of memory required for the input data.
* **Basic Step**: An operation that takes a constant amount of time to execute, such as comparing two values or
  exchanging their contents.
* **Complexity**: The number of basic steps an algorithm requires to execute for an input of size $N$.
* **Worst-Case Complexity**: The number of basic steps required for an input of size $N$ that forces the algorithm to do
  the most work.

### "Big O" Notation

**"Big O" notation**, written as $O(g(n))$, is a way to classify algorithms based on how their execution time or space
requirements grow as the input size ($n$) increases. It describes a complexity class for a function $f(n)$ if the
ratio $\frac{f(n)}{g(n)}$ approaches a positive constant as $n$ gets very large. An algorithm in a higher complexity
class has a faster rate of growth and is less efficient.