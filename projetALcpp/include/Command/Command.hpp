#ifndef COMMAND_HPP
#define COMMAND_HPP

class Command {
public:
	virtual void execute() = 0;
	virtual void unexecute() = 0;
};

#endif // !COMMAND_HPP
