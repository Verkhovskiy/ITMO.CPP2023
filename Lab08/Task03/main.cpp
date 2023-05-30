#include <iostream>
#include <string>
#include "student.h"
#include "student.cpp"
using namespace std;
int main()
{
    // Создание объекта класса Student
    Student *student02 = new Student;
    string name;
    string last_name;
    // Ввод имени с клавиатуры
    cout << "Name: ";
    getline(cin, name);
    // Ввод фамилии
    cout << "Last name: ";
    getline(cin, last_name);
    // Оценки
    int scores[5];
    // Сумма всех оценок
    int sum = 0;
    // Ввод промежуточных оценок
    for (int i = 0; i < 5; ++i) {
        cout << "Score " << i+1 << ": ";
        cin >> scores[i];
        // суммирование
        sum += scores[i];
    }
    // Считаем средний балл
    double average_score = sum / 5.0;
    // Сохраняем средний балл в объект класса Student
    // Сохранение имени и фамилии в объект класса Students
    student02->set_name(name);
    student02->set_last_name(last_name);
    // Сохраняем промежуточные оценки в объект класса Student
    student02->set_scores(scores);
    // Сохраняем средний балл в объект класса Student
    student02->set_average_score(average_score);
    // Выводим данные по студенту
    cout << "Average ball for " << student02->get_name() << " "
    << student02->get_last_name() << " is "
    << student02->get_average_score() << endl;
    delete student02;
    return 0;
}