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
        float   toFloat(void) const;
        int     toInt(void) const;
        Fixed   &operator=(const Fixed &src);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
};