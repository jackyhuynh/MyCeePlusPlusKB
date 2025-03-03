# **Chapter 3 Exercises and Solutions – Arithmetic for Computers**  
*(Based on "Computer Organization and Design 5E" by Patterson & Hennessy)*  

---

### **Exercise 3.1**  
#### **Problem**:  
What is **5ED4 × 07A4** when these values represent **unsigned 16-bit hexadecimal numbers**? The result should be written in **hexadecimal**. Show your work.  

#### **Solution**:  
1. Convert hexadecimal to decimal:  
   - \(5ED4_{16} = 24276_{10}\)  
   - \(07A4_{16} = 1956_{10}\)  
2. Multiply the decimal values:  
   \[
   24276 \times 1956 = 47496256_{10}
   \]  
3. Convert back to hexadecimal:  
   \[
   47496256_{10} = 2D45D200_{16}
   \]  
**Answer**: **2D45D200** (Hexadecimal)  

---

### **Exercise 3.2**  
#### **Problem**:  
What is **5ED4 × 07A4** when these values represent **signed 16-bit hexadecimal numbers** stored in **sign-magnitude format**?  

#### **Solution**:  
- Since both numbers are **positive** in sign-magnitude representation, the result is the same as in **Exercise 3.1**.  
- **Answer**: **2D45D200** (Hexadecimal)  

---

### **Exercise 3.3**  
#### **Problem**:  
Convert **5ED4** into a **binary number**. What makes **base-16 (hexadecimal)** an attractive numbering system for representing values in computers?  

#### **Solution**:  
1. Convert **5ED4** to binary:  
   - **5E** → `0101 1110`  
   - **D4** → `1101 0100`  
   - **5ED4 (Hex) = 0101 1110 1101 0100 (Binary)**  
2. **Advantages of Hexadecimal**:  
   - **Compact Representation**: 1 hex digit = 4 binary digits.  
   - **Human Readability**: Easier to interpret than long binary sequences.  
   - **Alignment with Byte Boundaries**: Matches **8-bit, 16-bit, and 32-bit architectures**.  

**Answer**: `0101 1110 1101 0100 (Binary)`  

---

### **Exercise 3.4**  
#### **Problem**:  
What is **4365 × 3412** when these values represent **unsigned 12-bit octal numbers**? The result should be written in **octal**.  

#### **Solution**:  
1. Convert octal numbers to decimal:  
   - \(4365_8 = 2301_{10}\)  
   - \(3412_8 = 1802_{10}\)  
2. Multiply the decimal values:  
   \[
   2301 \times 1802 = 4144002_{10}
   \]  
3. Convert back to octal:  
   \[
   4144002_{10} = 15725002_8
   \]  

**Answer**: **15725002 (Octal)**  

---

### **Exercise 3.5**  
#### **Problem**:  
What is **4365 × 3412** when these values represent **signed 12-bit octal numbers** stored in **sign-magnitude format**?  

#### **Solution**:  
- Since both numbers are **positive**, the result is the **same as in Exercise 3.4**.  
**Answer**: **15725002 (Octal)**  

---

### **Exercise 3.6**  
#### **Problem**:  
Assume **185 and 122** are **unsigned 8-bit decimal integers**. Calculate **185 – 122**. Is there **overflow, underflow, or neither**?  

#### **Solution**:  
1. **Unsigned binary representation**:  
   - 185 → `1011 1001`  
   - 122 → `0111 1010`  
2. Perform **binary subtraction**:  
   \[
   1011 1001 - 0111 1010 = 0100 1111 (Decimal: 63)
   \]  
3. **Overflow/Underflow Check**:  
   - **Unsigned subtraction never results in overflow/underflow** unless **result is negative**, which is not the case.  
**Answer**: **Neither**  

---

### **Exercise 3.7**  
#### **Problem**:  
Assume **185 and 122** are **signed 8-bit decimal integers** stored in **sign-magnitude format**. Calculate **185 + 122**. Is there **overflow, underflow, or neither**?  

#### **Solution**:  
1. **Sign-magnitude representation**:  
   - 185 → `1 011 1001`  
   - 122 → `0 111 1010`  
2. **Check for Overflow**:  
   - The sum **exceeds the maximum signed 8-bit integer (+127)**.  
   - **Overflow occurs.**  
**Answer**: **Overflow**  

---

### **Exercise 3.8**  
#### **Problem**:  
Assume **185 and 122** are **signed 8-bit decimal integers** stored in **sign-magnitude format**. Calculate **185 – 122**. Is there **overflow, underflow, or neither**?  

#### **Solution**:  
- The result **is within range (-128 to +127)**, so **no overflow/underflow**.  
**Answer**: **Neither**  

---

### **Exercise 3.9**  
#### **Problem**:  
Assume **151 and 214** are **signed 8-bit decimal integers** stored in **two’s complement format**. Calculate **151 + 214** using **saturating arithmetic**.  

#### **Solution**:  
1. **Check Overflow**:  
   - **Max value for 8-bit two’s complement:** **+127**  
   - **151 + 214 = 365 → Exceeds 127**  
   - **Saturating arithmetic clamps result to +127.**  

**Answer**: **127 (Clamped due to saturation)**  

---

### **Exercise 3.10**  
#### **Problem**:  
Assume **151 and 214** are **unsigned 8-bit integers**. Calculate **151 + 214** using **saturating arithmetic**.  

#### **Solution**:  
- **Max value for 8-bit unsigned integer** = **255**  
- **151 + 214 = 365 → Exceeds 255**  
- **Clamp result to 255 (Saturating arithmetic)**  

**Answer**: **255 (Clamped due to saturation)**  

---

### **Exercise 3.11**  
#### **Problem**:  
Assume **151 and 214** are **unsigned 8-bit integers**. Calculate **151 × 214** using **saturating arithmetic**.  

#### **Solution**:  
- **Unsigned multiplication result:**  
  \[
  151 \times 214 = 32314
  \]  
- **Max 8-bit unsigned integer = 255**  
- **Clamp to 255**  

**Answer**: **255 (Saturating arithmetic)**  

---

### **Conclusion**  
These exercises cover **number representations, binary arithmetic, overflow detection, and saturating arithmetic**. They are **essential for understanding low-level computation in MIPS and modern processors**. 🚀
