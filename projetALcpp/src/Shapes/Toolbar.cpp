#include <Shapes/Toolbar.hpp>

Toolbar::Toolbar(DrawingApi * api, Rectangle * form)
{
	this->api = api;
	this->form = form;
}

Toolbar::Toolbar(DrawingApi * api, Rectangle * form, std::vector<Shape*> shapes)
{
	this->api = api;
	this->form = form;
	this->shapes = shapes;
}

void Toolbar::setMemento(Memento * m)
{
	//TODO
}

Memento * Toolbar::createMemento()
{
	//TODO
	return nullptr;
}

void Toolbar::draw()
{
	form->draw();
	for (auto s : shapes) {
		s->draw();
	}
}

void Toolbar::setColorFill(Color * color)
{
	form->setColorFill(color);
}

void Toolbar::setColorLine(Color * color)
{
	form->setColorLine(color);

}

Color * Toolbar::getColorFill()
{
	return form->getColorFill();
}

Color * Toolbar::getColorLine()
{
	return form->getColorLine();
}

std::vector<Vector2*> Toolbar::getBounds()
{
	return form->getBounds();
}
