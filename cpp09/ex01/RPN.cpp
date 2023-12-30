#include <stdexcept>
#include <iostream>
#include "RPN.hpp"

RPN::RPN(void): _input("") {}

RPN::RPN(const std::string &input): _input(input)
{
	if(isInputInvalid())
		throw std::runtime_error("Invalid input");
}

RPN::RPN(const RPN &rpn)
{
	*this = rpn;
}

RPN &RPN::operator=(const RPN &rpn)
{
	if(this == &rpn)
		return *this;

	const_cast<std::string&>(_input) = rpn._input;
	_stack = rpn._stack;

	return *this;
}

RPN::~RPN() {}

bool RPN::isInputInvalid(void) const
{
	for(unsigned long i = 0; i < _input.length(); i++)
	{
		if(i % 2 == 0 && isCharInvalid(_input[i]))
			return true;
		if(i % 2 == 1 && _input[i] != ' ')
			return true;
	}

	if(_input[_input.length() - 1] == ' ')
		return true;

	// std::cout << "count " << count << std::endl;

	int count = -1;

	for(unsigned long i = 0; i < _input.length(); i += 2)
	{
		if (isNumber(_input[i]))
			count++;
		else
			count--;

		if(count < 0)
			return true;
	}

	return count != 0;
}

bool RPN::isCharInvalid(const char &c) const
{
	return !(isNumber(c) || isOperator(c));
}

bool RPN::isNumber(const char &c) const
{
	return c >= '0' && c <= '9';
}

bool RPN::isOperator(const char &c) const
{
	return c == '+' || c == '-' || c == '*' || c == '/';
}

void RPN::addNumber(const char &c)
{
	int number = static_cast<int>(c - '0');

	_stack.push(number);
}

void RPN::applyOperation(const char &c)
{
	int tmp = _stack.top();
	_stack.pop();
	int &top = _stack.top();

	switch(c)
	{
		case '+':
			top += tmp;
			break;
		case '-':
			top -= tmp;
			break;
		case '*':
			top *= tmp;
			break;
		case '/':
			top /= tmp;
			break;
	}
}

int RPN::calculate(void)
{
	for(unsigned long i = 0; i < _input.length(); i += 2)
	{
		const char &c = _input[i];

		if(isNumber(c))
			addNumber(c);
		else
			applyOperation(c);
	}

	int result = _stack.top();
	_stack.pop();

	return result;
}
