#ifndef COMPOSITE_HPP
# define COMPOSITE_HPP

# include <vector>
# include <stdexcept>

class Composite
{
	private:
		Composite(const Composite &composite);
		Composite &operator=(const Composite &composite);

	protected:
		Composite(void);

	public:
		virtual ~Composite();

		virtual int getValue(void) const = 0;

		bool operator>(const Composite &composite) const;
		bool operator<(const Composite &composite) const;
		bool operator==(const Composite &composite) const;
		bool operator!=(const Composite &composite) const;
};

class Pair: public Composite
{
	private:
		Pair(void);
		Pair(const Pair &pair);
		Pair &operator=(const Pair &pair);

		const Composite &_min;
		const Composite &_max;

	public:
		Pair(const Composite &c1, const Composite &c2);
		~Pair();

		int getValue(void) const;
		const Composite &getMin(void) const;
		const Composite &getMax(void) const;
};

class Number: public Composite
{
	private:
		Number(void);
		Number(const Number &number);
		Number &operator=(const Number &number);

		int _value;

	public:
		static const Number Default;

		Number(const int number);
		~Number();

		int getValue(void) const;

};

#endif

