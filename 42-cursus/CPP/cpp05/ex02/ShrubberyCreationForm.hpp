#pragma once 


#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
    private:
        const std::string target;
    public:
        ShrubberyCreationForm(std::string _target);
        ~ShrubberyCreationForm();
        void execute(Bureaucrat const & executor) const;
        ShrubberyCreationForm(const ShrubberyCreationForm &object);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &object);
        std::string getTarget() const;
        
};