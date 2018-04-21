#ifndef HANDLERCLOSE_HPP
#define HANDLERCLOSE_HPP

#include <Events/Handler.hpp>

class HandlerClose : public Handler {
public:
	bool task(Event* e, Canvas* env);
};

#endif // !HANDLERCLOSE_HPP
