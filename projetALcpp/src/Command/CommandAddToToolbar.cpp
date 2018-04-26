#include <Command/CommandAddToToolbar.hpp>

CommandAddToToolbar::CommandAddToToolbar(Shape * shape, Canvas * canvas)
{
	this->shape = shape;
	this->canvas = canvas;
}

CommandAddToToolbar::~CommandAddToToolbar()
{
}

void CommandAddToToolbar::execute()
{
	Shape* newShape = shape->clone();
	canvas->addShapeToToolbar(newShape);
}

void CommandAddToToolbar::unexecute()
{
	canvas->removeShapeFromToolbar(shape);
}