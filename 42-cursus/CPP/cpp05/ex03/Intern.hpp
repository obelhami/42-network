#pragma once 

#include "AForm.hpp"

class AForm;

class Intern
{
    public:
        Intern();
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);
        AForm *makeForm(const std::string Form_name, const std::string target) const;
        ~Intern(); 
};