#ifndef IDRAWINGAPI_HPP
#define IDRAWINGAPI_HPP

#include <rectangle.hpp>

class IDrawingApi {
	virtual void drawRectangle(Rectangle rectangle) = 0;
};

#endif // !IDRAWINGAPI_HPP
