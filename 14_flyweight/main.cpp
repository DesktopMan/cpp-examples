/* Flyweight pattern
 *
 * Reuse an object for multiple values / states instead of allocating new ones.
 * Reduces allocations and deallocations which can result in speedups and
 * reduced memory fragmentation. Also reduces the work for the garbage
 * collector if there is one.
 */
#include <iostream>
#include <string>
#include <algorithm>

// Class that simply stores a char value
class Character
{
	char ch;
public:
	void set(char ch) { this->ch = ch; }
	char get() const { return ch; }
};

// Print a given character
void printCharacter(const Character& ch)
{
	std::cout << ch.get();
}

// Use flyweight object on string
void hello_world(const std::string& message)
{
	Character ch;

	// Iterate the string, calling the function object once on each char
	for (auto it = message.begin(); it != message.end(); it++)
	{
		// Reuse the Character by setting a new value on it
		ch.set(*it);

		printCharacter(ch);
	}
}

int main()
{
	hello_world("Hello world!\n");

	system("pause");

	return EXIT_SUCCESS;
}
