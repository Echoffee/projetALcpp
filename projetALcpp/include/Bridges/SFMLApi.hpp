#ifndef SFMLAPI_HPP
#define SFMLAPI_HPP

#include <Bridges/IDrawingApi.hpp>

#include <SFML/Graphics.hpp>
#include <vector>

class SFMLApi : public IDrawingApi {
public:
	SFMLApi(sf::RenderWindow* w);

	// IDrawingApi methods
	void drawRectangle(Rectangle* rectangle);

	void clear();
	void render();

private:
	// Window
	sf::RenderWindow* window;

	std::vector<sf::Drawable*> shapes;

};

#endif // !SFMLAPI_HPP

