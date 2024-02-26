#include "Fixed.hpp"

// Default constructor
Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	_fixedValue = 0;
}

// Constructor from a constant integer
Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	_fixedValue = value << _fractionalBits;
}
// Constructor from a constant float
Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;

	_fixedValue = roundf(value * (1 << _fractionalBits));
}

// Copy constructor
Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	_fixedValue = other.getRawBits();
}

// Copy assignment operator
Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		_fixedValue = other.getRawBits();
	}
	return *this;
}

// Destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// Get the raw value of the fixed point value
int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _fixedValue;
}

// Set the raw value of the fixed point value
void Fixed::setRawBits(int const raw)
{
	_fixedValue = raw;
}

// Convert the fixed point value to a floating point value
float Fixed::toFloat(void) const
{
	float floatValue = _fixedValue;
	float conversionFactor = 1 << _fractionalBits;
	float result = floatValue / conversionFactor;

	return result;
}

// Convert the fixed point value to an integer value
int Fixed::toInt(void) const
{
	return _fixedValue >> _fractionalBits;
}

// Overload the << operator: not the bitwise shift operator but the stream insertion operator
std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return os;
}
