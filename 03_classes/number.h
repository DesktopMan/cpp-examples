// Contains class definition only.
// Implementation is in number.cpp
#ifndef __number_h__
#define __number_h__

class Number
{
public:
	// Prototypes
	Number(int number);
	int getNumber() const;
	void setNumber(int number);

protected:
	int number;
};

#endif
