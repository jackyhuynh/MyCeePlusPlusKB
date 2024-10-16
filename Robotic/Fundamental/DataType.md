# Data Types in C++

*Material retrieved
from [Udacity](https://classroom.udacity.com/courses/ud210/lessons/1343a461-102f-41e1-b505-bf9ec62f427b/concepts/b1e0db7a-619e-4f23-a30d-b505d84ae3bc)*

## C++ Preprocessor Directives and the `main` Function

Each C++ program typically has two key parts:

1. **Preprocessor Directives**
2. **The `main` Function**

Example code:

```cpp
#include <iostream>

int main() 
{
    std::cout << "Hello world, I am ready for C++";
    return 0;
}
```

### Preprocessor Directives

Any line starting with a `#` is a preprocessor directive. The most common one is `#include`, which tells the compiler to
include the contents of a file.

```cpp
#include <iostream>
```

This statement adds the declarations from the `iostream` library, which is required for input and output operations in
C++. The `<>` brackets instruct the compiler to look for the file in the system’s standard library directory.

When using quotes (`" "`), C++ will search in the current directory first, and then in the standard library directories
if the file is not found.

```cpp
#include "main.hpp"
```

Later in the course, you’ll see scenarios where the use of quotes versus brackets matters.

### The `main` Function

The `main` function is the entry point of every C++ program. The program execution starts here:

```cpp
int main() 
{
    std::cout << "Hello world, I am ready for C++";
    return 0;
}
```

## Comments in C++

Comments help explain how the code works but should not describe **why** it works a certain way. They can be written in
two ways:

1. **Block Comments**: Enclosed within `/*` and `*/`.

   Example:
   ```cpp
   /* This is a block comment.
      It spans multiple lines. */
   ```

2. **Single-line Comments**: Start with `//`.

   Example:
   ```cpp
   int age = 25;  // This is a single-line comment
   ```

## C++ Programming Style Guide

There are many style guides available for C++ development, and while we don’t enforce a strict style in this course,
consistency is key for readability. The following are useful style guides:

- [Modern C++ Coding Guidelines](https://github.com/Microsoft/AirSim/blob/master/docs/coding_guidelines.md)
- [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)

## The G++ Compiler

To compile your C++ program, you use the `g++` command:

```bash
g++ main.cpp -o main.out
```

- `g++`: Invokes the C++ compiler.
- `main.cpp`: The source code file.
- `-o main.out`: Specifies the output executable.

To run the compiled program, execute the following:

```bash
./main.out
```

## `namespace std`

Including `using namespace std;` allows you to avoid prefixing standard library functions (like `std::cout`) with
`std::`. Here’s an example:

```cpp
using namespace std;
int main()
{
    cout << "Hello, world!";
}
```

## The `sizeof` Operator

The `sizeof` operator helps determine the memory size (in bytes) of a data type.

Example:

```cpp
cout << "Size of int: " << sizeof(int) << " bytes\n";
```

### Printing with Newline or `endl`

You can print newlines in two ways:

1. Using `\n`:
   ```cpp
   cout << "Hello\n";
   ```

2. Using `endl`:
   ```cpp
   cout << "Hello" << endl;
   ```

While both work similarly, `endl` flushes the output buffer, which can affect performance in some scenarios. Learn more
about the differences between `\n` and `endl` [here](#).

## Defining Constants with `const`

In C++, you can define a constant using the `const` keyword. The value of a constant cannot change during the program’s
execution.

Example:

```cpp
const int MAX_SIZE = 100;
```

## Enumerated Constants (`enum`)

C++ also supports **enumerated constants** that allow you to define a type with a fixed set of values.

Example:

```cpp
enum MONTH { Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec };
```

Here, each month is assigned an integer starting from 0 (e.g., `Jan = 0`, `Feb = 1`).

## Formatting Output with `iomanip`

You can format your program’s output using the `iomanip` library, which provides features like setting field width with
`setw`.

Example:

```cpp
#include <iomanip>
cout << "Ints" << setw(15) << "Floats" << setw(15) << "Doubles" << "\n";
```

The output will look something like this:

```
Ints         Floats        Doubles
```

## Input and Output Streams (`fstream`)

C++ provides functionality to read from and write to files via the `<fstream>` library. There are three types of file
streams:

- `ofstream`: For writing to files.
- `ifstream`: For reading from files.
- `fstream`: For both reading and writing.

### Example of File I/O:

```cpp
#include <fstream>

ofstream outfile("example.txt");  // Open for writing
outfile << "This is a line of text." << endl;
outfile.close();
```

## Header Files

Header files (`.hpp` or `.h` extensions) contain declarations that can be included in other files using `#include`. They
help organize the code by separating declarations (how to do something) from the implementation (what to do).

Example:

```cpp
#include "main.hpp"
```

## String Input with `getline`

The `cin` function stops reading a string when it encounters a space. To read an entire line, use `getline`.

Example:

```cpp
string name;
getline(cin, name);
```

`getline` reads the entire line until a newline (`\n`) is encountered, storing it in the `name` variable. You can also
specify a different delimiter if necessary.