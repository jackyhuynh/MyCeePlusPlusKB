/*

* **Comparison and Considerations: comparison vector addition.**

* **Readability:**
    * Operator overloading often leads to more concise and readable code, especially for mathematical or vector-like operations. `vec1[i] + vec2[i]` is generally easier to understand than a lambda expression.
* **Performance:**
    * In most cases, the performance difference between operator overloading and a simple lambda expression like this is negligible. The compiler is often capable of optimizing both approaches effectively.
    * `std::transform` may offer slight optimizations in some cases, because it is a standard library algorithm, and compilers may have specific optimizations for it.
    * However, if the lambda expression becomes very complex, there might be a small overhead due to the function call.
    * When using very simple operations, like the one in the example, the compiler will often inline both the operator overload and the lambda, resulting in almost identical performance.
* **Flexibility:**
    * Lambda expressions provide more flexibility when you need to perform more complex operations or when you want to pass the operation as a function object to other algorithms.
    * Operator overloading is more tightly bound to the class itself.
* **Context:**
    * Operator overloading is best suited for scenarios where you want to provide natural syntax for operations on objects of a specific class.
    * Lambda expressions are more versatile and can be used in a wider range of situations, including callbacks, algorithms, and function objects.

**In summary:**

* For simple operations like vector addition, operator overloading is often preferred due to its readability.
* For more complex operations or when flexibility is needed, lambda expressions are a powerful tool.
* Performance wise, in most cases, they will be very similar. Always use benchmarking if you need to be absolutely sure.

* */

#include <iostream>
#include <vector>
#include <chrono>

class Vector2D {
public:
    double x, y;

    Vector2D(double x = 0.0, double y = 0.0) : x(x), y(y) {}

    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(x + other.x, y + other.y);
    }
};

int main() {
    std::vector<Vector2D> vec1(1000000, Vector2D(1.0, 2.0));
    std::vector<Vector2D> vec2(1000000, Vector2D(3.0, 4.0));
    std::vector<Vector2D> result1(1000000);
    std::vector<Vector2D> result2(1000000);

    // Operator Overloading Time Measurement
    auto start1 = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < vec1.size(); ++i) {
        result1[i] = vec1[i] + vec2[i];
    }
    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration1 = end1 - start1;
    std::cout << "Operator overloading time: " << duration1.count() << " seconds" << std::endl;

    // Lambda Expression Time Measurement
    auto start2 = std::chrono::high_resolution_clock::now();
    std::transform(vec1.begin(), vec1.end(), vec2.begin(), result2.begin(),
                   [](const Vector2D& v1, const Vector2D& v2) {
                       return Vector2D(v1.x + v2.x, v1.y + v2.y);
                   });
    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration2 = end2 - start2;
    std::cout << "Lambda expression time: " << duration2.count() << " seconds" << std::endl;

    // Verify Results (Optional)
    bool resultsMatch = true;
    for(size_t i = 0; i < result1.size(); ++i){
        if(result1[i].x != result2[i].x || result1[i].y != result2[i].y){
            resultsMatch = false;
            break;
        }
    }
    if(resultsMatch){
        std::cout << "Results match." << std::endl;
    } else {
        std::cout << "Results do not match." << std::endl;
    }

    return 0;
}