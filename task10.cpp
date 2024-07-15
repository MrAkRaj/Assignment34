#include <iostream>
#include <fstream>
#include <vector>

struct Account {
    std::string name;
    int accountNumber;
    double balance;
};

void addRecord(std::ofstream& file) {
    Account acc;
    std::cout << "Enter name: ";
    std::cin >> acc.name;
    std::cout << "Enter account number: ";
    std::cin >> acc.accountNumber;
    std::cout << "Enter balance: ";
    std::cin >> acc.balance;

    file.write(reinterpret_cast<char*>(&acc), sizeof(acc));
    std::cout << "Record added successfully" << std::endl;
}

void displayContent(std::ifstream& file) {
    Account acc;
    file.clear();
    file.seekg(0);

    while (file.read(reinterpret_cast<char*>(&acc), sizeof(acc))) {
        std::cout << "Name: " << acc.name << ", Account Number: " << acc.accountNumber << ", Balance: " << acc.balance << std::endl;
    }
}

void displayHighBalance(std::ifstream& file) {
    Account acc;
    file.clear();
    file.seekg(0);

    std::cout << "Accounts with balance > 10,000:" << std::endl;
    while (file.read(reinterpret_cast<char*>(&acc), sizeof(acc))) {
        if (acc.balance > 10000) {
            std::cout << acc.name << std::endl;
        }
    }
}

int main() {
    std::ofstream outFile("accounts.txt", std::ios::app | std::ios::binary);
    if (!outFile) {
        std::cerr << "Error opening the file" << std::endl;
        return 1;
    }

    int choice;
    std::cout << "1. Add record\n2. Display content\n3. Display name of person having balance > 10,000\n";
    std::cin >> choice;

    if (choice == 1) {
        addRecord(outFile);
    }

    outFile.close();

    std::ifstream inFile("accounts.txt", std::ios::binary);
    if (!inFile) {
        std::cerr << "Error opening the file" << std::endl;
        return 1;
    }

    if (choice == 2) {
        displayContent(inFile);
    } else if (choice == 3) {
        displayHighBalance(inFile);
    }

    inFile.close();
    return 0;
}
