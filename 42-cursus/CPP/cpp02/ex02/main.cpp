#include "Fixed.hpp"

std::ostream &operator<<(std::ostream &o,Fixed const &object)
{
    o << object.toFloat();
    return o;
}

int     main()
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    Fixed c (Fixed(10) + Fixed(5));
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << Fixed::max(a, b) << std::endl;
    std::cout << Fixed::max(a, c) << std::endl;
    std::cout << Fixed::max(c, b) << std::endl;
}