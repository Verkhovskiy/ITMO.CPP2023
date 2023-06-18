#include <iostream>
#include <string>
#include "person.cpp"
#pragma once

class Student : public Person {
    private:
        std::string university;

    public:
        Student(const std::string& name, const std::string& phone, const std::string& university) : Person(name, phone), university(university) {}

        std::string getOccupation() const override {
            return "Student";
        }

        void displayDetails() const override {
            Person::displayDetails();
            std::cout << "University: " << university << std::endl;
        }
};