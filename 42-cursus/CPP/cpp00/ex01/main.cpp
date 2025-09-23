#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <cctype>
#include <cstring>
#include <iostream>
#include <ostream>

int CheckIsPrint(std::string str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (std::isprint(str[i]) == 0)
            return 0;
        i++;
    }
    return 1;
}

void    AddContact(PhoneBook *NewContact)
{
    Contact contact;
    std::string Info;

    do{
        std::cout << "Please Enter The FirstName :";
        std::getline(std::cin >> std::ws, Info);
        if (std::cin.fail())
            exit (1);
        if (Info.size() == 0 || CheckIsPrint(Info) == 0)
            std::cout << "the FirstName is wrong" << std::endl;
    }while(Info.size()== 0 || CheckIsPrint(Info) == 0);
    contact.SetFirstName(Info);
    do{
        std::cout << "Please Enter The LastName :";
        std::getline(std::cin >> std::ws, Info);
        if (std::cin.fail())
            exit (1);
        if (Info.size() == 0 || CheckIsPrint(Info) == 0)
        std::cout << "the LastName is wrong" << std::endl;
    }while(Info.size()== 0 || CheckIsPrint(Info) == 0);
    contact.SetLastName(Info);
    do{
        std::cout << "Please Enter The NickName :";
        std::getline(std::cin >> std::ws, Info);
        if (std::cin.fail())
            exit (1);
        if (Info.size() == 0 || CheckIsPrint(Info) == 0)
        std::cout << "the NickName is wrong" << std::endl;
    }while(Info.size()== 0 || CheckIsPrint(Info) == 0);
    contact.SetNickName(Info);
    while (1)
    {
        bool check = false;
        std::cout << "Please Enter The PhoneNumber :";
        std::getline(std::cin >> std::ws, Info);
        if (std::cin.fail())
            exit (1);
        if (Info.size() > 9)
        {
            for (unsigned long i = 0;i < Info.size(); i++)
            {
                if (std::isdigit(Info[i]) == 0 || std::isprint(Info[i]) == 0)
                    break;
                if (i == Info.size() - 1)
                    check = true;
            }
        }
        if (check == true)
            break;
        else
            std::cout << "the PhoneNumber is wrong" << std::endl;
    }
    contact.SetPhoneNumber(Info);
    do{
        std::cout << "Please Enter The Darkest Secret :";
        std::getline(std::cin >> std::ws, Info);
        if (Info.size() == 0 || CheckIsPrint(Info) == 0)
            std::cout << "the DarkestSecret is wrong" << std::endl;
    }while(Info.size()== 0 || CheckIsPrint(Info) == 0);
    contact.SetDarkestSecret(Info);
    NewContact->AddNewContact(contact);
}

int main()
{
    std::string command;
    PhoneBook NewContact;
    while (1)
    {
        std::cout << "Welcome to the Phonebook!\n" << 
        "Please enter one of the following commands:\n" << 
        "1. ADD    - Add a new contact to the phonebook.\n" << 
        "2. SEARCH - Search for an existing contact.\n" <<
        "3. EXIT   - Exit the program.\n" << 
        "enter your command :";
        std::getline(std::cin >> std::ws , command);
        if (std::cin.fail())
            return 1;
        if (command == "EXIT")
            break;
        else if (command == "ADD")
        {
            AddContact(&NewContact);
        }
        else if (command == "SEARCH")
        {
            NewContact.SearchContact();
        }
        else
            std::cout << "Please enter the right one" << std::endl;
    }
}