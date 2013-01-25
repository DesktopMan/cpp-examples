/* Abstract factory pattern
 *
 * Instead of creating objects directly using their class name an abstract
 * class is defined with an interface to create objects. The factory can then
 * be passed around, making it easy to change out the class at a later time.
 *
 * It also makes it easier to handle failures (invalid constructor parameters)
 * for example, as it's not possible to "abort" a constructor call without
 * throwing exceptions.
 */
#include <iostream>
#include <string>
#include <memory>

// Abstract class definition
class Message
{
public:
	virtual ~Message() { }
	virtual std::string get_message()=0;
};

// Abstract factory definition
class MessageFactory
{
public:
	virtual ~MessageFactory() { }
	virtual std::auto_ptr<Message> create_message() const=0;
};

// Class implementation
class HelloWorldMessage : public Message
{
public:
	std::string get_message()
	{
		return "Hello world!";
	}
};

// Factory implementation
class HelloWorldFactory : public MessageFactory
{
public:
	std::auto_ptr<Message> create_message() const
	{
		return std::auto_ptr<Message>(new HelloWorldMessage());
	}
};

// Function that takes a factory as parameter
void hello_world(const MessageFactory& factory)
{
	// Use factory to create object
	std::auto_ptr<Message> message = factory.create_message();

	// Do some stuff with the object
	std::cout << message->get_message() << std::endl;
}

int main()
{
	// Call work function, pass factory
	hello_world(HelloWorldFactory());

	system("pause");

	return EXIT_SUCCESS;
}
