#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <string>
// Your code here
#define RED "\033[31m" 
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define GREY "\033[30m"
#define RESET "\033[0m"

class Contact
{
    private:
        std::string firstName;
        std::string lastName;
        std::string nickname;
        std::string phoneNumber;
        std::string darkestSecret;
        void setFirstName(std::string name) { firstName = name; }
        void setNickname(std::string name) { nickname = name; }
        void setPhoneNumber(std::string number) { phoneNumber = number; }
        void setLastName(std::string name) { lastName = name; }
        void setDarkestSecret(std::string secret) { darkestSecret = secret; }
        std::string getInput(const std::string& prompt, bool hasLengthLimit = false, size_t maxLength = 25);
    public:
        void printInfo(int index, int width = 10);
        void printContact(int index);
        bool isAnyFieldEmpty(void) {
            return firstName.empty() || lastName.empty() || nickname.empty() || phoneNumber.empty() || darkestSecret.empty();
        }
        Contact createContact(void);
        Contact(/* args */);
        ~Contact();
};

void printFields(int width);

#endif // CONTACT_HPP