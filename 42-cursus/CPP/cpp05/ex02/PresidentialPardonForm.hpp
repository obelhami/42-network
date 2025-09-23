#pragma once 

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
    private:
        const std::string target;
    public:
        PresidentialPardonForm(std::string _target);
        ~PresidentialPardonForm();
        void execute(Bureaucrat const & executor) const;
        PresidentialPardonForm(const PresidentialPardonForm &object);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &object);
        std::string getTarget() const;
};