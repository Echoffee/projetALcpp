#ifndef COMMAND_TRANSLATE_HPP
#define COMMAND_TRANSLATE_HPP

#include <Command/ICommand.hpp>
#include <Memento/IMemento.hpp>
#include <Shapes/IShape.hpp>
#include <Maths/Vector2.hpp>

class CommandTranslate : public ICommand {
private :
	IMemento* savedState;
	IShape* shape;
	Vector2* direction;

public :
	CommandTranslate(float x, float y, IShape* shape);
	//via ICommand
	virtual void execute() override;

	virtual void unexecute() override;

};

#endif // !COMMAND_TRANSLATE_HPP
