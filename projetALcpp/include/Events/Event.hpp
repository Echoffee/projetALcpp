#ifndef EVENT_HPP
#define EVENT_HPP

#include <Events/EventType.hpp>
#include <Maths/Vector2.hpp>

class Event {
public:
	Event();
	Event(EventType t);
	~Event();
	EventType type;
	int keyid;
	Vector2* mousePosition;
};


#endif // !EVENT_HPP
