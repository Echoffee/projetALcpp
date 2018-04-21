#ifndef MEMENTO_COMPOSITE_HPP
#define MEMENTO_COMPOSITE_HPP

#include <Memento/IMemento.hpp>
#include <Shapes/IShape.hpp>
#include <vector>

class MementoComposite : public IMemento {
	friend class CompositeShape;

private:
	MementoComposite(std::vector<IShape*> shapes);
	~MementoComposite();
	std::vector<IShape*> savedShapes;


};

#endif
