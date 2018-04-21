#include <Factories/SFMLApiFactory.hpp>

#include <Bridges/SFMLRenderingApi.hpp>
#include <Bridges/SFMLDrawingApi.hpp>
SFMLApiFactory::SFMLApiFactory() {
	this->window = new sf::RenderWindow(sf::VideoMode(1280, 720), "ohayou");
}

IDrawingApi* SFMLApiFactory::createDrawingApi()
{
	return new SFMLDrawingApi(this->window);
}

IRenderingApi* SFMLApiFactory::createRenderingApi() {
	return new SFMLRenderingApi(this->window);
}

