#ifndef COMPOSITE_HPP
# define COMPOSITE_HPP

# include <vector>
# include <stdexcept>

class Composite
{
	private:

	protected:
		Composite(void);

	public:
		Composite(const Composite &composite);
		Composite &operator=(const Composite &composite);
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

		const Composite *_min;
		const Composite *_max;

	public:
		Pair(const Composite *c1, const Composite *c2);
		Pair(const Pair &pair);
		Pair &operator=(const Pair &pair);
		~Pair();

		int getValue(void) const;
		const Composite *getMin(void) const;
		const Composite *getMax(void) const;
};

class Number: public Composite
{
	private:
		Number(void);

		int _value;

	public:
		Number(const int number);
		Number(const Number &number);
		Number &operator=(const Number &number);
		~Number();

		int getValue(void) const;
};

#endif

