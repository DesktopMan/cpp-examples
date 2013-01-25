/*
 * Templates are class or functions that take other types as parameters.
 * Useful for generic code such as containers.
 * The parameter type is literally inserted into the template.
 * Compiler generates the specific implementation internally.
 * The C++ Standard Library ships with C++ compilers and contain
 * many generic classes and functions.
 */
#include <iostream>
#include <string>

// Automatically sized array
#include <vector>

// Linked size
#include <list>

// Associative map
#include <map>

// Generic algorithms
#include <algorithm>

// Generic class, holds one value of any type
template <class T>
class Storage
{
public:
	Storage(const T& value)
	{
		this->value = value;
	}

protected:
	T value;
};

// Generic function, prints anything to stdout as long as the operator exists.
// If it does not it will generate a build error.
template <class T>
void print(const T& value)
{
	std::cout << value << std::endl;
}

int main()
{
	// Create an instance of the template vector, with the type int
	std::vector<int> v;

	// Add some ints to the vector. This is typesafe following the declaration.
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);

	/*
	 * Print values using an iterator. Some containers support random access
	 * using the [] operator, while some do not.
	 *
	 * The auto keyword is part of C++11 and allows variables to be created
	 * using type inference. The alternative to auto is to write:
	 * std::vector<int>::iterator
	 */
	for(auto it = v.begin(); it != v.end(); it++)
	{
		// Use the dereference operator to get a reference
		// to the current iterator object
		std::cout << *it << std::endl;
	}

	/* Sort the numbers
	 *
	 * Many of the built in algorithms use iterators and can therefore work on
	 * many types of containers including your own if you implement iterator
	 * support for them. If you are sorting custom types you can also pass a
	 * predicate with a custom comparison, or implement the comparison
	 * operators.
	 */
	std::sort(v.begin(), v.end());

	// Templates can of course be used with complex types
	std::map<int, std::string> countries;

	// Note that the literal string will be implicitely converted to an
	// std::string object using one of the std::string constructors.
	countries[46] = "Sweden";
	countries[47] = "Norway";
	
	// Iterate the map
	for(auto it = countries.begin(); it != countries.end(); it++)
	{
		// Since maps have two values you use -> to access the two members
		// named first and second, which is key and value respectively.
		std::cout << it->first << ": " << it->second << std::endl;
	}

	// Search for a specific key value. Returns an iterator.
	if(countries.find(46) != countries.end())
		std::cout << "Value was found in map" << std::endl;

	/*
	 * Use the useless storage class and put a value in it. Note the extra
	 * space in the template parameters. This used to be required, but it's
	 * fixed in C++11 and some compilers fixed it before that.
	 */
	Storage<std::map<int, std::string> > s(countries);
	// If you have C++11 support you can also do
	// Storage<std::map<decltype(countries)> s(countries);

	// Print a string and a number with our generic print function
	print(std::string("hello"));
	print(5);

	system("pause");

	return EXIT_SUCCESS;
}
