#ifndef SFMLRENDERINGAPI_HPP
#define SFMLRENDERINGAPI_HPP

#include <Bridges/IRenderingApi.hpp>
#include <SFML/Graphics.hpp>

class SFMLUIApi : public IUIApi {
public:
	SFMLUIApi(sf::RenderWindow* w);
	~SFMLUIApi();
	void displayWindow();
	void closeWindow();
	bool isRunning();
	bool getEvent(Event* event);

private:
	sf::RenderWindow* window;
};


#endif // !SFMLRENDERINGAPI_HPP
