#include <Events/Handlers/HandlerCreateFromToolbar.hpp>
#include <Application/App.hpp>
#include <Command/CommandAddShape.hpp>
#include <Command/CommandTranslate.hpp>
#include <Command/CommandDeleteShape.hpp>
bool HandlerCreateFromToolbar::task(Event* e, App* env) {
	if (!isInOp) {
		if (e->type == EventType::MouseButtonDown && e->keyid == 0 && env->isOnToolbar(e->mousePosition, UiElements::ShapeToolbar)) {
			trueShape = env->getShapeFromToolbar(e->mousePosition);
			if (trueShape == nullptr)
				return false;

			isInOp = true;
			ghostShape = trueShape->clone();
			Color* c = ghostShape->getColorFill();
			c->a = 128;
			ghostShape->setColorFill(c);
			Command* command = new CommandAddShape(ghostShape, env);
			env->addCommand(command);
			deltaOld = e->mousePosition->copy();

			return true;

		}
	}
	else {
		{
			if (e->type == EventType::MouseMove) {
				deltaNew = e->mousePosition->copy();
				Command* command = new CommandTranslate(deltaNew->x - deltaOld->x, deltaNew->y - deltaOld->y, ghostShape);
				env->addCommand(command);
				delete deltaOld;
				deltaOld = deltaNew;
				return true;
			}

			if (e->type == EventType::MouseButtonUp && e->keyid == 0) {
				std::vector<Vector2*> bounds = ghostShape->getBounds();
				deltaNew = e->mousePosition->copy();

				if (env->isOnCanvas(bounds.at(0)) && env->isOnCanvas(bounds.at(1)))
				{
					Shape* finalShape = trueShape->clone();
					env->addCommand(new CommandAddShape(finalShape, env));
					Command* command = new CommandTranslate(e->mousePosition->x - trueShape->getPosition()->x, e->mousePosition->y - trueShape->getPosition()->y, finalShape);
					env->addCommand(command);
				}

				env->addCommand(new CommandDeleteShape(ghostShape, env));
				isInOp = false;

				delete deltaNew;
				return true;
			}
		}
	}
}