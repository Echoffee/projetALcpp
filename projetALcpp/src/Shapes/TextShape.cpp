#include <Shapes/TextShape.hpp>
#include <Visitor/Visitor.hpp>
TextShape::TextShape(DrawingApi * api, Vector2 * position, std::string text)
{
	this->api = api;
	points.push_back(position->copy());
	this->text = text;
}

Vector2 * TextShape::getPosition()
{
	return points.at(0)->copy();
}

Vector2 * TextShape::getOrigin()
{
	return points.at(0)->copy();
}

Color * TextShape::getColorFill()
{
	return color;
}

void TextShape::setColorFill(Color * c)
{
	this->color = c;
}

Color * TextShape::getColorLine()
{
	//Unused
	return nullptr;
}

void TextShape::setColorLine(Color * c)
{
	//Unused
}

std::vector<Vector2*> TextShape::getBounds()
{
	std::vector<Vector2*> result = std::vector<Vector2*>();
	result.push_back(new Vector2(0, 0));
	result.push_back(new Vector2(0, 0));
	//TODO
	return result;
}

void TextShape::setMemento(Memento * m)
{
	//TODO
}

Memento * TextShape::createMemento()
{
	//TODO
	return nullptr;
}

void TextShape::addShape(Shape * shape)
{
	//Unused
}

void TextShape::draw()
{
	api->setColorFill(color);
	api->drawText(points.at(0), text);
}

Shape * TextShape::clone()
{
	TextShape* t = new TextShape(api, points.at(0)->copy(), text);
	t->setColorFill(color);
	return t;
}

void TextShape::accept(Visitor * visitor)
{
	visitor->visit(this);
}
