#include "game/shapes/figures/TetrisFigureShape.h"

const int TetrisFigureShape::STATE_COUNT = 4;

std::pair<int, int> TetrisFigureShape::map(int iToMap, int jToMap) const
{
    iToMap -= centerI;
    jToMap -= centerJ;
    switch (state)
    {
        case 0:
        {
            return std::pair(i + iToMap, j + jToMap);
        }
        case 1:
        {
            return std::pair(i + jToMap, j - iToMap);
        }
        case 2:
        {
            return std::pair(i - iToMap, j - jToMap);
        }
        default:
        {
            return std::pair(i - jToMap, j + iToMap);
        }
    }
}

TetrisLayout TetrisFigureShape::combineWith(TetrisLayout otherLayout) const
{
    for (int i = 0; i < layout.getHeight(); i++)
    {
        for (int j = 0; j < layout.getWidth(); j++)
        {
            auto point = map(i, j);
            if (point.first >= 0)
                otherLayout(point.first, point.second) = layout(i, j);
        }
    }
    return otherLayout;
}

bool TetrisFigureShape::interfireWith(const TetrisLayout& otherLayout) const
{
    for (int i = 0; i < layout.getHeight(); i++)
    {
        for (int j = 0; j < layout.getWidth(); j++)
        {
            auto point = map(i, j);
            if (point.first >= otherLayout.getHeight() || point.second >= otherLayout.getWidth() || point.second < 0 || otherLayout(point.first, point.second))
                return true;
        }
    }
    return false;
}
