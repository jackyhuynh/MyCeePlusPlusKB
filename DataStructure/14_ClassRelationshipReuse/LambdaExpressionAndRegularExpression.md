# Regular Expressions and Lambda Expressions in C++

## Regular Expressions

Regular expressions (regex) are a powerful tool for pattern matching in strings. They allow you to search, manipulate, and validate text based on specific patterns.

**Key Concepts:**

* **Pattern:** A sequence of characters that defines a search pattern.
* **Matching:** The process of finding occurrences of the pattern within a string.
* **`std::regex`:** The C++ standard library class for working with regular expressions (requires `<regex>`).

**Common Regex Syntax (Simplified):**

* `.` (dot): Matches any single character.
* `*` (asterisk): Matches zero or more occurrences of the preceding character or group.
* `+` (plus): Matches one or more occurrences of the preceding character or group.
* `?` (question mark): Matches zero or one occurrence of the preceding character or group.
* `[abc]`: Matches any character within the brackets (a, b, or c).
* `[a-z]`: Matches any lowercase letter.
* `\d`: Matches any digit (0-9).
* `\w`: Matches any word character (alphanumeric and underscore).
* `^`: Matches the beginning of a string.
* `$`: Matches the end of a string.
* `()`: Groups characters together.
* `|`: Or operator
* `\` : Escape character.

**C++ Code Example:**

```cpp
#include <iostream>
#include <regex>
#include <string>

int main() {
    std::string text = "My email is [email address removed] and another email is [email address removed].";
    std::regex emailRegex(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");

    std::sregex_iterator iterator(text.begin(), text.end(), emailRegex);
    std::sregex_iterator end;

    while (iterator != end) {
        std::smatch match = *iterator;
        std::cout << "Found email: " << match.str() << std::endl;
        ++iterator;
    }

    std::string phoneNumber = "My phone number is 123-456-7890";
    std::regex phoneRegex(R"(\d{3}-\d{3}-\d{4})");
    std::smatch phoneMatch;

    if (std::regex_search(phoneNumber, phoneMatch, phoneRegex)) {
        std::cout << "Found phone number: " << phoneMatch.str() << std::endl;
    }

    return 0;
}
```

## Lambda Expressions

Lambda expressions are anonymous functions that can be defined and used inline. They are particularly useful for short, one-time functions, especially when working with algorithms and function pointers.

**Key Concepts:**

* **Anonymous Function:** A function without a name.
* **Inline Definition:** Defined where it's used.
* **Capture List:** Specifies which variables from the surrounding scope are accessible within the lambda.
* **Parameter List:** Specifies the input parameters of the lambda.
* **Return Type (Optional):** Specifies the return type of the lambda.
* **Function Body:** Contains the code that the lambda executes.

**Lambda Syntax:**

```cpp
[capture list](parameter list) -> return type { function body };
```

**Capture List:**

* `[]`: Capture nothing.
* `[=]`: Capture all surrounding variables by value.
* `[&]`: Capture all surrounding variables by reference.
* `[x, &y]`: Capture `x` by value and `y` by reference.

**C++ Code Example:**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Lambda to filter even numbers
    std::vector<int> evenNumbers;
    std::copy_if(numbers.begin(), numbers.end(), std::back_inserter(evenNumbers),
                   [](int n) { return n % 2 == 0; });

    std::cout << "Even numbers: ";
    for (int num : evenNumbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Lambda to multiply each number by 2
    std::vector<int> multipliedNumbers;
    std::transform(numbers.begin(), numbers.end(), std::back_inserter(multipliedNumbers),
                   [](int n) { return n * 2; });

    std::cout << "Multiplied numbers: ";
    for (int num : multipliedNumbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    int multiplier = 3;
    std::vector<int> multipliedByCapture;
    std::transform(numbers.begin(), numbers.end(), std::back_inserter(multipliedByCapture),
                   [multiplier](int n) { return n * multiplier; });

    std::cout << "Multiplied by capture numbers: ";
    for (int num : multipliedByCapture) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

**Benefits:**

* Concise code.
* Improved readability for short functions.
* Flexibility in using functions as arguments.
