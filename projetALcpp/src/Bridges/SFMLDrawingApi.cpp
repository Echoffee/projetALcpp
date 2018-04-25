#include <Bridges/SFMLDrawingApi.hpp>

SFMLDrawingApi::SFMLDrawingApi(sf::RenderWindow* w) {
	this->window = w;
	this->shapes = std::vector<sf::Drawable*>();
}

SFMLDrawingApi::~SFMLDrawingApi() {
	//sf::RenderWindow* window;
	//std::vector<sf::Drawable*> shapes;
	delete window;
	for (auto shape : shapes)
		delete shape;
}

void SFMLDrawingApi::setColorFill(Color * color)
{
	colorFill = color;
}

void SFMLDrawingApi::setColorLine(Color * color)
{
	colorLine = color;
}

void SFMLDrawingApi::setLineWidth(float width)
{
	lineWidth = width;
}

void SFMLDrawingApi::clear() {
	for (auto s : shapes)
		delete s;
	std::vector<sf::Drawable*>().swap(this->shapes);
	window->clear();
}

void SFMLDrawingApi::render() {
	for (auto s : this->shapes) {
		window->draw(*s);
	}
}

void SFMLDrawingApi::drawShape(std::vector<Vector2*> points) {
	//sf::RectangleShape* s = new sf::RectangleShape();
	//s->setPosition(getPosition(rectangle));
	//s->setOrigin(getOrigin(rectangle));
	
	sf::ConvexShape* s = new sf::ConvexShape(points.size());
	s->setFillColor(sf::Color(colorFill->r, colorFill->g, colorFill->b, colorFill->a));
	for (int i = 0; i < points.size(); ++i) {
		Vector2* v = points.at(i);
		sf::Vector2f sfv = sf::Vector2f(v->x, v->y);
		s->setPoint(i, sfv);
	}

	////Rectangle only
	//sf::Vector2f size = sf::Vector2f();
	//size.x = rectangle->getSize()->x;
	//size.y = rectangle->getSize()->y;
	//s->setSize(size);

	this->shapes.push_back(s);
}

float distance(Vector2* a, Vector2* b) {
	float l1 = b->x - a->x;
	l1 = l1 * l1;
	float l2 = b->y - a->y;
	l2 = l2 * l2;
	return sqrtf(l1 + l2);
}

void SFMLDrawingApi::drawLine(Vector2 * start, Vector2 * end)
{
	sf::RectangleShape* l = new sf::RectangleShape();
	l->setFillColor(sf::Color(colorLine->r, colorLine->g, colorLine->b, colorLine->a));
	l->setPosition(sf::Vector2f(start->x, start->y));
	l->setOrigin(sf::Vector2f(0, lineWidth/2));
	float length = distance(start, end);
	l->setSize(sf::Vector2f(length, lineWidth));
	l->rotate(57.2958 * atan2f(end->y - start->y, end->x - start->x));
	shapes.push_back(l);
}