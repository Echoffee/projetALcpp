#ifndef SELECTIONRECTANGLE_HPP
#define SELECTIONRECTANGLE_HPP

#include <Shapes/Rectangle.hpp>

class SelectionRectangle : public Rectangle {
public:
	SelectionRectangle(DrawingApi* api);
	void setPoint(int index, Vector2* position);
};
#endif // !SELECTIONRECTANGLE_HPP
