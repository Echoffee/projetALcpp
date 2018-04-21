#ifndef IAPIFACTORY_HPP
#define IAPIFACTORY_HPP

#include<Bridges/IDrawingApi.hpp>
#include<Bridges/IRenderingApi.hpp>


class IApiFactory {
public:
	virtual IDrawingApi* createDrawingApi() = 0;
	virtual IRenderingApi* createRenderingApi() = 0;
};

#endif // !IAPIFACTORY_HPP
