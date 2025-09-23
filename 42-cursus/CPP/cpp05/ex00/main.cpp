#include "Bureaucrat.hpp"



int main()
{
    try {
        Bureaucrat omar("omar", 2);
        std::cout << omar << std::endl;
        omar.incrementGrade();
        std::cout << omar << std::endl;
        omar.decrementGrade();
        std::cout << omar << std::endl;
        omar.incrementGrade();
        std::cout << omar << std::endl;
        omar.incrementGrade();
    } catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}