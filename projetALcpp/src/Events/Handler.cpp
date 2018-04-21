#include <Events/Handler.hpp>

Handler::Handler(Handler* s) {
	this->successor = s;
}

void Handler::handle(Event * e, Canvas* env)
{
	if (!task(e, env) && successor != nullptr)
		this->successor->handle(e, env);
}
