# **Chapter 2: Instructions - Language of the Computer**

Chapter 2 of *Computer Organization and Design* explores how computers execute programs through **instructions**. It introduces **MIPS assembly language**, discusses computer hardware operations, and explains how high-level programs are translated into machine language.

---

## **2.1 Introduction**
Computers understand only **machine instructions**, which consist of **binary numbers** (0s and 1s). However, writing programs in binary is impractical, so we use **assembly language**, which is a human-readable representation of machine instructions.

🔹 **Key Points:**
- An **instruction set** is a collection of commands a processor can execute.
- Most computers use **similar** instruction sets.
- The **MIPS instruction set** is introduced as a simple and elegant example.
- Other instruction sets discussed: **ARMv7, ARMv8 (64-bit), and Intel x86**.

---

## **2.2 Operations of the Computer Hardware**
Computers perform fundamental operations like **arithmetic, data transfer, and control flow**. In MIPS assembly, instructions typically follow the **format**:
```assembly
operation destination, source1, source2
```
For example:
```assembly
add $s1, $s2, $s3  # $s1 = $s2 + $s3
```
📌 **Characteristics of MIPS instructions:**
- **Fixed format:** Each instruction has exactly **three operands**.
- **Explicit load/store operations:** Memory access is separate from computation.
- **Registers-based:** Arithmetic operations are performed on registers, **not directly on memory**.

---

## **2.3 Operands of the Computer Hardware**
Operands (data manipulated by instructions) are stored in **registers**. MIPS has **32 general-purpose registers**, each **32-bits** wide.

🔹 **Common MIPS Registers:**
| Register Name | Purpose |
|--------------|---------|
| `$t0 - $t9`  | Temporary variables |
| `$s0 - $s7`  | Saved variables |
| `$a0 - $a3`  | Function arguments |
| `$v0, $v1`   | Function return values |
| `$sp`        | Stack pointer |
| `$ra`        | Return address |

📌 **Example: Using registers for arithmetic**
```assembly
add $t0, $s1, $s2  # $t0 = $s1 + $s2
sub $t1, $s3, $s4  # $t1 = $s3 - $s4
```
✅ **Why registers?**  
Using registers **instead of memory** speeds up execution.

---

## **2.4 Signed and Unsigned Numbers**
Computers represent numbers in **binary**. MIPS supports both **signed** (can be negative) and **unsigned** (only positive) integers.

🔹 **Two’s Complement Representation (for signed numbers)**
- Negative numbers are stored using **two’s complement**:
  - Example: `-5` in 8-bit binary:
    - `00000101` → Invert bits → `11111010`
    - Add `1` → `11111011` (which represents `-5`)

📌 **Signed vs. Unsigned Ranges (8-bit example):**
| Type | Min Value | Max Value |
|------|----------|----------|
| **Signed (two’s complement)** | `-128` | `127` |
| **Unsigned** | `0` | `255` |

✅ **Why use two’s complement?**  
It allows **simple binary arithmetic operations**, making subtraction easier.

---

## **2.5 Representing Instructions in the Computer**
Since computers only understand **binary**, assembly instructions are encoded into **machine code**.

📌 **Example: MIPS `add` instruction**
```assembly
add $s1, $s2, $s3
```
🔹 **Binary Encoding (Machine Code)**
```
000000 10010 10011 10001 00000 100000
```
- **Opcode (6 bits):** Operation type (e.g., addition, load, store)
- **Registers (5 bits each):** Specifies operands
- **Function Code (6 bits):** Differentiates instructions with the same opcode

✅ **Why use binary?**  
Binary instructions can be **processed efficiently by hardware**.

---

## **2.6 Logical Operations**
Logical operations allow bitwise manipulations in MIPS.

🔹 **Common MIPS Logical Instructions**
| Instruction | Description | Example |
|------------|------------|---------|
| `and` | Bitwise AND | `and $t0, $t1, $t2` |
| `or`  | Bitwise OR | `or $t0, $t1, $t2` |
| `xor` | Bitwise XOR | `xor $t0, $t1, $t2` |
| `nor` | Bitwise NOR | `nor $t0, $t1, $t2` |

📌 **Example: Bitwise AND**
```assembly
and $t0, $s1, $s2  # $t0 = $s1 & $s2
```

✅ **Why use logical operations?**  
Efficient for **bit manipulation, masking, and conditional execution**.

---

## **2.7 Instructions for Making Decisions**
Branching instructions allow conditional execution, like **if-else** statements.

🔹 **Common MIPS Branch Instructions**
| Instruction | Description | Example |
|------------|------------|---------|
| `beq` | Branch if equal | `beq $s1, $s2, LABEL` |
| `bne` | Branch if not equal | `bne $s1, $s2, LABEL` |
| `j` | Unconditional jump | `j LABEL` |

📌 **Example: If Statement in C**
```c
if (x == y) {
   z = 1;
} else {
   z = 0;
}
```
🔹 **Equivalent MIPS Code**
```assembly
beq $s1, $s2, LABEL  # If $s1 == $s2, jump to LABEL
addi $s3, $zero, 0    # Else: z = 0
j END
LABEL:
  addi $s3, $zero, 1  # z = 1
END:
```

✅ **Why use branches?**  
They control **program flow**, allowing loops and conditional execution.

---

## **2.8 Supporting Procedures in Computer Hardware**
Functions (or procedures) in assembly require:
1. **Passing arguments**
2. **Returning values**
3. **Storing return addresses**

📌 **Example: Function Call in C**
```c
int add(int a, int b) {
   return a + b;
}
```
🔹 **Equivalent MIPS Code**
```assembly
add $v0, $a0, $a1  # Return value stored in $v0
jr $ra             # Jump back to caller
```
✅ **Why use function calls?**  
Encapsulation improves **code reuse and modularity**.

---

## **2.9 Communicating with People**
Computers support **input/output operations** via system calls.

🔹 **Example: Printing a String**
```assembly
li $v0, 4         # System call for print string
la $a0, message   # Load address of string
syscall           # Execute system call
```

✅ **Why system calls?**  
Allow interaction with **keyboards, displays, and files**.

---

## **2.10 - 2.19 Advanced Topics**
These sections cover:
- **MIPS Addressing**: Handling large constants and memory access.
- **Parallelism**: Synchronization and multi-threading.
- **Instruction Parallelism**: Modern CPUs execute multiple instructions in parallel.
- **Compiling C to Assembly**: Demonstrates real-world translation.
- **ARM and x86 Instruction Sets**: Comparisons with MIPS.

---

## **2.20 Concluding Remarks**
- Instructions form the **fundamental unit of computation**.
- Assembly language **bridges** the gap between **high-level programming** and **machine execution**.
- Understanding **instruction sets** is critical for **efficient programming and processor design**.
