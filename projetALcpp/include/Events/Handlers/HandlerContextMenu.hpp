#ifndef HANDLERCONTEXTMENU_HPP
#define HANDLERCONTEXTMENU_HPP

#include <Events/Handler.hpp>
class DrawingApi;
class HandlerContextMenu : public Handler {
private :
	bool isOpened;
	DrawingApi* api;
public :
	HandlerContextMenu(DrawingApi* api);
	bool task(Event* e, App* env);
};

#endif // !HANDLERCONTEXTMENU_HPP
