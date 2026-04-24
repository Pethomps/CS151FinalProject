/**
 * @file play.cpp
 * @author Target Acquistion Group
 * @brief Class `Play` creates the game screen and handles leaving the game.
 * 
 */
#include "../header/play.h"
#include "../header/target.h"


/**
 * @brief Default constructor for Play object
 *          - sets frame and target boundary (based on frame)
 *          - sets buttons: restart, results, quit
 */
Play::Play()
{
    // sf::RectangleShape mFrame;
    mFrame.setSize(sf::Vector2f(760,540));
    mFrame.setPosition(sf::Vector2f(20,20));
    mFrame.setOutlineColor(sf::Color::White);
    mFrame.setOutlineThickness(5);
    mFrame.setFillColor(sf::Color::Transparent);
    
    // Button mRestart;  
    mRestart.setPosition(sf::Vector2f(420,450));
    mRestart.setSize(sf::Vector2f(60,20));
    mRestart.setText("Restart");
    mRestart.setColorTextNormal(sf::Color::Red);

    // Button mResults;
    mResults.setPosition(sf::Vector2f(580,450));
    mResults.setSize(sf::Vector2f(60,20));
    mResults.setText("Scores");
    mResults.setColorTextNormal(sf::Color::Red);

    // Button mQuit;
    mQuit.setPosition(sf::Vector2f(40,570));
    mQuit.setSize(sf::Vector2f(60,20));
    mQuit.setText("Give up");
    mQuit.setColorTextNormal(sf::Color::Red);
}

/**
 * @brief Checks if a button was pressed, otherwise continues the game
 * 
 * @param e 
 * @param window 
 * @return State 
 */
State Play::handleInput(sf::Event &e, sf::RenderWindow &window)
{
    std::cout<<"---Play handleInput()--- e.type:"<<e.type<<std::endl;
    // quit, welcome, game, results
    if (mQuit.handleInput(e, window)) {
        return quit;
    }
    if (mQuit.handleInput(e, window)) {
        return welcome;
    }
    if (mRestart.handleInput(e, window)) {
        return game;
    }
    if (mResults.handleInput(e, window)) {
        return results;
    }
    // no Button pressed
    return game;
}

/**
 * @brief Updates each button and the target based on user input
 * 
 * @param elapsedTime 
 * @param window 
 */
void Play::update(double elapsedTime, sf::RenderWindow &window)
{
    // Target mTarget;Button mRestart;Button mResults;Button mQuit;
    // mTarget.update(elapsedTime, window);
    mRestart.update();
    mResults.update();
    mQuit.update();
}

/**
 * @brief Draws playable frame, target, and buttons.
 * 
 * @param window 
 */
void Play::render(sf::RenderWindow &window)
{
    // std::cout<<"---Play render()---"<<std::endl;
    // mTarget.render(window);
    window.draw(mFrame);
    window.draw(mRestart);
    window.draw(mResults);
    window.draw(mQuit);
}