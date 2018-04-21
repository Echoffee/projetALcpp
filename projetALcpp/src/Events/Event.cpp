#include <Events/Event.hpp>

Event::Event()
{
	this->type = EventType::None;
}

Event::Event(EventType t) {
	this->type = t;
}