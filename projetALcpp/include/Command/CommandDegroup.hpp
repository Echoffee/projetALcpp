#ifndef COMMAND_DEGROUP_HPP
#define COMMAND_DEGROUP_HPP

#include <Command/Command.hpp>
#include <Shapes/CompositeShape.hpp>
#include <Application/Canvas.hpp>

class CommandDegroup : public Command {
private:
	CompositeShape* composite;
	//Memento* savedState;
	Canvas* canvas;
	std::vector<Shape*> degroupedShapes;

public:
	CommandDegroup(CompositeShape* composite, Canvas* canvas);
	~CommandDegroup();

	virtual void execute() override;
	virtual void unexecute() override;
};

#endif // !COMMAND_DEGROUP_HPP
