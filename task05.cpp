#include <iostream>
#include <fstream>

void mergeFiles(const std::string& file1, const std::string& file2, const std::string& outFile) {
    std::ifstream src1(file1);
    std::ifstream src2(file2);
    std::ofstream dest(outFile);

    if (!src1 || !src2 || !dest) {
        std::cerr << "Error opening the file(s)" << std::endl;
        return;
    }

    dest << src1.rdbuf();
    dest << "\n--- End of First File ---\n";
    dest << src2.rdbuf();

    src1.close();
    src2.close();
    dest.close();
    std::cout << "Files merged successfully" << std::endl;
}

int main() {
    mergeFiles("file1.txt", "file2.txt", "merged.txt");
    return 0;
}
