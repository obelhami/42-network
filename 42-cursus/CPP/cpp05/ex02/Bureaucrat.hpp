#pragma once

#include <iostream>
#include <string>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
    public:
        Bureaucrat(std::string _name, int _grade);
        Bureaucrat(const Bureaucrat &obj);
        Bureaucrat &operator=(const Bureaucrat &obj);
        ~Bureaucrat();
        class   GradeTooHighException : public std::exception 
        {
            public :
                const char *what() const throw();
        };
        class   GradeTooLowException : public std::exception 
        {
            public :
                const char *what() const throw();
        };
        std::string getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();
        void    signForm( AForm &form);
        void    executeForm(AForm const & form);
        friend std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);
};