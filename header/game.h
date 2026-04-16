#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>


class Game 
{
    void handleInput(sf::RenderWindow &mWindow);
    void update(double elapsedTime, sf::RenderWindow &mWindow);
    void render(sf::RenderWindow &mWindow);
};
#endif