#include <Factories/ContextMenuFactory.hpp>
#include <Shapes/CompositeShape.hpp>
#include <Shapes/Rectangle.hpp>
#include <Shapes/TextShape.hpp>
ContextMenuFactory::ContextMenuFactory(DrawingApi * api)
{
	this->api = api;
}

Shape * ContextMenuFactory::createContextMenuForShape()
{
	Shape* result = new CompositeShape();
	Color* buttonBck = new Color(240, 240, 240, 255);
	Color* buttonLine = new Color(0, 0, 0, 0);
	Rectangle* r1 = new Rectangle(api, 0, 0, 100, 30);
	r1->setColorFill(buttonBck);
	r1->setColorLine(buttonLine);
	TextShape* t1 = new TextShape(api, new Vector2(2, 2), "Change color...");
	t1->setColorFill(new Color(0, 0, 0, 255));
	result->addShape(t1);
	result->addShape(r1);
	return result;
}

Shape * ContextMenuFactory::createContextMenuForGroup()
{
	return nullptr;
}

Shape * ContextMenuFactory::createContextMenuForSelectedGroup()
{
	return nullptr;
}

Shape * ContextMenuFactory::createContextMenuForColorPick()
{
	return nullptr;
}
