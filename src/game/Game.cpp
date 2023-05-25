#include "game/Game.h"
#include <random>

bool Game::tick()
{
    std::shared_ptr<AbstractFigureShape> activeFigure = cachedFigures.front();
    activeFigure->moveBot();
    if (notActiveShape.interfireWith(*activeFigure))
    {
        cachedFigures.pop();
        activeFigure->moveTop();
        if (!notActiveShape.combineWith(*activeFigure))
            return false;
        cachedFigures.push(FigurePtr(figureCreators[rand()%figureCreators.size()](notActiveShape.getHeight(), notActiveShape.getWidth(), colors[rand()%colors.size()])));
        score.figures++;
        score.lines += notActiveShape.removeFullLines();
    }
    score.ticks++;
    return true;
}

void Game::removeColor(int color)
{
    for (auto it = colors.begin(); it != colors.end(); it++)
    {
        if (*it = color)
        {
            colors.erase(it);
            return;
        }
    }
}

TetrisLayout Game::getCurrentLayout()
{
    TetrisLayout result = notActiveShape.getLayout();
    cachedFigures.front()->combineWith(result);
    return result;
}

void Game::prepare()
{
    while (cachedFigures.size() > cacheSize)
        cachedFigures.pop();
    while (cachedFigures.size() < cacheSize)
        cachedFigures.push(FigurePtr(figureCreators[rand()%figureCreators.size()](notActiveShape.getHeight(), notActiveShape.getWidth(), colors[rand()%colors.size()])));
    notActiveShape.reset();
    score.figures = 0;
    score.lines = 0;
    score.ticks = 0;
}

bool Game::rotateRight()
{
    std::shared_ptr<AbstractFigureShape> activeFigure = cachedFigures.front();
    activeFigure->rotateRight();
    if (!notActiveShape.interfireWith(*activeFigure))
        return true;
    activeFigure->rotateLeft();
    return false;
}

bool Game::rotateLeft()
{
    std::shared_ptr<AbstractFigureShape> activeFigure = cachedFigures.front();
    activeFigure->rotateLeft();
    if (!notActiveShape.interfireWith(*activeFigure))
        return true;
    activeFigure->rotateRight();
    return false;
}

bool Game::moveRight()
{
    std::shared_ptr<AbstractFigureShape> activeFigure = cachedFigures.front();
    activeFigure->moveRight();
    if (!notActiveShape.interfireWith(*activeFigure))
        return true;
    activeFigure->moveLeft();
    return false;
}

bool Game::moveLeft()
{
    std::shared_ptr<AbstractFigureShape> activeFigure = cachedFigures.front();
    activeFigure->moveLeft();
    if (!notActiveShape.interfireWith(*activeFigure))
        return true;
    activeFigure->moveRight();
    return false;
}
