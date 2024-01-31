#include <iostream>
#include <array>

using namespace std; // Now we don't need to prefix standard library names with std::

template<typename T, size_t N>
class FixedArray {
private:
    array<T, N> data;

public:
    FixedArray() = default;

    // Constructor to initialize from an array for convenience
    FixedArray(const array<T, N>& dataArray) : data(dataArray) {}

    // Overloaded + operator for element-wise addition
    FixedArray operator+(const FixedArray& other) const {
        FixedArray result;
        for (size_t i = 0; i < N; ++i) {
            result.data[i] = this->data[i] + other.data[i];
        }
        return result;
    }

    // Overloaded - operator for element-wise subtraction
    FixedArray operator-(const FixedArray& other) const {
        FixedArray result;
        for (size_t i = 0; i < N; ++i) {
            result.data[i] = this->data[i] - other.data[i];
        }
        return result;
    }

    // Overloaded * operator for element-wise multiplication
    FixedArray operator*(const FixedArray& other) const {
        FixedArray result;
        for (size_t i = 0; i < N; ++i) {
            result.data[i] = this->data[i] * other.data[i];
        }
        return result;
    }

    // Overloaded / operator for element-wise division
    FixedArray operator/(const FixedArray& other) const {
        FixedArray result;
        for (size_t i = 0; i < N; ++i) {
            // Assume T can be divided and check for division by zero.
            if (other.data[i] != 0) {
                result.data[i] = this->data[i] / other.data[i];
            } else {
                // Handle division by zero as per your requirements.
                result.data[i] = 0; // Example handling, could throw an exception instead.
            }
        }
        return result;
    }

    // Helper function to print the contents of the array
    void print() const {
        cout << "{ ";
        for (const auto& item : data) {
            cout << item << " ";
        }
        cout << "}\n";
    }
};

int main() {
    FixedArray<int, 5> arr1({1, 2, 3, 4, 0});
    FixedArray<int, 5> arr2({5, 4, 3, 2, 1});

    FixedArray<int, 5> resultAdd = arr1 + arr2;
    FixedArray<int, 5> resultSub = arr1 - arr2;
    FixedArray<int, 5> resultMul = arr1 * arr2;
    FixedArray<int, 5> resultDiv = arr1 / arr2;

    cout << "Addition: ";
    resultAdd.print();

    cout << "Subtraction: ";
    resultSub.print();

    cout << "Multiplication: ";
    resultMul.print();

    cout << "Division: ";
    resultDiv.print();

    return 0;
}
