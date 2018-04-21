#ifndef SFMLAPIFACTORY_HPP
#define SFMLAPIFACTORY_HPP

#include <Factories/ApiFactory.hpp>
#include <SFML/Graphics.hpp>

class SFMLApiFactory : public ApiFactory {
public:
	SFMLApiFactory();
	~SFMLApiFactory();
	DrawingApi* createDrawingApi();
	UIApi* createRenderingApi();

private:
	sf::RenderWindow* window;
};

#endif // !SFMLAPIFACTORY_HPP
