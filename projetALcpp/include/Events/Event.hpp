#ifndef EVENT_HPP
#define EVENT_HPP

#include <Events/EventType.hpp>
class Vector2;
class Event {
public:
	Event();
	Event(EventType t);
	EventType type;
	int keyid;
	Vector2* mousePosition;
};


#endif // !EVENT_HPP
