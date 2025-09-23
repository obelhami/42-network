#pragma once

#include <iostream>

class   Fixed{
    private:
        int fixed_point;
        static const int fractional;
    public:
        Fixed();
        Fixed(const Fixed& copy);
        ~Fixed();
        Fixed   &operator=(const Fixed &src);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
};