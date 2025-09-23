#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


Intern::Intern() {
}

Intern::~Intern() {
}

Intern::Intern(const Intern& other) {
    *this = other;
}

AForm *Intern::makeForm(const std::string Form_name, const std::string target) const
{
    const std::string array[3] = {"robotomy request", "shrubbery creation", "presidential pardon"};
    
    for (int i = 0; i < 3; i++)
    {
        if (Form_name == array[i])
        {
            std::cout << "Intern creates " << Form_name << std::endl;
            switch (i)
            {
            case 0:
                return new RobotomyRequestForm(target);
            case 1:
                return new ShrubberyCreationForm(target);
            case 2:
                return new PresidentialPardonForm(target);
            }
        }
    }
        std::cerr << "Error: Unknown form name '" << Form_name << "'" << std::endl;
    return NULL;
}


Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}