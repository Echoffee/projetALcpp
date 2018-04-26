#ifndef COMMANDEDITSELECTION_HPP
#define COMMANDEDITSELECTION_HPP

#include <Command/Command.hpp>
#include <Shapes/SelectionRectangle.hpp>
class CommandEditSelection : public Command {
private:
	SelectionRectangle * shape;
	Vector2* tl;
	Vector2* br;

public :
	CommandEditSelection(SelectionRectangle* shape, Vector2* tl, Vector2* br);
	~CommandEditSelection();

	virtual void execute() override;
	virtual void unexecute() override;
};
#endif // !COMMANDEDITSELECTION_HPP
