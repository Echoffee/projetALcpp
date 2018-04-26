#ifndef COMMANDADDTOTOOLBAR_HPP
#define COMMANDADDTOTOOLBAR_HPP

#include <Command/Command.hpp>
#include <Shapes/Shape.hpp>
#include <Application/Canvas.hpp>

class CommandAddToToolbar : public Command {
private :
	Shape * shape;
	Canvas* canvas;

public:
	CommandAddToToolbar(Shape* shape, Canvas* canvas);
	~CommandAddToToolbar();

	virtual void execute() override;
	virtual void unexecute() override;
};

#endif // !COMMANDADDTOTOOLBAR_HPP
