/* Facade pattern
 *
 * Provide a simple interface to complex actions. Might itself use other
 * objects etc depending on need. Represents functionality, not data.
 */
#include <string>
#include <iostream>

// Facade interface
class HelloWorld
{
public:
	virtual ~HelloWorld() { }
	virtual std::string hello() = 0;
	virtual std::string world() = 0;
	virtual void output(const std::string&) = 0;
	virtual void endl() = 0;
};

// Facade implementation of said interface
class HelloWorldImpl : public HelloWorld
{
public:
	std::string hello() { return "Hello"; }
	std::string world() { return "world"; }
	void output(const std::string& str)
	{
		std::cout << str;
	}
	void endl()
	{
		std::cout << std::endl;
	}
};

// Performs some work using the given implementation
void hello_world(HelloWorld& hw)
{
	hw.output(hw.hello());
	hw.output(" ");
	hw.output(hw.world());
	hw.output("!");
	hw.endl();
}

int main()
{
	// Create an instance of the implementation
	HelloWorldImpl hw;

	// Perform some work based on that implementation
	hello_world(hw);

	system("pause");

	return EXIT_SUCCESS;
}
