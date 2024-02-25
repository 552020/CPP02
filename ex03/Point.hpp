#include "Fixed.hpp"

class Point
{
  private:
	Fixed const _x;
	Fixed const _y;
	// Anything else useful?
	// Copy assignment operator - not implemented, private to prevent use
	Point &operator=(const Point &);

  public:
	Point() : _x(0), _y(0)
	{
	}
	Point(const float x, const float y) : _x(x), _y(y) {};
	Point(const Point &other) : _x(other._x), _y(other._y)
	{
	}
	~Point();
	// Getters for x and y
	Fixed const &getX() const;
	Fixed const &getY() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);