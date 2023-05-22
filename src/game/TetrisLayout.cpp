#include "game/TetrisLayout.h"

TetrisLayout::TetrisLayout(int height, int width) : height(height), width(width)
{
    layout = new int*[height];
    for (int i = 0; i < height; i++)
        layout[i] = new int[width];
}

TetrisLayout::TetrisLayout(const TetrisLayout& obj) : TetrisLayout(obj.height, obj.width)
{
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            layout[i][j] = obj.layout[i][j];
}

TetrisLayout TetrisLayout::operator|(const TetrisLayout& secondLayout)
{
    TetrisLayout result(*this);
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            result(i, j) |= secondLayout(i, j);
    return result;
}

int& TetrisLayout::operator()(int x, int y)
{
    return layout[x][y];
}

TetrisLayout::~TetrisLayout()
{
    for (int i = 0; i < height; i++)
        delete[] layout[i];
    delete[] layout;
}
