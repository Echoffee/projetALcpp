#include <Application/App.hpp>

App::App(IApiFactory* factory)
{
	this->drawingApi = factory->createDrawingApi();
	this->renderingApi = factory->createRenderingApi();
}

void App::run()
{
	//TODO
}
