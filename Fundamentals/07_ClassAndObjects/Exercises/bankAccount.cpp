#include <iostream>
#include <string>
using namespace std;

class BankAccount {

private:
    int accountNumber;
    double balance;
    string accountHolder;

public:
    BankAccount(int accNum=0, double bal=0, string holder=""): accountNumber(accNum), balance(bal), accountHolder(holder) {
    }

    ~BankAccount() {
        cout << "Bank account object destroyed." << endl;
    }

    void deposit(double amount) {
        balance += amount;
    }

    double withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            return amount;
        }
        cout << "You do not have enough money to withdraw " << amount << ". Your Balance is: " << balance ;
        return -1.0;
    }

    double getBalance() {
        return balance;
    }
};

    // Test program
    int main() {
        BankAccount account1( 123456789, 1000.00, "John Doe");
        account1.deposit(100.00);
        cout << "You balance is: " << account1.getBalance()<< endl;
        account1.withdraw(50.00);
    }