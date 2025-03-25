#include <iostream>
#include <vector>
#include <cmath>

/*
    **Explanation of the Complex Exercises:**

    * **Exercise 4 (Complex Numbers):**
        * This demonstrates overloading arithmetic operators (`+`, `-`, `*`, `/`) for a `Complex` number class.
        * It shows how to implement complex number arithmetic, including handling division by zero.
        * The output stream operator is overloaded to display complex numbers in a standard format (e.g., `1+2i`).
    * **Exercise 5 (String with Custom Comparison):**
        * This shows overloading comparison operators (`==`, `!=`, `<`, `>`, `<=`, `>=`) for a `String` class.
        * However, it uses a custom comparison logic based on the *length* of the strings rather than lexicographical order. This highlights that you can define operator behavior according to your specific needs.
        * This exercises highlights the importance of consistency. If you overload `==` you should also overload `!=`, and if you overload `<` you should also overload `>`, `<=`, and `>=`.
 */


// Exercise 4: Overload arithmetic operators for a Complex number class.
class Complex {
public:
    double real, imag;

    Complex(double real = 0.0, double imag = 0.0) : real(real), imag(imag) {}

    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex operator*(const Complex& other) const {
        return Complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
    }

    Complex operator/(const Complex& other) const {
        double denominator = other.real * other.real + other.imag * other.imag;
        if (denominator == 0) {
            throw std::runtime_error("Division by zero");
        }
        return Complex((real * other.real + imag * other.imag) / denominator,
                       (imag * other.real - real * other.imag) / denominator);
    }

    friend std::ostream& operator<<(std::ostream& os, const Complex& c) {
        os << c.real << (c.imag >= 0 ? "+" : "-") << fabs(c.imag) << "i";
        return os;
    }
};

// Exercise 5: Overload comparison operators for a String class with custom comparison.
class String {
private:
    std::string str;

public:
    String(const std::string& s = "") : str(s) {}

    bool operator==(const String& other) const {
        return str.length() == other.str.length(); // Compare based on length
    }

    bool operator!=(const String& other) const {
        return !(*this == other);
    }

    bool operator<(const String& other) const {
        return str.length() < other.str.length(); // Compare based on length
    }

    bool operator>(const String& other) const {
        return str.length() > other.str.length();
    }

    bool operator<=(const String& other) const {
        return !(*this > other);
    }

    bool operator>=(const String& other) const {
        return !(*this < other);
    }

    friend std::ostream& operator<<(std::ostream& os, const String& s) {
        os << s.str;
        return os;
    }
};

int main() {
    // Exercise 4: Complex class
    Complex c1(1, 2);
    Complex c2(3, -4);
    std::cout << "c1: " << c1 << ", c2: " << c2 << std::endl;
    std::cout << "c1 + c2: " << c1 + c2 << std::endl;
    std::cout << "c1 - c2: " << c1 - c2 << std::endl;
    std::cout << "c1 * c2: " << c1 * c2 << std::endl;
    try {
      std::cout << "c1 / c2: " << c1 / c2 << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    // Exercise 5: String class with custom comparison
    String s1("apple");
    String s2("banana");
    String s3("grape");
    std::cout << "s1: " << s1 << ", s2: " << s2 << ", s3: " << s3 << std::endl;
    std::cout << "s1 == s2: " << (s1 == s2) << std::endl;
    std::cout << "s1 < s2: " << (s1 < s2) << std::endl;
    std::cout << "s2 > s3: " << (s2 > s3) << std::endl;

    return 0;
}

