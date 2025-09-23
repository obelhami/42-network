#include "Intern.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    Intern someRandomIntern;

    AForm* form1 = someRandomIntern.makeForm("robotomy request", "Bender");
    AForm* form2 = someRandomIntern.makeForm("shrubbery creation", "Home");
    AForm* form3 = someRandomIntern.makeForm("presidential pardon", "Zaphod");
    AForm* form4 = someRandomIntern.makeForm("invalid form", "Nobody");

    std::cout << "\n--- Form Creation Summary ---" << std::endl;
    if (form1) std::cout << *form1 << std::endl;
    if (form2) std::cout << *form2 << std::endl;
    if (form3) std::cout << *form3 << std::endl;

    // Clean up
    delete form1;
    delete form2;
    delete form3;
    delete form4;  // will be nullptr if form4 creation failed

    return 0;
}
