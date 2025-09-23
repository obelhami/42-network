#include "Fixed.hpp"

const int Fixed::fractional = 8;

Fixed::Fixed():fixed_point(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
    std::cout << "copy constructor called" << std::endl;
    *this = copy;
}

Fixed &Fixed::operator=(const Fixed &src)
{
    std::cout << "copy assignment operator called" << std::endl;
    if (this != &src)
        this->fixed_point = src.fixed_point;
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "destructot called" << std::endl;
}

int     Fixed::getRawBits(void)const 
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->fixed_point;
}

void    Fixed::setRawBits(int const raw)
{
    this->fixed_point = raw;
}



