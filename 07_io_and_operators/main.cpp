/*
 * Input and ouput is implemented using streams.
 * Internally this is done by overloading the
 * << and >> operators for various classes.
 */
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

class Point
{
	// Make the left shift stream operator a friend of this class, giving it
	// access to protected and private members.
	friend std::ostream& operator<<(std::ostream& stream, const Point& p);

public:
	/* Addition operator
	 *
	 * Allows two points to be added together using +. This could also have
	 * been implemented outside the class as below, but often members are
	 * protected so it makes sense to do it on the inside if possible.
	 */
	Point operator+(const Point& p)
	{
		Point tmp;
		tmp.x = x + p.x;
		tmp.x = y + p.y;

		return tmp;
	}

protected:
	int x, y;
};

/* Operator for use of point with ostream
 *
 * Similar could be done with istream to directly read a point. This can't be
 * inside the Point class as it would not be called on Point but on the stream.
 * The reference return is required to allow chaining.
 *
 * This operator is a friend of the Point class as it requires access to
 * protected members. If it only required access to public members this would
 * not be required.
 */
std::ostream& operator<<(std::ostream& stream, const Point& p)
{
	stream << "X: " << p.x << ", Y: " << p.y;
	return stream;
}

int main()
{
	std::string data = "Hello, the answer is ";

	std::ofstream output("test.txt", std::ifstream::out);

	/*
	 * Write some data, notice the direct support for built in classes such as
	 * string. This is implemented as operator overloads in <string>. Simple
	 * types are also supported.
	 */
	output << data << 42;
	output.close();
	data = "";

	// Allocate a string stream for reading the data back in.
	// These can be used to construct strings from various types.
	std::stringstream ss;

	// Open the file for reading
	std::ifstream input("test.txt", std::ifstream::in);

	// Read the data back. This will be done on a per token basis separated by
	// white space.
	while (input.good())
	{
		std::string tmp;
		input >> tmp;
		ss << tmp;
	}

	std::cout << "Data read as tokens: " << ss.str() << std::endl;

	// You can also read full lines.
	// First clear flags on stream then seek to the beginning:
	input.clear();
	input.seekg(std::ios_base::beg);

	// Then read the line
	std::getline(input, data);

	std::cout << "Data read as line: " << data << std::endl;

	// Classes can be used directly with streams by implementing the proper
	// operators. Useful for serialization. Also uses the addition operator.
	Point p;
	std::cout << (p + p) << std::endl;

	system("pause");

	return EXIT_SUCCESS;
}
