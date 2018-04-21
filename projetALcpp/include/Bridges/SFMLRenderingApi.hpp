#ifndef SFMLRENDERINGAPI_HPP
#define SFMLRENDERINGAPI_HPP

#include <Bridges/IRenderingApi.hpp>
#include <SFML/Graphics.hpp>

class SFMLRenderingApi : public IRenderingApi {
public:
	SFMLRenderingApi(sf::RenderWindow* w);
	void displayWindow();

private:
	sf::RenderWindow* window;
};


#endif // !SFMLRENDERINGAPI_HPP
