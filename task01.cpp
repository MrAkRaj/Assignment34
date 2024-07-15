#include <iostream>
#include <fstream>

int main() {
    std::ofstream file("example.txt");
    if (file.is_open()) {
        std::cout << "File created successfully" << std::endl;
        file.close();
    } else {
        std::cerr << "Error creating the file" << std::endl;
    }
    return 0;
}
