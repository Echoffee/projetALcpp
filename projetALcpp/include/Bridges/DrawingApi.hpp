#ifndef IDRAWINGAPI_HPP
#define IDRAWINGAPI_HPP

#include <Shapes/Rectangle.hpp>

class DrawingApi {

public:
	//Drawing methods
	virtual void drawShape(std::vector<Vector2*> points) = 0;

	//Canvas management methods (called by the 'Application' class maybe)
	virtual void clear() = 0;
	virtual void render() = 0;
};

#endif // !IDRAWINGAPI_HPP
