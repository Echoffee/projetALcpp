#include <Events/Handlers/HandlerSelection.hpp>
#include <Application/App.hpp>
#include <Command/CommandAddShape.hpp>
#include <Command/CommandEditSelection.hpp>
#include <Command/CommandDeleteShape.hpp>
#include <Command/CommandGroup.hpp>
#include <Command/CommandDegroup.hpp>

HandlerSelection::HandlerSelection(SelectionRectangle* selectionBox) {
	this->selectionBox = selectionBox;
	selectionBox->setColorFill(new Color(0, 0, 0, 0));
	selectionBox->setColorLine(new Color(255, 0, 0, 128));
}

bool HandlerSelection::task(Event * e, App * env)
{
	if (!isInOp) {
		if (e->type == EventType::MouseButtonDown && e->keyid == 0 && env->isOnCanvas(e->mousePosition)) {
			isInOp = true;
			this->startPos = e->mousePosition->copy();
			env->addCommand(new CommandDeleteShape(selectionBox, env));
			env->addCommand(new CommandAddShape(selectionBox, env));
			env->addCommand(new CommandEditSelection(selectionBox, startPos, e->mousePosition->copy()));
			oldPos = startPos;
			return true;
		}
	}
	else {
		if (e->type == EventType::MouseMove) {
			Vector2* v = e->mousePosition->copy();
			if (!env->isOnCanvas(v))
				v = oldPos;
			env->addCommand(new CommandEditSelection(selectionBox, startPos, v));
			oldPos = v;
			return true;
		}

		if (e->type == EventType::MouseButtonUp) {
			std::vector<Vector2*> bounds = selectionBox->getBounds();
			Vector2* tl = bounds.at(0);
			Vector2* br = bounds.at(1);
			std::vector<Shape*> selectedShapes = env->getShapesBetweenTwoPoints(tl, br);
			env->setSelectedShapes(selectedShapes);
			isInOp = false;
			return true;
		}

	}
	return false;
}
