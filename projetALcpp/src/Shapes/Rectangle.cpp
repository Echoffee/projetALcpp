#include <Shapes/Rectangle.hpp>

Rectangle::Rectangle(DrawingApi* api, std::vector<Vector2*> points, int color) {
	this->points = points;
	this->color = color;
	this->api = api;
}

Rectangle::Rectangle(DrawingApi* api, int x, int y, int width, int height){
	points.push_back(new Vector2(x, y));
	points.push_back(new Vector2(x + width, y));
	points.push_back(new Vector2(x + width, y + height));
	points.push_back(new Vector2(x, y + height));
	color = 0xFFFFFF;
	this->api = api;
}

Rectangle::~Rectangle() {
	for (auto point : points)
		delete point;
}

void Rectangle::setMemento(Memento * m){
	MementoRectangle* savedState = (MementoRectangle*)m;
	color = savedState->color;
	points = savedState->points;
}

Memento * Rectangle::createMemento(){
	std::vector<Vector2*> savedPoints(points.size());
	for (int i = 0; i < points.size(); ++i) {
		savedPoints.at(i) = new Vector2(points.at(i)->x, points.at(i)->y);
	}
	MementoRectangle* state = new MementoRectangle(savedPoints, color);
	return state;
}

void Rectangle::draw(){
	api->setColorFill(new Color(255, 0, 0));
	api->setColorLine(new Color(0, 255, 0));
	api->setLineWidth(2);
	api->drawShape(points);
	for (int i = 0; i < 4; ++i) {
		api->drawLine(points.at(i), points.at((i + 1) % 4));
	}
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


Shape * Rectangle::clone(){
	std::vector<Vector2*> newPoints(points);
	Rectangle* r = new Rectangle(api, newPoints, color);
	//memcpy(r, this, sizeof(this));
	return r;
}
