#ifndef TETRISLAYOUT_H
#define TETRISLAYOUT_H

class TetrisLayout
{
private:
    int width;
    int height;
    int** layout;

public:
    TetrisLayout(int width, int height);
    int getWidth() const { return width; }
    int getHeight() const { return height; }
    TetrisLayout operator|(const TetrisLayout& secondLayout);
    int& operator()(int x, int y);
};

#endif // TETRISLAYOUT_H
