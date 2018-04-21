#include <Factories/SFMLApiFactory.hpp>

#include <Bridges/SFMLUIApi.hpp>
#include <Bridges/SFMLDrawingApi.hpp>
SFMLApiFactory::SFMLApiFactory() {
	this->window = new sf::RenderWindow(sf::VideoMode(1280, 720), "ohayou");
}

SFMLApiFactory::~SFMLApiFactory() {
	delete window;
}


DrawingApi* SFMLApiFactory::createDrawingApi() {
	return new SFMLDrawingApi(this->window);
}

UIApi* SFMLApiFactory::createRenderingApi() {
	return new SFMLUIApi(this->window);
}

