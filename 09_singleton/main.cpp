/* Singleton pattern
 *
 * Global, one instance only object
 * Can be accessed from anywhere
 *
 * Note: Easy to overuse
 * Note: Do not keep state in a singleton
 * Note: All examples are from:
 * http://calumgrant.net/patterns/index.html
 */
#include <iostream>

class HelloWorld
{
	// Empty default constructor
	HelloWorld() { }

	// Copy constructor, not implemented.
	// Prevents copies from being made.
	HelloWorld(const HelloWorld&);
public:
	// Do some stuff
	void output()
	{
		std::cout << "Hello world!" << std::endl;
	}
	
	// Returns the same instance each call
	static HelloWorld& get()
	{
		static HelloWorld singleton;
		return singleton;
	}
};

int main()
{
	// Get instance and call function
	HelloWorld::get().output();

	system("pause");

	return EXIT_SUCCESS;
}
