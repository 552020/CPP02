class Fixed
{
  private:
	int _fixedValue;
	static const int _fractionalBits = 8;

  public:
	// Default constructor
	Fixed();

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
};
