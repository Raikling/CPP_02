#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int _value;
        static const int _fractional_bits = 8;

    public:
        Fixed(void);
        Fixed(Fixed const& other);
        Fixed& operator=(Fixed const& rhs);
        ~Fixed(void);

        int getRawBits(void) const;         //returns the raw value of the fixed-point value
        void setRawBits(int const raw);     //sets the raw value of the fixed-point
};


#endif