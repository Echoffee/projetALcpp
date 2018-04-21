#include <Memento/MementoComposite.hpp>

MementoComposite::MementoComposite(std::vector<Shape*> shapes) {
	std::vector<Shape*> newShapes(shapes);
	this->savedShapes = newShapes;
}

MementoComposite::~MementoComposite() {
	for (auto shape : savedShapes)
		delete shape;
}
