# Chapter 13: Advanced File and I/O Operations

This chapter covers advanced topics in C++ file and I/O operations, including different stream types, detailed error
handling, binary files, and random-access file manipulation. 🗃️

---

## 13.1 Input and Output Streams

C++ uses streams to handle data flow.

* **Input Streams**: Read data from a source. Examples include `cin` and the keyboard. The classes used to read data are
  `istream`, `ifstream`, and `istringstream`.
* **Output Streams**: Write data to a destination. Examples include `cout` and the computer screen. The classes used to
  write data are `ostream`, `ofstream`, and `ostringstream`.
* **Input/Output Streams**: Can be used for both reading and writing. The `fstream` class is used for this purpose.

The file stream classes `ifstream`, `ofstream`, and `fstream` have constructors that take a filename and an **open mode
**. Since C++ 11, the filename can be a `string` object. It's crucial to close files using the `close()` member function
when they're no longer needed.

### File Open Modes

**File open modes**, or **file mode flags**, specify how a file is opened and used. Multiple modes can be combined using
the bitwise OR operator (`|`). Some common modes include:

* `ios::app`: Opens a file to append data to the end.
* `ios::binary`: Reads or writes the file in binary mode instead of text mode.
* `ios::in`: Opens a file for input.
* `ios::out`: Opens a file for output.

`ifstream`, `ofstream`, and `fstream` have default open modes. The default for `ifstream` is input, `ofstream` is
output, and `fstream` is both input and output.

### Output Formatting

Output can be formatted using **I/O manipulators**. For example, `setw(n)` sets the output field width, and
`setprecision(n)` sets the floating-point precision. The `ostringstream` class allows you to format output in memory
before writing it to a file. You write to an `ostringstream` object using the insertion operator `<<` and retrieve the
formatted string using the `str()` member function.

---

## 13.2 More Detailed Error Testing

Stream objects have **error bits** (flags) that indicate the success or failure of an operation. These bits can be
checked using member functions:

* `eof()`: Returns true if the end of the file has been reached.
* `fail()`: Returns true if `failbit` or `hardfail` are set, indicating an operation failed.
* `bad()`: Returns true if `badbit` is set, indicating an invalid operation was attempted.
* `good()`: Returns true if no other error bits are set.
* `clear()`: Clears all error flags.

An entire file stream object can be tested as a boolean value to check if an operation was successful.

---

## 13.3 Member Functions for Reading and Writing Files

Unlike the `>>` operator, many reading functions do not skip whitespace.

* **`getline(source, dest, stopChar)`**: Reads a line of input from `source` into `dest` until a `stopChar` is found.
* **`get()`**: Reads a single character from the input stream.
* **`peek()`**: Reads the next character from the input stream but does not remove it from the stream.
* **`put(int c)`**: Writes a single character to a file.

To move to a specific location in a file, use `seekg` for input files and `seekp` for output files. Both functions take
an `offset` (number of bytes to move) and a `place` (starting point). The `place` can be `ios::beg` (beginning),
`ios::end` (end), or `ios::cur` (current position). To return to the beginning of a file, you must first clear any error
bits, then seek to position 0.

---

## 13.4 Binary Files

**Binary files** store data in the same format used in a computer's main memory. They are more efficient than text
files, which convert numeric values to ASCII characters. Files are opened in text mode by default. To open a file in
binary mode, you must use the `ios::binary` flag.

Special member functions are used to read and write binary data.

* **`read(char *buffer, int numberBytes)`**: Reads a specified number of bytes from a file into a buffer.
* **`write(char *buffer, int numberBytes)`**: Writes a specified number of bytes from a buffer to a file.
  The buffer's address may need to be cast to `char *` using `reinterpret_cast<char *>`.

---

## 13.5 Creating Records with Structures

You can read and write entire **structures** to and from binary files. You must open the file with the `ios::binary`
flag and use the `read` and `write` member functions. Structures written to a file cannot contain pointers or `string`
objects, as they use dynamic memory internally. Instead, use `char` arrays.

---

## 13.6 Random-Access Files

In contrast to **sequential access**, which requires you to read a file from the beginning in order, **random access**
allows you to access data in a file in any order.

The `seekg` and `seekp` member functions are used for random access. They allow you to move the read or write position
to a specific byte location in a file. The `tellg()` and `tellp()` member functions return the current byte position in
an input or output file, respectively.

---

## 13.7 Opening a File for Both Input and Output

A file can be opened for both input and output simultaneously using an `fstream` object with the `ios::in` and
`ios::out` flags. This supports updating a file by reading data, modifying it in memory, and then writing it back to the
file.