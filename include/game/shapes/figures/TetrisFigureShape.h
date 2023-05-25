#ifndef TETRISFIGURESHAPE_H
#define TETRISFIGURESHAPE_H

class TetrisFigureShape;

#include "game/shapes/figures/AbstractFigureShape.h"
#include <utility>

class TetrisFigureShape : AbstractFigureShape
{
protected:
    static const int STATE_COUNT;
    const TetrisLayout layout;
    const int centerI;
    const int centerJ;
    int i;
    int j;
    int state;
    std::pair<int, int> map(int iToMap, int jToMap) const;
    virtual TetrisLayout combineWith(TetrisLayout otherLayout) const override;
    virtual bool interfireWith(const TetrisLayout& otherLayout) const override;
public:
    TetrisFigureShape(TetrisLayout layout, int centerI, int centerJ, int i, int j) : layout(layout), centerI(centerI), centerJ(centerJ), i(i), j(j), state(0) {}
    virtual void rotateRight() override { state = (state + 1)%STATE_COUNT; }
    virtual void rotateLeft() override { state = (state + STATE_COUNT - 1)%STATE_COUNT; }
    virtual void moveRight() override { i++; }
    virtual void moveLeft() override { i--; }
    virtual void moveTop() override { j++; }
    virtual void moveBot() override { j--; }
    virtual TetrisLayout getLayout() const override { return layout; }
};

#endif // TETRISFIGURESHAPE_H
