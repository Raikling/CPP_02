#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int _value;
        static const int _fractional_bits = 8;

    public:
        Fixed(void);
        Fixed(Fixed const& other);
        Fixed& operator=(Fixed const& rhs);
        Fixed(int const int_val);               //Parametric constructor (int)(converts the parameter to its fixed-point value)
        Fixed(float const float_val);            //Parametric constructor (float)(converts the parameter to its fixed-point value)
        ~Fixed(void);

        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat(void) const;
        int toInt(void) const;
};

std::ostream& operator<<(std::ostream& o, Fixed const& rhs);

#endif