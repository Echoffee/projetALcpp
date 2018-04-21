#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP

#include <Visitor/IVisitor.hpp>
#include <Memento/MementoComposite.hpp>

class CompositeShape : public IShape {
private:
	std::vector<IShape*> shapes;

public:
	CompositeShape();
	CompositeShape(std::vector<IShape*> shapes);
	// Shape methods
	virtual void setMemento(IMemento* m) override;

	virtual IMemento* createMemento() override;

	virtual void addShape(IShape* shape) override;

	virtual void draw() override;

	virtual IShape* clone() override;

	virtual Vector2* getPosition() override;

	virtual Vector2* getOrigin() override;

	virtual void accept(IVisitor* visitor) override;

	std::vector<IShape*> getShapes();
};

#endif