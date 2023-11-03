#include "Fixed.hpp"
Fixed::Fixed() { _rawBitsValue = 0; }
Fixed::Fixed(const int value) { _rawBitsValue = value << _fractionalBits; }
Fixed::Fixed(const float value) {
  _rawBitsValue = roundf(value * (1 << _fractionalBits));
}
Fixed::Fixed(const Fixed &other) { _rawBitsValue = other.getRawBits(); }
Fixed &Fixed::operator=(const Fixed &other) {
  if (this != &other) {
    _rawBitsValue = other.getRawBits();
  }
  return *this;
}
bool Fixed::operator>(const Fixed &other) const {
  return _rawBitsValue > other.getRawBits();
}
bool Fixed::operator<(const Fixed &other) const {
  return _rawBitsValue < other.getRawBits();
}
bool Fixed::operator>=(const Fixed &other) const {
  return _rawBitsValue >= other.getRawBits();
}
bool Fixed::operator<=(const Fixed &other) const {
  return _rawBitsValue <= other.getRawBits();
}
bool Fixed::operator==(const Fixed &other) const {
  return _rawBitsValue == other.getRawBits();
}
bool Fixed::operator!=(const Fixed &other) const {
  return _rawBitsValue != other.getRawBits();
}
Fixed Fixed::operator+(const Fixed &other) const {
  Fixed result;
  result.setRawBits(_rawBitsValue + other.getRawBits());
  return result;
}
Fixed Fixed::operator-(const Fixed &other) const {
  Fixed result;
  result.setRawBits(_rawBitsValue - other.getRawBits());
  return result;
}
Fixed Fixed::operator*(const Fixed &other) const {
  Fixed fixedResult;
  long long int thisRawLong = static_cast<long long int>(_rawBitsValue);
  long long int otherRawLong = static_cast<long long int>(other.getRawBits());
  long long int multipliedValue = (thisRawLong * otherRawLong);
  long long int scaledResult = multipliedValue >> _fractionalBits;
  int result = static_cast<int>(scaledResult);
  fixedResult.setRawBits(result);
  return fixedResult;
}
Fixed Fixed::operator/(const Fixed &other) const {
  if (other.getRawBits() == 0) {
    std::cerr << "Error: Division by zero." << std::endl;
    return Fixed();
  }
  Fixed fixedResult;
  long long int thisRawLong = static_cast<long long int>(_rawBitsValue)
                              << _fractionalBits;
  long long int otherRawLong = static_cast<long long int>(other.getRawBits());
  long long int dividedValue = thisRawLong / otherRawLong;
  int result = static_cast<int>(dividedValue);
  fixedResult.setRawBits(result);
  return fixedResult;
}
Fixed &Fixed::operator++() {
  this->_rawBitsValue += 1;
  return *this;
}
Fixed Fixed::operator++(int) {
  Fixed temp = *this;
  this->_rawBitsValue += 1;
  return temp;
}
Fixed &Fixed::operator--() {
  this->_rawBitsValue -= 1;
  return *this;
}
Fixed Fixed::operator--(int) {
  Fixed temp = *this;
  this->_rawBitsValue -= 1;
  return temp;
}
Fixed &Fixed::min(Fixed &a, Fixed &b) {
  if (a.getRawBits() < b.getRawBits()) {
    return a;
  } else {
    return b;
  }
}
const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
  if (a.getRawBits() < b.getRawBits()) {
    return a;
  } else {
    return b;
  }
}
Fixed &Fixed::max(Fixed &a, Fixed &b) {
  if (a.getRawBits() > b.getRawBits()) {
    return a;
  } else {
    return b;
  }
}
const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
  if (a.getRawBits() > b.getRawBits()) {
    return a;
  } else {
    return b;
  }
}
Fixed::~Fixed() {}
int Fixed::getRawBits(void) const { return _rawBitsValue; }

void Fixed::setRawBits(int const raw) { _rawBitsValue = raw; }

float Fixed::toFloat(void) const {
  float floatValue = static_cast<float>(_rawBitsValue);
  float conversionFactor = 1 << _fractionalBits;
  float result = floatValue / conversionFactor;
  return result;
}
int Fixed::toInt(void) const { return _rawBitsValue >> _fractionalBits; }
std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
  os << fixed.toFloat();
  return os;
}
