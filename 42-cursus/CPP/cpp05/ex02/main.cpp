#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{

    // Create some Bureaucrats with various grades
    Bureaucrat highGradeBureaucrat("John", 1);  // Highest possible grade
    Bureaucrat lowGradeBureaucrat("Jane", 151); // Lowest possible grade
    Bureaucrat midGradeBureaucrat("Jim", 75);   // Middle grade

    // Create the forms
    ShrubberyCreationForm shrubberyForm("Garden");
    RobotomyRequestForm robotomyForm("Home");
    PresidentialPardonForm pardonForm("Target");

    // Try signing the forms
    try
    {
        highGradeBureaucrat.signForm(shrubberyForm); // Should succeed
        highGradeBureaucrat.signForm(robotomyForm);  // Should succeed
        highGradeBureaucrat.signForm(pardonForm);    // Should succeed

        lowGradeBureaucrat.signForm(shrubberyForm);  // Should fail (GradeTooLowException)
    }
    catch (const std::exception &e)
    {
        std::cout << "Error signing form: " << e.what() << std::endl;
    }

    // Try executing the forms
    try
    {
        highGradeBureaucrat.executeForm(shrubberyForm);   // Should succeed
        highGradeBureaucrat.executeForm(robotomyForm);    // Should succeed (random outcome)
        highGradeBureaucrat.executeForm(pardonForm);      // Should succeed

        lowGradeBureaucrat.executeForm(shrubberyForm);    // Should fail (GradeTooLowException)
    }
    catch (const std::exception &e)
    {
        std::cout << "Error executing form: " << e.what() << std::endl;
    }

    // Test form behaviors with the middle-grade bureaucrat (midGradeBureaucrat)
    try
    {
        midGradeBureaucrat.signForm(shrubberyForm);  // Should fail (GradeTooLowException)
        midGradeBureaucrat.executeForm(shrubberyForm); // Should fail (form is not signed)
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // RobotomyRequestForm random behavior
    try
    {
        highGradeBureaucrat.executeForm(robotomyForm);  // Should succeed, with a random outcome (robotomized or not)
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // Presidential Pardon form should always execute if signed and bureaucrat has a high enough grade
    try
    {
        highGradeBureaucrat.executeForm(pardonForm);   // Should succeed
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
