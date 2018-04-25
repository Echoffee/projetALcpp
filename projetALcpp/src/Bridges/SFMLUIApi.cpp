#include <Bridges/SFMLUIApi.hpp>
#include <Maths/Vector2.hpp>

SFMLUIApi::SFMLUIApi(sf::RenderWindow* w) {
	this->window = w;
}

SFMLUIApi::~SFMLUIApi() {
	delete window;
}

void SFMLUIApi::displayWindow() {
	window->display();
}

void SFMLUIApi::closeWindow() {
	window->close();
}

bool SFMLUIApi::isRunning() {
	return this->window->isOpen();
}

bool SFMLUIApi::getEvent(Event * event) {
	sf::Event sfe;
	if (this->window->pollEvent(sfe)) {

		switch (sfe.type) {
			case sf::Event::Closed:
				event->type = EventType::Close;
				break;

			case sf::Event::EventType::MouseButtonPressed:
				event->type = EventType::MouseButtonDown;
				if (sfe.mouseButton.button == sf::Mouse::Left)
					event->keyid = 0;
				if (sfe.mouseButton.button == sf::Mouse::Right)
					event->keyid = 1;
				break;

			case sf::Event::EventType::MouseButtonReleased:
				event->type = EventType::MouseButtonUp;
				if (sfe.mouseButton.button == sf::Mouse::Left)
					event->keyid = 0;
				if (sfe.mouseButton.button == sf::Mouse::Right)
					event->keyid = 1;
				break;

			case sf::Event::EventType::MouseMoved:
				event->type = EventType::MouseMove;
				event->mousePosition = new Vector2(sfe.mouseMove.x, sfe.mouseMove.y);
				break;

			default:
				return false;
		}
		//TODO
		//Wrapping events from SFML to our app here 

		return true;
	}

	return false;
}
