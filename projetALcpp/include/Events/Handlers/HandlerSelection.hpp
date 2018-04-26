#ifndef HANDLERSELECTION
#define HANDLERSELECTION

#include <Events/Handler.hpp>
#include <Shapes/SelectionRectangle.hpp>
class HandlerSelection : public Handler {
private:
	SelectionRectangle * selectionBox;
	CompositeShape* tempSelection;
	bool isInOp = false;
	Vector2* startPos;

public:
	HandlerSelection(SelectionRectangle* selectionBox);
	bool task(Event* e, App* env);
};

#endif // !HANDLERSELECTION
