#include <rectangle.hpp>

Rectangle::Rectangle(std::vector<int> points, int color) {
	this->points = points;
	this->color = color;
}

Rectangle::Rectangle(int x, int y, int width, int height){
	AbsShape::points.push_back(x);
	AbsShape::points.push_back(y);

	AbsShape::points.push_back(x + width);
	AbsShape::points.push_back(y);

	AbsShape::points.push_back(x + width);
	AbsShape::points.push_back(y + height);

	AbsShape::points.push_back(x);
	AbsShape::points.push_back(y + height);

	AbsShape::color = 0xFFFFFF;
}

void Rectangle::setMemento(IMemento * m){
	MementoRectangle* savedState = (MementoRectangle*)m;
	color = savedState->color;
	points = savedState->points;
}

IMemento * Rectangle::createMemento(){
	MementoRectangle* state = new MementoRectangle(points, color);
	return state;
}

void Rectangle::draw(){

}

IShape * Rectangle::clone(){
	std::vector<int> newPoints(points);
	Rectangle* r = new Rectangle(newPoints, color);
	//memcpy(r, this, sizeof(this));
	return r;
}
