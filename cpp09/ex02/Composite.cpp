#include "Composite.hpp"

// Composite
Composite::Composite(void) {}

Composite::Composite(const Composite &composite) {
	(void) composite;
}

Composite &Composite::operator=(const Composite &composite)
{
	(void) composite;
	return *this;
}

Composite::~Composite(void) {}

bool Composite::operator>(const Composite &composite) const
{
	return getValue() > composite.getValue();
}

bool Composite::operator<(const Composite &composite) const
{
	return getValue() < composite.getValue();
}

bool Composite::operator==(const Composite &composite) const
{
	return getValue() == composite.getValue();
}

bool Composite::operator!=(const Composite &composite) const
{
	return getValue() != composite.getValue();
}


// Pair
Pair::Pair(void): Composite(), _min(Number::Default), _max(Number::Default) {}

Pair::Pair(const Composite &c1, const Composite &c2): Composite(), _min(c1 > c2 ? c1 : c2), _max(c2 > c1 ? c2 : c1) {}

Pair::Pair(const Pair &pair): Composite(), _min(pair._min), _max(pair._max) {}

Pair &Pair::operator=(const Pair &pair)
{
	(void) pair;

	return *this;
}

Pair::~Pair(void) {}

int Pair::getValue(void) const
{
	return _max.getValue();
}

const Composite &Pair::getMin(void) const
{
	return _min;
}

const Composite &Pair::getMax(void) const
{
	return _max;
}

// Number
const Number Number::Default = Number(0);

Number::Number(void): Composite(), _value(0) {}

Number::Number(int number): Composite(), _value(number) {}

Number::Number(const Number &number): Composite(), _value(number._value) {}

Number &Number::operator=(const Number &number)
{
	(void) number;

	return *this;
}

Number::~Number(void) {}

int Number::getValue(void) const
{
	return _value;
}
