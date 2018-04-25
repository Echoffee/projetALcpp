#ifndef COMMAND_GROUP_HPP
#define COMMAND_GROUP_HPP

#include <Command/Command.hpp>
#include <Shapes/CompositeShape.hpp>
#include <Application/Canvas.hpp>

class CommandGroup : public Command {
private:
	std::vector<Shape*> shapes;
	Canvas* canvas;
	CompositeShape* composite;

public:
	CommandGroup(std::vector<Shape*> shapes, Canvas* canvas);
	~CommandGroup();

	virtual void execute() override;
	virtual void unexecute() override;

};

#endif // !COMMAND_GROUP_HPP
