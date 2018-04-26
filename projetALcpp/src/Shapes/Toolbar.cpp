#include <Shapes/Toolbar.hpp>
#include <Visitor/VisitorScale.hpp>
#include <Visitor/VisitorTranslate.hpp>

Toolbar::Toolbar(DrawingApi * api, Rectangle * form)
{
	this->api = api;
	this->form = form;
	std::vector<Vector2*> points = form->getBounds();
	float sizeX = points.at(1)->x - points.at(0)->x;
	float sizeY = points.at(1)->y - points.at(0)->y;
	minSize = abs(fminf(sizeX, sizeY));
	minSize = minSize * 0.9f;
	emptySlotPosition = new Vector2(sizeX / 2, points.at(0)->y + minSize / 2);
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

void Toolbar::addShape(Shape* s) {
	shapes.push_back(s);
	std::vector<Vector2*> bounds = s->getBounds();
	float sizeX = bounds.at(1)->x - bounds.at(0)->x;
	float sizeY = bounds.at(1)->y - bounds.at(0)->y;
	float scale = minSize / fmaxf(sizeX, sizeY);
	Vector2* vscale = new Vector2(scale, scale);
	Visitor* v = new VisitorScale(vscale);
	s->accept(v);
	//shape rescaled
	Vector2* pos_start = s->getPosition();
	Vector2* vtranslate = new Vector2(emptySlotPosition->x - pos_start->x, emptySlotPosition->y - pos_start->y);
	v = new VisitorTranslate(vtranslate);
	s->accept(v);
	emptySlotPosition->y = emptySlotPosition->y + minSize;
	//shape placed
	delete vscale;
	delete v;
	delete pos_start;
	delete vtranslate;
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
