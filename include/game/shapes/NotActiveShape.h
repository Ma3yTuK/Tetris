#ifndef NOTACTIVESHAPE_H
#define NOTACTIVESHAPE_H

class NotActiveShape;

#include "game/shapes/AbstractShape.h"
#include "game/shapes/figures/AbstractFigureShape.h"

class NotActiveShape : public AbstractShape
{
protected:
    TetrisLayout layout;

public:
    NotActiveShape(int height, int width) : layout(height, width) {}
    int getHeight() { return layout.getHeight(); }
    int getWidth() { return layout.getWidth(); }
    bool combineWith(const AbstractFigureShape& figure);
    bool interfireWith(const AbstractFigureShape& figure);
    void reset() { layout.reset(); }
    int removeFullLines();
    virtual TetrisLayout getLayout() const override { return layout; }
};

#endif // NOTACTIVESHAPE_H
