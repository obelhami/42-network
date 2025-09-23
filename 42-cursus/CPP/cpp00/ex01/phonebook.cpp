#include "PhoneBook.hpp"

PhoneBook::PhoneBook():index(0){}

void    PhoneBook::AddNewContact(Contact contact)
{
    // static int index;
    std::cout << index << std::endl;
    if (index % 8 == 0)
        index = 0;
    contacts[index] = contact;
    index++;
}

void    PhoneBook::SearchContact()
{
    int i = 0;
    std :: cout << index << std::endl;
    while (i < 8 && !contacts[i].GetFirstName().empty())
    {
        if (contacts[i].GetFirstName().size() > 10)
            std::cout << contacts[i].GetFirstName().substr(0,9) << '.' << " | ";
        else
            std::cout << contacts[i].GetFirstName() << " | ";
        if (contacts[i].GetLastName().size() > 10)
            std::cout << contacts[i].GetLastName().substr(0,9) << '.' << " | ";
        else
            std::cout << contacts[i].GetLastName() << " | ";
        if (contacts[i].GetNickName().size() > 10)
            std::cout << contacts[i].GetNickName().substr(0,9) << '.' << std::endl;
        else
            std::cout << contacts[i].GetNickName() << std::endl;
        // std::cout << i + 1 << " | " << contacts[i].GetFirstName().substr(0,9) << " | " << contacts[i].GetLastName().substr(0,9) << " | " <<
        // contacts[i].GetNickName().substr(0,9) << std::endl;
        i++;
    }
    std::cout << "here\n";
}
PhoneBook::~PhoneBook()
{
}