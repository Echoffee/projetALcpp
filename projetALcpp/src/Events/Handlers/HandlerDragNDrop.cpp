#include <Events/Handlers/HandlerDragNDrop.hpp>
#include <Application/App.hpp>
#include <Command/CommandTranslate.hpp>

bool HandlerDragNDrop::task(Event* e, App* env)
{
	if (!isInOp) {
		if (e->type == EventType::MouseButtonDown && e->keyid == 0) {
			shapes = env->getCanvas()->getShapesAtPoint(e->mousePosition);
			if (shapes.size() > 0) {
				shape = shapes.front();
			}
			else {
				return false;
			}

			deltaOld = e->mousePosition;
			isInOp = true;

			return true;
		}
	}
	else {
		if (e->type == EventType::MouseMove) {
			deltaNew = e->mousePosition;
			env->addCommand(new CommandTranslate(deltaNew->x - deltaOld->x, deltaNew->y - deltaOld->y, shape));
			deltaOld = deltaNew;
			return true;
		}

		if (e->type == EventType::MouseButtonUp && e->keyid == 0) {
			deltaNew = e->mousePosition;
			env->addCommand(new CommandTranslate(deltaNew->x - deltaOld->x, deltaNew->y - deltaOld->y, shape));
			isInOp = false;
			return true;
		}
	}
	
	return false;
}