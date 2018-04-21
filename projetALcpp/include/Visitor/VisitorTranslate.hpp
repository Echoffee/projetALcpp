#ifndef VISITOR_TRANSLATE_HPP
#define VISITOR_TRANSLATE_HPP

#include <Visitor/Visitor.hpp>

class VisitorTranslate : public Visitor {
private:
	Vector2* direction;
public:
	// Visitor
	VisitorTranslate(Vector2* direction);
	~VisitorTranslate();

	void visit(AbstractShape* shape) override;

	void visit(CompositeShape* shapes) override;

};

#endif
