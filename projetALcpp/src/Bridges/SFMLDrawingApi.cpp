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

void SFMLDrawingApi::clear() {
	this->shapes = std::vector<sf::Drawable*>();
}

void SFMLDrawingApi::render() {
	for (auto s : this->shapes) {
		window->draw(*s);
	}
}

void SFMLDrawingApi::drawRectangle(Rectangle* rectangle) {
	//sf::RectangleShape* s = new sf::RectangleShape();
	//s->setPosition(getPosition(rectangle));
	//s->setOrigin(getOrigin(rectangle));
	
	sf::ConvexShape* s = new sf::ConvexShape(4);
	s->setFillColor(sf::Color::Red);
	for (int i = 0; i < 4; ++i) {
		Vector2* v = rectangle->getPoints().at(i);
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

sf::Vector2f getPosition(Shape* shape) {
	sf::Vector2f result = sf::Vector2f();
	result.x = shape->getPosition()->x;
	result.y = shape->getPosition()->y;
	return result;
}

sf::Vector2f getOrigin(Shape* shape) {
	sf::Vector2f result = sf::Vector2f();
	result.x = shape->getOrigin()->x;
	result.y = shape->getOrigin()->y;
	return result;
}
