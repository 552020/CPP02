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
	Point();
	Point(const float x, const float y);
	Point(const Point &other);
	~Point();
	// Getters for x and y
	Fixed const &getX() const;
	Fixed const &getY() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);