#include "Contact.hpp"

Contact::Contact()
{
    this->firstName = "";
    this->lastName = "";
    this->nickname = "";
    this->phoneNumber = "";
}

Contact::~Contact()
{
    // Destructor
}

std::string Contact::getInput(const std::string& prompt, bool hasLengthLimit, size_t maxLength) {
    std::string input;
    while (true) {
        std::cout << GREY << prompt << RESET;
        std::getline(std::cin, input);
        if (input.empty()) {
            if (std::cin.eof()) {
                std::cout << YELLOW << "EOF" << RESET << std::endl;
                std::cout << "Exiting program" << std::endl;
                std::exit(0);
            }
            std::cout << RED << "Field cannot be empty" << RESET << std::endl;
            continue;
        }
        if (hasLengthLimit && input.length() > maxLength) {
            input.resize(maxLength);
            input.replace(maxLength - 1, 1, ".");
            std::cout << YELLOW    <<"Warning: Input truncated to "
                      << maxLength << " characters" << RESET
                      << std::endl;
        }
        return input;
    }
}

Contact Contact::createContact(void) {
    Contact contact;
    std::string input;
    
    while (true) {
        try {
            contact.setFirstName(getInput("Enter first name: ", true, 10));
            contact.setLastName(getInput("Enter last name: ", true, 10));
            contact.setNickname(getInput("Enter nickname: ", true, 10));
            contact.setPhoneNumber(getInput("Enter phone number: ", false));
            contact.setDarkestSecret(getInput("Enter darkest secret: ", false));
            break;
        } catch (const std::exception& e) {
            std::cout << "\033[31mError: " << e.what() << "\033[0m" << std::endl;
            std::cout << "Intentando nuevamente..." << std::endl;
        }
    }
    return contact;
}

void Contact::printInfo(int index, int width)
{
    std::cout << std::setw(width) << std::right << index << "|"
              << std::setw(width) << std::right << this->firstName << "|"
              << std::setw(width) << std::right << this->lastName << "|"
              << std::setw(width) << std::right << this->nickname << "|" << std::endl;
}

void Contact::printContact(int index)
{
    printFields(10);
    printInfo(index, 10);
}