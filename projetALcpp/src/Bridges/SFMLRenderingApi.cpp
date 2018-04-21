#include <Bridges/SFMLRenderingApi.hpp>

SFMLRenderingApi::SFMLRenderingApi(sf::RenderWindow* w)
{
	this->window = w;
}

void SFMLRenderingApi::displayWindow() {
	window->display();
}
