#include <rectangle.hpp>

Rectangle::Rectangle(int x, int y, int width, int height)
{
	AbsShape::points.push_back(x);
	AbsShape::points.push_back(y);

	AbsShape::points.push_back(x + width);
	AbsShape::points.push_back(y);

	AbsShape::points.push_back(x + width);
	AbsShape::points.push_back(y + height);

	AbsShape::points.push_back(x);
	AbsShape::points.push_back(y + height);

	AbsShape::color = 0xFFFFFF;
}

void Rectangle::setMemento(IMemento * m)
{

}

IMemento * Rectangle::createMemento()
{
	return nullptr;
}

void Rectangle::draw()
{
}

IShape * Rectangle::clone()
{
	return nullptr;
}
