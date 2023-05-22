#ifndef BASICSHAPE_H
#define BASICSHAPE_H

#include "game/TetrisLayout.h"

class BasicShape
{
public:
    virtual TetrisLayout getLayout() = 0;
};

#endif // BASICSHAPE_H
