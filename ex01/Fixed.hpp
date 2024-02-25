#include <iostream> // for std::ostream and std::cout and std::endl
#include <math.h>	// roundf

#define FRAC_BITS 8
// 0000 0001 0000 0000 0000 0000 0000 0000
// in decimal, this is 2^23 = 8388608
#define MAX_INT_FOR_SHIFT ((1 << (sizeof(int) * 8 - FRAC_BITS)) - 1)

class Fixed
{
  private:
	int _fixedValue;
	static const int _fractionalBits = FRAC_BITS;

  public:
	// Default constructor
	// In the previous exercise, the default constructor was the only constructor (besides the copy constructor).
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
