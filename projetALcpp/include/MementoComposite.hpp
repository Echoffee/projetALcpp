#ifndef MEMENTO_COMPOSITE_HPP
#define MEMENTO_COMPOSITE_HPP

#include <IMemento.hpp>
#include <IShape.hpp>
#include <vector>

class MementoComposite : public IMemento {
	friend class CompositeShape;

private:
	MementoComposite(std::vector<IShape*> shapes);
	std::vector<IShape*> savedShapes;


};

#endif
