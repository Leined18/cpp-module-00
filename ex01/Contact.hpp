#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
// Your code here

class Contact
{
    private:
        std::string firstName;
        std::string lastName;
        std::string nickname;
        std::string phoneNumber;
    public:
        void setFirstName(std::string name) { firstName = name; }
        void setNickname(std::string name) { nickname = name; }
        void setPhoneNumber(std::string number) { phoneNumber = number; }
        void setLastName(std::string name) { lastName = name; }
        Contact createContact(void);
        Contact(/* args */);
        ~Contact();
        void printContact(void);
};

#endif // CONTACT_HPP