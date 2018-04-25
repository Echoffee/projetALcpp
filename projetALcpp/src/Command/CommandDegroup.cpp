#include <Command/CommandDegroup.hpp>
#include <Command/CommandGroup.hpp>
#include <algorithm>

CommandDegroup::CommandDegroup(CompositeShape* composite, Canvas* canvas) {
	this->composite = composite;
	this->canvas = canvas;
}

CommandDegroup::~CommandDegroup() {

}

void CommandDegroup::execute() {
	//savedState = groupOfShapes->createMemento();
	std::vector<Shape*> group(composite->getShapes());

	for (auto shape : group) {
		degroupedShapes.push_back(shape);
		canvas->getShapes().push_back(shape);
	}

	std::vector<Shape*> vec(canvas->getShapes());
	vec.erase(std::remove(vec.begin(), vec.end(), composite), vec.end());
}

void CommandDegroup::unexecute() {
	//groupOfShapes->setMemento(savedState);
	/*
	canvas->getShapes().push_back(composite);
	std::vector<Shape*> vec(canvas->getShapes());
	for(auto shape : degroupedShapes)
		vec.erase(std::remove(vec.begin(), vec.end(), shape), vec.end());
	*/
	CommandGroup* groupCommand = new CommandGroup(degroupedShapes, canvas);
	groupCommand->execute();
}
