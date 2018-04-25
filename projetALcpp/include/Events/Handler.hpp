#ifndef HANDLER_HPP
#define HANDLER_HPP

#include <Events/Event.hpp>

class App;
class Handler {

public:
	void handle(Event* e, App* env);
	void setSuccessor(Handler* next);
	virtual bool task(Event* e, App* env) = 0;


private:
	Handler* successor;
};

#endif // !HANDLER_HPP
