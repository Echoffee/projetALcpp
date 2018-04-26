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
	bool pointable = true;

public:
	// Shape methods
	virtual void addShape(Shape* shape) override;
	virtual Vector2* getOrigin() override;
	virtual void accept(Visitor* visitor) override;
	virtual std::vector<Vector2*> getPoints();
	void setColorFill(Color* color);
	void setColorLine(Color* color);
	Color* getColorFill();
	Color* getColorLine();
	std::vector<Vector2*> getBounds();
	bool isPointable();
};

#endif