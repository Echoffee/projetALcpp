#ifndef CONTEXTMENUFACTORY
#define CONTEXTMENUFACTORY

#include <Shapes/Shape.hpp>
#include <Bridges/DrawingApi.hpp>
class ContextMenuFactory {
public:
	ContextMenuFactory(DrawingApi* api);
	Shape* createContextMenuForShape();
	Shape* createContextMenuForGroup();
	Shape* createContextMenuForSelectedGroup();
	Shape* createContextMenuForColorPick();
private:
	DrawingApi* api;
};

#endif // !CONTEXTMENUFACTORY
