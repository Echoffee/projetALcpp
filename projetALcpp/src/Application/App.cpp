#include <Application/App.hpp>
#include <Events/Event.hpp>

#include <Events/Handlers/HandlerClose.hpp>
#include <Events/Handlers/HandlerDragNDrop.hpp>

#include <Visitor/VisitorPoint.hpp>

#include <Shapes/Rectangle.hpp>
App::App(ApiFactory* factory) {
	this->drawingApi = factory->createDrawingApi();
	this->uiApi = factory->createRenderingApi();
	Handler* hClose = new HandlerClose();
	Handler* hDragNDrop = new HandlerDragNDrop();

	hClose->setSuccessor(hDragNDrop);

	this->eventHandler = hClose;
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
	Rectangle* rect = new Rectangle(drawingApi, 10, 10, 25, 30);
	shapes.push_back(rect);

	//TODO
	while (uiApi->isRunning()) {
		Event e;

		while (uiApi->getEvent(&e)) {
			eventHandler->handle(&e, this);
		}

		while (commands.size() > 0) {
			commands.front()->execute();
			commands.pop();
		}
		drawingApi->clear();
		//Drawing stuff
		//drawingApi->drawShape(rect->getPoints());
		for (auto s : shapes)
			s->draw();
		//
		drawingApi->render();
		uiApi->displayWindow();
	}
}

void App::addCommand(Command* command) {
	commands.push(command);
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

Canvas* App::getCanvas() {
	return this;
}

std::vector<Shape*> App::getShapesAtPoint(Vector2* point) {
	std::vector<Shape*> result = std::vector<Shape*>();
	for (auto s : shapes) {
		VisitorPoint* v = new VisitorPoint(point);
		s->accept(v);
		if (v->isContained())
			result.push_back(s);
	}

	return result;
}