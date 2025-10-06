## Step-by-Step Explanation

### **Step 1: Define the Feature**
We're building a banking account system. Before writing code, we identify the behaviors:
- Customers should be able to deposit money
- Customers should be able to withdraw money
- Withdrawals should fail if there are insufficient funds
- Accounts cannot start with negative balances

### **Step 2: Write Scenarios in Given-When-Then Format**
Each test scenario follows the BDD pattern:
- **Given** (context): "a customer has an account with $100"
- **When** (action): "the customer deposits $50"
- **Then** (outcome): "the account balance should be $150"

### **Step 3: Create the Domain Model**
The `BankAccount` class implements the actual business logic:
- Constructor with initial balance validation
- `deposit()` method with validation
- `withdraw()` method with insufficient funds check
- Getters for balance and account holder

### **Step 4: Implement Test Framework**
The `BDDTest` class provides methods that match BDD language:
- `scenario()` - describes what we're testing
- `given()`, `when()`, `then()` - document the test steps
- `assert()` - verifies expectations

### **Step 5: Write Executable Specifications**
Each scenario is both documentation AND a test:
```cpp
Scenario: Customer deposits money
  Given a customer has an account with $100
  When the customer deposits $50
  Then the account balance should be $150
```

### **Step 6: Run and Verify**
When you compile and run this program, you'll see:
- Clear scenario descriptions
- Each Given-When-Then step
- Pass/fail status for each assertion
- A summary of all tests

## Key BDD Benefits Demonstrated

1. **Readable Tests**: Anyone can understand what's being tested
2. **Living Documentation**: Tests describe expected behavior
3. **Collaboration**: Business stakeholders can review these scenarios
4. **Confidence**: Automated tests verify the behavior works

This is a simplified example - in production, you'd typically use frameworks like **Cucumber-CPP** or **Catch2 with BDD macros** for more sophisticated testing capabilities!
