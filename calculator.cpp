#include <iostream>
#include <string>

class BankAccount {
private:
    std::string accountNumber;
    double balance;

public:
    BankAccount(const std::string& accNumber, double initialBalance)
        : accountNumber(accNumber), balance(initialBalance) {
    }

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
        } else {
            std::cout << "Insufficient funds." << std::endl;
        }
    }

    void display() const {
        std::cout << "Account Number: " << accountNumber << std::endl;
        std::cout << "Balance: " << balance << std::endl;
    }

    BankAccount operator+(const BankAccount& other) const {
        std::string newAccNumber = accountNumber + "-" + other.accountNumber;
        double newBalance = balance + other.balance;
        return BankAccount(newAccNumber, newBalance);
    }

    BankAccount operator-(const BankAccount& other) const {
        std::string newAccNumber = accountNumber + "-" + other.accountNumber;
        double newBalance = balance - other.balance;
        return BankAccount(newAccNumber, newBalance);
    }

    std::string toString() const {
        return "Account Number: " + accountNumber + "\nBalance: " + std::to_string(balance);
    }
};

std::istream& operator>>(std::istream& input, BankAccount& account) {
    std::string accNumber;
    double balance;
    input >> accNumber >> balance;
    account = BankAccount(accNumber, balance);
    return input;
}

std::ostream& operator<<(std::ostream& output, const BankAccount& account) {
    output << account.toString();
    return output;
}

int main() {
    BankAccount account1("123456789", 1000.0);
    BankAccount account2("987654321", 500.0);

    std::cout << "Account 1:" << std::endl;
    std::cout << account1 << std::endl;

    std::cout << "Account 2:" << std::endl;
    std::cout << account2 << std::endl;

    BankAccount sum = account1 + account2;
    std::cout << "Sum of Account 1 and Account 2:" << std::endl;
    std::cout << sum << std::endl;

    BankAccount difference = account1 - account2;
    std::cout << "Difference between Account 1 and Account 2:" << std::endl;
    std::cout << difference << std::endl;

    std::cout << "Enter account details (Account Number Balance): ";
    std::cin >> account1;
    std::cout << "Updated Account 1:" << std::endl;
    std::cout << account1 << std::endl;

    return 0;
}