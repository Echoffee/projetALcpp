#include <Command/CommandGroup.hpp>
#include <Command/CommandDegroup.hpp>
#include <algorithm>

CommandGroup::CommandGroup(std::vector<Shape*> shapes, Canvas* canvas) {
	this->shapes = shapes;
	this->canvas = canvas;
}

CommandGroup::~CommandGroup() {

}

/*
canvas->getShapes().push_back(groupOfShapes);
std::vector<Shape*> vec(canvas->getShapes());
for (auto shape : degroupedShapes)
vec.erase(std::remove(vec.begin(), vec.end(), shape), vec.end());
*/

void CommandGroup::execute() {
	std::vector<Shape*> vec(canvas->getShapes());
	composite = new CompositeShape();
	for (auto shape : shapes) {
		vec.erase(std::remove(vec.begin(), vec.end(), shape), vec.end());
		composite->addShape(shape);
	}
	vec.push_back(composite);
}

void CommandGroup::unexecute() {
	CommandDegroup* degroupCommand = new CommandDegroup(composite, canvas);
	degroupCommand->execute();
	delete degroupCommand;
}
