#ifndef MEMENTO_RECTANGLE_HPP
#define MEMENTO_RECTANGLE_HPP

#include <IMemento.hpp>
#include <vector>

class MementoRectangle : public IMemento {
	//friend <classe qui a acces aux privates>
private:
	std::vector<int> points;


};


#endif
