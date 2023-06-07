#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

class Item
{
    private:
        string title;
        double price;
    public:
        virtual void getdata()
        {
            cout << "\nInput title: ";
            cin >> title;
            cout << "\nInput price: ";
            cin >> price;
        }
        virtual void putdata()
        {
            cout << "\nTitle: " << title;
            cout << "\nPrice: " << price;
        }
};

class Paperbook: public Item
{
    private:
        int pages;
    public:
        void getdata()
        {
            Item::getdata();
            cout << "\nInput number of pages: ";
            cin >> pages;
        }
        void putdata()
        {
            Item::putdata();
            cout << "\nPages: " << pages;
        }
};

class AudioBook: public Item
{
    private:
        double time;
    public:
        void getdata()
        {
            Item::getdata();
            cout << "\nInput playing time: ";
            cin >> time;
        }
        void putdata()
        {
            Item::putdata();
            cout << "\nPlaying time: " << time;
        }
};

int main()
{
    SetConsoleOutputCP(1251);
    Item* pubarr [100];
    int n = 0;
    char choice;
    do
    {
        cout << "\nInput data for book or audio book (b/a)? ";
        cin >> choice;
        if(choice == 'b') pubarr[n] = new Paperbook;
        else pubarr[n] = new AudioBook;
        pubarr[n++]->getdata();
        cout << "Continue(y/n)? ";
        cin >> choice;
    }
    while(choice == 'y');
    for(int j=0; j<n; j++) pubarr[j]->putdata();
    cout << endl;
    return 0;
}