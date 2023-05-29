#include "game/shapes/figures/TetrisFigureShape.h"

const int TetrisFigureShape::STATE_COUNT = 4;

std::pair<int, int> TetrisFigureShape::map(const int& iToMap, const int& jToMap) const
{
    switch (state)
    {
        case 0:
        {
            return std::pair(i + iToMap - centerI, j + jToMap - centerJ);
        }
        case 1:
        {
            return std::pair(i + jToMap - centerJ, j - iToMap + centerI);
        }
        case 2:
        {
            return std::pair(i - iToMap + centerI, j - jToMap + centerJ);
        }
        default:
        {
            return std::pair(i - jToMap + centerJ, j + iToMap - centerI);
        }
    }
}

bool TetrisFigureShape::combineWith(TetrisLayout& otherLayout) const
{
    bool result = true;
    for (int i = 0; i < layout.getHeight(); i++)
    {
        for (int j = 0; j < layout.getWidth(); j++)
        {
            auto point = map(i, j);
            if (point.first >= 0)
                otherLayout(point.first, point.second) = layout(i, j);
            else
                result = false;
        }
    }
    return result;
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
