#include <iostream>
#include <fstream>

int main() {
    std::ifstream file("example.txt");
    if (!file) {
        std::cerr << "Error opening the file" << std::endl;
        return 1;
    }
    
    char ch;
    int count = 0;
    while (file.get(ch)) {
        ++count;
    }
    file.close();

    std::cout << "Number of characters: " << count << std::endl;
    return 0;
}
