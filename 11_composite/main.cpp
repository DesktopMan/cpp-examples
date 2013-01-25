/* Composite pattern
 *
 * Combines multiple classes into a single class
 * "Favor composition over inheritance" is a thing
 */
#include <iostream>
#include <string>

// Abstract base class 1
class Greeting
{
public:
	virtual ~Greeting() { }
	virtual std::string get_greeting()=0;
};

// Abstract base class 2
class Recipient
{
public:
	virtual ~Recipient() { }
	virtual std::string get_recipient()=0;
};

// Composite class that contains a reference to the two classes above
class Composite
{
	Greeting& greeting;
	Recipient& recipient;
public:
	Composite(Greeting& greeting, Recipient& recipient) :
	    greeting(greeting),
		recipient(recipient) { }
	void greet() const
	{
		std::cout << greeting.get_greeting() << " " 
			<< recipient.get_recipient() << "!" << std::endl;
	}
};

// Implementation of abstract base class 1
class Hello : public Greeting
{
public:
	std::string get_greeting() { return "Hello"; }
};

// Implementation of abstract base class 2
class World : public Recipient
{
public:
	std::string get_recipient() { return "world"; }
};

// Performs some work on a composite object
void hello_world(const Composite& composite)
{
	composite.greet();
}

int main()
{
	// Create an instance of the two implementations
	Hello hello;
	World world;

	// Create an instance of the composite class and pass it to a function
	hello_world(Composite(hello, world));

	system("pause");

	return EXIT_SUCCESS;
}
