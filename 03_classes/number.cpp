// Contains the implementation of the class defined in number.h.
#include "number.h"

// Name of class followed by :: is used to indicate where a function belongs
Number::Number(int number)
{
	setNumber(number);
}

int Number::getNumber() const
{
	return number;
}

void Number::setNumber(int number)
{
	this->number = number;
}
