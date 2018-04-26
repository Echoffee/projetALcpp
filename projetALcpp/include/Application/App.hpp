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
#include <Shapes/Toolbar.hpp>
class Rectangle; //debug
class App : public Canvas{
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
	void addShape(Shape* s);
	void deleteShape(Shape* s);
	void addShapeToToolbar(Shape* s);
	void removeShapeFromToolbar(Shape* s);
	bool isOnCanvas(Vector2* point);
	bool isOnToolbar(Vector2* point, UiElements toolbar = UiElements::All);
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
	Rectangle* canvas;
	Toolbar* toolbarLeft;
	Toolbar* toolbarTop;
	std::vector<Shape*> shapes;
	std::vector<Shape*> uiElements;
	std::vector<Shape*> tools;

};

#endif // !APP_HPP
