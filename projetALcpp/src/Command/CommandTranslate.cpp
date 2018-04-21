#include <Command/CommandTranslate.hpp>
#include <Visitor/VisitorTranslate.hpp>

CommandTranslate::CommandTranslate(float x, float y, IShape* shape) {
	this->shape = shape;
	direction = new Vector2(x, y);
}

CommandTranslate::~CommandTranslate() {

}

void CommandTranslate::execute() {
	savedState = shape->createMemento();
	VisitorTranslate* visitor = new VisitorTranslate(direction);
	shape->accept(visitor);
}

void CommandTranslate::unexecute() {
	shape->setMemento(savedState);
}
