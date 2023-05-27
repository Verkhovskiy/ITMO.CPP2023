#include <iostream>
#include <fstream>
#include <cmath>
#include <ctime>

int main() {
    srand(time(NULL));
    double sum = 0;
    int const n = 100;
    double nums[n];
    for (int i = 0; i < n; i++)
    {
        nums[i] = (rand() % 100);
    }
    std::ofstream out ("test", std::ios::out | std::ios::binary);
    if (!out) {
        std::cout << "Файл открыть невозможно\n";
        return 1;
    }
    out.write((char *) nums, sizeof(nums));
    out.close();
    std::ifstream in("test", std::ios::in | std::ios::binary);
    if(!in) {
        std::cout << "Файл открыть невозможно";
    return 1;
    }
    
    double upload[n];
    in.read((char *) &upload, sizeof(upload));
    int k = sizeof(upload)/sizeof(double);
    for (int i=0; i<k; i++)
    {
        sum = sum + upload[i];
        std::cout << upload[i] <<' ';
    }
    std::cout << "\nsum = " << sum << std::endl;
    in.close();
}