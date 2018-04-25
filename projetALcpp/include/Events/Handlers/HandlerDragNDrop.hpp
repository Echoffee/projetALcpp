#ifndef HANDLERDRAGNDROP_HPP
#define HANDLERDRAGNDROP_HPP

#include <Events/Handler.hpp>
#include <vector>

class Shape;
class HandlerDragNDrop : public Handler {
public :
	bool task(Event* e, App* env);

private:
	bool isInOp = false;
	Vector2* startPos;
	Vector2* endPos;
	Shape* shape;
	std::vector<Shape*> shapes;

	Vector2* deltaOld;
	Vector2* deltaNew;
};

#endif // !HANDLERDRAGNDROP_HPP
