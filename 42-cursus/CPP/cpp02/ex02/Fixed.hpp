#pragma once

#include <iostream>
#include <cmath>

class   Fixed{
    private:
        int fixed_point;
        static const int fractional;
    public:
        Fixed();
        Fixed(const int value_int);
        Fixed(const float value_float);
        Fixed(const Fixed& copy);
        ~Fixed();
        Fixed   &operator=(const Fixed &src);
        Fixed   operator+(const Fixed &src);
        Fixed   operator-(const Fixed &src);
        Fixed   operator*(const Fixed &src);
        Fixed   operator/(const Fixed &src);
        Fixed   &operator++();
        Fixed   operator++(int);
        Fixed   &operator--();
        Fixed   operator--(int);
        void setRawBits( int const raw );
        float   toFloat(void) const;
        int     toInt(void) const;
        int getRawBits( void ) const;
        bool operator>(const Fixed& object);
        bool operator<(const Fixed& object);
        bool operator>=(const Fixed& object);
        bool operator<=(const Fixed& object);
        bool operator==(const Fixed& object);
        bool operator!=(const Fixed& object);
        static Fixed& min(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);

};