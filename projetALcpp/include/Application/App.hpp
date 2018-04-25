#ifndef APP_HPP
#define APP_HPP

#include <Factories/ApiFactory.hpp>
#include <Events/Handler.hpp>

//UI part
#include <Command/Command.hpp>
#include <queue>

//Canvas part
#include <Application/Canvas.hpp>
#include <Shapes/Shape.hpp>

class App : Canvas{
public:
	App(ApiFactory* factory);
	~App();

	void run();

	//UI stuff
	void addCommand(Command* command);
	Canvas* getCanvas();

	//Canvas stuff
	std::vector<Shape*> getShapes();
	std::vector<Shape*> getShapesAtPoint(Vector2* point);
	std::vector<Shape*> getTools(); //Ces Shape seront des Tools : Shape en fait
	Vector2* getCornerPosition();
	Vector2* getSize();
	void closeWindow();
private:

	//Systeme + IO
	DrawingApi* drawingApi;
	UIApi* uiApi;
	Handler* eventHandler;	//base of CoR
	std::queue<Command*> commands;

	//Rendering objects
	std::vector<Shape*> uiElements;
	std::vector<Shape*> shapes;
	std::vector<Shape*> tools;

};

#endif // !APP_HPP
