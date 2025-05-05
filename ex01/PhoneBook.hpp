#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <limits>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define RESET "\033[0m"

// Your code goes here

class PhoneBook {
    public:
        PhoneBook();
        ~PhoneBook();
        void displayContact(int index);
        void displayAllContacts();
        void addContact();
        void searchContact();
        void run();
    private:
        Contact contacts[8];
        int index;
        int count;
};

void printFields(int width);

#endif // PHONEBOOK_HPP