#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>

// Your code goes here

class PhoneBook {
    public:
        PhoneBook();
        ~PhoneBook();
        void displayContact(int index);
        void displayContactInfo(void);
        void addContact();
        void searchContact();
        void run();
    private:
        Contact contacts[8];
        int index;
        int count;
};

#endif // PHONEBOOK_HPP