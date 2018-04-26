#include <Shapes/SelectionRectangle.hpp>

SelectionRectangle::SelectionRectangle(DrawingApi * api)
{
	points.push_back(new Vector2(0, 0));
	points.push_back(new Vector2(0, 0));
	points.push_back(new Vector2(0, 0));
	points.push_back(new Vector2(0, 0));
	this->api = api;

}

void SelectionRectangle::setPoint(int index, Vector2 * position)
{
	//delete points.at(index);
	points.at(index) = position;
	points.at((index + 1) % 4)->x = position->x;
	points.at((index == 0 ? 3 : index - 1))->y = position->y;
}
