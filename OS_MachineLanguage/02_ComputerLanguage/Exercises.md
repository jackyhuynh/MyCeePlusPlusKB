# **Chapter 2 Exercises and Solutions – Instructions: The Language of the Computer**  

---

## **Exercise 2.1**  
### **Problem:**  
For the following C statement, what is the corresponding MIPS assembly code? Assume that the variables `f`, `g`, `h`, and `i` are given as 32-bit integers.

```c
f = g + (h - 5);
```

### **Solution:**  
1. **Convert the expression step-by-step:**  
   - Compute `h - 5`
   - Add the result to `g`
   - Store the result in `f`
   
2. **Assume registers for variables:**  
   - `f` → `$s0`  
   - `g` → `$s1`  
   - `h` → `$s2`  
   - `i` → `$s3` (not used here)  

3. **MIPS Assembly Code:**
```assembly
addi $t0, $s2, -5   # $t0 = h - 5
add  $s0, $s1, $t0  # f = g + $t0
```

**Answer:**  
```assembly
addi $t0, $s2, -5
add  $s0, $s1, $t0
```

---

## **Exercise 2.2**  
### **Problem:**  
For the following MIPS assembly instructions, what is the corresponding C statement?

```assembly
add  $s0, $s1, $s2
add  $s0, $s3, $s0
```

### **Solution:**  
- First instruction: `f = g + h`  
- Second instruction: `f = i + f`

**Final C Statement:**
```c
f = g + h;
f = i + f;
```

---

## **Exercise 2.3**  
### **Problem:**  
For the following C statement, what is the corresponding MIPS assembly code? Assume the variables `f`, `g`, `h`, `i`, and `j` are assigned to registers `$s0, $s1, $s2, $s3,` and `$s4`, respectively. The base addresses of arrays `A` and `B` are stored in `$s6` and `$s7`.

```c
B[8] = A[i - j];
```

### **Solution:**
1. **Compute the index:**  
   - `i - j` → `$t0`
   - Multiply by 4 (assuming 4-byte integers)  
   - Add base address of `A`
   - Load value from `A[i - j]`  
   - Store the result in `B[8]`

2. **MIPS Assembly Code:**
```assembly
sub  $t0, $s3, $s4     # $t0 = i - j
sll  $t0, $t0, 2       # Multiply by 4 (shift left by 2)
add  $t0, $s6, $t0     # Add base address of A
lw   $t1, 0($t0)       # Load A[i - j]
sw   $t1, 32($s7)      # Store in B[8] (offset 8 * 4 = 32)
```

**Answer:**
```assembly
sub  $t0, $s3, $s4
sll  $t0, $t0, 2
add  $t0, $s6, $t0
lw   $t1, 0($t0)
sw   $t1, 32($s7)
```

---

## **Exercise 2.4**  
### **Problem:**  
For the given MIPS instructions, write the corresponding C statement. Assume `f, g, h, i, j` are stored in `$s0-$s4`, and arrays `A` and `B` have base addresses in `$s6` and `$s7`.

```assembly
sll  $t0, $s0, 2
add  $t0, $s6, $t0
sll  $t1, $s1, 2
add  $t1, $s7, $t1
lw   $s0, 0($t0)
addi $t2, $t0, 4
lw   $t0, 0($t2)
add  $t0, $t0, $s0
sw   $t0, 0($t1)
```

### **Solution:**  
1. Compute index for `A[f]`  
2. Compute index for `B[g]`  
3. Load `A[f]` into `s0`  
4. Load `A[f+1]`  
5. Add `A[f+1]` to `A[f]`  
6. Store result in `B[g]`

**Equivalent C Statement:**
```c
B[g] = A[f] + A[f + 1];
```

---

## **Exercise 2.5**  
### **Problem:**  
Optimize the MIPS assembly code in **Exercise 2.4**.

### **Solution:**  
We can **eliminate** the unnecessary `addi` instruction and reuse the loaded value.

**Optimized MIPS Code:**
```assembly
sll  $t0, $s0, 2
add  $t0, $s6, $t0
lw   $t1, 0($t0)
lw   $t2, 4($t0)  
add  $t1, $t1, $t2
sll  $t3, $s1, 2
add  $t3, $s7, $t3
sw   $t1, 0($t3)
```

---

## **Exercise 2.6**  
### **Problem:**  
The table below shows an array stored in memory:

| **Address** | **Data** |
|------------|---------|
| 24         | 2       |
| 28         | 4       |
| 32         | 3       |
| 36         | 6       |
| 40         | 1       |

Write a C function to **sort the array** in **ascending order**.

### **Solution:**  
```c
#include <stdio.h>

void bubbleSort(int arr[], int size) {
    int i, j, temp;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {2, 4, 3, 6, 1};
    int size = 5;
    bubbleSort(arr, size);
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
```

---

## **Conclusion**  
- These exercises **strengthen** understanding of **MIPS Assembly, instruction encoding, memory access, and arithmetic operations**.
- **Key Takeaways:**  
  - **Arithmetic Operations:** `add, sub, sll, lw, sw`
  - **Memory Operations:** Base address manipulation
  - **Control Flow:** Branching, loops, and function calls
  - **Optimization Techniques:** Minimizing instruction count
