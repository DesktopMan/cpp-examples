/* Strategy pattern
 *
 * Pass algorithm to function or object.
 * Can be used for custom sorting, formatting etc
 */
#include <iostream>
#include <string>

// Abstract base class defining the interface for the algorithm
class Strategy
{
public:
	virtual ~Strategy() { }
	virtual std::string format(const std::string&, const std::string&) const=0;
};

// Implementation of strategy
class Formatter : public Strategy
{
public:
	std::string format(const std::string& s1, const std::string& s2) const
	{
		return s1 + " " + s2 + "!";
	}
};

// Do some work and use the provided strategy
void hello_world(const Strategy& strategy)
{
	std::cout << strategy.format("Hello", "world") << std::endl;
}

int main()
{
	// Call work with strategy instance
	hello_world(Formatter());

	system("pause");

	return EXIT_SUCCESS;
}
