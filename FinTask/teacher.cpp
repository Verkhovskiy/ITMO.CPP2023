#include <iostream>
#include <string>
#include "person.cpp"
#pragma once

class Teacher : public Person {
    private:
        std::string department;

    public:
        Teacher(const std::string& name, const std::string& phone, const std::string& department) : Person(name, phone), department(department) {}

        std::string getOccupation() const override {
            return "Teacher";
        }

        void displayDetails() const override {
            Person::displayDetails();
            std::cout << "Department: " << department << std::endl;
        }
};