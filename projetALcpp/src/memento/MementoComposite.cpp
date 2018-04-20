#include <MementoComposite.hpp>

MementoComposite::MementoComposite(std::vector<IShape*> shapes) {
	std::vector<IShape*> newShapes(shapes);
	this->savedShapes = newShapes;
}