#ifndef COMMAND_ROTATE_HPP
#define COMMAND_ROTATE_HPP

#include <Command/Command.hpp>
#include <Shapes/Shape.hpp>

class CommandRotate : public Command {
private:
	Memento* savedState;
	double angle;
	Shape* shape;

public:
	CommandRotate(Shape* shape, double angle);
	~CommandRotate();
	virtual void execute() override;
	virtual void unexecute() override;
};


#endif // !COMMAND_ROTATE_HPP
