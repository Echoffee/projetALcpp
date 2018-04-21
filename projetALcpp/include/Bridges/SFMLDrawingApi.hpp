#ifndef SFMLDRAWINGAPI_HPP
#define SFMLDRAWINGAPI_HPP

#include <Bridges/IDrawingApi.hpp>

#include <SFML/Graphics.hpp>
#include <vector>

class SFMLDrawingApi : public IDrawingApi {
public:
	SFMLDrawingApi(sf::RenderWindow* w);
	~SFMLDrawingApi();

	// IDrawingApi methods
	void drawRectangle(Rectangle* rectangle);

	void clear();
	void render();

private:
	// Window
	sf::RenderWindow* window;

	std::vector<sf::Drawable*> shapes;

};

#endif // !SFMLDRAWINGAPI_HPP

