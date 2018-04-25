#include <Command/CommandAddShape.hpp>
#include <Command/CommandDeleteShape.hpp>

CommandAddShape::CommandAddShape(Shape* shape, Canvas* canvas) {
	this->shape = shape;
	this->canvas = canvas;
}

CommandAddShape::~CommandAddShape() {

}

void CommandAddShape::execute() {
	canvas->addShape(shape);
}

void CommandAddShape::unexecute() {
	CommandDeleteShape* command = new CommandDeleteShape(shape, canvas);
	command->execute();
	delete command;
}
