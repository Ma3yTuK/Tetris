#include "game/Game.h"
#include <random>

bool Game::tick()
{
    std::shared_ptr<AbstractFigureShape> activeFigure = cachedFigures.front();
    activeFigure->moveBot();
    if (notActiveShape.interfireWith(*activeFigure))
    {
        cachedFigures.pop_front();
        activeFigure->moveTop();
        if (!notActiveShape.combineWith(*activeFigure))
            return false;
        cachedFigures.push_back(FigurePtr(figureCreators[rand()%figureCreators.size()](notActiveShape.getHeight(), notActiveShape.getWidth(), colors[rand()%colors.size()])));
        score.figures++;
        score.lines += notActiveShape.removeFullLines();
    }
    score.ticks++;
    return true;
}

void Game::removeColor(const int& color)
{
    for (auto it = colors.begin(); it != colors.end(); it++)
    {
        if (*it == color)
        {
            colors.erase(it);
            return;
        }
    }
}

void Game::removeFigureType(const TetrisLayout& figureType)
{
    for (auto it = figureCreators.begin(); it != figureCreators.end(); it++)
    {
        if ((*it)(notActiveShape.getHeight(), notActiveShape.getWidth(), 1)->getLayout() == figureType)
        {
            figureCreators.erase(it);
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

std::vector<TetrisLayout> Game::getCachedFigures()
{
    std::vector<TetrisLayout> result;
    for (int i = 0; i < cachedFigures.size(); i++)
        result.push_back(cachedFigures[i]->getLayout());
    return result;
}

void Game::prepare()
{
    while (cachedFigures.size() > cacheSize)
        cachedFigures.pop_front();
    while (cachedFigures.size() < cacheSize)
        cachedFigures.push_back(FigurePtr(figureCreators[rand()%figureCreators.size()](notActiveShape.getHeight(), notActiveShape.getWidth(), colors[rand()%colors.size()])));
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
