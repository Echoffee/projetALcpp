#ifndef ICOMMAND_HPP
#define ICOMMAND_HPP

class ICommand {
public:
	virtual void execute() = 0;
	virtual void unexecute() = 0;
};

#endif // !ICOMMAND_HPP
