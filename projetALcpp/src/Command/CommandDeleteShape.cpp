#include <Command/CommandDeleteShape.hpp>
#include <Command/CommandAddShape.hpp>
#include <algorithm>

CommandDeleteShape::CommandDeleteShape(Shape* shape, Canvas* canvas) {
	this->shape = shape;
	this->canvas = canvas;
}

CommandDeleteShape::~CommandDeleteShape() {
	delete shape;
}

void CommandDeleteShape::execute() {
	//std::vector<Shape*> vec(canvas->getShapes());
	//vec.erase(std::remove(vec.begin(), vec.end(), shape), vec.end());
	canvas->deleteShape(shape);
	//delete shape;
}

void CommandDeleteShape::unexecute() {/*
	CommandAddShape* command = new CommandAddShape(shape, canvas);
	command->execute();
	delete command;
	*/
}