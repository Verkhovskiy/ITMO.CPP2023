#include <iostream>
#include <string>
#pragma once

class Person {
    protected:
        std::string name;
        std::string phone;

    public:
        Person(const std::string& name, const std::string& phone) : name(name), phone(phone) {}

        virtual std::string getOccupation() const = 0;

        std::string getName() const {
            return name;
        }

        std::string getPhone() const {
            return phone;
        }

        virtual void displayDetails() const {
            std::cout << "Name: " << name << std::endl;
            std::cout << "Phone: " << phone << std::endl;
            std::cout << "Occupation: " << getOccupation() << std::endl;
        }
};