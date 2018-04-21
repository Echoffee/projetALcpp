#ifndef SFMLDRAWINGAPI_HPP
#define SFMLDRAWINGAPI_HPP

#include <Bridges/DrawingApi.hpp>

#include <SFML/Graphics.hpp>
#include <vector>

class SFMLDrawingApi : public DrawingApi {
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

