#include <iostream>
#include <math.h>

class Fixed
{
  private:
	int _fixedValue;
	static const int _fractionalBits = 8;

  public:
	// Default constructor
	Fixed();
	// Constructor from a constant integer
	Fixed(const int value);
	// Constructor from a constant float
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

	// convert the fixed point value to a floating point value.
	float toFloat(void) const;

	// convert the fixed point value to an integer value.
	int toInt(void) const;
};

// Overload the << operator
std::ostream &operator<<(std::ostream &os, const Fixed &fixed);
