#ifndef COMMAND_ADD_SHAPE_HPP
#define COMMAND_ADD_SHAPE_HPP

#include <Command/Command.hpp>
#include <Shapes/Shape.hpp>
#include <Application/Canvas.hpp>

class CommandAddShape : public Command {
private:
	Shape* shape;
	Canvas* canvas;

public:
	CommandAddShape(Shape* Shape, Canvas* canvas);
	~CommandAddShape();

	virtual void execute() override;
	virtual void unexecute() override;

};


#endif // !COMMAND_ADD_SHAPE_HPP
