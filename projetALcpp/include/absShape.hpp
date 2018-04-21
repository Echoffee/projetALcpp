#ifndef ABS_SHAPE_HPP
#define ABS_SHAPE_HPP

#include <IShape.hpp>
#include <Maths/Vector2.hpp>
#include <vector>

class AbsShape : public IShape{
protected:
	std::vector<Vector2*> points;
	int color;

public:
	// Shape methods
	virtual void addShape(IShape * shape) override;
	virtual Vector2* getOrigin() override;
};

#endif