#include "Fixed.hpp"
// Default constructor
Fixed::Fixed()
{
	//   std::cout << "Default constructor called" << std::endl;
	_rawBitsValue = 0;
}
// Constructor from a constant integer
Fixed::Fixed(const int value)
{
	//   std::cout << "Int constructor called" << std::endl;
	_rawBitsValue = value << _fractionalBits;
}
// Constructor from a constant float
// Note 1
Fixed::Fixed(const float value)
{
	//   std::cout << "Float constructor called" << std::endl;
	_rawBitsValue = roundf(value * (1 << _fractionalBits));
}
// Copy constructor
Fixed::Fixed(const Fixed &other)
{
	//   std::cout << "Copy constructor called" << std::endl;
	_rawBitsValue = other.getRawBits();
}
// Copy assignment operator
Fixed &Fixed::operator=(const Fixed &other)
{
	//   std::cout << "Copy assignment operator called" << std::endl;
	// Check for self assignment
	if (this != &other)
	{
		_rawBitsValue = other.getRawBits();
	}
	return *this;
}
// Overloading comparison operator >
bool Fixed::operator>(const Fixed &other) const
{
	return _rawBitsValue > other.getRawBits();
}
// Overloading comparison operator <
bool Fixed::operator<(const Fixed &other) const
{
	return _rawBitsValue < other.getRawBits();
}
// Overloading comparion opearator >=
bool Fixed::operator>=(const Fixed &other) const
{
	return _rawBitsValue >= other.getRawBits();
}
// Overlaoding comparions operator <=
bool Fixed::operator<=(const Fixed &other) const
{
	return _rawBitsValue <= other.getRawBits();
}
// Overloading comparison operator ==
bool Fixed::operator==(const Fixed &other) const
{
	return _rawBitsValue == other.getRawBits();
}
// Overloading comparison operator !=
bool Fixed::operator!=(const Fixed &other) const
{
	return _rawBitsValue != other.getRawBits();
}
// Overloading arithmetic operator +
Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed result;
	result.setRawBits(_rawBitsValue + other.getRawBits());
	return result;
}
// Overloading arithmetic operator -
Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed result;
	result.setRawBits(_rawBitsValue - other.getRawBits());
	return result;
}
// Overloading arithmetic operator *
Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed fixedResult;
	long long int thisRawLong = static_cast<long long int>(_rawBitsValue);
	long long int otherRawLong = static_cast<long long int>(other.getRawBits());
	long long int multipliedValue = (thisRawLong * otherRawLong);
	long long int scaledResult = multipliedValue >> _fractionalBits;
	int result = static_cast<int>(scaledResult);
	fixedResult.setRawBits(result);
	return fixedResult;
}
// Overloading arithmetic operator /
Fixed Fixed::operator/(const Fixed &other) const
{
	// Check for division by zero
	if (other.getRawBits() == 0)
	{
		// Handle division by zero error or throw an exception
		std::cerr << "Error: Division by zero." << std::endl;
		return Fixed(); // or handle differently
	}
	Fixed fixedResult;
	// Scale up the dividend by the number of fractional bits
	long long int thisRawLong = static_cast<long long int>(_rawBitsValue) << _fractionalBits;
	// Convert divisor to long long
	long long int otherRawLong = static_cast<long long int>(other.getRawBits());
	// Perform the division
	long long int dividedValue = thisRawLong / otherRawLong;
	int result = static_cast<int>(dividedValue);
	fixedResult.setRawBits(result);
	return fixedResult;
}
// Overloading pre-increment operator
Fixed &Fixed::operator++()
{
	this->_rawBitsValue += 1;
	return *this;
}
// Overloading post-increment operator
Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	this->_rawBitsValue += 1;
	return temp;
}
// Overloading pre-decrement operator
Fixed &Fixed::operator--()
{
	this->_rawBitsValue -= 1;
	return *this;
}
// Overloading post-decrement operator
Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	this->_rawBitsValue -= 1;
	return temp;
}
// reference to the min of two fixed point values
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
	{
		return a;
	}
	else
	{
		return b;
	}
}
// reference to the min of two fixed point values const
const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
	{
		return a;
	}
	else
	{
		return b;
	}
}
// reference to the max of two fixec point values
Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
	{
		return a;
	}
	else
	{
		return b;
	}
}
// reference to the max of two fixed point values const
const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
	{
		return a;
	}
	else
	{
		return b;
	}
}
// Destructor
Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}
// return the raw value of the fixed point value.
int Fixed::getRawBits(void) const
{
	//   std::cout << "getRawBits member function called" << std::endl;
	return _rawBitsValue;
}

// set the raw value of the fixed point value.
void Fixed::setRawBits(int const raw)
{
	_rawBitsValue = raw;
}

// convert the fixed point value to a floating point value.
// float Fixed::toFloat(void) const {
//   return (float)_rawBitsValue / (1 << _fractionalBits);
// }

// second implementation
// float Fixed::toFloat(void) const {
//   return static_cast<float>(_rawBitsValue) / (1 << _fractionalBits);
// }

// third implementation
float Fixed::toFloat(void) const
{
	// Cast the fixed point value to a float
	float floatValue = static_cast<float>(_rawBitsValue);
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
	return _rawBitsValue >> _fractionalBits;
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
