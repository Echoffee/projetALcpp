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

void SFMLApi::drawRectangle(Rectangle* rectangle) {
	/*sf::RectangleShape* s = new sf::RectangleShape();
	s->setPosition(getPosition(rectangle));
	s->setOrigin(getOrigin(rectangle));

	//Rectangle only
	sf::Vector2f size = sf::Vector2f();
	size.x = rectangle->getSize()->getX();
	size.y = rectangle->getSize()->getY();
	s->setSize(size);

	shapes.push_back(s);*/
}

sf::Vector2f getPosition(IShape* shape) {
	sf::Vector2f result = sf::Vector2f();
	result.x = shape->getPosition()->x;
	result.y = shape->getPosition()->y;
	return result;
}

sf::Vector2f getOrigin(IShape* shape) {
	sf::Vector2f result = sf::Vector2f();
	result.x = shape->getOrigin()->x;
	result.y = shape->getOrigin()->y;
	return result;
}
