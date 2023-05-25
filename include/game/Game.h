#ifndef GAME_H
#define GAME_H

class Game;

#include "game/shapes/figures/AbstractFigureShape.h"
#include "game/shapes/NotActiveShape.h"
#include "game/GameScore.h"
#include <vector>
#include <memory>
#include <queue>
#include <functional>

class Game
{
public:
    using FigurePtr = std::shared_ptr<AbstractFigureShape>;
    using FigureCreator = std::function<AbstractFigureShape*(int height, int width, int color)>;

protected:
    std::vector<FigureCreator> figureCreators;
    std::vector<int> colors;
    int cacheSize;
    NotActiveShape notActiveShape;
    GameScore score;
    std::queue<FigurePtr> cachedFigures;
    bool tick();

public:
    Game(int height, int width, std::vector<FigureCreator> figureCreators, std::vector<int> colors, int cacheSize = 1) :
        figureCreators(figureCreators), colors(colors), cacheSize(cacheSize), notActiveShape(height, width), score(), cachedFigures() {}
    void addColor(int color) { colors.push_back(color); }
    void removeColor(int color);
    void addFigureType(const FigureCreator& figureCreator) { figureCreators.push_back(figureCreator); }
    void removeFigureType(const AbstractFigureShape& figure);
    void setCacheSize(int size) { cacheSize = size; }
    GameScore getScore() { return score; }
    std::queue<FigurePtr> getCachedFigures() { return cachedFigures; }
    TetrisLayout getCurrentLayout();
    void prepare();
    bool rotateRight();
    bool rotateLeft();
    bool moveRight();
    bool moveLeft();
};

#endif // GAME_H
