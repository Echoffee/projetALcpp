#include <Command/CommandClose.hpp>
#include <Application/App.hpp>

CommandClose::CommandClose(App* app) {
	this->app = app;
}

void CommandClose::execute()
{
	app->closeWindow();
}

void CommandClose::unexecute()
{
	//lol
}
