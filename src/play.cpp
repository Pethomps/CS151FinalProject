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
    mFrame.setSize(sf::Vector2f(800,600));
    mFrame.setPosition(sf::Vector2f(0,0));
    mFrame.setOutlineColor(sf::Color::Black);
    mFrame.setOutlineThickness(5);
    mFrame.setFillColor(sf::Color::Transparent);
    
    // Button mRestart;  
    mRestart.setPosition(sf::Vector2f(400,575));
    mRestart.setSize(sf::Vector2f(120,40));
    mRestart.setText("Restart");
    mRestart.setColorTextNormal(sf::Color::Black);
    mRestart.setColorTextHover(sf::Color::Red);

    // Button mResults;
    mResults.setPosition(sf::Vector2f(730,575));
    mResults.setSize(sf::Vector2f(120,40));
    mResults.setText("Scores");
    mResults.setColorTextNormal(sf::Color::Black);
    mResults.setColorTextHover(sf::Color::Red);

    // Button mQuit;
    mQuit.setPosition(sf::Vector2f(75,575));
    mQuit.setSize(sf::Vector2f(120,40));
    mQuit.setText("Give up");
    mQuit.setColorTextNormal(sf::Color::Black);
    mQuit.setColorTextHover(sf::Color::Red);}

/**
 * @brief Checks if a button was pressed, otherwise continues the game
 * 
 * @param e 
 * @param window 
 * @return State 
 */
State Play::handleInput(sf::Event &e, sf::RenderWindow &window)
{
    // quit, welcome, game, results

    // During the game, I find it unnecessary to have a button to close the whole window 
    // if (mQuit.handleInput(e, window)) {
    //     std::cout<<"---Play handleInput()--- QUIT"<<std::endl;
    //     return quit;
    // }

    // Return to welcome screen
    if (mQuit.handleInput(e, window)) {
        std::cout<<"---Play handleInput()--- WELCOME"<<std::endl;
        return welcome;
    }

    // Reset entire game (score, target, weapon, bullet)
    if (mRestart.handleInput(e, window)) {
        std::cout<<"---Play handleInput()--- RESTART"<<std::endl;
        return game;
    }

    // Results screen
    if (mResults.handleInput(e, window)) {
        std::cout<<"---Play handleInput()--- RESULTS"<<std::endl;
        return results;
    }

    // no Button pressed
    return cont;
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
    mTarget.render(window);
    mPlay.render(window);
    
}