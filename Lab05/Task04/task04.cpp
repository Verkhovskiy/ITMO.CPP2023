#include <iostream>
using namespace std;

void fill_array(int Arr[], int N)
{
	for(int i = 0; i < N; i++)
	{
        int curNumber;
		cout << "Input your number #" << i + 1 <<"\n";
        cin >> curNumber;
        Arr[i] = curNumber;
	}
}

void show_array(const int Arr[],const int N)
{
    for (int i = 0; i < N; i++)
    cout << Arr[i] <<" ";
    cout << "\n";
}

bool from_min(const int a, const int b)
{
    return a>b;
}

bool from_max(const int a,const int b)
{
    return a<b;
}

void bubble_sort(int Arr[],const int N, bool (*compare)(int a,int b))
{
    for (int i=1;i<N;i++)
    {
        for (int j=0;j<N-1;j++)
        {
            if ((*compare)(Arr[j],Arr[j+1])) swap(Arr[j],Arr[j+1]);
        }
    }
}

int main()
{
    bool (*from_f[2])(int, int) = { from_min,from_max };
    int my_choose = 0;
    int arraySize;
	cout << "How many numbers do you have?\n";
    cin >> arraySize;
    int* myArray = new int[arraySize];
    fill_array(myArray, arraySize);
    cout << "1. Sort ascending\n";
    cout << "2. Sort Descending\n";
    cin >> my_choose;
    cout << "Initial data: ";
    show_array(myArray, arraySize);
    bubble_sort(myArray, arraySize,(from_f[my_choose - 1]));
    show_array(myArray, arraySize);
    delete []myArray;
    return 0;
}