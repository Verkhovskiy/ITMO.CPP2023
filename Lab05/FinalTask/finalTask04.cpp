#include <iostream>
#include <cstring>

int main(int argc, char *argv[]) 
{
    int add = strncmp(argv[1], "-a", 2);
    int mult = strncmp(argv[1], "-m", 2);
    try {if (!(add == 0 || mult == 0) || argc != 4) throw 1;}
    catch (...) {
        std::cout << "Arguments are incorrect";
    }
    int a = atoi(argv[2]);
    int b = atoi(argv[3]);
    if (add == 0) return a + b;
    if (mult == 0) return a * b;
}