#include <iostream>
#include "Point.hpp"
#include "Fixed.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

class Triangle
{
  private:
	Point _a;
	Point _b;
	Point _c;

  public:
	Triangle() {};
	Triangle(Point const &a, Point const &b, Point const &c) : _a(a), _b(b), _c(c)
	{
	}
	~Triangle()
	{
	}
	Triangle(Triangle const &other) : _a(other._a), _b(other._b), _c(other._c)
	{
	}
	Triangle &operator=(Triangle const &other)
	{
		if (this != &other)
		{
			this->_a = other._a;
			this->_b = other._b;
			this->_c = other._c;
		}
		return *this;
	}
	Point const &getA() const
	{
		return _a;
	}
	Point const &getB() const
	{
		return _b;
	}
	Point const &getC() const
	{
		return _c;
	}
};

void testPointInside(Triangle const &t, Point const *points, int const size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << "Point "
				  << "(" << points[i].getX() << ", " << points[i].getY() << ")"
				  << " is "
				  << (bsp(t.getA(), t.getB(), t.getC(), points[i]) ? "inside: TEST PASSED!" : "outside: TEST FAILED!")
				  << std::endl;
	}
}

void testPointOutside(Triangle const &t, Point const *points, int const size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << "Point "
				  << "(" << points[i].getX() << ", " << points[i].getY() << ")"
				  << " is "
				  << (!bsp(t.getA(), t.getB(), t.getC(), points[i]) ? "outside: TEST PASSED!" : "inside: TEST FAILED!")
				  << std::endl;
	}
}

int main(void)
{
	Triangle t(Point(0, 0), Point(10, 00), Point(00, 10));

	std::cout << "The triangle coordinates are: " << std::endl;
	std::cout << "A: " << t.getA().getX() << ", " << t.getA().getY() << std::endl;
	std::cout << "B: " << t.getB().getX() << ", " << t.getB().getY() << std::endl;
	std::cout << "C: " << t.getC().getX() << ", " << t.getC().getY() << std::endl;

	Point pointsInside[] = {Point(1, 1), Point(2, 2), Point(3, 3), Point(1, 8)};
	Point pointsOutside[] = {Point(100, 100), Point(100, 200), Point(200, 100), Point(100, 100)};

	std::cout << "Testing points inside the triangle" << std::endl;
	testPointInside(t, pointsInside, 4);
	std::cout << "Testing points outside the triangle" << std::endl;
	testPointOutside(t, pointsOutside, 4);
}