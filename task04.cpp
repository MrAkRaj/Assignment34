#include <iostream>
#include <fstream>
#include <cctype>

void changeCaseAndCopy(const std::string& srcFile, const std::string& destFile) {
    std::ifstream src(srcFile);
    std::ofstream dest(destFile);

    if (!src || !dest) {
        std::cerr << "Error opening the file(s)" << std::endl;
        return;
    }

    char ch;
    while (src.get(ch)) {
        if (std::islower(ch)) {
            ch = std::toupper(ch);
        } else if (std::isupper(ch)) {
            ch = std::tolower(ch);
        }
        dest.put(ch);
    }

    src.close();
    dest.close();
    std::cout << "File copied and case changed successfully" << std::endl;
}

int main() {
    changeCaseAndCopy("source.txt", "destination.txt");
    return 0;
}
