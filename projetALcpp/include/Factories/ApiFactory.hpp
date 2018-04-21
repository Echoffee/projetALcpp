#ifndef IAPIFACTORY_HPP
#define IAPIFACTORY_HPP

#include<Bridges/DrawingApi.hpp>
#include<Bridges/UIApi.hpp>


class ApiFactory {
public:
	virtual DrawingApi* createDrawingApi() = 0;
	virtual UIApi* createRenderingApi() = 0;
};

#endif // !IAPIFACTORY_HPP
