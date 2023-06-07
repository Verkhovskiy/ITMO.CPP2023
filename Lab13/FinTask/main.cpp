#include <iostream>
#include <vector>
#include "human.h"
#include "student.h"
#include "teacher.h"

int main()
{
    // Оценкистудента
    std::vector<int> scores;
    // Добавление оценок студента в вектор
    scores.push_back(5);
    scores.push_back(3);
    scores.push_back(4);
    scores.push_back(4);
    scores.push_back(5);
    scores.push_back(3);
    scores.push_back(3);
    scores.push_back(3);
    scores.push_back(3);
    student *stud = new student("Petrov", "Ivan", "Alekseevich", scores);
    human *human1 = stud;
    std::cout<< human1->get_full_name() <<std::endl;
    std::cout << "Avarage score: "<< stud->get_average_score() <<std::endl;

    unsigned int teacher_work_time = 40;
    teacher *tch = new teacher("Sergeev", "Dmitri", "Sergeevich", teacher_work_time);
    human *human2 = tch;
    std::cout << human2->get_full_name() << std::endl;
    std::cout << "Work time: " << tch->get_work_time() << std::endl;

    return 0;
}
