# Chapter 12: More on C-Strings and the string Class

This chapter explores C-strings and the C++ `string` class, including how to test and convert characters, use C-string
library functions, and leverage the powerful features of the `string` class. ✍️

---

## 12.1 Character Testing

The `<cctype>` header file provides functions for testing characters. These functions take a `char` as an argument and
return a non-zero value for true or zero for false. Some common character testing functions include:

* **`isalpha`**: Returns true if the character is an alphabet letter.
* **`isdigit`**: Returns true if the character is a digit (0–9).
* **`isalnum`**: Returns true if the character is a letter or a digit.
* **`islower`**: Returns true if the character is a lowercase letter.
* **`isupper`**: Returns true if the character is an uppercase letter.
* **`isspace`**: Returns true if the character is a whitespace character, such as a space, tab, or newline.
* **`ispunct`**: Returns true if the character is a punctuation mark.

These functions are useful for validating data formats, like ensuring a part number follows a specific pattern of digits
and letters.

## 12.2 Character Case Conversion

The `<cctype>` header also includes functions for converting character case. These functions take a `char` as an
argument and return its converted `char` equivalent.

* **`toupper`**: If the argument is a lowercase letter, it returns the uppercase equivalent; otherwise, it returns the
  original character.
* **`tolower`**: If the argument is an uppercase letter, it returns the lowercase equivalent; otherwise, it returns the
  original character.

These can simplify data testing by allowing comparisons to be case-insensitive.

---

## 12.3 C-Strings

A **C-string** is a sequence of characters stored in adjacent memory locations, terminated by a null character (`\0`).
The null character signals the end of the string. It can be represented as the character literal `'\0'`, the integer
value `0`, or the named constant `NULL`.

C-strings can be represented in three ways, all of which are pointers to `char`:

1. **String Literal**: A string constant enclosed in double quotes (e.g., `"Hi There!"`) is stored as a null-terminated
   array of characters. The value of the string is the address of its first character.
2. **Character Array**: A C-string can be stored in a character array, which can be initialized with a string literal
   upon definition (e.g., `char str1[20] = "hi";`).
3. **Character Pointer**: A pointer to `char` can point to a string literal or an array of characters.

---

## 12.4 Library Functions for Working with C-Strings

The `<cstring>` header file contains several functions for manipulating C-strings. These functions accept C-string
arguments, which can be an array name, a pointer to `char`, or a string literal.

* **`strlen(char *str)`**: Returns the number of characters in a string, not including the null terminator.
* **`strcat(char *dest, char *source)`**: Appends the contents of the `source` string to the end of the `dest` string.
  It's the programmer's responsibility to ensure the destination array is large enough to hold the new string.
* **`strcpy(char *dest, char *source)`**: Copies the `source` string to the `dest` string.
* **`strcmp(char *str1, char *str2)`**: Compares two C-strings to determine their relative alphabetical order. It
  returns a value less than 0 if `str1` comes before `str2`, 0 if they are equal, and greater than 0 if `str1` comes
  after `str2`. Unlike relational operators, which compare the addresses of C-strings, `strcmp` compares their contents.
  The comparison is case-sensitive.

---

## 12.5 Conversions Between Numbers and Strings

The `<sstream>` header file provides classes for converting between string and numeric representations of numbers.

* **`istringstream`**: Used to convert a string to numeric values. You can use the stream extraction operator (`>>`) to
  read values from the string.
* **`ostringstream`**: Used to convert numeric data into a string. You can use the stream insertion operator (`<<`) to
  add data to the string.

C++ 11 also introduced numeric conversion functions. These include:

* **`to_string()`**: Converts a numeric value to a string.
* **`stoi()`, `stol()`, `stof()`, `stod()`**: Convert a string to an integer, long, float, or double, respectively.

---

## 12.6 Writing Your Own C-String Handling Functions

When writing custom C-string functions, you can pass arrays or pointers to `char` as arguments. It's a good practice to
include bounds checking to ensure enough space is available for the results and to handle unexpected user input.

---

## 12.7 More About the C++ `string` Class

The C++ `string` class, which requires the `<string>` header, offers many advantages over C-strings. It includes a large
body of member functions and overloaded operators that simplify string manipulation.

The `string` class has constructors for various initialization scenarios, including a default constructor, a copy
constructor that initializes with another `string` object, and a convert constructor that initializes from a C-string.

### Overloaded Operators

The `string` class overloads several operators, making string operations more intuitive:

* `>>` and `<<` for input and output.
* `=` for assignment.
* `+` for concatenation.
* `+=` for appending a string.
* `[]` for accessing individual characters with array notation.
* Relational operators (`==`, `!=`, `<`, `>`, etc.) for comparing string contents.

### Member Functions

The `string` class provides member functions for:

* **Conversion**: `c_str()` and `data()` return a C-string equivalent of the `string` object, useful for functions that
  expect a C-string.
* **Modification**: Functions like `append()`, `insert()`, and `replace()` allow you to modify a string's contents.
* **Space Management**: Functions like `size()` and `length()` return the number of characters in the string, while
  `capacity()` and `empty()` manage the string's memory.