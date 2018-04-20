#ifndef IDRAWINGAPI_HPP
#define IDRAWINGAPI_HPP

#include <rectangle.hpp>

class IDrawingApi {

public:
	//Drawing methods
	virtual void drawRectangle(Rectangle* rectangle) = 0;

	//Canvas management methods (called by the 'Application' class maybe)
	virtual void clear() = 0;
	virtual void render() = 0;
};

#endif // !IDRAWINGAPI_HPP
