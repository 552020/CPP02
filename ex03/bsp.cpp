#include "Fixed.hpp"
#include "Point.hpp"
#include <cmath>

// https://en.wikipedia.org/wiki/Area_of_a_triangle
Fixed area(Point const &a, Point const &b, Point const &c)
{
	Fixed Area =
		(a.getX() * (b.getY() - c.getY())) + (b.getX() * (c.getY() - a.getY())) + (c.getX() * (a.getY() - b.getY()));

	float areaValue = std::abs(Area.toFloat() / 2.0f);
	return Fixed(areaValue);
}

// Function to determine if a point is inside a triangle
bool bsp(Point const a, Point const b, Point const c, Point const p)
{
	// Calculate the area of the original triangle ABC
	Fixed areaABC = area(a, b, c);
	// Calculate the area of the three triangles PAB, PBC, and PAC
	Fixed areaPAB = area(p, a, b);
	Fixed areaPBC = area(p, b, c);
	Fixed areaPAC = area(p, a, c);

	// Sum of areas of PAB, PBC, and PAC
	Fixed totalArea = areaPAB + areaPBC + areaPAC;

	return areaABC == totalArea;
}