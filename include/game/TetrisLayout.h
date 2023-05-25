#ifndef TETRISLAYOUT_H
#define TETRISLAYOUT_H

class TetrisLayout;

#include <array>

class TetrisLayout
{
protected:
    const int height;
    const int width;
    int** layout;

public:
    TetrisLayout(int height, int width);
    TetrisLayout(const TetrisLayout& obj);
    TetrisLayout(std::initializer_list<std::initializer_list<int>> obj);
    int getWidth() const { return width; }
    int getHeight() const { return height; }
    void removeRowWithShift(int rowIndex);
    void reset();
    int& operator()(int x, int y);
    const int& operator()(int x, int y) const;
    void operator=(const TetrisLayout& obj);
    bool operator==(const TetrisLayout& obj);
    ~TetrisLayout();
};

#endif // TETRISLAYOUT_H
