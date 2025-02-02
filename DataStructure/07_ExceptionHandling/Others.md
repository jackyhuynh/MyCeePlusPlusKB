## Exception Handling ()

overview of how exception handling is implemented in **Java**, **Go**, **Rust**, **TypeScript**, and **Python**, with
code samples for each:

---

## **1. Java**

### **Syntax:**

Java uses the `try-catch-finally` structure for exception handling, and exceptions are thrown using the `throw` keyword.
Java has both checked and unchecked exceptions.

### **Example:**

```java
public class Main {
    public static void main(String[] args) {
        try {
            int result = divide(10, 0);
            System.out.println(result);
        } catch (ArithmeticException e) {
            System.out.println("Error: " + e.getMessage());
        } finally {
            System.out.println("Execution completed.");
        }
    }

    public static int divide(int a, int b) {
        if (b == 0) {
            throw new ArithmeticException("Cannot divide by zero");
        }
        return a / b;
    }
}
```

### **Key Concepts:**

- **Checked exceptions** must be either handled or declared in the method signature (`throws`).
- **Unchecked exceptions** (like `ArithmeticException`) do not need to be explicitly handled.

---

## **2. Go**

### **Syntax:**

Go does not have a built-in exception handling mechanism like try-catch. Instead, it uses multiple return values to
return errors and has the `defer`, `panic`, and `recover` functions for handling unexpected conditions.

### **Example:**

```go
package main
import "fmt"

func divide(a, b int) (int, error) {
    if b == 0 {
        return 0, fmt.Errorf("cannot divide by zero")
    }
    return a / b, nil
}

func main() {
    result, err := divide(10, 0)
    if err != nil {
        fmt.Println("Error:", err)
    } else {
        fmt.Println("Result:", result)
    }
}
```

### **Key Concepts:**

- Go uses error handling via **multiple return values**.
- For more serious errors, Go uses **panic** (for unrecoverable errors) and **recover** (to catch panics).

---

## **3. Rust**

### **Syntax:**

Rust uses the `Result` and `Option` enums for error handling instead of exceptions. For unrecoverable errors, Rust uses
`panic!`.

### **Example:**

```rust
fn divide(a: i32, b: i32) -> Result<i32, String> {
    if b == 0 {
        return Err(String::from("Cannot divide by zero"));
    }
    Ok(a / b)
}

fn main() {
    match divide(10, 0) {
        Ok(result) => println!("Result: {}", result),
        Err(e) => println!("Error: {}", e),
    }
}
```

### **Key Concepts:**

- Rust uses **`Result<T, E>`** for functions that can succeed or fail.
- **`Option<T>`** is used when a value might be `None`.
- Unrecoverable errors are handled by **`panic!`**.

---

## **4. TypeScript**

### **Syntax:**

TypeScript, like JavaScript, uses the `try-catch-finally` mechanism for exception handling. Errors are thrown using the
`throw` keyword.

### **Example:**

```typescript
function divide(a: number, b: number): number {
    if (b === 0) {
        throw new Error("Cannot divide by zero");
    }
    return a / b;
}

try {
    const result = divide(10, 0);
    console.log(result);
} catch (e) {
    console.error("Error:", (e as Error).message);
} finally {
    console.log("Execution completed.");
}
```

### **Key Concepts:**

- **Exceptions** are thrown and caught using `throw` and `try-catch`.
- TypeScript's type system allows for better type-safety when catching and handling errors.

---

## **5. Python**

### **Syntax:**

Python uses the `try-except-finally` structure for exception handling. Exceptions are thrown using the `raise` keyword.

### **Example:**

```python
def divide(a, b):
    if b == 0:
        raise ValueError("Cannot divide by zero")
    return a / b


try:
    result = divide(10, 0)
    print(result)
except ValueError as e:
    print("Error:", e)
finally:
    print("Execution completed.")
```

### **Key Concepts:**

- Python uses **`try-except-finally`** for exception handling.
- You can define custom exceptions by subclassing `Exception`.
- **`raise`** is used to trigger exceptions manually.

---

## **Comparison Overview**

| Language       | Mechanism                     | Key Features                                                      |
|----------------|-------------------------------|-------------------------------------------------------------------|
| **Java**       | `try-catch-finally`, `throw`  | Checked and unchecked exceptions, finally block                   |
| **Go**         | Return errors, `panic`        | Error values instead of exceptions, `defer`, `panic`, `recover`   |
| **Rust**       | `Result`, `Option`, `panic!`  | Result and Option types for handling errors, `panic!` for crashes |
| **TypeScript** | `try-catch-finally`, `throw`  | JavaScript-style exception handling with static types             |
| **Python**     | `try-except-finally`, `raise` | Dynamically typed exceptions, customizable exceptions via classes |

---

Each language offers different paradigms for error handling, from traditional exception handling in Java, TypeScript,
and Python, to result-based approaches in Go and Rust.