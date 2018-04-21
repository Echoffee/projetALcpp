#ifndef SFMLUAPI_HPP
#define SFMLUAPI_HPP

#include <Bridges/UIApi.hpp>
#include <SFML/Graphics.hpp>

class SFMLUIApi : public UIApi {
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


#endif // !SFMLUAPI_HPP
