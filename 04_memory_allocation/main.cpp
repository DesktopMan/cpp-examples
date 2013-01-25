/*
 * Memory is allocated with operators new and delete.
 * Arrays must be deleted with the delete[] operator
 * Simple types are not initialized by default.
 * This can be done by calling their initializer explicitely.
 */

#include <iostream>

int main()
{
	// *number remains uninitialized
	int* number = new int;
	delete number;

	// Default initialize (0 for numeric types)
	number = new int();
	delete number;

	// Initialize with value
	number = new int(5);
	delete number;

	// Uninitialized array
	double* numbers = new double[30];
	delete[] numbers;

	// Zero-initialized heap array.
	// Arrays do not support heap initialization with value.
	numbers = new double[30]();
	delete[] numbers;

	system("pause");

	return EXIT_SUCCESS;
}
