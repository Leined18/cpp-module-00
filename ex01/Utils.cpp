#include "PhoneBook.hpp"

void printFields(int width)
{
    std::cout << std::setw(width) << std::right << "Index"      << "|"
              << std::setw(width) << std::right << "First Name" << "|"
              << std::setw(width) << std::right << "Last Name"  << "|"
              << std::setw(width) << std::right << "Nickname"   << "|"
              << std::endl;

    std::cout << std::setfill('-') << std::setw(width * 4 + 4)
              << "" 
              << std::setfill(' ') 
              << std::endl;
}
// Print the fields with a width of 10 characters