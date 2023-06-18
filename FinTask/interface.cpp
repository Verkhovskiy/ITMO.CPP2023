#include "addressBook.cpp"

class Interface {
private:
    AddressBook addressBook;

public:
    void run() {
        int choice;
        do {
            displayMenu();
            choice = getUserChoice();

            switch (choice) {
                case 1:
                    addPerson();
                    break;
                case 2:
                    displayAll();
                    break;
                case 3:
                    saveToFile();
                    break;
                case 0:
                    std::cout << "Exiting the program..." << std::endl;
                    break;
                default:
                    std::cout << "Invalid choice. Please try again." << std::endl;
                    break;
            }

            std::cout << std::endl;
        } while (choice != 0);
    }

private:
    void displayMenu() const {
        std::cout << "===== Address Book Menu =====" << std::endl;
        std::cout << "1. Add a person" << std::endl;
        std::cout << "2. Display all contacts" << std::endl;
        std::cout << "3. Save address book to file" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "=============================" << std::endl;
        std::cout << "Enter your choice: ";
    }

    int getUserChoice() const {
        int choice;
        std::cin >> choice;
        return choice;
    }

    void addPerson() {
        std::string name, phone;
        std::string occupation, universityOrDepartment;
        std::cin.sync();

        std::cout << "Enter name: ";
        std::getline(std::cin, name);


        std::cout << "Enter phone number: ";
        std::getline(std::cin, phone);

        std::cout << "Enter occupation (Student/Teacher): ";
        std::getline(std::cin, occupation);

        if (occupation == "Student") {
            std::cout << "Enter university: ";
            std::getline(std::cin, universityOrDepartment);

            addressBook.addPerson(new Student(name, phone, universityOrDepartment));
        } else if (occupation == "Teacher") {
            std::cout << "Enter department: ";
            std::getline(std::cin, universityOrDepartment);

            addressBook.addPerson(new Teacher(name, phone, universityOrDepartment));
        } else {
            std::cout << "Invalid occupation. Person not added." << std::endl;
        }
    }

    void displayAll() const {
        std::cout << "===== All Contacts =====" << std::endl;
        addressBook.displayAll();
        std::cout << "========================" << std::endl;
    }

    void saveToFile() {
        addressBook.saveToFile("book.txt");
    }
};