#include <string>
#include <fstream>
#include "student.h"
using namespace std;

Student::Student(string name, string last_name)
{
    Student::set_name(name);
    Student::set_last_name(last_name);
}
// Деструктор Student
Student::~Student()
{
    Student::save();
}

// Запись данных о студенте в файл
void Student::save()
{
    ofstream fout("students.txt", ios::app);
    fout << Student::get_name() << " "
    << Student::get_last_name() << " ";
    for (int i = 0; i <5; ++i) {
        fout << Student::scores[i] <<" ";
    }
}
void Student::set_name(string student_name)
{
    Student::name = student_name;
}
// Получение имени студента
string Student::get_name()
{
    return Student::name;
}
// Установка фамилии студента
void Student::set_last_name(string student_last_name)
{
    Student::last_name = student_last_name;
}
// Получение фамилии студента
string Student::get_last_name()
{
    return Student::last_name;
}
// Установка промежуточных оценок
void Student::set_scores(int student_scores[])
{
    for (int i = 0; i < 5; ++i) {
        Student::scores[i] = student_scores[i];
    }
}
// Установка среднего балла
void Student::set_average_score(double ball)
{
    Student::average_score = ball;
}
// Получение среднего балла
double Student::get_average_score()
{
    return Student::average_score;
}