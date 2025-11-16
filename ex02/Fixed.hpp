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
        
        static Fixed& min(Fixed& lhs, Fixed& rhs);
        static Fixed const& min(Fixed const& lhs, Fixed const& rhs);
        static Fixed& max(Fixed& lhs, Fixed&rhs);
        static Fixed const& max(Fixed const& lhs, Fixed const& rhs);
        
        bool operator>(Fixed const& rhs);
        bool operator<(Fixed const& rhs);
        bool operator>=(Fixed const& rhs);
        bool operator<=(Fixed const& rhs);
        bool operator==(Fixed const& rhs);
        bool operator!=(Fixed const& rhs);

        Fixed operator+(Fixed const& rhs) const;
        Fixed operator-(Fixed const& rhs) const;
        Fixed operator*(Fixed const& rhs) const;
        Fixed operator/(Fixed const& rhs) const;

        Fixed& operator++(); //understand the difference between pre/post 'the int param'
        Fixed operator++(int);
        Fixed& operator--();
        Fixed operator--(int);
        
        ~Fixed(void);

        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat(void) const;
        int toInt(void) const;
};

std::ostream& operator<<(std::ostream& o, Fixed const& rhs);

#endif