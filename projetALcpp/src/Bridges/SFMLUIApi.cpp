#include <Bridges/SFMLUIApi.hpp>

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

			default:
				return false;
		}
		//TODO
		//Wrapping events from SFML to our app here 

		return true;
	}

	return false;
}
