#pragma once

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string name;
        bool    isSigned;
        const int GradeToSign;
        const int GradeToexecution;
    public:
        AForm(std::string _name, int grade_to_sign, int grade_to_execute);
        AForm(const AForm &object);
        AForm &operator=(const AForm &object);
        virtual ~AForm();
        std::string getName() const;
        class GradeTooHighException: public std::exception
        {
            public:
                const char * what() const throw();
        };
        class GradeTooLowException: public std::exception
        {
            public:
                const char * what() const throw();
        };
        bool    getIsSigned() const;
        int     getGradeToSign() const;
        int     getGradeToExecution() const;
        void    BeSigned(const Bureaucrat &object);
        virtual void execute(Bureaucrat const & executor) const = 0;
        friend  std::ostream& operator<<(std::ostream &out, const AForm &object);
};      