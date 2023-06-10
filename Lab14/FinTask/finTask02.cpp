#include <vector>
#include <iostream>

template<class T>
void Print(const T &container, std::string delimiter) {
    bool first = true;
	for (const auto &item : container) {
		if(!first) {
			std::cout << delimiter;
		}
		std::cout << item;
        first = false;
	}
}

int main() {
    std::vector<int> data = { 1, 2, 3 };
    Print(data, ", "); // на экране: 1, 2, 3
}
