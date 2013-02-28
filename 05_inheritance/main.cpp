/*
 * Inheritence can be used to
 *   Add functions
 *   Override functions
 *   Combine objects (multiple inheritance)
 *   Implement the concept of interfaces
 *   Pure virtual is often use for interfaces
 *   and other abstract base classes.
 * Objects are constructed base -> child
 * Objects are destructed child -> base
 */
#include <iostream>

// Base / parent class.
// Will be constructed first and destructed last
class Point2d
{
public:
	// Default constructor
	Point2d() : x(0), y(0)
	{
		initData();
	}

	Point2d(int x, int y) : x(x), y(y)
	{
		initData();
	}

	/*
	 * Virtual keyword ensures runtime type check of Point2d pointers and
	 * references in case of overridden	functions in child classes. See example
	 * below. This is called late binding. If virtual is not used then the base
	 * implementation is always called.

	 * If the base destructor is not virtual then child destructors will not be
	 * called when deleting base pointers, instead the behavior is undefined.
	 */
	virtual ~Point2d()
	{
		delete[] someData;
	}

	virtual void print()
	{
		std::cout << "X: " << x << ", Y: " << y;
	}

protected:
	/* Common init function for constructors
	 *
	 * You can't call one constructor from another so this is quite common.
	 */
	void initData()
	{
		someData = new char[64];
	}

	int x, y;
	char* someData;
};

/* Child class, inherits members from Point2d
 *
 * The public keyword keeps the base members at the same access level as they
 * are.
 * Will be constructed last and destructed first.
 */
class Point3d : public Point2d
{
public:
	// Point2d constructor is called first, automatically
	Point3d() : z(0) {}

	// Call Point2d constructor explicitely as we want to pass arguments to it.
	// It will as previously be run first.
	Point3d(int x, int y, int z) : Point2d(x, y), z(z) {}

	/* Overrides print function from base class
	 *
	 * Virtual is not required here (even if this class is again inherited)
	 * because the virtual property itself is inherited, but actually typing it
	 * makes code easier to read.
	 */
	virtual void print()
	{
		// Call base implementation
		Point2d::print();
		std::cout << ", Z: " << z;
	}

protected:
	// Adds variable z
	int z;
};

// Example of an abstract base class
class Vehicle
{
public:

	/* Pure virtual function with no implementation
	 *
	 * Having this prevents an object of type Vehicle from being created, and
	 * the compiler will complain if any child class omits implementing it.
	 */
	virtual void start() = 0;

	int speed;
	int passengerCount;
};

int main()
{
	// Access point2d object through point2d pointer
	Point2d* p2d = new Point2d(1, 2);
	p2d->print();
	std::cout << std::endl;

	// Access point3d object through point3d pointer
	Point3d* p3d = new Point3d(1, 2, 3);
	p3d->print();
	std::cout << std::endl;

	// Access point3d object through point2d (base) pointer
	Point2d* p2d2 = new Point3d(1, 2, 3);
	p2d2->print();
	std::cout << std::endl;

	system("pause");

	return EXIT_SUCCESS;
}
