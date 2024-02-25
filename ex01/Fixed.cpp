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
	// This works also for negative numbers due to the two's complement representation
	std::cout << "Int constructor called" << std::endl;
	if (value > MAX_INT_FOR_SHIFT || value < -MAX_INT_FOR_SHIFT)
	{
		std::cerr << "Warning: Conversion is not safe due to potential overflow." << std::endl;
		std::cerr << "We will perform the conversion anyway." << std::endl;
	}
	_fixedValue = value << _fractionalBits;
}
// Constructor from a constant float
// Note 1
Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	// We could explicitly convert the float to an int, but it is not necessary _fixedValue =
	// static_cast<int>(roundf(floatValue * (1 << FRAC_BITS))); since fractionalBits is a constant, we can use it
	// directly, so we can multiply by 2^fractionalBits which is 1 << fractionalBits or 1 << 8 or 256 roundf rounds to
	// the nearest integer value, rounding halfway cases away from zero, regardless of the current rounding Why is
	// rounding necessary? The fractional part of the float value is multiplied by 2^fractionalBits, so it is shifted to
	// the left by fractionalBits bits. The result is a float value with a fractional part that is a power of 2. The
	// fractional part of the float value is then truncated, and the result is stored as an integer. The rounding is
	// necessary to ensure that the fractional part of the float value is correctly represented in the fixed-point
	// value. Practical example: 0.1 * 256 = 25.6, which is rounded to 26. Otherwise we would have 25. 1 <<
	// _fractionalBits is the scaling factor. It is used to convert the float value to a fixed-point value. The scaling
	// factor is a power of 2, so it is a binary number with a single 1 bit followed by fractionalBits 0 bits. When the
	// float value is multiplied by the scaling factor, the fractional part is shifted to the left by fractionalBits
	// bits, effectively converting it to a fixed-point value.
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
	// float floatValue = static_cast<float>(_fixedValue);
	float floatValue = _fixedValue;
	// Define the conversion factor from fixed point to float
	// Similar to the scale factor used in the constructor from a float but in this case we are converting from fixed to
	// float, so we need to divide by the scale factor
	// we could explicitly set the converstion factor also in the constructor
	// set the conversion factor to float, even if this would happen automatically due to the division of an int by a
	// float int float conversionFactor = 1.0f << _fractionalBits; but the result is the same

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

// Overload the << operator: not the bitwise shift operator but the stream insertion operator
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
