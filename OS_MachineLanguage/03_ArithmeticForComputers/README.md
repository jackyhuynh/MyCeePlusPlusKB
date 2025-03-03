# **Chapter 3: Arithmetic for Computers**  
*(Based on "Computer Organization and Design 5E" by Patterson & Hennessy)*  

## **3.1 Introduction**  
- Computer words are composed of bits, and numerical representation is critical in computing.  
- This chapter explores representation, arithmetic operations, hardware implementation, and implications for instruction sets.  
- Key questions include:  
  - How are real numbers represented?  
  - What happens when operations exceed the representational limits?  
  - How does hardware perform multiplication and division?  
  - Binary arithmetic  
  - Integer vs. floating-point operations  
  - Hardware multiplication and division algorithms  
  - How computer arithmetic affects performance and instruction sets  
---

## **3.2 Addition and Subtraction**  
- **Binary Addition**: Operates bit by bit from right to left with carries.  
- **Binary Subtraction**: Uses two's complement notation for negation before addition.  
- **Overflow Handling**: Essential for both signed and unsigned integers.  
- **Example**:  

```yaml
  0000 0000 0000 0000 0000 0000 0000 0111 (7 in decimal)
+ 0000 0000 0000 0000 0000 0000 0000 0110 (6 in decimal)
---------------------------------------------------------
= 0000 0000 0000 0000 0000 0000 0000 1101 (13 in decimal)
```

### **3.2.1 Binary Addition** (MIPS Assembly)
```assembly
# MIPS Addition
addi $t0, $zero, 7      # Load 7 into register $t0
addi $t1, $zero, 6      # Load 6 into register $t1
add  $t2, $t0, $t1      # Add $t0 and $t1, store result in $t2
```

### **3.2.2 Binary Subtraction** (MIPS Assembly)
```assembly
# MIPS Subtraction
addi $t0, $zero, 15     # Load 15 into register $t0
addi $t1, $zero, 6      # Load 6 into register $t1
sub  $t2, $t0, $t1      # Subtract $t1 from $t0, store result in $t2
```

### **3.2.3 Overflow Detection**  
```assembly
# MIPS Addition with Overflow Detection
add  $t2, $t0, $t1
bov  Overflow_Handler   # Branch to overflow handler if overflow occurs
```

---

## **3.3 Multiplication**  
- **Unsigned Binary Multiplication**: Based on repeated addition and bit shifting.  
- **Two’s Complement Multiplication**: Requires sign extension.  
- **Booth’s Algorithm**: Efficient handling of multiplication, reducing the number of operations.  
- **Hardware Implementation**: Typically uses shift-and-add methods or parallel multipliers.  

### **3.3.1 Unsigned Multiplication** (MIPS Assembly)
```assembly
# MIPS Multiplication
addi $t0, $zero, 4      # Load 4 into register $t0
addi $t1, $zero, 5      # Load 5 into register $t1
mult $t0, $t1           # Multiply $t0 by $t1
mflo $t2                # Move the lower result to $t2
```

### **3.3.2 Booth's Algorithm for Multiplication** (Python)
```python
def booth_multiplication(m, r, size):
    m = int(m, 2)
    r = int(r, 2)
    product = m * r
    return bin(product)[2:].zfill(size)

print(booth_multiplication("1010", "1100", 8))  # Multiply 10 and -4
```

---

## **3.4 Division**  
- **Restoring Division Algorithm**: Uses trial subtractions and corrections.  
- **Non-Restoring Division**: Eliminates correction steps for efficiency.  
- **Floating-Point Division**: More complex due to rounding and precision handling.  
- **Example of Division**:  
  - Computing \( 14 \div 3 \) in binary involves shifting and subtracting iteratively.  

### **3.4.1 Restoring Division Algorithm** (MIPS Assembly)
```assembly
# MIPS Division
addi $t0, $zero, 14     # Load 14 into register $t0
addi $t1, $zero, 3      # Load 3 into register $t1
div  $t0, $t1           # Divide $t0 by $t1
mflo $t2                # Move quotient to $t2
mfhi $t3                # Move remainder to $t3
```

### **3.4.2 Non-Restoring Division Algorithm** (Python)
```python
def binary_division(dividend, divisor):
    quotient = dividend // divisor
    remainder = dividend % divisor
    return quotient, remainder

print(binary_division(14, 3))  # Output: (4, 2)
```

---

## **3.5 Floating-Point Arithmetic**  
- **IEEE 754 Standard**: Defines 32-bit and 64-bit floating-point representation.  
- **Key Components**:  
  - **Sign Bit**: 1-bit (0 for positive, 1 for negative).  
  - **Exponent**: Biased representation for range adjustment.  
  - **Mantissa (Significand)**: Fractional part for precision.  
- **Operations**:  
  - Addition/Subtraction: Align exponents before computation.  
  - Multiplication: Multiply mantissas and add exponents.  
  - Division: Divide mantissas and subtract exponents.  
- **Rounding Modes**:  
  - Round-to-Nearest  
  - Round Toward Zero  
  - Round Up  
  - Round Down  
- **Overflow and Underflow**: Occur when numbers exceed representational limits.  

### **3.5.1 IEEE 754 Representation** (Python)
```python
import struct

def float_to_binary(value):
    return ''.join(f'{c:08b}' for c in struct.pack('!f', value))

print(float_to_binary(5.75))  # IEEE 754 representation of 5.75
```

### **3.5.2 Floating-Point Addition** (C)
```c
#include <stdio.h>

int main() {
    float a = 3.14, b = 2.71;
    float sum = a + b;
    printf("Sum: %f\n", sum);
    return 0;
}
```

---

## **3.6 Parallelism and Computer Arithmetic: Subword Parallelism**  
- **Subword Parallelism**: Uses wide registers to perform multiple operations in one instruction.  
- **SIMD (Single Instruction, Multiple Data)**: Parallel computations on multiple data elements.  
- **Example**: SIMD instructions for graphics/audio applications.  

### **3.6.1 SIMD Addition Using AVX** (C)
```c
#include <immintrin.h>

int main() {
    __m256 a = _mm256_set1_ps(3.0);
    __m256 b = _mm256_set1_ps(2.0);
    __m256 sum = _mm256_add_ps(a, b);
    return 0;
}
```

---

## **3.7 Real Stuff: SIMD Extensions and AVX in x86**  
- **Intel's SSE and AVX**:  
  - SSE (Streaming SIMD Extensions) introduced parallel floating-point operations.  
  - AVX (Advanced Vector Extensions) added wider registers for higher performance.  
- **Example**: Accelerating matrix multiplication using AVX.  

### **3.7.1 SIMD Addition Using SSE** (C)
```c
#include <emmintrin.h>

int main() {
    __m128 a = _mm_set_ps(1.0, 2.0, 3.0, 4.0);
    __m128 b = _mm_set_ps(4.0, 3.0, 2.0, 1.0);
    __m128 sum = _mm_add_ps(a, b);
    return 0;
}
```

---

## **3.8 Going Faster: Subword Parallelism and Matrix Multiply**  
- **Optimization Techniques**:  
  - Loop unrolling.  
  - Using specialized CPU instructions (e.g., Intel AVX).  
- **Performance Gains**: Up to 4x improvement using SIMD-based optimizations.  

### **3.8.1 Naïve Matrix Multiplication** (C)
```c
#define N 512
float A[N][N], B[N][N], C[N][N];

void matrix_multiply() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                C[i][j] += A[i][k] * B[k][j];
}
```

### **3.8.2 SIMD Matrix Multiplication (C with AVX)**
```c
#include <immintrin.h>

void matrix_multiply_simd(float *A, float *B, float *C, int N) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            __m256 sum = _mm256_setzero_ps();
            for (int k = 0; k < N; k += 8) {
                __m256 a = _mm256_loadu_ps(&A[i*N + k]);
                __m256 b = _mm256_loadu_ps(&B[k*N + j]);
                sum = _mm256_fmadd_ps(a, b, sum);
            }
            _mm256_storeu_ps(&C[i*N + j], sum);
        }
}
```

---

## **3.9 Fallacies and Pitfalls**  
- **Common Mistakes**:  
  - Assuming floating-point addition is associative.  
  - Using integer division incorrectly.  
- **Example of Non-Associativity**:  
  - \( (a + b) + c \neq a + (b + c) \) due to rounding errors in floating point.  
- **Common Mistakes**:  
  - Assuming floating-point addition is associative.  
  - Using integer division incorrectly.  
- **Example of Non-Associativity**:  
  ```python
  print((0.1 + 0.2) + 0.3)  # May not equal 0.1 + (0.2 + 0.3)
  ```

---

### **3.10 Concluding Remarks**  
- **Standardization in Computer Arithmetic**:  
  - Two’s complement integer representation is universal.  
  - IEEE 754 is the standard for floating-point arithmetic.  
- **Challenges in Floating-Point Computation**:  
  - Precision loss and numerical errors require careful handling.  
- **Parallelism Trends**:  
  - SIMD and subword parallelism continue to evolve for higher performance.  
- **Key Takeaways**:  
  - Arithmetic operations in hardware follow strict rules.  
  - Floating-point arithmetic is **not** always accurate.  
  - Parallelism (SIMD) enhances performance.  
---

### **3.11 Historical Perspective and Further Reading**  
- Evolution of numerical computing, from early mechanical calculators to modern floating-point standards.  

---

### **3.12 Exercises**  
- Practice problems on integer and floating-point arithmetic, including overflow handling and parallel computation strategies.  
