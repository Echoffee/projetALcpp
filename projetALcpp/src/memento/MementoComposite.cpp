#include <Memento/MementoComposite.hpp>

MementoComposite::MementoComposite(std::vector<IShape*> shapes) {
	std::vector<IShape*> newShapes(shapes);
	this->savedShapes = newShapes;
}

MementoComposite::~MementoComposite() {
	for (auto shape : savedShapes)
		delete shape;
}
