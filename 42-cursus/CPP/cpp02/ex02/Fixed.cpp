#include "Fixed.hpp"

const int Fixed::fractional = 8;

Fixed::Fixed():fixed_point(0)
{
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
    // std::cout << "copy constructor called" << std::endl;
    *this = copy;
}

Fixed &Fixed::operator=(const Fixed &src)
{
    // std::cout << "copy assignment operator called" << std::endl;
    if (this != &src)
        this->fixed_point = src.fixed_point;
    return *this;
}

Fixed::Fixed(const int value_int)
{
    // std::cout << "Int constructor called" << std::endl;
    this->fixed_point = value_int << 8;
}

Fixed::Fixed(const float value_float)
{
    // std::cout << "Float constructor called" << std::endl;
    this->fixed_point = roundf(value_float * (1 << this->fractional));
}

Fixed::~Fixed()
{
    // std::cout << "destructot called" << std::endl;
}

int     Fixed::getRawBits(void)const 
{
    // std::cout << "getRawBits member function called" << std::endl;
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

Fixed   Fixed::operator+(const Fixed &src)
{
    return Fixed(this->toFloat() + src.toFloat());
}

Fixed   Fixed::operator-(const Fixed &src)
{
    return Fixed(this->toFloat() - src.toFloat());
}

Fixed   Fixed::operator*(const Fixed &src)
{
    return Fixed(this->toFloat() * src.toFloat());
}

Fixed   Fixed::operator/(const Fixed &src)
{
    return Fixed(this->toFloat() / src.toFloat());
}

Fixed   &Fixed::operator++()
{
    ++fixed_point;
    return *this;
}

Fixed   Fixed::operator++(int)
{
    Fixed tmp = *this;
    fixed_point++;
    return tmp;
}

Fixed   &Fixed::operator--()
{
    --fixed_point;
    return *this;
}

Fixed   Fixed::operator--(int)
{
    Fixed tmp = *this;
    fixed_point--;
    return tmp;
}


bool Fixed::operator>(const Fixed& object){return fixed_point > object.fixed_point;}
bool Fixed::operator<(const Fixed& object){return fixed_point < object.fixed_point;}
bool Fixed::operator>=(const Fixed& object){return fixed_point >= object.fixed_point;}
bool Fixed::operator<=(const Fixed& object){return fixed_point <= object.fixed_point;}
bool Fixed::operator==(const Fixed& object){return fixed_point == object.fixed_point;}
bool Fixed::operator!=(const Fixed& object){return fixed_point != object.fixed_point;}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return (a.toFloat() < b.toFloat()) ? a : b;
}
const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    return (a.toFloat() < b.toFloat()) ? a : b;

}
Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    return (a.toFloat() > b.toFloat()) ? a : b;

}
const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    return (a.toFloat() > b.toFloat()) ? a : b;

}






