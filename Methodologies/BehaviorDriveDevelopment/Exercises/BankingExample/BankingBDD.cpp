#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

// Do this 2nd: Simple BDD-style testing framework
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

// Do this 3rd: Domain Model - Bank Account
class BankAccount {
private:
    std::string accountHolder;
    double balance;

public:
    BankAccount(const std::string& holder, double initialBalance = 0.0) 
        : accountHolder(holder), balance(initialBalance) {
        if (initialBalance < 0) {
            throw std::invalid_argument("Initial balance cannot be negative");
        }
    }

    void deposit(double amount) {
        if (amount <= 0) {
            throw std::invalid_argument("Deposit amount must be positive");
        }
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            throw std::invalid_argument("Withdrawal amount must be positive");
        }
        if (amount > balance) {
            throw std::runtime_error("Insufficient funds");
        }
        balance -= amount;
    }

    double getBalance() const {
        return balance;
    }

    std::string getAccountHolder() const {
        return accountHolder;
    }
};

// Do this 1st: BDD Test Scenarios
void testBankAccountBehavior() {
    BDDTest bdd;

    // Scenario 1: Successful Deposit
    bdd.scenario("Customer deposits money into their account");
    {
        bdd.given("a customer has an account with $100");
        BankAccount account("John Doe", 100.0);

        bdd.when("the customer deposits $50");
        account.deposit(50.0);

        bdd.then("the account balance should be $150");
        bdd.assert(account.getBalance() == 150.0, "Balance is $150");
    }

    // Scenario 2: Successful Withdrawal
    bdd.scenario("Customer withdraws money from their account");
    {
        bdd.given("a customer has an account with $200");
        BankAccount account("Jane Smith", 200.0);

        bdd.when("the customer withdraws $75");
        account.withdraw(75.0);

        bdd.then("the account balance should be $125");
        bdd.assert(account.getBalance() == 125.0, "Balance is $125");
    }

    // Scenario 3: Withdrawal with insufficient funds
    bdd.scenario("Customer attempts to withdraw more than available balance");
    {
        bdd.given("a customer has an account with $50");
        BankAccount account("Bob Johnson", 50.0);

        bdd.when("the customer attempts to withdraw $100");
        bool exceptionThrown = false;
        try {
            account.withdraw(100.0);
        } catch (const std::runtime_error& e) {
            exceptionThrown = true;
        }

        bdd.then("the withdrawal should be rejected");
        bdd.assert(exceptionThrown, "Insufficient funds exception thrown");

        bdd.then("the account balance should remain $50");
        bdd.assert(account.getBalance() == 50.0, "Balance unchanged at $50");
    }

    // Scenario 4: Multiple transactions
    bdd.scenario("Customer performs multiple transactions");
    {
        bdd.given("a customer has an account with $1000");
        BankAccount account("Alice Williams", 1000.0);

        bdd.when("the customer deposits $500");
        account.deposit(500.0);

        bdd.when("the customer withdraws $200");
        account.withdraw(200.0);

        bdd.when("the customer deposits $100");
        account.deposit(100.0);

        bdd.then("the account balance should be $1400");
        bdd.assert(account.getBalance() == 1400.0, "Balance is $1400");
    }

    // Scenario 5: Creating account with negative balance
    bdd.scenario("Attempt to create account with negative balance");
    {
        bdd.given("a customer wants to open an account");
        
        bdd.when("they try to create an account with -$50");
        bool exceptionThrown = false;
        try {
            BankAccount account("Charlie Brown", -50.0);
        } catch (const std::invalid_argument& e) {
            exceptionThrown = true;
        }

        bdd.then("the account creation should be rejected");
        bdd.assert(exceptionThrown, "Invalid argument exception thrown");
    }

    bdd.printSummary();
}

// Do this last: Main function to run tests
int main() {
    std::cout << "BDD Example: Bank Account Management System" << std::endl;
    std::cout << std::string(50, '=') << std::endl;

    testBankAccountBehavior();

    return 0;
}