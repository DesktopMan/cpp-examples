/* Interpreter pattern
 *
 * Process commands on a given format and perform actions based on them. Can be
 * used to support scripting, command queing and commands given by an external
 * user at runtime.
 */
#include <string>
#include <iostream>
#include <stdexcept>

// Intepreter implementation, interface is a single function taking two
// iterators to the beginning and end of the command sequence.
class Interpreter
{
public:
	// This is a template to allow any iterator implementation that support
	// the increment and dereference operator to be used.
	template<typename It>
	bool run(It from, It to)
	{
		for(It i = from; i != to; ++i)
		{
			// The actual command interpreting
			switch(*i)
			{
			case 'h': std::cout << "Hello";		break;
			case ' ': std::cout << ' ';			break;
			case 'w': std::cout << "world";		break;
			case '!': std::cout << '!';			break;
			case 'n': std::cout << std::endl;	break;
			default:  return false;
			}
		}

		return true;
	}
};

// Call interpreter on given string
void hello_world(const std::string& script)
{
	Interpreter().run(script.begin(), script.end());
}

int main()
{
	hello_world("h w!n");

	system("pause");

	return EXIT_SUCCESS;
}
