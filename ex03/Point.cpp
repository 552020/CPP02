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
// This will throw an error because the we try to change the value of a const member
// Point &Point::operator=(const Point &other)
// {
// 	if (this != &other)
// 	{
// 		this->_x = other._x;
// 		this->_y = other._y;
// 	}
// 	return *this;
// }
// This is the correct way to implement the copy assignment operator but actually it makes more sense not to implement
// it at all
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
// Destructor
Point::~Point()
{
}

// Getters for x and y
Fixed const &Point::getX() const
{
	return _x;
}

Fixed const &Point::getY() const
{
	return _y;
}

// Helper function to calculate area of a triangle given its vertices
Fixed area(Point const &a, Point const &b, Point const &c)
{
	// Step 1: Calculate the components of the formula
	float aComponent = a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat());
	float bComponent = b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat());
	float cComponent = c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat());

	// Step 2: Calculate the sum of components
	float sumOfComponents = aComponent + bComponent + cComponent;

	// Step 3: Calculate the absolute value and divide by 2 to get the area
	float areaValue = std::abs(sumOfComponents) / 2.0f;

	// Step 4: Convert the area value to Fixed and return
	return Fixed(areaValue);
}

// Function to determine if a point is inside a triangle
bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	// Calculate the area of the original triangle ABC
	Fixed areaABC = area(a, b, c);
	// Calculate the area of the three triangles PAB, PBC, and PAC
	Fixed areaPAB = area(point, a, b);
	Fixed areaPBC = area(point, b, c);
	Fixed areaPAC = area(point, a, c);

	// Sum of areas of PAB, PBC, and PAC
	Fixed totalArea = areaPAB + areaPBC + areaPAC;

	return areaABC == totalArea;
}