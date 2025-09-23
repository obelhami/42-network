#include "ShrubberyCreationForm.hpp"

#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string _target) : AForm("ShrubberyCreationForm", 145, 137), target(_target)
{
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (!getIsSigned())
        throw std::runtime_error("Form is not signed!");
    if (executor.getGrade() > getGradeToExecution())
        throw AForm::GradeTooLowException();
    const std::string filename = target + "_shrubbery";
    std::ofstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("Failed to open file for writing.");

    file << "  ^ \n";
    file << " ^^^\n";
    file << "^^^^^\n";
    file << "  | \n";
    file << "  | \n";
    file << "  | \n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &object) : AForm(object), target(object.target)
{
}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &object)
{
    if (this != &object)
    {
        AForm::operator=(object);
    }
    return *this;
}

std::string ShrubberyCreationForm::getTarget() const
{
    return target;
}