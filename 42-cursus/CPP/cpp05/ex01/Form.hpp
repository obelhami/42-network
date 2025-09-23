#pragma once

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string name;
        bool    isSigned;
        const int GradeToSign;
        const int GradeToexecution;
    public:
        Form(std::string _name, int grade_to_sign, int grade_to_execute);
        Form(const Form &object);
        Form &operator=(const Form &object);
        ~Form();
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
        bool    getIsSigned();
        int     getGradeToSign() const;
        int     getGradeToExecution() const;
        void    BeSigned(const Bureaucrat &object);
        friend  std::ostream& operator<<(std::ostream &out, const Form &object);
};      