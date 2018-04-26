#ifndef TOOLBAR_HPP
#define TOOLBAR_HPP

#include <Shapes/CompositeShape.hpp>
#include <Shapes/Rectangle.hpp>

#include <Bridges/DrawingApi.hpp>
class Toolbar : public CompositeShape {
private:
	Rectangle* form;
	Color* colorFill;
	Color* colorLine;
	DrawingApi* api;
	Vector2* emptySlotPosition;
	Vector2* toolsMaxSize;
	Vector2* buttonSize;
	float minSize;
public:
	Toolbar(DrawingApi* api, Rectangle* form);
	Toolbar(DrawingApi* api, Rectangle* form, std::vector<Shape*> shapes);
	virtual void setMemento(Memento* m) override;
	virtual Memento* createMemento() override;
	virtual void draw() override;
	void setColorFill(Color* color);
	void setColorLine(Color* color);
	Color* getColorFill();
	Color* getColorLine();
	std::vector<Vector2*> getBounds();
	void addShape(Shape* shape);
};

#endif // !TOOLBAR_HPP
