/*
 * References in a nutshell:
 *   Typesafe assign once pointers
 * Can be used many places instead of pointers
 * Helps to sort out the const char* const etc mess
 * Good for const input parameters
 * Good for output parameters
 * Follow the same rule as pointers in regards to
 * inheritance and virtual members. See example 05.
 */
#include <iostream>

/* Calculate square of number
 *
 * Returns overflow.
 * Returns square of integer in output parameter passed by reference.
 * Note: Only const references can be assigned literal values, see below.
 */
bool getSquare(const int& num, int& result)
{
	result = num * num;
	
	return result < num;
}

int main()
{
	int result;

	bool overflow = getSquare(5, result);
	std::cout << "Overflow: " << (overflow ? "yes" : "no") << std::endl;

	overflow = getSquare(123456, result);
	std::cout << "Overflow: " << (overflow ? "yes" : "no") << std::endl;

	system("pause");

	return EXIT_SUCCESS;
}
