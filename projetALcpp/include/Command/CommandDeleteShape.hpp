#ifndef COMMAND_DELETE_HPP
#define COMMAND_DELETE_HPP

#include <Command/Command.hpp>
#include <Shapes/Shape.hpp>
#include <Application/Canvas.hpp>

class CommandDeleteShape : public Command {
private:
	Shape* shape;
	Canvas* canvas;

public:
	CommandDeleteShape(Shape* shape, Canvas* canvas);
	~CommandDeleteShape();

	virtual void execute() override;
	virtual void unexecute() override;

};

#endif // !COMMAND_DELETE_HPP
