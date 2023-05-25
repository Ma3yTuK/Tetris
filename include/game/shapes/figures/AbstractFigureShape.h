#ifndef ABSTRACTFIGURESHAPE_H
#define ABSTRACTFIGURESHAPE_H

class AbstractFigureShape;

#include "game/shapes/AbstractShape.h"
#include "game/shapes/NotActiveShape.h"

class AbstractFigureShape : public AbstractShape
{
protected:
    virtual TetrisLayout combineWith(TetrisLayout otherLayout) const = 0;
    virtual bool interfireWith(const TetrisLayout& otherLayout) const = 0;
public:
    virtual void rotateRight() = 0;
    virtual void rotateLeft() = 0;
    virtual void moveRight() = 0;
    virtual void moveLeft() = 0;
    virtual void moveTop() = 0;
    virtual void moveBot() = 0;
    virtual TetrisLayout getLayout() const override = 0;

    friend class NotActiveShape;
};

#endif // ABSTRACTFIGURESHAPE_H
