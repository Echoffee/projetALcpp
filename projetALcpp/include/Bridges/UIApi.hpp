#ifndef IUIAPI_HPP
#define IUIAPI_HPP

#include <Events/Event.hpp>

class UIApi {
public:
	virtual void displayWindow() = 0;
	virtual void closeWindow() = 0;
	virtual bool isRunning() = 0;
	virtual bool getEvent(Event* event) = 0;
};

#endif // !IUIAPI_HPP
