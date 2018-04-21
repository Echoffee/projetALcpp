#ifndef HANDLER_HPP
#define HANDLER_HPP

#include <Events/Event.hpp>
#include <Application/Canvas.hpp>

class Handler {

public:
	Handler(Handler* s = nullptr);
	~Handler();
	void handle(Event* e, Canvas* env);
	virtual bool task(Event* e, Canvas* env) = 0;


private:
	Handler* successor;
};

#endif // !HANDLER_HPP
