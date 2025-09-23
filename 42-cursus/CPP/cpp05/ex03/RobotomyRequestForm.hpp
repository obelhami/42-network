#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
    private:
        const std::string target;
    public:
        RobotomyRequestForm(std::string _target);
        ~RobotomyRequestForm();
        void execute(Bureaucrat const & executor) const;
        RobotomyRequestForm(const RobotomyRequestForm &object);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &object);
        std::string getTarget() const;
};