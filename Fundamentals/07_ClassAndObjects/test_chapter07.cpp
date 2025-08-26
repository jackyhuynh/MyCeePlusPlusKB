#include <iostream>
#include <string>
#include <cassert>
#include <cmath>

class Rectangle {
private:
    double length;
    double width;
    
public:
    Rectangle() : length(0), width(0) {}
    
    Rectangle(double l, double w) : length(l), width(w) {}
    
    void setLength(double l) { 
        if (l >= 0) length = l; 
    }
    
    void setWidth(double w) { 
        if (w >= 0) width = w; 
    }
    
    double getLength() const { return length; }
    double getWidth() const { return width; }
    
    double getArea() const { return length * width; }
    double getPerimeter() const { return 2 * (length + width); }
};

class BankAccount {
private:
    std::string accountNumber;
    double balance;
    static int totalAccounts;
    
public:
    BankAccount(std::string accNum, double initialBalance = 0.0) 
        : accountNumber(accNum), balance(initialBalance) {
        totalAccounts++;
    }
    
    ~BankAccount() {
        totalAccounts--;
    }
    
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }
    
    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            return true;
        }
        return false;
    }
    
    double getBalance() const { return balance; }
    std::string getAccountNumber() const { return accountNumber; }
    
    static int getTotalAccounts() { return totalAccounts; }
};

int BankAccount::totalAccounts = 0;

class Student {
private:
    std::string name;
    int id;
    double gpa;
    
public:
    Student() : name(""), id(0), gpa(0.0) {}
    
    Student(std::string n, int i, double g) 
        : name(n), id(i), gpa(g) {}
    
    void setName(const std::string &n) { name = n; }
    void setId(int i) { id = i; }
    void setGPA(double g) { 
        if (g >= 0.0 && g <= 4.0) gpa = g; 
    }
    
    std::string getName() const { return name; }
    int getId() const { return id; }
    double getGPA() const { return gpa; }
    
    void display() const {
        std::cout << "Student: " << name 
                  << ", ID: " << id 
                  << ", GPA: " << gpa << std::endl;
    }
};

void testClassBasics() {
    std::cout << "Test 1: Class Definition and Object Creation" << std::endl;
    
    Rectangle rect1;
    Rectangle rect2(5.0, 3.0);
    
    assert(rect1.getArea() == 0);
    assert(rect2.getArea() == 15.0);
    
    std::cout << "Default rectangle area: " << rect1.getArea() << std::endl;
    std::cout << "Rectangle(5,3) area: " << rect2.getArea() << std::endl;
    
    std::cout << "✓ Test passed: Basic class creation works\n" << std::endl;
}

void testConstructorsDestructors() {
    std::cout << "Test 2: Constructors and Destructors" << std::endl;
    
    {
        BankAccount acc1("ACC001", 1000.0);
        assert(BankAccount::getTotalAccounts() == 1);
        
        BankAccount acc2("ACC002", 500.0);
        assert(BankAccount::getTotalAccounts() == 2);
    }
    
    assert(BankAccount::getTotalAccounts() == 0);
    
    std::cout << "Accounts after scope: " << BankAccount::getTotalAccounts() << std::endl;
    std::cout << "✓ Test passed: Constructors and destructors work\n" << std::endl;
}

void testGettersSetters() {
    std::cout << "Test 3: Getters and Setters" << std::endl;
    
    Rectangle rect;
    rect.setLength(10.0);
    rect.setWidth(5.0);
    
    assert(rect.getLength() == 10.0);
    assert(rect.getWidth() == 5.0);
    assert(rect.getArea() == 50.0);
    
    rect.setLength(-5.0);
    assert(rect.getLength() == 10.0);
    
    std::cout << "Rectangle dimensions: " << rect.getLength() 
              << " x " << rect.getWidth() << std::endl;
    std::cout << "✓ Test passed: Getters and setters work correctly\n" << std::endl;
}

void testMemberFunctions() {
    std::cout << "Test 4: Member Functions" << std::endl;
    
    BankAccount account("ACC123", 1000.0);
    
    account.deposit(500.0);
    assert(account.getBalance() == 1500.0);
    
    bool success = account.withdraw(200.0);
    assert(success == true);
    assert(account.getBalance() == 1300.0);
    
    success = account.withdraw(2000.0);
    assert(success == false);
    assert(account.getBalance() == 1300.0);
    
    std::cout << "Account balance: $" << account.getBalance() << std::endl;
    std::cout << "✓ Test passed: Member functions work correctly\n" << std::endl;
}

void testPrivatePublic() {
    std::cout << "Test 5: Private and Public Access" << std::endl;
    
    Student student("John Doe", 12345, 3.5);
    
    assert(student.getName() == "John Doe");
    assert(student.getId() == 12345);
    assert(student.getGPA() == 3.5);
    
    student.setGPA(4.5);
    assert(student.getGPA() == 3.5);
    
    student.setGPA(3.8);
    assert(student.getGPA() == 3.8);
    
    std::cout << "Student GPA: " << student.getGPA() << std::endl;
    std::cout << "✓ Test passed: Access control works correctly\n" << std::endl;
}

void testStaticMembers() {
    std::cout << "Test 6: Static Members" << std::endl;
    
    BankAccount acc1("STATIC01", 100.0);
    BankAccount acc2("STATIC02", 200.0);
    BankAccount acc3("STATIC03", 300.0);
    
    assert(BankAccount::getTotalAccounts() == 3);
    
    std::cout << "Total accounts: " << BankAccount::getTotalAccounts() << std::endl;
    std::cout << "✓ Test passed: Static members work correctly\n" << std::endl;
}

void testConstMemberFunctions() {
    std::cout << "Test 7: Const Member Functions" << std::endl;
    
    const Rectangle rect(10.0, 5.0);
    
    double area = rect.getArea();
    double perimeter = rect.getPerimeter();
    
    assert(area == 50.0);
    assert(perimeter == 30.0);
    
    std::cout << "Const rectangle area: " << area << std::endl;
    std::cout << "Const rectangle perimeter: " << perimeter << std::endl;
    std::cout << "✓ Test passed: Const member functions work\n" << std::endl;
}

void testObjectArrays() {
    std::cout << "Test 8: Arrays of Objects" << std::endl;
    
    Student students[3] = {
        Student("Alice", 101, 3.9),
        Student("Bob", 102, 3.5),
        Student("Charlie", 103, 3.7)
    };
    
    double totalGPA = 0;
    for (int i = 0; i < 3; i++) {
        totalGPA += students[i].getGPA();
    }
    
    double avgGPA = totalGPA / 3;
    assert(std::abs(avgGPA - 3.7) < 0.01);
    
    std::cout << "Average GPA: " << avgGPA << std::endl;
    std::cout << "✓ Test passed: Object arrays work correctly\n" << std::endl;
}

void testThisPointer() {
    std::cout << "Test 9: this Pointer" << std::endl;
    
    class Point {
    private:
        int x, y;
    public:
        Point(int x, int y) {
            this->x = x;
            this->y = y;
        }
        
        Point& setX(int x) {
            this->x = x;
            return *this;
        }
        
        Point& setY(int y) {
            this->y = y;
            return *this;
        }
        
        int getX() const { return x; }
        int getY() const { return y; }
    };
    
    Point p(0, 0);
    p.setX(5).setY(10);
    
    assert(p.getX() == 5);
    assert(p.getY() == 10);
    
    std::cout << "Point: (" << p.getX() << ", " << p.getY() << ")" << std::endl;
    std::cout << "✓ Test passed: this pointer works correctly\n" << std::endl;
}

void testObjectPointers() {
    std::cout << "Test 10: Pointers to Objects" << std::endl;
    
    Rectangle* rectPtr = new Rectangle(8.0, 6.0);
    
    assert(rectPtr->getArea() == 48.0);
    assert((*rectPtr).getPerimeter() == 28.0);
    
    std::cout << "Dynamic rectangle area: " << rectPtr->getArea() << std::endl;
    
    delete rectPtr;
    
    std::cout << "✓ Test passed: Object pointers work correctly\n" << std::endl;
}

int main() {
    std::cout << "========================================" << std::endl;
    std::cout << "Chapter 7: Classes and Objects" << std::endl;
    std::cout << "Test Suite" << std::endl;
    std::cout << "========================================\n" << std::endl;
    
    testClassBasics();
    testConstructorsDestructors();
    testGettersSetters();
    testMemberFunctions();
    testPrivatePublic();
    testStaticMembers();
    testConstMemberFunctions();
    testObjectArrays();
    testThisPointer();
    testObjectPointers();
    
    std::cout << "========================================" << std::endl;
    std::cout << "All Chapter 7 tests passed successfully!" << std::endl;
    std::cout << "========================================" << std::endl;
    
    return 0;
}