#ifndef CANVAS_HPP
#define CANVAS_HPP

#include<vector>
#include<Shapes/IShape.hpp>

class Canvas {
public:
	virtual std::vector<IShape*> getShapes() = 0;
	virtual std::vector<IShape*> getTools() = 0; //Ces IShape seront des Tools : IShape en fait
	virtual Vector2* getCornerPosition() = 0;
	virtual Vector2* getSize() = 0;
	//TODO :	Add rendering/drawing apis ?
	virtual void closeWindow() = 0;
};

#endif // !CANVAS_HPP
