#include <iostream>
#include "Fixed.hpp"

void printComparisonResult(const Fixed &lhs, const std::string &op, const Fixed &rhs, bool result)
{
	std::cout << "Comparing " << lhs << " " << op << " " << rhs << " -> " << (result ? "true" : "false") << std::endl;
}

void testComparisonOperators(void)
{
	Fixed a(5.5f);
	Fixed b(5.5f);
	Fixed c(10);
	Fixed d(2.25f);

	printComparisonResult(a, ">", c, a > c);
	printComparisonResult(c, ">", a, c > a);

	printComparisonResult(a, "<", c, a < c);
	printComparisonResult(c, "<", a, c < a);

	printComparisonResult(a, ">=", b, a >= b);
	printComparisonResult(a, ">=", c, a >= c);

	printComparisonResult(a, "<=", b, a <= b);
	printComparisonResult(a, "<=", c, a <= c);

	printComparisonResult(a, "==", b, a == b);
	printComparisonResult(a, "==", c, a == c);

	printComparisonResult(a, "!=", b, a != b);
	printComparisonResult(a, "!=", c, a != c);
}

void testArithmeticOperators()
{
	Fixed a(5.5f);
	Fixed b(2.0f);

	Fixed resultAdd = a + b;
	std::cout << "Addition: " << a << " + " << b << " = " << resultAdd << std::endl;

	Fixed resultSub = a - b;
	std::cout << "Subtraction: " << a << " - " << b << " = " << resultSub << std::endl;

	Fixed resultMul = a * b;
	std::cout << "Multiplication: " << a << " * " << b << " = " << resultMul << std::endl;

	Fixed resultDiv;
	if (b != Fixed(0))
	{
		resultDiv = a / b;
		std::cout << "Division: " << a << " / " << b << " = " << resultDiv << std::endl;
	}
	else
		std::cout << "Division by zero is not allowed." << std::endl;
}

void testIncrementDecrementOperators()
{
	std::cout << "\n***Test1***\n" << std::endl;
	Fixed a(5.5f);
	Fixed b(2.0f);

	std::cout << "a: " << a << std::endl;
	std::cout << "++a: " << ++a << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "a++: " << a++ << std::endl;
	std::cout << "a: " << a << std::endl;

	std::cout << "b: " << b << std::endl;
	std::cout << "--b: " << --b << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "b--: " << b-- << std::endl;
	std::cout << "b: " << b << std::endl;

	std::cout << "\n***Test2***\n" << std::endl;
	Fixed x(5.05f);							  // Starting point
	float stepSize = 1.0f / (1 << FRAC_BITS); // Calculate step size based on fractional bits
	// Display original value and step size
	std::cout << "Original x = " << x << " (Step size = " << stepSize << ")\n" << std::endl;

	// Pre-increment
	std::cout << "x: " << x << std::endl;
	std::cout << "Pre-increment (++x): x = " << ++x;
	std::cout << ", After pre-increment: x = " << x << std::endl;

	// Reset x for post-increment test
	x = Fixed(5.05f);

	// Post-increment
	std::cout << "x: " << x << std::endl;
	std::cout << "Post-increment (x++): x = " << x++;
	std::cout << ", After post-increment: x = " << x << std::endl;

	// Reset x for pre-decrement test
	x = Fixed(5.05f);

	// Pre-decrement
	std::cout << "x: " << x << std::endl;
	std::cout << "Pre-decrement (--x): x = " << --x;
	std::cout << ", After pre-decrement: x = " << x << std::endl;

	// Reset x for post-decrement test
	x = Fixed(5.05f);

	// Post-decrement
	std::cout << "x: " << x << std::endl;
	std::cout << "Post-decrement (x--): x = " << x--;
	std::cout << ", After post-decrement: x = " << x << std::endl;
}

void testMinMax()
{
	Fixed a(5.5f);
	Fixed b(10.1f);
	const Fixed c(7.25f);
	const Fixed d(2.5f);

	// Using non-const references
	std::cout << "Non-const references:" << std::endl;
	std::cout << "Min of " << a << " and " << b << " is " << Fixed::min(a, b) << std::endl;
	std::cout << "Max of " << a << " and " << b << " is " << Fixed::max(a, b) << std::endl;

	// Using const references
	std::cout << "Const references:" << std::endl;
	std::cout << "Min of " << c << " and " << d << " is " << Fixed::min(c, d) << std::endl;
	std::cout << "Max of " << c << " and " << d << " is " << Fixed::max(c, d) << std::endl;
}

void tests()
{
	std::cout << "\nTesting comparison operators:" << std::endl;

	testComparisonOperators();
	std::cout << "\nTesting arithmetic operators:" << std::endl;
	testArithmeticOperators();
	std::cout << "\nTesting increment/decrement operators:" << std::endl;
	testIncrementDecrementOperators();
	std::cout << "\nTesting min/max functions:" << std::endl;
	testMinMax();
}
