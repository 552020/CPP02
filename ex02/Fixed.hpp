#include <iostream>
#include <math.h>

class Fixed
{
  private:
	int _rawBitsValue;
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
	/* COMPARISON OPERATORS */
	// Overloading comparison operator >
	bool operator>(const Fixed &other) const;
	// Overloading comparison operator <
	bool operator<(const Fixed &other) const;
	// Overloading comparison operator >=
	bool operator>=(const Fixed &other) const;
	// Overloading comparison operator <=
	bool operator<=(const Fixed &other) const;
	// Overloading comparison operator ==
	bool operator==(const Fixed &other) const;
	// Overloading comparison operator !=
	bool operator!=(const Fixed &other) const;
	// Overloading arithmetic operator +
	Fixed operator+(const Fixed &other) const;
	// Overloading arithmetic operator -
	Fixed operator-(const Fixed &other) const;
	// Overloading arithmetic operator *
	Fixed operator*(const Fixed &other) const;
	// Overloading arithmetic operator /
	Fixed operator/(const Fixed &other) const;
	// Overloading pre-increment operator
	Fixed &operator++();
	// Overloading post-increment operator
	Fixed operator++(int);
	// Overloading pre-decrement operator
	Fixed &operator--();
	// Overloading post-decrement operator
	Fixed operator--(int);
	// reference to the min of two fixed point values
	static Fixed &min(Fixed &a, Fixed &b);
	// reference to the min of two fixed point values const
	static const Fixed &min(const Fixed &a, const Fixed &b);
	// reference to the max of two fixec point values
	static Fixed &max(Fixed &a, Fixed &b);
	// reference to the max of two fixed point values const
	static const Fixed &max(const Fixed &a, const Fixed &b);

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
