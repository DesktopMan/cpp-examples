/*
 * Heap memory is allocated with operators new and delete.
 * Arrays must be deleted with the delete[] operator
 * Simple types are not initialized by default.
 * This can be done by calling their initializer explicitly.
 *
 * Smart pointers can be used to automatically free heap memory. Semantics are
 * different between smart pointer types, which dictates how they are used.
 */

#include <iostream>
#include <memory>

/*
 * Function takes a shared pointer as argument, which will trigger the copy
 * constructor. This increases the internal reference counter. Once the
 * function returns the reference counter is decremented.
 */
void func(std::shared_ptr<int> value)
{
	// Change value pointed to by the smart pointer
	*value = 42;
}

int main()
{
	// Uninitialized stack variable
	char c;
	// Assign a value to it
	c = 'c';

	// Initialized stack variable
	char c2 = c;

	// Uninitialized stack array
	double d[3];
	// Assign a value to the first element
	d[0] = 5;

	// Initialized stack array
	double d2[20] = { 5 };

	// Initialized per value stack array
	double d3[3] = { 1, 2, 3 };

	// Uninitialized heap variable
	int* number = new int;
	delete number;

	// Default initialized heap variable (0 for numeric types)
	number = new int();
	delete number;

	// Value initialized heap variable
	number = new int(5);
	delete number;

	// Uninitialized heap array
	double* numbers = new double[30];
	delete[] numbers;

	// Zero-initialized heap array.
	// Arrays do not support heap initialization with value.
	numbers = new double[30]();
	delete[] numbers;

	// Shared pointer (from C++11) to a value initialized int on the heap.
	// Freed once all copies of intPtr go out of scope.
	std::shared_ptr<int> intPtr(new int(3));

	// Call func with shared pointer (makes a copy)
	func(intPtr);


	system("pause");

	return EXIT_SUCCESS;
}
