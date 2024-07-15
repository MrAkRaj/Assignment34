#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct Employee {
    int id;
    std::string name;
    std::string address;
    std::string dept;
    std::string phone;
    int age;
};

int main() {
    std::ifstream inFile("emp.dat", std::ios::binary);
    if (!inFile) {
        std::cerr << "Error opening the file" << std::endl;
        return 1;
    }

    std::ofstream adminFile("Adm.dat", std::ios::binary);
    std::ofstream salesFile("Sal.dat", std::ios::binary);
    std::ofstream productionFile("Pro.dat", std::ios::binary);
    std::ofstream itFile("IT.dat", std::ios::binary);

    if (!adminFile || !salesFile || !productionFile || !itFile) {
        std::cerr << "Error opening one or more files" << std::endl;
        return 1;
    }

    Employee emp;
    while (inFile.read(reinterpret_cast<char*>(&emp), sizeof(emp))) {
        if (emp.dept == "Admin") {
            adminFile.write(reinterpret_cast<char*>(&emp), sizeof(emp));
        } else if (emp.dept == "Sales") {
            salesFile.write(reinterpret_cast<char*>(&emp), sizeof(emp));
        } else if (emp.dept == "Production") {
            productionFile.write(reinterpret_cast<char*>(&emp), sizeof(emp));
        } else if (emp.dept == "IT") {
            itFile.write(reinterpret_cast<char*>(&emp), sizeof(emp));
        }
    }

    inFile.close();
    adminFile.close();
    salesFile.close();
    productionFile.close();
    itFile.close();
    std::cout << "Employee records sorted into department-specific files successfully" << std::endl;

    return 0;
}
