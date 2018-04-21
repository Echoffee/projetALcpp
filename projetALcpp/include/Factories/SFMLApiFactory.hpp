#ifndef SFMLAPIFACTORY_HPP
#define SFMLAPIFACTORY_HPP

#include <Factories/IApiFactory.hpp>
#include <SFML/Graphics.hpp>

class SFMLApiFactory : public IApiFactory {
public:
	SFMLApiFactory();
	IDrawingApi* createDrawingApi();
	IRenderingApi* createRenderingApi();

private:
	sf::RenderWindow* window;
};

#endif // !SFMLAPIFACTORY_HPP
