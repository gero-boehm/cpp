#ifndef RPN_HPP
# define RPN_HPP

# include <string>
# include <stack>

class RPN
{
	private:
		RPN(void);

		const std::string _input;
		std::stack<int> _stack;

		bool isInputInvalid(void) const;
		bool isCharInvalid(const char &c) const;
		bool isNumber(const char &c) const;
		bool isOperator(const char &c) const;
		void addNumber(const char &c);
		void applyOperation(const char &c);

	public:
		RPN(const std::string &input);
		RPN(const RPN &rpn);
		RPN &operator=(const RPN &rpn);
		~RPN();

		int calculate(void);
};

#endif
