/*
 * Classes contain variables and functions
 * Different member access levels: public, protected, private
 * Special members: Constructor and destructor
 * Functions similar to what we already have in MID: structs with fptrs
 * Note: To create an instance you don't have struct or class in front
*/
#include <iostream>

// Usually the definition is seperate from implementation,
// so include an example of this.
#include "number.h"

// Definition and implementation at the same time. The examples will mostly
// use this, but splitting in .h / .cpp is more common in real projects.
class Point
{
// Public members can be accessed from everywhere
public:

	// Default constructor
	Point()
	{
		setx(0);
		sety(0);

		// Increment common object counter
		count++;
	}

	/* Constructor with parameters
	 *
	 * Uses initialization instead of assignment for x and y. For simple types
	 * this matters little, but for complex types it's the difference between
	 * running the default constructor first, then the copy constructor, or
	 * to only initialize.
	 */
	Point(int x, int y) : x(x), y(y)
	{
		// Increment common object counter
		count++;
	}

	/* Destructor, never has parameters
	 *
	 * Called when stack objects to out of scope and when heap objects are
	 * deleted.
	 */
	~Point()
	{
		// Decrement object counter
		count--;
	}

	// Setter, uses this to get a pointer to the current object. Not required
	// unless the names are the same, as here.
	void setx(int x)
	{
		this->x = x;
	};

	// Ditto
	void sety(int y)
	{
		this->y = y;
	};

	// Getter example. These are usually made const  which will give
	// a compile error if the function tries to modify the object.
	int getx() const
	{
		return x;
	}

	// Print object info
	void print() const
	{
		std::cout << "X: " << x << ", Y: " << y << std::endl;
	}

	// Get count of allocated objects.
	// static, so can be called without an instance.
	static int getCount()
	{
		return count;
	}

// Protected members are only accessible from inside the class and child classes
protected:
	int x, y;

	// Common variable for class
	static int count;

// Private members are only accessible from inside the class
private:
	int someData;
};

// Static members must be allocated outside class
int Point::count = 0;

int main()
{
	// Allocate on stack with default constructor.
	// Note that () is not used, as that would be a function prototype.
	Point p;

	// Allocate on stack using constructor with arguments
	Point p2(2, 3);

	// Then call print member function
	p.print();

	// Print number of allocated objects, calling static function.
	// The function can also be called on objects.
	std::cout << "Object count: " << Point::getCount() << std::endl;

	// Use the class that was defined in the .h file
	Number n(5);
	std::cout << "Number is: " << n.getNumber() << std::endl;

	system("pause");

	return EXIT_SUCCESS;
}
