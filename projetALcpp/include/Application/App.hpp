#ifndef APP_HPP
#define APP_HPP

#include <Factories/IApiFactory.hpp>

class App {
public:
	App(IApiFactory* factory);
	void run();

private:
	IDrawingApi* drawingApi;
	IRenderingApi* renderingApi;

};

#endif // !APP_HPP
