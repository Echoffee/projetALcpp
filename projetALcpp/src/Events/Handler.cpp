#include <Events/Handler.hpp>

void Handler::handle(Event * e, App* env)
{
	if (!task(e, env) && successor != nullptr)
		this->successor->handle(e, env);
}

void Handler::setSuccessor(Handler * next)
{
	this->successor = next;
}
