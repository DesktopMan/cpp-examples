/*
 * Mixed declarations and code allowed
 * Variable declarations are allowed in loops
 * Function overloading
 *   Multiple functions with same name
 *   Must have different signature (return type not part of that)
 */
#include <iostream>

// Print version one, takes an int
void print(int val)
{
	std::cout << val << std::endl;
}

// Print version two, takes a double
void print(double val)
{
	std::cout << val << std::endl;
}

int main()
{
	int var = 1;
	// Calls version one automatically
	print(var);

	double var2 = 2.5;
	// Calls version two automatically
	print(var2);

	// Counter allocated in loop, scope is the loop
	for (int i = 0; i < 3; i++)
		std::cout << i << std::endl;

	system("pause");

	return EXIT_SUCCESS;
}
