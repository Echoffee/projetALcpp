#ifndef EVENT_HPP
#define EVENT_HPP

#include <Events/EventType.hpp>
class Event {
public:
	Event();
	Event(EventType t);
	EventType type;
};


#endif // !EVENT_HPP
