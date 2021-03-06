#include <Events/Handlers/HandlerDragNDrop.hpp>
#include <Application/App.hpp>
#include <Application/Canvas.hpp>
#include <Command/CommandTranslate.hpp>
#include <Command/CommandAddShape.hpp>
#include <Command/CommandDeleteShape.hpp>
#include <Command/CommandAddToToolbar.hpp>
bool HandlerDragNDrop::task(Event* e, App* env)
{
	if (!isInOp) {
		if (e->type == EventType::MouseButtonDown && e->keyid == 0 && env->isOnCanvas(e->mousePosition)) {
			shapes = env->getShapesAtPoint(e->mousePosition);
			if (shapes.size() > 0) {
				trueShape = shapes.back();
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
			startPos = e->mousePosition->copy();
			deltaOld = e->mousePosition->copy();
			isInOp = true;

			return true;
		}
	}
	else {
		if (e->type == EventType::MouseMove) {
			deltaNew = e->mousePosition->copy();
			Command* command = new CommandTranslate(deltaNew->x - deltaOld->x, deltaNew->y - deltaOld->y, ghostShape);
			env->addCommand(command);
			delete deltaOld;
			deltaOld = deltaNew;
			return true;
		}

		if (e->type == EventType::MouseButtonUp && e->keyid == 0) {
			std::vector<Vector2*> bounds(ghostShape->getBounds());

			if (env->isOnCanvas(bounds.at(0)) && env->isOnCanvas(bounds.at(1))) {
				deltaNew->x = e->mousePosition->x;
				deltaNew->y = e->mousePosition->y;
			}
			else {
				deltaNew->x = startPos->x;
				deltaNew->y = startPos->y;
			}
			
			if (env->isOnToolbar(e->mousePosition, UiElements::ShapeToolbar))
				env->addCommand(new CommandAddToToolbar(trueShape, env));

			env->addCommand(new CommandDeleteShape(ghostShape, env));
			env->addCommand(new CommandTranslate(deltaNew->x - startPos->x, deltaNew->y - startPos->y, trueShape));
			isInOp = false;

			//delete deltaNew;
			//delete startPos;
			return true;
		}
	}
	
	return false;
}