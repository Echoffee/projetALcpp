#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <Shapes/AbstractShape.hpp>
#include <Memento/mementoRectangle.hpp>
class Rectangle : public AbstractShape {
public:
	Rectangle(DrawingApi* api, std::vector<Vector2*> points, int color);
	Rectangle(DrawingApi* api, int x, int y, int width, int height);
	~Rectangle();

	// AbsShape methods
	virtual void setMemento(Memento * m) override;
	virtual Memento * createMemento() override;
	virtual void draw() override;
	virtual Shape * clone() override;
	virtual Vector2* getPosition() override;
};

#endif