#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(std::string _name, int grade_to_sign, int grade_to_execute) : name(_name),  isSigned(false), GradeToSign(grade_to_sign), GradeToexecution(grade_to_execute) 
{
    if (GradeToexecution < 1 || GradeToSign < 1)
        throw GradeTooHighException();
    else if (GradeToexecution >150 || GradeToSign > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &object) : GradeToSign(0) ,GradeToexecution(0)
{
    *this = object;
}

AForm &AForm::operator=(const AForm &object)
{
    if (this != &object)
    {
        this->isSigned = object.isSigned;
    }
    return *this;
}

AForm::~AForm()
{
}

std::string AForm::getName() const 
{
    return name;
}

bool    AForm::getIsSigned() const
{
    return isSigned;
}

int     AForm::getGradeToSign() const
{
    return GradeToSign;
}

int     AForm::getGradeToExecution() const
{
    return GradeToexecution;
}

void    AForm::BeSigned(const Bureaucrat &object)
{
    if (object.getGrade() <= GradeToSign)
        isSigned = true;
    else
        throw GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "Grade too high!";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "Grade too Low!";
}

std::ostream& operator<<(std::ostream &out, const AForm &Aform)
{
    out << "All the form's information:\n";
    out << "Name: " << Aform.name << "\n";
    out << "Signed: " << Aform.isSigned << "\n";
    out << "Grade required to sign: " << Aform.GradeToSign << "\n";
    out << "Grade required to execute: " << Aform.GradeToexecution << "\n";
    return out;
}