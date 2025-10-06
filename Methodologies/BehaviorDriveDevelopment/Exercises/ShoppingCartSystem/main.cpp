/*
 * BDD EXERCISES IN C++
 * 
 * Instructions: Complete the two exercises below by implementing the classes
 * and BDD test scenarios. Follow the Given-When-Then pattern.
 * 
 * Solutions are provided in a separate file.
 */

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

// Simple BDD Test Framework (provided)
class BDDTest {
private:
    std::string currentScenario;
    int passedTests = 0;
    int failedTests = 0;

public:
    void scenario(const std::string& description) {
        currentScenario = description;
        std::cout << "\nScenario: " << description << std::endl;
    }

    void given(const std::string& context) {
        std::cout << "  Given " << context << std::endl;
    }

    void when(const std::string& action) {
        std::cout << "  When " << action << std::endl;
    }

    void then(const std::string& expectation) {
        std::cout << "  Then " << expectation << std::endl;
    }

    void assert(bool condition, const std::string& message) {
        if (condition) {
            std::cout << "    ✓ PASS: " << message << std::endl;
            passedTests++;
        } else {
            std::cout << "    ✗ FAIL: " << message << std::endl;
            failedTests++;
        }
    }

    void printSummary() {
        std::cout << "\n" << std::string(50, '=') << std::endl;
        std::cout << "Test Summary:" << std::endl;
        std::cout << "  Passed: " << passedTests << std::endl;
        std::cout << "  Failed: " << failedTests << std::endl;
        std::cout << std::string(50, '=') << std::endl;
    }
};

// ============================================================================
// EXERCISE 1: Shopping Cart System
// ============================================================================
/*
 * Requirements:
 * 1. A shopping cart can add items with a name and price
 * 2. A shopping cart can remove items by name
 * 3. A shopping cart can calculate the total cost
 * 4. A shopping cart can apply a discount percentage (0-100)
 * 5. Cannot add items with negative or zero price
 * 6. Cannot apply discount less than 0 or greater than 100
 * 
 * YOUR TASK: Implement the ShoppingCart class below
 */

class ShoppingCart {
    // TODO: Add private member variables
    
public:
    // TODO: Implement constructor
    
    // TODO: Implement addItem(name, price)
    // Throw std::invalid_argument if price <= 0
    
    // TODO: Implement removeItem(name)
    // Throw std::runtime_error if item not found
    
    // TODO: Implement getTotal()
    // Returns total cost of all items
    
    // TODO: Implement applyDiscount(percentage)
    // Throw std::invalid_argument if percentage < 0 or > 100
    // Returns discounted total
    
    // TODO: Implement getItemCount()
    // Returns number of items in cart
};

// YOUR TASK: Complete the BDD test scenarios for Shopping Cart
void testShoppingCartBehavior() {
    BDDTest bdd;
    
    // Scenario 1: Add items to cart
    bdd.scenario("Customer adds items to empty cart");
    {
        bdd.given("an empty shopping cart");
        // TODO: Create ShoppingCart object
        
        bdd.when("the customer adds 'Apple' for $2.50");
        // TODO: Add item
        
        bdd.when("the customer adds 'Banana' for $1.50");
        // TODO: Add item
        
        bdd.then("the cart should contain 2 items");
        // TODO: Assert item count is 2
        
        bdd.then("the total should be $4.00");
        // TODO: Assert total is 4.00
    }
    
    // Scenario 2: Remove item from cart
    bdd.scenario("Customer removes item from cart");
    {
        bdd.given("a cart with 'Apple' ($2.50) and 'Banana' ($1.50)");
        // TODO: Create cart and add items
        
        bdd.when("the customer removes 'Apple'");
        // TODO: Remove item
        
        bdd.then("the cart should contain 1 item");
        // TODO: Assert item count is 1
        
        bdd.then("the total should be $1.50");
        // TODO: Assert total is 1.50
    }
    
    // Scenario 3: Apply discount
    bdd.scenario("Customer applies 20% discount");
    {
        bdd.given("a cart with items totaling $100");
        // TODO: Create cart and add items
        
        bdd.when("the customer applies a 20% discount");
        // TODO: Apply discount
        
        bdd.then("the discounted total should be $80");
        // TODO: Assert discounted total is 80.00
    }
    
    // TODO: Add 2 more scenarios:
    // - Scenario 4: Attempt to add item with negative price
    // - Scenario 5: Attempt to apply invalid discount (e.g., 150%)
    
    bdd.printSummary();
}

// ============================================================================
// MAIN FUNCTION
// ============================================================================
int main() {
    std::cout << "BDD EXERCISES\n" << std::string(50, '=') << std::endl;
    
    std::cout << "\n--- EXERCISE 1: Shopping Cart System ---" << std::endl;
    testShoppingCartBehavior();
    
    return 0;
}