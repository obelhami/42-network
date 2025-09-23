#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string _target) : AForm("PresidentialPardonForm", 25, 5), target(_target)
{
}
PresidentialPardonForm::~PresidentialPardonForm()
{
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (!getIsSigned())
        throw std::runtime_error("Form is not signed!");
    if (executor.getGrade() > getGradeToExecution())
        throw AForm::GradeTooLowException();

    std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &object) : AForm(object), target(object.target)
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &object)
{
    if (this != &object)
    {
        AForm::operator=(object);
    }
    return *this;
}
std::string PresidentialPardonForm::getTarget() const
{
    return target;
}
std::ostream& operator<<(std::ostream& out, const PresidentialPardonForm& form)
{
    out << "PresidentialPardonForm: " << form.getName() << ", Target: " << form.getTarget() << ", Is Signed: " << (form.getIsSigned() ? "Yes" : "No");
    return out;
}
