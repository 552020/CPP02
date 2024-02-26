#include <iostream>
#include <math.h>

#define FRAC_BITS 8

class Fixed
{
  private:
	int _fixedValue;
	static const int _fractionalBits = FRAC_BITS;

  public:
	// Default constructor
	Fixed();
	// Constructor from a constant integer. New!
	Fixed(const int value);
	// Constructor from a constant float. New!
	Fixed(const float value);

	// Copy constructor
	Fixed(const Fixed &other);
	// Copy assignment operator
	Fixed &operator=(const Fixed &other);
	// Destructor
	~Fixed();

	// return the raw value of the fixed point value.
	int getRawBits(void) const;

	// set the raw value of the fixed point value.
	void setRawBits(int const raw);

	// convert the fixed point value to a floating point value. New!
	float toFloat(void) const;

	// convert the fixed point value to an integer value. New!
	int toInt(void) const;
};

// Overload the << operator. New!
std::ostream &operator<<(std::ostream &os, const Fixed &fixed);
