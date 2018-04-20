#pragma once
#ifndef MEMENTO_RECTANGLE_HPP
#define MEMENTO_RECTANGLE_HPP

#include "IMemento.hpp"
#include <vector>

class MementoRectangle : public IMemento {
	friend std::vector<int> points;


};


#endif
