#ifndef HANDLERCREATEFROMTOOLBAR_HPP
#define HANDLERCREATEFROMTOOLBAR_HPP
#include <Events/Handler.hpp>

class Shape;
class HandlerCreateFromToolbar : public Handler {
public :
	bool task(Event* e, App* env);

private:
	bool isInOp = false;
	Shape* trueShape;
	Shape* ghostShape;

	Vector2* deltaOld;
	Vector2* deltaNew;
};

#endif // !HANDLERCREATEFROMTOOLBAR_HPP
