/*
 * C++ / object oriented is not forced
 * Can still use C code
 * c-headers are renamed to c<name>, e.g. cmath
 */
#include <iostream>
#include <cstdio>
#include <string>

// Uses cout, the C++ representation of stdout
void hello_world_cplusplus()
{
	// C++ can dynamically handle strings.
	// They can be constructed using char*, and can be retrived with .c_str()
	std::string hello("Hello C++");

	/*
	 * std is a namespace where the standard functionality lives.
	 * Namespaces are used to group functionality and prevent naming colisions.
	 * cout is the C++ stream representation of stdout.
	 */
	std::cout << hello << std::endl;
	std::cout << "Hello C++ 2" << std::endl;
}

// Uses good ol' printf
void hello_world_c()
{
	printf("Hello C\n");
}

int main()
{
	hello_world_cplusplus();
	hello_world_c();

	system("pause");

	return EXIT_SUCCESS;
}
