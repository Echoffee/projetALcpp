#include <Command/CommandOpenContextMenu.hpp>
#include <Visitor/VisitorTranslate.hpp>
CommandOpenContextMenu::CommandOpenContextMenu(DrawingApi* api, Vector2 * position, Canvas * canvas)
{
	this->canvas = canvas;
	this->position = position->copy();
	factory = new ContextMenuFactory(api);
}

CommandOpenContextMenu::~CommandOpenContextMenu()
{
	//TODO
}

void CommandOpenContextMenu::execute()
{
	Shape* s = factory->createContextMenuForShape();
	canvas->addShape(s);
	s->accept(new VisitorTranslate(new Vector2(position->x - s->getPosition()->x, position->y - s->getPosition()->y)));
}

void CommandOpenContextMenu::unexecute()
{
}
