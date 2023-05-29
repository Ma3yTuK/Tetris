#include "game/shapes/NotActiveShape.h"

bool NotActiveShape::combineWith(const AbstractFigureShape& figure)
{
    return figure.combineWith(layout);
}
bool NotActiveShape::interfireWith(const AbstractFigureShape& figure)
{
    return figure.interfireWith(layout);
}

int NotActiveShape::removeFullLines()
{
    int result = 0;
    for (int i = 0; i < layout.getHeight(); i++)
    {
        int j;
        for (j = 0; j < layout.getWidth(); j++)
            if (!layout(i, j))
                break;
        if (j == layout.getWidth())
        {
            layout.removeRowWithShift(i);
            result++;
        }
    }
    return result;
}
