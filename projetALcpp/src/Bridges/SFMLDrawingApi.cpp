#include <Bridges/SFMLDrawingApi.hpp>

SFMLDrawingApi::SFMLDrawingApi(sf::RenderWindow* w) {
	this->window = w;
	this->shapes = std::vector<sf::Drawable*>();
}

void SFMLDrawingApi::clear() {
	this->shapes = std::vector<sf::Drawable*>();
}

void SFMLDrawingApi::render() {
	for (auto s : shapes) {
		window->draw(*s);
	}
}

void SFMLDrawingApi::drawRectangle(Rectangle* rectangle) {
	sf::RectangleShape* s = new sf::RectangleShape();
	s->setPosition(getPosition(rectangle));
	s->setOrigin(getOrigin(rectangle));

	//Rectangle only
	sf::Vector2f size = sf::Vector2f();
	size.x = rectangle->getSize()->getX();
	size.y = rectangle->getSize()->getY();
	s->setSize(size);

	shapes.push_back(s);
}

sf::Vector2f getPosition(IShape* shape) {
	sf::Vector2f result = sf::Vector2f();
	result.x = shape->getPosition()->getX();
	result.y = shape->getPosition()->getY();
}

sf::Vector2f getOrigin(IShape* shape) {
	sf::Vector2f result = sf::Vector2f();
	result.x = shape->getOrigin()->getX();
	result.y = shape->getOrigin()->getY();
}