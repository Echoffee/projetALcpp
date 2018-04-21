#ifndef VISITOR_TRANSLATE_HPP
#define VISITOR_TRANSLATE_HPP

#include <Visitor/IVisitor.hpp>

class VisitorTranslate : public IVisitor {
private:
	Vector2* direction;
public:
	// IVisitor
	VisitorTranslate(Vector2* direction);

	void visit(AbsShape* shape) override;

	void visit(CompositeShape* shapes) override;

};

#endif
