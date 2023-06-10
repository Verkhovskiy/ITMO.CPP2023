#include <iostream>
#include <windows.h>
#include <string>
#include "student.h"
#include "student.cpp"
#include "IdCard.h"
#include "IdCard.cpp"
#include "Group.h"
#include "Group.cpp"

using namespace std;

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    string name;
    string last_name;
	IdCard* idc = new IdCard(123456, "Student");
	IdCard* idc2 = new IdCard(654321, "Student");
	//int id;
	//string category;

    cout << "Name: ";
    getline(cin, name);

    cout << "Last name: ";
    getline(cin, last_name);

	//cout << "Category: ";
	//getline(cin, category);
	//idc->setCategory(category);

	//cout << "IdCard :";
	//cin >> id;
	//idc->setNumber(id);

    Student *student02 = new Student(name, last_name, idc);
    Student student03 ("Peter", "Petrov", idc2);
    Student student04 ("Igor", "Igorev", idc);
    Student student05 ("Sasha", "Kogan", idc2);
    Student student06 ("Dmitri", "Ivanov", idc);

    Group gr1957("1957");

    gr1957.addStudent(*student02);
    gr1957.addStudent(student03);
    gr1957.addStudent(student04);
    gr1957.addStudent(student05);
    gr1957.addStudent(student06);

    gr1957.delStudent(student04);
    gr1957.delStudent(gr1957.findStudent("Dmitri", "Ivanov"));

    int k = gr1957.getSize();
    gr1957.GroupSort();
    cout << "Group: "<< gr1957.getName() << " " << k <<" students" << endl;
    gr1957.GroupOut();
 
    int scores[5];
    int sum = 0;

    for (int i = 0; i < 5; ++i) {
        cout << "Score " << i+1 << ": ";
        cin >> scores[i];
        sum += scores[i];
    }

    student02->set_scores(scores);

    double average_score = sum / 5.0;
    student02->set_average_score(average_score);

	//IdCard* card = new IdCard(123);
	//student02->setIdCard(*card);
	
    cout << "Average ball for " << student02->get_name() << " "
         << student02->get_last_name() << " is "
         << student02->get_average_score() << endl;

	cout << "IdCard: " << student02->getIdCard().getNumber() << endl;
	cout << "Category: " << student02->getIdCard().getCategory() << endl;

	delete student02; 
	return 0;
}
