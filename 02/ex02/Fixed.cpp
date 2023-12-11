#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed(): _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	_value = value << _fraction;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value)
{
	_value = roundf(value * (1 << _fraction));
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
	*this = fixed;
	std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
	_value = fixed.getRawBits();
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void Fixed::setRawBits(int const raw)
{
	_value = raw;
}

float Fixed::toFloat() const
{
	return static_cast<float>(_value) / (1 << _fraction);
}

int Fixed::toInt() const
{
	return _value >> _fraction;
}

bool Fixed::operator>(const Fixed &fixed) const
{
	return _value > fixed.getRawBits();
}

bool Fixed::operator<(const Fixed &fixed) const
{
	return _value < fixed.getRawBits();
}

bool Fixed::operator>=(const Fixed &fixed) const
{
	return _value >= fixed.getRawBits();
}

bool Fixed::operator<=(const Fixed &fixed) const
{
	return _value <= fixed.getRawBits();
}

bool Fixed::operator==(const Fixed &fixed) const
{
	return _value == fixed.getRawBits();
}

bool Fixed::operator!=(const Fixed &fixed) const
{
	return _value != fixed.getRawBits();
}

Fixed Fixed::operator+(const Fixed &fixed) const
{
	return Fixed(toFloat() + fixed.toFloat());
}

Fixed Fixed::operator-(const Fixed &fixed) const
{
	return Fixed(toFloat() - fixed.toFloat());
}

Fixed Fixed::operator*(const Fixed &fixed) const
{
	return Fixed(toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(const Fixed &fixed) const
{
	Fixed zero(0);
	return fixed == zero ? zero : Fixed(toFloat() / fixed.toFloat());
}

Fixed &Fixed::operator++()
{
	_value++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	_value++;
	return tmp;
}

Fixed &Fixed::operator--()
{
	_value--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	_value--;
	return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return a < b ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return a > b ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return a < b ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return a > b ? a : b;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}
