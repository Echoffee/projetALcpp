#ifndef MEMENTO_COMPOSITE_HPP
#define MEMENTO_COMPOSITE_HPP

#include <Memento/Memento.hpp>
#include <Shapes/Shape.hpp>
#include <vector>

class MementoComposite : public Memento {
	friend class CompositeShape;

private:
	MementoComposite(std::vector<Shape*> shapes);
	~MementoComposite();
	std::vector<Shape*> savedShapes;


};

#endif
