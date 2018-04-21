#ifndef COMMAND_TRANSLATE_HPP
#define COMMAND_TRANSLATE_HPP

#include <Command/Command.hpp>
#include <Memento/Memento.hpp>
#include <Shapes/Shape.hpp>
#include <Maths/Vector2.hpp>

class CommandTranslate : public Command {
private :
	Memento* savedState;
	Shape* shape;
	Vector2* direction;

public :
	CommandTranslate(float x, float y, Shape* shape);
	~CommandTranslate();
	//via ICommand
	virtual void execute() override;
	virtual void unexecute() override;

};

#endif // !COMMAND_TRANSLATE_HPP
