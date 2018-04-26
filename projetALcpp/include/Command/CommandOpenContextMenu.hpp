#ifndef COMMANDOPENCONTEXTMENU_HPP
#define COMMANDOPENCONTEXTMENU_HPP

#include <Command/Command.hpp>
#include <Maths/Vector2.hpp>
#include <Application/Canvas.hpp>
#include <Factories/ContextMenuFactory.hpp>
class CommandOpenContextMenu : public Command {
private:
	Canvas * canvas;
	Vector2* position;
	ContextMenuFactory* factory;
public:
	CommandOpenContextMenu(DrawingApi* api, Vector2* posititon, Canvas* canvas);
	~CommandOpenContextMenu();

	virtual void execute() override;
	virtual void unexecute() override;

};

#endif // !COMMANDOPENCONTEXTMENU_HPP
