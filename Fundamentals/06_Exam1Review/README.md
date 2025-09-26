# 📘 Programming Fundamentals II – Exam 1 Review

This review covers **common C++ topics** that appear on the exam, with practice questions and example answers. Use it to prepare by writing code snippets and checking against the examples.

---

## Question 1–3 (5 points each)

### Q1. Printing with formatting

**Practice:**
Write one or more C++ statements that display the value of a float variable `pizza_charge` with a dollar sign and two decimal places, preceded by the text:

`The total amount for pizza is:`

**Answer Example:**

```cpp
cout << setprecision(2) << fixed;
cout << "The total amount for pizza is: $" << pizza_charge;
```

---

### Q2. Function call with parameters

**Practice:**
Write C++ statements that call a function named `process` with parameters:

* `code` (a `char`)
* `amount` (a `float`)

Declare any needed variables.

**Answer Example:**

```cpp
char code;
float amount;
process(code, amount);
```

---

### Q3. Arithmetic with constants

**Practice:**
Multiply the variable `number_of_cookies` by the constant `COOKIE_PRICE` and store the result in `cookie_total`.

**Answer Example:**

```cpp
cookie_total = number_of_cookies * COOKIE_PRICE;
```

---

## Question 4–6 (5–10 points each)

### Q4. If statement with range check

**Practice:**
Write an `if` statement that prints “The number is valid” if the variable `growth_rate` is between 0 and 20 inclusive.

**Answer Example:**

```cpp
if (growth_rate >= 0 && growth_rate <= 20)
    cout << "The number is valid" << endl;
```

---

### Q5. Function with one parameter

**Practice:**
Write a function that takes a floating-point parameter `distance` and prints:
`The sun was <distance> miles from this planet.`

**Answer Example:**

```cpp
void print_distance(float distance) {
    cout << "The sun was " << distance << " miles from this planet";
}
```

---

### Q6. Function with reference parameter

**Practice:**
Write a `void` function with:

* `num` (float, value parameter)
* `result` (float, reference parameter)
  The function stores `23.0*num+52` in `result`.
  No I/O inside the function.

**Answer Example:**

```cpp
void function1(float num, float &result) {
    result = 23.0 * num + 52;
}
```

---

## Question 7–9 (10 points each)

### Q7. Loop with sentinel value

**Practice:**
Write a loop that reads integers until a negative number is entered. Print the sum of all entered (non-negative) numbers.

**Answer Example:**

```cpp
int sum = 0, num;
cout << "Enter a number. Enter a negative number to stop: ";
cin >> num;

while (num >= 0) {
    sum += num;
    cout << "Enter a number. Enter a negative number to stop: ";
    cin >> num;
}

cout << "The sum is: " << sum;
```

---

### Q8. Count-controlled loop

**Practice:**
Write C++ statements that sum the numbers **2 through 8** (inclusive) and print the total.

**Answer Example:**

```cpp
int total = 0;
for (int i = 2; i <= 8; i++)
    total += i;

cout << "The total is: " << total;
```

---

### Q9. File output

**Practice:**
Create an `ofstream` object named `outfile`, open `"numfile.txt"`, write `data` followed by a newline, then close the file.

**Answer Example:**

```cpp
ofstream outfile;
outfile.open("numfile.txt");
outfile << data << endl;
outfile.close();
```

---

## Question 10 (15 points)

### Q10. Switch statement with string assignment

**Practice:**
Write a switch statement that assigns a string `color` based on `number` (int). If `number` is not 1–3, set `color` to `"null"`.

| number | color  |
| ------ | ------ |
| 1      | red    |
| 2      | blue   |
| 3      | yellow |

**Answer Example:**

```cpp
switch (number) {
    case 1: color = "red"; break;
    case 2: color = "blue"; break;
    case 3: color = "yellow"; break;
    default: color = "null";
}
```

---

# ✅ Tips for Review

1. **Memorize syntax** for:

    * `if` statements
    * `for` loops
    * `while` loops (sentinel-controlled)
    * `switch` statements
    * file I/O with `ofstream`

2. **Practice functions**:

    * Passing by value vs reference
    * Writing functions without input/output
    * Using `void` return type

3. **Formatting output**:

    * `setprecision()` and `fixed`

4. **Test yourself**:

    * Write out each solution without looking, then compare.

---