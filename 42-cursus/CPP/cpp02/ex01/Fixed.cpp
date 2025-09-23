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

Fixed::Fixed(const int value_int)
{
    std::cout << "Int constructor called" << std::endl;
    this->fixed_point = value_int << 8;
}

Fixed::Fixed(const float value_float)
{
    std::cout << "Float constructor called" << std::endl;
    this->fixed_point = roundf(value_float * (1 << this->fractional));
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

float   Fixed::toFloat(void)const
{
    return ((float)fixed_point / (1 << this->fractional));
}

int   Fixed::toInt(void)const
{
    return (fixed_point >> this->fractional);
}

void    Fixed::setRawBits(int const raw)
{
    this->fixed_point = raw;
}







