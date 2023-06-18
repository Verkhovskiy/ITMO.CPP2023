#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "person.cpp"
#include "student.cpp"
#include "teacher.cpp"

class AddressBook {
private:
    std::vector<Person*> contacts;

public:
    ~AddressBook() {
        for (Person* person : contacts) {
            delete person;
        }
    }

    void addPerson(Person* person) {
        contacts.push_back(person);
    }

    void displayAll() const {
        for (const Person* person : contacts) {
            person->displayDetails();
            std::cout << std::endl;
        }
    }

    void saveToFile(const std::string& filename) const {
        std::ofstream file(filename);
        if (file.is_open()) {
            for (const Person* person : contacts) {
                file << person->getName() << std::endl;
                file << person->getPhone() << std::endl;
                file << person->getOccupation() << std::endl;
                file << std::endl;
            }
            file.close();
            std::cout << "Address book saved to file: " << filename << std::endl;
        } else {
            std::cout << "Unable to open file: " << filename << std::endl;
        }
    }
};