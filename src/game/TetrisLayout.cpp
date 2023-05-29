#include "game/TetrisLayout.h"

TetrisLayout::TetrisLayout(const int& height, const int& width) : height(height), width(width)
{
    layout = new int*[height];
    for (int i = 0; i < height; i++)
        layout[i] = new int[width]();
}

TetrisLayout::TetrisLayout(const TetrisLayout& obj) : TetrisLayout(obj.height, obj.width)
{
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            layout[i][j] = obj.layout[i][j];
}

TetrisLayout::TetrisLayout(std::initializer_list<std::initializer_list<int>> obj) : TetrisLayout(obj.size(), data(obj)[0].size())
{
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            layout[i][j] = data(data(obj)[i])[j];
}

void TetrisLayout::removeRowWithShift(const int& rowIndex)
{
    int* tmp = layout[rowIndex];
    for (int i = rowIndex; i > 0; i--)
        layout[i] = layout[i-1];
    for (int j = 0; j < width; j++)
        tmp[j] = 0;
    layout[0] = tmp;
}

void TetrisLayout::reset()
{
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            layout[i][j] = 0;
}

int& TetrisLayout::operator()(const int& x, const int& y)
{
    return layout[x][y];
}

const int& TetrisLayout::operator()(const int& x, const int& y) const
{
    return layout[x][y];
}

void TetrisLayout::operator=(const TetrisLayout& obj)
{
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            layout[i][j] = obj.layout[i][j];
}

bool TetrisLayout::operator==(const TetrisLayout& obj)
{
    if (height != obj.height || width != obj.width)
        return false;
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            if ((bool)layout[i][j] != (bool)obj.layout[i][j])
                return false;
    return true;
}

TetrisLayout::~TetrisLayout()
{
    for (int i = 0; i < height; i++)
        delete[] layout[i];
    delete[] layout;
}
