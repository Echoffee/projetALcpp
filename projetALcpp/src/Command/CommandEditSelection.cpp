#include <Command/CommandEditSelection.hpp>

CommandEditSelection::CommandEditSelection(SelectionRectangle * shape, Vector2* tl, Vector2* br)
{
	this->shape = shape;
	this->tl = tl;
	this->br = br;
}

CommandEditSelection::~CommandEditSelection()
{
}

void CommandEditSelection::execute()
{
	shape->setPoint(0, tl);
	shape->setPoint(2, br);
}

void CommandEditSelection::unexecute()
{
}
