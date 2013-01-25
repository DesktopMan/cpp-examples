/* State pattern
 *
 * Base class defines functionality
 * Child classes implement those
 * Can be used to implement state machines
 */
#include <iostream>

// Abstract base class, defines functionaliy
class Mood
{
public:
	virtual ~Mood() { }
	virtual void talk()=0;
};

// Child class, implements functionality
class Happy : public Mood
{
public:
	void talk() { std::cout << "Hello world!" << std::endl; }
};

// Function takes any state and performs work on it
void hello_world(Mood& mood)
{
	mood.talk();
}

int main()
{
	// Create an instance of the happy implementation
	Happy mood;

	// And do some work with it
	hello_world(mood);

	system("pause");

	return EXIT_SUCCESS;
}
