#ifndef IDRAWINGAPI_HPP
#define IDRAWINGAPI_HPP

#include <vector>
#include <Maths/Vector2.hpp>
#include <Maths/Color.hpp>
class DrawingApi {

public:
	//Drawing methods
	virtual void setColorFill(Color* color) = 0;
	virtual void setColorLine(Color* color) = 0;
	virtual void setLineWidth(float width) = 0;
	virtual void drawShape(std::vector<Vector2*> points) = 0;
	virtual void drawLine(Vector2* start, Vector2* end) = 0;
	//Canvas management methods (called by the 'Application' class maybe)
	virtual void clear() = 0;
	virtual void render() = 0;
};

#endif // !IDRAWINGAPI_HPP
