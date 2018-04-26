#ifndef SFMLDRAWINGAPI_HPP
#define SFMLDRAWINGAPI_HPP

#include <Bridges/DrawingApi.hpp>

#include <SFML/Graphics.hpp>
#include <Maths/Vector2.hpp>
#include <Maths/Color.hpp>
#include <vector>

class SFMLDrawingApi : public DrawingApi {
public:
	SFMLDrawingApi(sf::RenderWindow* w);
	~SFMLDrawingApi();

	// IDrawingApi methods
	void setColorFill(Color* color);
	void setColorLine(Color* color);
	void setLineWidth(float width);
	void drawShape(std::vector<Vector2*> points);
	void drawLine(Vector2* start, Vector2* end);
	void drawText(Vector2* position, std::string text);

	void clear();
	void render();

private:
	// Window
	sf::RenderWindow* window;
	std::vector<sf::Drawable*> shapes;
	sf::Font* font;

	Color* colorFill;
	Color* colorLine;
	float lineWidth;
};

#endif // !SFMLDRAWINGAPI_HPP

