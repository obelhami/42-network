#pragma once

#include <iostream>
#include <cctype>
#include <string>
#include "Contact.hpp"

class PhoneBook{
    private:
        int index;
        Contact contacts[8];

    public:
        PhoneBook();
        void    AddNewContact(Contact contact);
        void    SearchContact();
        ~PhoneBook();
};
