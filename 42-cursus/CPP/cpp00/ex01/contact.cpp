#include "Contact.hpp"


void    Contact::SetFirstName(std::string F_Name)
{
    FirstName = F_Name;
}

void    Contact::SetLastName(std::string L_Name)
{
    LastName = L_Name;
}

void    Contact::SetNickName(std::string N_Name)
{
    NickName = N_Name;
}

void    Contact::SetPhoneNumber(std::string P_Number)
{
    PhoneNumber = P_Number;
}

void    Contact::SetDarkestSecret(std::string D_Secret)
{
    DarkestSecret = D_Secret;
}

std::string Contact::GetFirstName()
{
    return FirstName;
}

std::string Contact::GetLastName()
{
    return LastName;
}

std::string Contact::GetNickName()
{
    return NickName;
}

std::string Contact::GetPhoneNumber()
{
    return PhoneNumber;
}

std::string Contact::GetDarkestSecret()
{
    return DarkestSecret;
}
