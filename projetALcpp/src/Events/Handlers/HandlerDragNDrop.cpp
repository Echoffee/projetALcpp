#include <Events/Handlers/HandlerDragNDrop.hpp>
#include <Application/App.hpp>
#include <Application/Canvas.hpp>
#include <Command/CommandTranslate.hpp>
#include <Command/CommandAddShape.hpp>
#include <Command/CommandDeleteShape.hpp>
bool HandlerDragNDrop::task(Event* e, App* env)
{
	if (!isInOp) {
		if (e->type == EventType::MouseButtonDown && e->keyid == 0 && env->isOnCanvas(e->mousePosition)) {
			shapes = env->getShapesAtPoint(e->mousePosition);
			if (shapes.size() > 0) {
				trueShape = shapes.front();
			}
			else {
				return false;
			}

			ghostShape = trueShape->clone();
			Color* c = ghostShape->getColorFill();
			c->a = 128;
			ghostShape->setColorFill(c);
			Command* command = new CommandAddShape(ghostShape, env);
			env->addCommand(command);
			startPos = e->mousePosition;
			deltaOld = e->mousePosition;
			isInOp = true;

			return true;
		}
	}
	else {
		if (e->type == EventType::MouseMove) {
			deltaNew = e->mousePosition;
			Command* command = new CommandTranslate(deltaNew->x - deltaOld->x, deltaNew->y - deltaOld->y, ghostShape);
			env->addCommand(command);
			deltaOld = deltaNew;
			return true;
		}

		if (e->type == EventType::MouseButtonUp && e->keyid == 0) {
			if (env->isOnCanvas(e->mousePosition))
				deltaNew = e->mousePosition;
			else
				deltaNew = startPos;
			
			env->addCommand(new CommandDeleteShape(ghostShape, env));
			env->addCommand(new CommandTranslate(deltaNew->x - startPos->x, deltaNew->y - startPos->y, trueShape));
			isInOp = false;
			return true;
		}
	}
	
	return false;
}