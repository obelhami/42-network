#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string _name, int grade_to_sign, int grade_to_execute) : name(_name),  isSigned(false), GradeToSign(grade_to_sign), GradeToexecution(grade_to_execute) 
{
    if (GradeToexecution < 1 || GradeToSign < 1)
        throw GradeTooHighException();
    else if (GradeToexecution >150 || GradeToSign > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &object) : GradeToSign(0) ,GradeToexecution(0)
{
    *this = object;
}

Form &Form::operator=(const Form &object)
{
    if (this != &object)
    {
        this->isSigned = object.isSigned;
    }
    return *this;
}

Form::~Form()
{
}

std::string Form::getName() const 
{
    return name;
}

bool    Form::getIsSigned()
{
    return isSigned;
}

int     Form::getGradeToSign() const
{
    return GradeToSign;
}

int     Form::getGradeToExecution() const
{
    return GradeToexecution;
}

void    Form::BeSigned(const Bureaucrat &object)
{
    if (object.getGrade() <= GradeToSign)
        isSigned = true;
    else
        throw GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Grade too high!";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Grade too Low!";
}

std::ostream& operator<<(std::ostream &out, const Form &form)
{
    out << "All the forms information:\n";
    out << "Name: " << form.name << "\n";
    out << "Signed: " << form.isSigned << "\n";
    out << "Grade required to sign: " << form.GradeToSign << "\n";
    out << "Grade required to execute: " << form.GradeToexecution << "\n";
    return out;
}