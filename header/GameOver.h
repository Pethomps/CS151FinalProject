/**
 * @file gameOver.h
 * @author Target Acquisition Group
 * @brief GameOver class handles the end-of-game.
 * @version 0.1
 * @date 2026-04-16
 * 
 */

#ifndef GAMEOVER_H
#define GAMEOVER_H
#include <iostream>
#include "../header/background.h"
#include "../header/states.h"
#include "../header/button.h"
#include <SFML/Graphics.hpp>

class GameOver
{
public:
    GameOver();
    ~GameOver(){};
    GameOver(sf::RenderWindow& window);
    void resize(sf::RenderWindow& window);
    void render(sf::RenderWindow& window);
    State handleInput(sf::Event& e, sf::RenderWindow& window);

private:
    Background mBackground;
    sf::Texture mTexture; //background image
    sf::Sprite mSprite;

    sf::Text mTitle;
    sf::Text mPlayAgain;
    sf::Font mFont;
    sf::Font mFontPlay;

    // Button mPlayAgain;
    // Button mViewResults;
    // Button mExit;

};


#endif