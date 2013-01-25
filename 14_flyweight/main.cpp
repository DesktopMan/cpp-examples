/* Flyweight pattern
 *
 * Create temporary objects (with no name) so that they have a very limited
 * lifetime. Simplifies cleanup and does not polute the namespace with dead
 * variables.
 *
 * Used with std::for_each in this example to perform an operation on every
 * item in an iterator range.
 */
#include <iostream>
#include <string>
#include <algorithm>

// Class that simply stores a char value
class Character
{
	char ch;
public:
	Character(char c) : ch(c) { }
	void output() const { std::cout << ch; }
};

// Class whose objects can be called as functions
struct OutputChar
{
	// Called when an object is used as a function with one parameter
	void operator()(char ch) const
	{
		Character(ch).output();
	}
};


// Use flyweight object on string
void hello_world(const std::string& message)
{
	// Iterate the string, calling the function object once on each char
	std::for_each(message.begin(), message.end(), OutputChar());
}

int main()
{
	hello_world("Hello world!\n");

	system("pause");

	return EXIT_SUCCESS;
}
