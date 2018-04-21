#include <Events/Handlers/HandlerClose.hpp>

bool HandlerClose::task(Event * e, Canvas* env)
{
	if (e->type == EventType::Close) {
		env->closeWindow();
	}
	return false;
}
