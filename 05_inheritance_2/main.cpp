/*
 * Example showing an abstract base class defining an interface, with child
 * classes implementing that interface.
 */
#include <iostream>

// Abstract base class
class Shape
{
public:
	// Draw shape. Not implemented here
	virtual void Draw() = 0;

	// Always have virtual destructors in polymorphic classes
	virtual ~Shape() { };
};

// Implementation of shape interface, square version
class Square : public Shape
{
	virtual void Draw()
	{
		std::cout << "Drawing square" << std::endl;
	}
};

// Implementation of shape interface, circle version
class Circle : public Shape
{
	virtual void Draw()
	{
		std::cout << "Drawing circle" << std::endl;
	}
};

/*
 * Function that takes a pointer to the abstract base class.
 * It can thus use any object that conforms to that interface without knowing
 * any specifics about the implementation.
 */
void DrawShape(Shape* shape)
{
	std::cout << "Drawing shape from pointer" << std::endl;
	shape->Draw();
	std::cout << std::endl;
}

// Same but with a reference instead
void DrawShape(Shape& shape)
{
	std::cout << "Drawing shape from reference" << std::endl;
	shape.Draw();
	std::cout << std::endl;
}

int main()
{
	// Create objects of the two implementations
	Square square;
	Circle circle;

	// Draw the square using the generic draw function
	DrawShape(&square);
	DrawShape(square);

	// Draw the circle using the generic draw function
	DrawShape(&circle);
	DrawShape(circle);

	system("pause");

	return EXIT_SUCCESS;
}
