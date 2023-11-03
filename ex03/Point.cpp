#include "Point.hpp"
Point::Point() : _x(0), _y(0) {}
Point::Point(const float x, const float y) : _x(x), _y(y) {}
Point::Point(const Point &other) : _x(other._x), _y(other._y) {}
Point &Point::operator=(const Point &other) {
  if (this != &other) {
    this->_x = other._x;
    this->_y = other._y;
  }
  return *this;
}
// Destructor
Point::~Point() {}

// Getters for x and y
Fixed const &Point::getX() const { return _x; }

Fixed const &Point::getY() const { return _y; }