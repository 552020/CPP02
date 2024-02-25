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
// Note 1
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
	// Check for self assignment
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

// return the raw value of the fixed point value.
int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _fixedValue;
}

// set the raw value of the fixed point value.
void Fixed::setRawBits(int const raw)
{
	_fixedValue = raw;
}

// convert the fixed point value to a floating point value.
// float Fixed::toFloat(void) const {
//   return (float)_fixedValue / (1 << _fractionalBits);
// }

// second implementation
// float Fixed::toFloat(void) const {
//   return static_cast<float>(_fixedValue) / (1 << _fractionalBits);
// }

// third implementation
float Fixed::toFloat(void) const
{
	// Cast the fixed point value to a float
	float floatValue = static_cast<float>(_fixedValue);
	// Define the conversion factor from fixed point to float
	float conversionFactor = 1 << _fractionalBits;
	// Scale the converted value by the conversion factor
	float result = floatValue / conversionFactor;

	return result;
}

// convert the fixed point value to an integer value.
// we just shift and we truncate the fractional part
int Fixed::toInt(void) const
{
	return _fixedValue >> _fractionalBits;
}

// Overload the << operator
std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return os;
}

/* Note 1

While conceptually, shifting a binary floating-point number to the left by the
number of fractional bits (e.g., 8 bits) would simulate converting it to a
fixed-point representation (scaling the value by 2^8), in actual C++ code,
floating-point numbers cannot be shifted due to their internal IEEE-754
representation. Instead, we multiply by the corresponding power of 2 to achieve
the same effect.

For instance, instead of shifting 1.5 (decimal) by 8 bits to the left, which is
not possible in code, we multiply 1.5 by 2^8 (256) to convert it to a
fixed-point representation where the fractional part is scaled up and stored as
an integer.*/
