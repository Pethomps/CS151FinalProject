/**
 * @file results.h
 * @author Target Acquisition Group
 * @brief Results class handles game-score and display.
 * 
 */

#ifndef RESULTS_H
#define RESULTS_H

#include "../header/button.h"
#include "../header/states.h"
#include "background.h"


class Results
{
    public:
        Results();
        State handleInput(sf::Event& e, sf::RenderWindow& window);
        void update();
        void render(sf::RenderWindow& window);
        void setScore(int score);

    private:
        sf::Text mTitle;
        sf::Text mYourScoreText;
        sf::Text mHighScoresText;
        sf::Font mFont;

        Button mMainMenu;
        Button mPlayAgain;  
        Button mExit;

        Background mBackground;

};

#endif