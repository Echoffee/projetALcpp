#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP

#include <Visitor/Visitor.hpp>
#include <Memento/MementoComposite.hpp>

class CompositeShape : public Shape {
private:
	std::vector<Shape*> shapes;

public:
	CompositeShape();
	CompositeShape(std::vector<Shape*> shapes);
	~CompositeShape();
	// Shape methods
	virtual void setMemento(Memento* m) override;

	virtual Memento* createMemento() override;

	virtual void addShape(Shape* shape) override;

	virtual void draw() override;

	virtual Shape* clone() override;

	virtual Vector2* getPosition() override;

	virtual Vector2* getOrigin() override;

	virtual void accept(Visitor* visitor) override;

	std::vector<Shape*> getShapes();

	void setColorFill(Color* color);
	void setColorLine(Color* color);
	Color* getColorFill();
	Color* getColorLine();
};

#endif