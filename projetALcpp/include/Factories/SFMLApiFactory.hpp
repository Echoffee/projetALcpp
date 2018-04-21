#ifndef SFMLAPIFACTORY_HPP
#define SFMLAPIFACTORY_HPP

#include <Factories/IApiFactory.hpp>
#include <SFML/Graphics.hpp>

class SFMLApiFactory : public IApiFactory {
public:
	SFMLApiFactory();
	~SFMLApiFactory();
	IDrawingApi* createDrawingApi();
	IUIApi* createRenderingApi();

private:
	sf::RenderWindow* window;
};

#endif // !SFMLAPIFACTORY_HPP
