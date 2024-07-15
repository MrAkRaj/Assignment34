#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::fstream file("Employee.txt", std::ios::in | std::ios::out | std::ios::app);
    if (!file) {
        std::cerr << "Error opening the file" << std::endl;
        return 1;
    }

    std::string empName;
    std::cout << "Enter employee name to search for: ";
    std::cin >> empName;

    bool found = false;
    std::string line;
    while (std::getline(file, line)) {
        if (line.find(empName) != std::string::npos) {
            found = true;
            break;
        }
    }

    if (found) {
        std::cout << "Employee " << empName << " found." << std::endl;
    } else {
        std::cout << "Employee " << empName << " not found." << std::endl;
    }

    file.close();
    return 0;
}
