#ifndef CANVAS_HPP
#define CANVAS_HPP

#include <vector>
#include <Shapes/Shape.hpp>
#include <Application/UiElements.hpp>

class Canvas {
public:
	virtual std::vector<Shape*> getShapes() = 0;
	virtual std::vector<Shape*> getShapesAtPoint(Vector2* point) = 0;
	virtual std::vector<Shape*> getTools() = 0; //Ces Shape seront des Tools : Shape en fait
	virtual void addShape(Shape* s) = 0;
	virtual void deleteShape(Shape* s) = 0;
	virtual void addShapeToToolbar(Shape* s) = 0;
	virtual void removeShapeFromToolbar(Shape* s) = 0;
	virtual bool isOnCanvas(Vector2* point) = 0;
	virtual bool isOnToolbar(Vector2* point, UiElements toolbar = UiElements::All) = 0;
	virtual Vector2* getCornerPosition() = 0;
	virtual Vector2* getSize() = 0;
	//TODO :	Add rendering/drawing apis ?
	virtual void closeWindow() = 0;
};

#endif // !CANVAS_HPP
