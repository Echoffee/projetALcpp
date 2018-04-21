#ifndef CANVAS_HPP
#define CANVAS_HPP

#include<vector>
#include<Shapes/Shape.hpp>

class Canvas {
public:
	virtual std::vector<Shape*> getShapes() = 0;
	virtual std::vector<Shape*> getTools() = 0; //Ces Shape seront des Tools : Shape en fait
	virtual Vector2* getCornerPosition() = 0;
	virtual Vector2* getSize() = 0;
	//TODO :	Add rendering/drawing apis ?
	virtual void closeWindow() = 0;
};

#endif // !CANVAS_HPP
