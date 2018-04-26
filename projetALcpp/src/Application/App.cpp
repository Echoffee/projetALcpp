#include <Application/App.hpp>
#include <Events/Event.hpp>

#include <Events/Handlers/HandlerClose.hpp>
#include <Events/Handlers/HandlerDragNDrop.hpp>

#include <Visitor/VisitorPoint.hpp>

#include <Shapes/Rectangle.hpp>
#include <Shapes/CompositeShape.hpp>


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
	//Canvas drawing
	Rectangle* toolbarTop = new Rectangle(drawingApi, 2, 2, 1278, 38);
	toolbarTop->setColorFill(new Color(255, 255, 255));
	toolbarTop->setColorLine(new Color(30, 30, 255));

	Rectangle* toolbarLeft = new Rectangle(drawingApi, 2, 40, 38, 678);
	toolbarLeft->setColorFill(new Color(255, 255, 255));
	toolbarLeft->setColorLine(new Color(30, 30, 255));

	canvas = new Rectangle(drawingApi, 40, 40, 1238, 678);
	canvas->setColorFill(new Color(255, 255, 255));
	canvas->setColorLine(new Color(30, 30, 255));
	uiElements.push_back(toolbarTop);
	uiElements.push_back(toolbarLeft);

	//Debug goes here
	Rectangle* rect = new Rectangle(drawingApi, 80, 40, 25, 30);
	Rectangle* rect2 = new Rectangle(drawingApi, 40, 40, 25, 30);
	Rectangle* rect3 = new Rectangle(drawingApi, 40, 80, 25, 30);

	Rectangle* rect4 = new Rectangle(drawingApi, 30, 60, 25, 30);
	Rectangle* rect5 = new Rectangle(drawingApi, 100, 150, 25, 30);

	CompositeShape* gr1 = new CompositeShape();
	gr1->addShape(rect);
	gr1->addShape(rect2);
	gr1->addShape(rect3);

	CompositeShape* gr2 = new CompositeShape();
	gr2->addShape(rect4);
	gr2->addShape(rect5);

	CompositeShape* gr3 = new CompositeShape();
	gr3->addShape(gr1);
	gr3->addShape(gr2);

	shapes.push_back(gr3);

	for (int i = 0; i < 50; i++)
		shapes.push_back(new Rectangle(drawingApi, 70 + 5 * i, 70 + 5 * i, 20, 25));

	/*CompositeShape* gr1 = new CompositeShape();
	gr1->addShape(rect);
	gr1->addShape(rect2);
	shapes.push_back(gr1);*/
	//TODO
	while (uiApi->isRunning()) {
		Event* e = new Event();

		while (uiApi->getEvent(e)) {
			eventHandler->handle(e, this);
		}

		while (commands.size() > 0) {
			commands.front()->execute();
			Command* c = commands.front();
			commands.pop();
			delete c;
		}

		drawingApi->clear();
		//Drawing stuff
		//drawingApi->drawShape(rect->getPoints());
		canvas->draw();
		for (auto s : uiElements)
			s->draw();
		for (auto s : tools)
			s->draw();
		for (auto s : shapes)
			s->draw();
		//
		drawingApi->render();
		uiApi->displayWindow();
		delete e;
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

void App::addShape(Shape * s)
{
	shapes.push_back(s);
}

void App::deleteShape(Shape* s) {
	shapes.erase(std::remove(shapes.begin(), shapes.end(), s), shapes.end());
}

bool App::isOnCanvas(Vector2 * point)
{
	Vector2* tl, *br;
	tl = canvas->getPoints().at(0);
	br = canvas->getPoints().at(2);

	return tl->x < point->x && br->x > point->x &&
		tl->y < point->y && br->y > point->y;
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

std::vector<Shape*> getShapesAtPointMacro(std::vector<Shape*> shapes, Vector2* point) {
	std::vector<Shape*> result = std::vector<Shape*>();
	for (auto s : shapes) {
		VisitorPoint* v = new VisitorPoint(point);
		s->accept(v);
		if (v->isContained())
			result.push_back(s);

		delete v;
	}

	return result;
}

std::vector<Shape*> App::getShapesAtPoint(Vector2 * point)
{
	return getShapesAtPointMacro(shapes, point);
}

bool App::isOnToolbar(Vector2 * point)
{
	return getShapesAtPointMacro(uiElements, point).size() > 0;
}