#ifndef TEXTSHAPE_HPP
#define TEXTSHAPE_HPP
#include <Shapes/AbstractShape.hpp>
#include <Bridges/DrawingApi.hpp>
class TextShape : public AbstractShape{
private:
	std::string text;
	Color* color;
	DrawingApi* api;
public:
	TextShape(DrawingApi* api, Vector2* position, std::string text);
	Vector2* getPosition();
	Vector2* getOrigin();
	Color* getColorFill();
	void setColorFill(Color* c);
	Color* getColorLine();
	void setColorLine(Color* c);
	std::vector<Vector2*> getBounds();
	//Methods for memento pattern 
	void setMemento(Memento* m);
	Memento* createMemento();

	//Specific method for group of Shape for Composite pattern
	void addShape(Shape* shape);

	//Common methods between groups and shapes
	void draw();
	Shape* clone();

	//method for visitors
	void accept(Visitor* visitor);
};
#endif // !TEXTSHAPE_HPP
