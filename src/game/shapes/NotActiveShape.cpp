#include "game/shapes/NotActiveShape.h"

void NotActiveShape::combineWith(const AbstractFigureShape& figure)
{
    layout = figure.combineWith(layout);
}
bool NotActiveShape::interfireWith(const AbstractFigureShape& figure)
{
    return figure.interfireWith(layout);
}

void NotActiveShape::removeFullLines()
{
    for (int i = 0; i < layout.getHeight(); i++)
    {
        int j;
        for (j = 0; j < layout.getWidth(); j++)
            if (!layout(i, j))
                break;
        if (j == layout.getWidth())
            layout.removeRowWithShift(i);
    }
}
