#ifndef IRENDERINGAPI_HPP
#define IRENDERINGAPI_HPP

#include <Events/Event.hpp>

class IUIApi {
public:
	virtual void displayWindow() = 0;
	virtual void closeWindow() = 0;
	virtual bool isRunning() = 0;
	virtual bool getEvent(Event* event) = 0;
};

#endif // !IRENDERINGAPI_HPP
