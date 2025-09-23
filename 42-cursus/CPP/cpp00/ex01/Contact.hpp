#pragma once

#include <iostream>
#include <cctype>
#include <string>
#include <stdlib.h>


class   Contact{
    private:
        std::string FirstName;
        std::string LastName;
        std::string NickName;
        std::string PhoneNumber;
        std::string DarkestSecret;

    public:
        void    SetFirstName(std::string F_Name);
        void    SetLastName(std::string L_Name);
        void    SetNickName(std::string N_Name);
        void    SetPhoneNumber(std::string P_Number);
        void    SetDarkestSecret(std::string D_Secret);
        std::string GetFirstName();
        std::string GetLastName();
        std::string GetNickName();
        std::string GetPhoneNumber();
        std::string GetDarkestSecret();
};


