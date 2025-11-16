#include "Fixed.hpp"

//Default Constructor
Fixed::Fixed(void):_value(0)
{
    std::cout << "Default constructor called" << std::endl;
    return;
}

//Copy Constructor
Fixed::Fixed(Fixed const& other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;

    return;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_value;
}


Fixed& Fixed::operator=(Fixed const& rhs)
{
    std::cout << "Copy assignment operator called" <<std::endl;
    if (this != &rhs)
        this->_value = rhs.getRawBits();

    return *this;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
    return;
}


void Fixed::setRawBits(int const raw)
{
    this->_value = raw;
}
