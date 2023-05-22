#ifndef TETRISLAYOUT_H
#define TETRISLAYOUT_H

class TetrisLayout
{
private:
    int height;
    int width;
    int** layout;

public:
    TetrisLayout(int height, int width);
    TetrisLayout(const TetrisLayout& obj);
    int getWidth() const { return width; }
    int getHeight() const { return height; }
    TetrisLayout operator|(const TetrisLayout& secondLayout);
    int& operator()(int x, int y);
    ~TetrisLayout();
};

#endif // TETRISLAYOUT_H
