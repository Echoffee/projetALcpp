#include <rectangle.hpp>

Rectangle::Rectangle(std::vector<Vector2*> points, int color) {
	this->points = points;
	this->color = color;
}

Rectangle::Rectangle(int x, int y, int width, int height){
	points.push_back(new Vector2(x, y));
	points.push_back(new Vector2(x + width, y));
	points.push_back(new Vector2(x + width, y + height));
	points.push_back(new Vector2(x, y + height));
	color = 0xFFFFFF;
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

Vector2* Rectangle::getPosition() {
	Vector2* center = new Vector2(0, 0);
	for (auto point : points) {
		center->x += point->x;
		center->y += point->y;
	}

	center->x = center->x / points.size();
	center->y = center->y / points.size();

	return center;
}


IShape * Rectangle::clone(){
	std::vector<Vector2*> newPoints(points);
	Rectangle* r = new Rectangle(newPoints, color);
	//memcpy(r, this, sizeof(this));
	return r;
}
