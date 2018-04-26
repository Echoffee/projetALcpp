#include <Events/Handlers/HandlerContextMenu.hpp>
#include <Command/CommandOpenContextMenu.hpp>
#include <Application/App.hpp>
HandlerContextMenu::HandlerContextMenu(DrawingApi * api)
{
	this->api = api;
}

bool HandlerContextMenu::task(Event* e, App* env) {
	if (isOpened) {
		return false;
	}
	else {
		if (e->type == MouseButtonDown && e->keyid == 1 && env->isOnCanvas(e->mousePosition)) {
			env->addCommand(new CommandOpenContextMenu(api, e->mousePosition, env));
			return true;
		}
	}

	return false;
}