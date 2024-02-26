#include "Point.hpp"
Point::Point() : _x(0), _y(0)
{
}
Point::Point(const float x, const float y) : _x(x), _y(y)
{
}
Point::Point(const Point &other) : _x(other._x), _y(other._y)
{
}
/* COPY ASSIGNMENT OPERATOR STANDARD
This will throw an error because the we try to change the value of a const member: _x and _y are const members!

Point &Point::operator=(const Point &other)
{
	if (this != &other)
	{
		this->_x = other._x;
		this->_y = other._y;
	}
	return *this;
}
 */
/* COPY ASSIGNMENT OPERATOR WOKRAROUND */
Point &Point::operator=(const Point &other)
{
	if (this != &other)
	{
		// Manually call the destructor on this object
		this->~Point();
		// Use placement new to construct a new instance in the same location
		new (this) Point(other._x.toFloat(), other._y.toFloat());
	}
	return *this;
}
Point::~Point()
{
}
Fixed const &Point::getX() const
{
	return _x;
}

Fixed const &Point::getY() const
{
	return _y;
}

// Helper function to calculate area of a triangle given its vertices
