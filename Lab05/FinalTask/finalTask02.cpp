#include <iostream>

using namespace std;

int* max_vect(const int ks, int a[], int b[]) {
    static int* myArray = new int[ks];
    for (int i = 0; i < ks; i++) {
        if (a[i] > b [i]) myArray[i] = a[i];
        else myArray[i] = b[i];
    }
    return myArray;
}

int main()
{
    int a[]={1,2,3,4,5,6,7,2};
    int b[]={7,6,5,4,3,2,1,3};
    int kc = sizeof(a)/sizeof(a[0]); //Количество элементов массива
    int *c; //Указатель на результирующий массив
    c = max_vect(kc,a,b); //вызов функции для создания массива
    for (int i = 0;i < kc; i++) //Вывод результата.
    cout << c[i] << " ";
    cout << endl;
    delete []c; //Возврат памяти.
}