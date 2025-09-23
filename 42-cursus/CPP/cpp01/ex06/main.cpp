#include "Harl.hpp"

int main(int argc, char **argv)
{
    Harl Harl;

    if (argc != 2)
    {
        std::cout << "you program must be one argument" << std::endl;
        return 0;
    }
    Harl.complain(argv[1]);
    return 0;
}