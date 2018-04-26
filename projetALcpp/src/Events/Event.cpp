#include <Events/Event.hpp>

Event::Event()
{
	this->type = EventType::None;
	this->mousePosition = new Vector2(0, 0);
}

Event::Event(EventType t) {
	this->type = t;
	this->mousePosition = new Vector2(0, 0);
}

Event::~Event() {
	delete mousePosition;
}