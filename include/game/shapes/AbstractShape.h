#ifndef BASICSHAPE_H
#define BASICSHAPE_H

class AbstractShape;

#include "game/TetrisLayout.h"

class AbstractShape
{
public:
    virtual TetrisLayout getLayout() const = 0;
};

#endif // BASICSHAPE_H
