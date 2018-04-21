#include <Application/App.hpp>
#include <Events/Event.hpp>

#include<Events/Handlers/HandlerClose.hpp>

App::App(ApiFactory* factory) {
	this->drawingApi = factory->createDrawingApi();
	this->uiApi = factory->createRenderingApi();
	this->eventHandler = new HandlerClose();
}

App::~App() {
	delete drawingApi;
	delete uiApi;
	delete eventHandler;

	for (auto shape : shapes)
		delete shape;

	for (auto tool : tools)
		delete tool;
}

void App::run() {
	//Debug goes here
	Rectangle* rect = new Rectangle(10, 10, 25, 30);

	//TODO
	while (uiApi->isRunning()) {
		Event e;

		while (uiApi->getEvent(&e)) {
			eventHandler->handle(&e, this);
		}

		drawingApi->clear();
		//Drawing stuff
		drawingApi->drawRectangle(rect);
		//
		drawingApi->render();
		uiApi->displayWindow();
	}
}

std::vector<Shape*> App::getShapes() {
	return this->shapes;
}

std::vector<Shape*> App::getTools() {
	return this->tools;
}

Vector2* App::getCornerPosition() {
	return new Vector2(20, 20);	//TODO
}

Vector2* App::getSize() {
	return new Vector2(1280 - this->getCornerPosition()->x, 720 - this->getCornerPosition()->y); //TODO
}

void App::closeWindow() {
	this->uiApi->closeWindow();
}