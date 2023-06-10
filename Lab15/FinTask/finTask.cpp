#include <iostream>
#include <string>
#include <map>

struct StudentGrade {
	std::string name;
	char grade;
};

int main() {
    StudentGrade student1 = {"Alex", 'A'};
    StudentGrade student2 = {"Boris", 'B'};
    StudentGrade student3 = {"Carl", 'C'};
    StudentGrade student4 = {"Denis", 'D'};
    StudentGrade student5 = {"Egor", 'E'};

    std::map<std::string, char> students;
    students[student1.name] = student1.grade;
    students[student2.name] = student2.grade;
    students[student3.name] = student3.grade;
    students[student4.name] = student4.grade;
    students[student5.name] = student5.grade;

    std::string inp;
    std::cout << "Input student's name: ";
    std::cin >> inp;

    auto stud = students.find(inp);
    if (stud != students.end()) {
        char newGrade;
        std::cout << "Current student's grade is: " << students[inp] << std::endl;
        std::cout << "Input new grade: ";
        std::cin >> newGrade;
        students[inp] = newGrade;
    } else {
        std::cout << "No student with this name found!" << std::endl;
    }
}