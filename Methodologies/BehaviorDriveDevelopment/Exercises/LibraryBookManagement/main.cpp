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
// EXERCISE 2: Library Book Management System
// ============================================================================
/*
 * Requirements:
 * 1. A library can add books with title and ISBN
 * 2. A library can check out a book (if available)
 * 3. A library can return a book
 * 4. A library can check if a book is available by ISBN
 * 5. Cannot check out a book that's already checked out
 * 6. Cannot return a book that's not checked out
 * 7. Cannot add duplicate ISBN
 * 
 * YOUR TASK: Implement the Library class below
 */

class Library {
    // TODO: Add private member variables
    // Hint: You might need a Book struct/class to track title, ISBN, and availability
    
public:
    // TODO: Implement constructor
    
    // TODO: Implement addBook(title, isbn)
    // Throw std::invalid_argument if ISBN already exists
    
    // TODO: Implement checkOutBook(isbn)
    // Throw std::runtime_error if book not found or already checked out
    
    // TODO: Implement returnBook(isbn)
    // Throw std::runtime_error if book not found or not checked out
    
    // TODO: Implement isBookAvailable(isbn)
    // Returns true if book exists and is available
    
    // TODO: Implement getTotalBooks()
    // Returns total number of books in library
    
    // TODO: Implement getAvailableBooks()
    // Returns number of available (not checked out) books
};

// YOUR TASK: Complete the BDD test scenarios for Library
void testLibraryBehavior() {
    BDDTest bdd;
    
    // Scenario 1: Add books to library
    bdd.scenario("Librarian adds books to the library");
    {
        bdd.given("an empty library");
        // TODO: Create Library object
        
        bdd.when("the librarian adds '1984' with ISBN '978-0451524935'");
        // TODO: Add book
        
        bdd.when("the librarian adds 'Brave New World' with ISBN '978-0060850524'");
        // TODO: Add book
        
        bdd.then("the library should have 2 books");
        // TODO: Assert total books is 2
        
        bdd.then("all books should be available");
        // TODO: Assert available books is 2
    }
    
    // Scenario 2: Check out a book
    bdd.scenario("Customer checks out an available book");
    {
        bdd.given("a library with '1984' available");
        // TODO: Create library and add book
        
        bdd.when("a customer checks out '1984'");
        // TODO: Check out book
        
        bdd.then("'1984' should not be available");
        // TODO: Assert book is not available
        
        bdd.then("available books count should be 0");
        // TODO: Assert available count is 0
    }
    
    // TODO: Add 3 more scenarios:
    // - Scenario 3: Return a checked out book
    // - Scenario 4: Attempt to check out already checked out book
    // - Scenario 5: Attempt to add duplicate ISBN
    
    bdd.printSummary();
}

// ============================================================================
// MAIN FUNCTION
// ============================================================================
int main() {
    std::cout << "BDD EXERCISES\n" << std::string(50, '=') << std::endl;

    std::cout << "\n--- EXERCISE 2: Library Management System ---" << std::endl;
    testLibraryBehavior();
    
    return 0;
}