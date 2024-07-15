#include <iostream>
#include <fstream>
#include <cctype>

int main() {
    std::ifstream file("example.txt");
    if (!file) {
        std::cerr << "Error opening the file" << std::endl;
        return 1;
    }

    int chars = 0, words = 0, lines = 0;
    bool inWord = false;
    char ch;

    while (file.get(ch)) {
        ++chars;
        if (ch == '\n') ++lines;
        if (std::isspace(ch)) {
            if (inWord) {
                inWord = false;
                ++words;
            }
        } else {
            inWord = true;
        }
    }
    if (inWord) ++words; // Count the last word if file does not end with a space

    file.close();
    std::cout << "Characters: " << chars << "\nWords: " << words << "\nLines: " << lines << std::endl;
    return 0;
}
