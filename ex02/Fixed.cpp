#include "Fixed.hpp"

Fixed::Fixed(void): _value(0)
{
    std::cout << "Default constructor called" << std::endl;
    return;
}

Fixed::Fixed(Fixed const& other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;

    return ;
}

Fixed& Fixed::operator=(Fixed const& rhs)
{
    std::cout << "Copy assignment operator called" <<std::endl;
    if (this != &rhs)
        this->_value = rhs.getRawBits();

    return *this;
}

Fixed::Fixed(int const int_val)
{
    std::cout << "Int constructor called" << std::endl;
    this->_value  = int_val << _fractional_bits;
}

Fixed::Fixed(float const float_val)
{
    std::cout << "Float constructor called" << std::endl;
    _value  = roundf(float_val * 256.0f); 
}

int Fixed::getRawBits(void) const
{
    return this->_value;
}

void Fixed::setRawBits(int const raw)
{
    this->_value = raw;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
    return;
}


float Fixed::toFloat(void) const
{
    return (float)this->_value / 256.0f;
}

int Fixed::toInt(void) const
{
    return this->_value >> _fractional_bits;
}

std::ostream& operator<<(std::ostream& o, Fixed const& rhs)
{
    o << rhs.toFloat();
    return o;
}

Fixed& Fixed::min(Fixed& lhs, Fixed& rhs)
{
    if (lhs.getRawBits() < rhs.getRawBits())
        return lhs;
    return rhs;
}

Fixed const& Fixed::min(Fixed const& lhs, Fixed const& rhs)
{
    if (lhs.getRawBits() < rhs.getRawBits())
        return lhs;
    return rhs;
}

Fixed& Fixed::max(Fixed& lhs, Fixed& rhs)
{
    if (lhs.getRawBits() > rhs.getRawBits())
        return lhs;
    return rhs;
}

Fixed const& Fixed::max(Fixed const& lhs, Fixed const& rhs)
{
    if (lhs.getRawBits() > rhs.getRawBits())
        return lhs;
    return rhs;
}

bool Fixed::operator>(Fixed const& rhs)
{
    if (this->_value > rhs.getRawBits())
        return true;
    return false;
}

bool Fixed::operator<(Fixed const& rhs)
{
    if (this->_value < rhs.getRawBits())
        return true;
    return false;
}

bool Fixed::operator>=(Fixed const& rhs)
{
    if (this->_value >= rhs.getRawBits())
        return true;
    return false;
}

bool Fixed::operator<=(Fixed const& rhs)
{
    if (this->_value <= rhs.getRawBits())
        return true;
    return false;
}

bool Fixed::operator==(Fixed const& rhs)
{
    if (this->_value == rhs.getRawBits())
        return true;
    return false;
}

bool Fixed::operator!=(Fixed const& rhs)
{
    if (this->_value != rhs.getRawBits())
        return true;
    return false;
}

Fixed Fixed::operator+(Fixed const& rhs) const
{
    Fixed ret;
    ret.setRawBits((this->_value + rhs.getRawBits()) >> _fractional_bits);
    return ret;
}

Fixed Fixed::operator-(Fixed const& rhs) const
{
    Fixed ret;
    ret.setRawBits((this->_value - rhs.getRawBits()) >> _fractional_bits);
    return ret;
}

Fixed Fixed::operator*(Fixed const& rhs) const
{
    Fixed ret;
    ret.setRawBits((this->_value * rhs.getRawBits()) >> _fractional_bits);
    return ret;
}

Fixed Fixed::operator/(Fixed const& rhs) const
{
    if (rhs.getRawBits() == 0)
    {
        std::cout << "Error: Division by 0" << std::endl;
        return Fixed();
    }
    Fixed ret;
    ret.setRawBits((this->_value / rhs.getRawBits()) >> _fractional_bits);
    return ret;
}


//read more about the differnce of the pre/post increment, when do we add int in the param
Fixed& Fixed::operator++() 
{
    this->_value++;
    return *this;
}
Fixed& Fixed::operator--()
{
    this->_value--;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed ret(*this);
    _value++;
    return ret;
}

Fixed Fixed::operator--(int)
{
    Fixed ret(*this);
    _value--;
    return ret;
}

