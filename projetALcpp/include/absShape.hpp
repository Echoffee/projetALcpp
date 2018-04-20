#ifndef ABS_SHAPE_HPP
#define ABS_SHAPE_HPP

#include <IShape.hpp>
#include <vector>

class AbsShape : public IShape{
protected:
	std::vector<int> points;
	int color;

public:
	// Shape methods
	virtual void addShape(IShape * shape) override;
};

#endif