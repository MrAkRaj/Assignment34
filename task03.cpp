#include <iostream>
#include <fstream>

int main() {
    std::ofstream file("a.txt", std::ios::app);
    if (!file) {
        std::cerr << "Error opening the file" << std::endl;
        return 1;
    }
    
    file << "Appending this text to the file.\n";
    file.close();
    std::cout << "Data appended successfully" << std::endl;

    return 0;
}
