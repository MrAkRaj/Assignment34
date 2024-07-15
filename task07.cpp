#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

struct Item {
    char code[7];
    char name[21];
    int price;

    bool operator<(const Item& other) const {
        return price > other.price; // Sort in descending order
    }
};

int main() {
    std::ifstream inFile("records.txt", std::ios::binary);
    std::vector<Item> items;

    if (!inFile) {
        std::cerr << "Error opening the file" << std::endl;
        return 1;
    }

    Item item;
    while (inFile.read(reinterpret_cast<char*>(&item), sizeof(item))) {
        items.push_back(item);
    }
    inFile.close();

    std::sort(items.begin(), items.end());

    std::ofstream outFile("records.txt", std::ios::binary);
    if (!outFile) {
        std::cerr << "Error opening the file" << std::endl;
        return 1;
    }

    for (const auto& it : items) {
        outFile.write(reinterpret_cast<const char*>(&it), sizeof(it));
    }
    outFile.close();
    std::cout << "Records sorted and written to the file successfully" << std::endl;

    return 0;
}
