#include<iostream>

template<class T>
double avarage (T arr[], int size){
    int j = 0;
    for (int i = 0; i < size; i++) {
        j += arr[i];
    }
    return (double)j / size;
}

int main()
{
    int arra[] = {9,3,17,6,5,4,31,2,12};
    double arrb[] = {2.1, 2.3,1.7,6.6,5.3,2.44,3.1,2.4,1.2};
    char arrc[] = "Hello, word";
    long arrd[] = {9,3,17,6,5,4,31,2,12};
    int k1 = sizeof(arra)/sizeof(arra[0]);
    int k2 = sizeof(arrb)/sizeof(arrb[0]);
    int k3 = sizeof(arrc)/sizeof(arrc[0]);
    int k4 = sizeof(arrd)/sizeof(arrd[0]);
    std::cout << avarage(arra, k1) << std::endl;
    std::cout << avarage(arrb, k2) << std::endl;
    std::cout << avarage(arrc, k3) << std::endl;
    std::cout << avarage(arrd, k4) << std::endl;
}