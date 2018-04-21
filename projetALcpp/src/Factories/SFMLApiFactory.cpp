#include <Factories/SFMLApiFactory.hpp>

#include <Bridges/SFMLRenderingApi.hpp>
#include <Bridges/SFMLDrawingApi.hpp>
SFMLApiFactory::SFMLApiFactory() {
	this->window = new sf::RenderWindow(sf::VideoMode(1280, 720), "ohayou");
}

SFMLApiFactory::~SFMLApiFactory() {
	delete window;
}


IDrawingApi* SFMLApiFactory::createDrawingApi() {
	return new SFMLDrawingApi(this->window);
}

IUIApi* SFMLApiFactory::createRenderingApi() {
	return new SFMLUIApi(this->window);
}

