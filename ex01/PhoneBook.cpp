#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : index(0), count(0) {

}

PhoneBook::~PhoneBook() {
}

void PhoneBook::displayContact(int index) {
    this->contacts[index].printContact();
}

void PhoneBook::displayContactInfo() {
    for (int i = 0; i < count; i++) {
        this->contacts[i].printContact();
    }
}

void PhoneBook::addContact() {
    Contact contact;

    contact = contact.createContact();
    if (count < 8) {
        std::cout << "Adding contact at index " << count << std::endl;
        // Add contact logic here
        contacts[count] = contact;  
        count++;
    } else {
        contacts[count - 1] = contact;
        std::cout << "PhoneBook is full" << std::endl;
        std::cout << "Overwriting contact at index " << count - 1 << std::endl;
    }
}

void PhoneBook::searchContact() {

    std::cout << "Searching contact" << std::endl;
    std::cout << "Enter index to search (0-7): ";
    std::cin >> index;
    std::cin.ignore(); // Clear the newline character from the input buffer
    if (index < 0 || index >= count) {
        std::cout << "Invalid index" << std::endl;
        return;
    }
    displayContact(index);
}

void PhoneBook::run() {
    std::string command;
    while (true) {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);
        command.erase(0, command.find_first_not_of(" \t")); // Quita espacios al inicio
        command.erase(command.find_last_not_of(" \t") + 1);
        if (command == "ADD" || command == "add") {
            addContact();
        } else if (command == "SEARCH" || command == "search") {
            searchContact();
        } else if (command == "EXIT" || command == "exit") {
            break;
        } else {
            std::cout << "Invalid command" << std::endl;
        }
    }
}