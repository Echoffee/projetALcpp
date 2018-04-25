#include <Events/Handlers/HandlerClose.hpp>
#include <Command/CommandClose.hpp>
#include <Application/App.hpp>
bool HandlerClose::task(Event * e, App* env)
{
	if (e->type == EventType::Close) {
		env->addCommand(new CommandClose(env));
		return true;
	}
	return false;
}
