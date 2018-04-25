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

			startPos = e->mousePosition;
			isInOp = true;

			return true;
		}
	}
	else {
		if (e->type == EventType::MouseButtonUp && e->keyid == 0) {
			endPos = e->mousePosition;
			isInOp = false;

			env->addCommand(new CommandTranslate(endPos->x - startPos->x, endPos->y - startPos->y, shape));
			return true;
		}
	}
	
	return false;
}