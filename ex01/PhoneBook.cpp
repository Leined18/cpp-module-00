#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : index(0), count(0) {

}

PhoneBook::~PhoneBook() {
    // Destructor
}

void PhoneBook::displayContact(int index) {
    this->contacts[index].printContact(index);
}

void PhoneBook::displayAllContacts() {
    printFields(10);
    for (int i = 0; i < count; i++) {
        contacts[i].printInfo(i, 10);
    }
}

void PhoneBook::addContact() {
    Contact contact;

    contact = contact.createContact();
    if (contact.isAnyFieldEmpty()) {
        std::cout << "\033[31mContact creation failed due to empty fields\033[0m" << std::endl;
        std::cout << "\033[32mPlease fill all fields\033[0m" << std::endl;
        std::cin.clear();
        return;
    }
    if (count < 8) {
        std::cout << "\033[32mAdding contact at index \033[0m" << count << std::endl;
        contacts[count] = contact;  
        count++;
    } else {
        contacts[count - 1] = contact;
        std::cout << "\033[31mPhoneBook is full\033[0m" << std::endl;
        std::cout << "\033[32mOverwriting contact at index \033[0m" << count - 1 << std::endl;
    }
    std::cout << "\033[32mContact added successfully\033[0m" << std::endl;
    std::cin.clear();
}

void PhoneBook::searchContact() {

    std::cout << BLUE"Searching contact"RESET << std::endl;
    std::cout << YELLOW"[Enter index to search (0-7)]"RESET << std::endl;
    std::cin >> index;
    if (std::cin.eof()) {
        std::cout << YELLOW"EOF"RESET << std::endl;
        std::cout << "Exiting program" << std::endl;
        std::exit(0);
    }
    if (index < 0 || index >= count || index >= 8 || std::cin.fail()) {
        std::cout << RED"Invalid index"RESET << std::endl;
        std::cout << BLUE"Displaying all contacts"RESET << std::endl;
        displayAllContacts();
        std::cin.clear();
        return;
    }
    displayContact(index);
}

void PhoneBook::run() {
    std::string command;
    while (true) {
        std::cout << BLUE"Enter command (ADD, SEARCH, EXIT): "RESET;
        if (!std::cin) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        if (!std::getline(std::cin, command)) {
            if (std::cin.eof()) {
                std::cout << YELLOW"EOF"RESET << std::endl;
                break;
            }
            std::cout << RED"Error reading command"RESET << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        // Limpiar espacios
        command.erase(0, command.find_first_not_of(" \t\v\r"));
        if (!command.empty()) {
            command.erase(command.find_last_not_of(" \t\v\r") + 1);
            
            if (command == "ADD" || command == "add") {
                addContact();
                std::cin.clear();
            } else if (command == "SEARCH" || command == "search") {
                searchContact();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin.clear();
            } else if (command == "EXIT" || command == "exit") {
                break;
            } else {
                std::cout << RED"invalid command"RESET << std::endl;
            }
        }
    }
}