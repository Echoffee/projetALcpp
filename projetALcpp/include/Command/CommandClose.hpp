#ifndef COMMANDCLOSE_HPP
#define COMMANDCLOSE_HPP

#include <Command/Command.hpp>

class App;
class CommandClose : public Command {
public:
	CommandClose(App* app);
	virtual void execute() override;
	virtual void unexecute() override;

private:
	App* app;
};

#endif // !COMMANDCLOSE_HPP
