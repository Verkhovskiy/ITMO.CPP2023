#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ofstream out ("poem.txt", std::ios::out);
    if (!out) {
        std::cout << "Файл открыть невозможно\n";
        return 1;
    }
    std::cout << "Write your poem (write \"end\" to finish):\n";
    std::string poem;
    while (poem != "end") {
        std::getline(std::cin, poem);
        if (poem != "end") {
            out << poem;
            out << "\n";
        }
    }
    out.close();
}