#ifndef ABS_SHAPE_HPP
#define ABS_SHAPE_HPP

#include <Visitor/Visitor.hpp>
#include <Maths/Vector2.hpp>
#include <Maths/Color.hpp>
#include <vector>
#include <Bridges/DrawingApi.hpp>
class AbstractShape : public Shape{
protected:
	std::vector<Vector2*> points;
	Color* colorFill;
	Color* colorLine;
	DrawingApi* api;

public:
	// Shape methods
	virtual void addShape(Shape* shape) override;
	virtual Vector2* getOrigin() override;
	virtual void accept(Visitor* visitor) override;
	virtual std::vector<Vector2*> getPoints();
	virtual void setColorFill(Color* color);
	virtual void setColorLine(Color* color);
};

#endif