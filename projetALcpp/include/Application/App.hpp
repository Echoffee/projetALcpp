#ifndef APP_HPP
#define APP_HPP

#include <Factories/IApiFactory.hpp>
#include <Events/Handler.hpp>

//Canvas part
#include <Application/Canvas.hpp>
#include <Shapes/IShape.hpp>

class App : Canvas{
public:
	App(IApiFactory* factory);
	void run();

	//Canvas stuff
	std::vector<IShape*> getShapes();
	std::vector<IShape*> getTools(); //Ces IShape seront des Tools : IShape en fait
	Vector2* getCornerPosition();
	Vector2* getSize();
	void closeWindow();
private:

	//Systeme + IO
	IDrawingApi* drawingApi;
	IUIApi* uiApi;
	Handler* eventHandler;	//base of CoR

	//Rendering objects
	std::vector<IShape*> shapes;
	std::vector<IShape*> tools;

};

#endif // !APP_HPP
