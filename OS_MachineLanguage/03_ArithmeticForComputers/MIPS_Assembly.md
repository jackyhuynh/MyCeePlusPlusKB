# MIPS Assembly Language: An Introduction
MIPS (Microprocessor without Interlocked Pipeline Stages) Assembly is a **low-level programming language** used to write programs for **MIPS processors**. It is designed to be **simple and efficient**, making it ideal for learning computer architecture and assembly programming.

---

## **1. What is MIPS?**
MIPS is a **Reduced Instruction Set Computing (RISC)** architecture, meaning it follows a **small, highly optimized set of instructions**. Unlike **Complex Instruction Set Computing (CISC)** architectures (such as x86), MIPS keeps instructions simple, uniform, and optimized for **fast execution**.

---

## **2. MIPS Registers**
MIPS uses **32 general-purpose registers** for computation. Each register is **32 bits (4 bytes) wide** in MIPS32.

| **Register Name** | **Alias**  | **Usage** |
|------------------|-----------|----------|
| `$zero`  | `$0`   | Always stores 0 |
| `$v0-$v1` | Return Values | Stores function return values |
| `$a0-$a3` | Arguments | Stores function arguments |
| `$t0-$t9` | Temporary | Used for temporary values |
| `$s0-$s7` | Saved Registers | Used for variables (preserved across function calls) |
| `$gp` | Global Pointer | Points to global/static variables |
| `$sp` | Stack Pointer | Points to the top of the stack |
| `$fp` | Frame Pointer | Used in function calls |
| `$ra` | Return Address | Stores return address for function calls |

---

## **3. MIPS Instruction Categories**
MIPS has three main types of instructions:

1. **R-type (Register-based)** – Arithmetic and logic operations
2. **I-type (Immediate-based)** – Load/store and arithmetic with constants
3. **J-type (Jump-based)** – Used for function calls and control flow

---

## **4. Basic MIPS Instructions**
Here are some of the **most common MIPS assembly instructions**:

### **4.1 Arithmetic Operations**
```assembly
add $t0, $t1, $t2  # $t0 = $t1 + $t2
sub $t0, $t1, $t2  # $t0 = $t1 - $t2
mul $t0, $t1, $t2  # $t0 = $t1 * $t2
div $t0, $t1, $t2  # $t0 = $t1 / $t2
addi $t0, $t1, 10  # $t0 = $t1 + 10
```

### **4.2 Memory Access (Load/Store)**
MIPS uses **load/store architecture**, meaning data must be loaded into registers before computation.

```assembly
lw $t0, 0($t1)   # Load word from memory at address in $t1 into $t0
sw $t0, 4($t1)   # Store word from $t0 into memory at address in $t1 + 4 bytes
```

### **4.3 Conditional Branching**
```assembly
beq $t0, $t1, LABEL  # Branch to LABEL if $t0 == $t1
bne $t0, $t1, LABEL  # Branch to LABEL if $t0 != $t1
```

### **4.4 Jump Instructions**
```assembly
j LABEL  # Jump to LABEL
jr $ra   # Jump to address stored in $ra (used in function returns)
jal FUNCTION  # Jump to FUNCTION and store return address in $ra
```

---

## **5. Example MIPS Program**
### **Objective:** Add two numbers and store the result in memory.
```assembly
.data
num1: .word 5
num2: .word 10
result: .word 0

.text
.globl main
main:
    lw $t0, num1       # Load num1 into $t0
    lw $t1, num2       # Load num2 into $t1
    add $t2, $t0, $t1  # Add $t0 and $t1, store in $t2
    sw $t2, result     # Store the result back in memory
    li $v0, 10         # Exit syscall
    syscall
```

---

## **6. Why Learn MIPS Assembly?**
- **Simple & Clean**: MIPS instructions are straightforward, unlike x86.
- **Educational Value**: Used in computer architecture courses to teach fundamentals.
- **RISC-Based**: Helps understand modern processor designs like ARM.
- **Foundation for Embedded Systems**: Used in networking and real-time systems.

---

## **7. MIPS vs x86 Assembly**
| Feature      | MIPS (RISC) | x86 (CISC) |
|-------------|------------|------------|
| Instruction Length | Fixed (32-bit) | Variable (1-15 bytes) |
| Instruction Set | Small & Optimized | Large & Complex |
| Load/Store Architecture | Yes | No (can operate on memory directly) |
| Registers | 32 General-Purpose | 16 General-Purpose |
| Simplicity | Easier to learn | Harder to master |

---

## **8. Running MIPS Assembly**
To run MIPS programs, you can use:
- **MARS (MIPS Assembler and Runtime Simulator)** – Java-based IDE for MIPS
- **SPIM** – A lightweight simulator for MIPS assembly

Example command to run in SPIM:
```
spim -file program.asm
```

---

## **9. Summary**
- **MIPS Assembly** is a **low-level programming language** for MIPS processors.
- Uses **32 registers** to store values before computation.
- Instructions are divided into **R-type (arithmetic), I-type (memory), and J-type (control flow)**.
- **Memory access is explicit** (load/store architecture).
- **Widely used for teaching** computer architecture.
