#include "Fixed.hpp"
Fixed::Fixed()
{
	_rawBitsValue = 0;
}
Fixed::Fixed(const int value)
{
	_rawBitsValue = value << _fractionalBits;
}
Fixed::Fixed(const float value)
{
	_rawBitsValue = roundf(value * (1 << _fractionalBits));
}
Fixed::Fixed(const Fixed &other)
{
	_rawBitsValue = other.getRawBits();
}
Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
	{
		_rawBitsValue = other.getRawBits();
	}
	return *this;
}

Fixed::~Fixed()
{
}
int Fixed::getRawBits(void) const
{
	return _rawBitsValue;
}

void Fixed::setRawBits(int const raw)
{
	_rawBitsValue = raw;
}

// Convert the fixed point value to a floating point value
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

// Convert the fixed point value to an integer value by shifting the bits to the right
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

/* HIER STARTS THE NEW PART*/
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

/* NEW APPROACH */
// The old approach is in the README.md
// Overloading arithmetic operator +
Fixed Fixed::operator+(const Fixed &other) const
{
	return Fixed(this->toFloat() + other.toFloat());
}

// Overloading arithmetic operator -
Fixed Fixed::operator-(const Fixed &other) const
{
	return Fixed(this->toFloat() - other.toFloat());
}

// Overloading arithmetic operator *
Fixed Fixed::operator*(const Fixed &other) const
{
	return Fixed(this->toFloat() * other.toFloat());
}

// Overloading arithmetic operator /
Fixed Fixed::operator/(const Fixed &other) const
{
	// Check for division by zero
	if (other.getRawBits() == 0)
	{
		// Handle division by zero error or throw an exception
		std::cerr << "Error: Division by zero." << std::endl;
		return Fixed();
	}
	return Fixed(this->toFloat() / other.toFloat());
}

// Overloading pre-increment operator
Fixed &Fixed::operator++()
{
	this->_rawBitsValue += 1;
	return *this;
}

// Overloading post-increment operator (with dummy int parameter)
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
// Postfix have the dummy int parameter (with dummy int parameter)
Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	this->_rawBitsValue -= 1;
	return temp;
}

// Reference to the min of two fixed point values
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return a;
	else
		return b;
}

// Reference to the min of two fixed point values const
const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return a;
	else
		return b;
}

// Reference to the max of two fixec point values
Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	else
		return b;
}

// Reference to the max of two fixed point values const
const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	else
		return b;
}
