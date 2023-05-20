#include <iostream>

void swap(int*, int*);
void swap(int&, int&);

int main()
{
    int x = 5, y = 10;
    std::cout << x << "  " << y << std::endl;
    swap(&x,&y);
    std::cout << x << "  " << y << std::endl;
    swap(x,y);
    std::cout << x << "  " << y << std::endl;
    return 0;
}

void swap (int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void swap (int &x, int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}