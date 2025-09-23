#include "Bureaucrat.hpp"


int main()
{
    try
    {
        Bureaucrat b1("Alice", 10);
        Bureaucrat b2("Bob", 100);

        Form f1("TopSecret", 20, 50);
        Form f2("SimpleForm", 120, 130);

        std::cout << b1 << std::endl;
        std::cout << b2 << std::endl;
        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;

        std::cout << "----- Signing Tests -----" << std::endl;

        b1.signForm(f1);  // Should succeed
        b2.signForm(f1);  // Should fail
        b2.signForm(f2);  // Should succeed
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
