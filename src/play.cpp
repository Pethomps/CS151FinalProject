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
    mBulletExists = false;
    mScore = 0;
    mPlayClock.restart();
    mGunshotSound.loadSound("./assets/Audio/gunshot.wav");
    mPlayBackground.loadFile(mBackgroundPNG);

    /*
    *   Frame & Buttons
    */
    // sf::RectangleShape mFrame;
    mPlayFrame.setSize(sf::Vector2f(800,600));
    mPlayFrame.setPosition(sf::Vector2f(0,0));
    mPlayFrame.setOutlineColor(sf::Color::Black);
    mPlayFrame.setOutlineThickness(5);
    mPlayFrame.setFillColor(sf::Color::Transparent);
    // Button mRestart;  
    mPlayRestart.setPosition(sf::Vector2f(400,575));
    mPlayRestart.setSize(sf::Vector2f(120,40));
    mPlayRestart.setText("Restart");
    mPlayRestart.setColorTextNormal(sf::Color::Black);
    mPlayRestart.setColorTextHover(sf::Color::Red);
    // Button mResults;
    mPlayResults.setPosition(sf::Vector2f(730,575));
    mPlayResults.setSize(sf::Vector2f(120,40));
    mPlayResults.setText("Scores");
    mPlayResults.setColorTextNormal(sf::Color::Black);
    mPlayResults.setColorTextHover(sf::Color::Red);
    // Button mQuit;
    mPlayQuit.setPosition(sf::Vector2f(75,575));
    mPlayQuit.setSize(sf::Vector2f(120,40));
    mPlayQuit.setText("Give up");
    mPlayQuit.setColorTextNormal(sf::Color::Black);
    mPlayQuit.setColorTextHover(sf::Color::Red);
}

/**
 * @brief Checks if a button was pressed, otherwise continues the game
 * 
 * @param e 
 * @param window 
 * @return State 
 */
State Play::handleInput(sf::Event &event, sf::RenderWindow &window)
{
    /*
    *   Buttons (quit, welcome, game, results)
    */
    // Return to welcome screen
    if (mPlayQuit.handleInput(event, window)) 
    {
        return welcome;
    }
    // Reset entire game (score, target, weapon, bullet)
    if (mPlayRestart.handleInput(event, window)) 
    {
        reset();
        return game;
    }
    // Results screen
    if (mPlayResults.handleInput(event, window)) 
    {
        return results;
    }

    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            sf::Vector2i mousePixel = sf::Mouse::getPosition(window);
            sf::Vector2f mouseWorld = window.mapPixelToCoords(mousePixel);
            
            mBullet = mGun.fireAt(mouseWorld);
            mBulletExists = true;
            
            mGunshotSound.play();
        }
    }
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
    // Bullet
    if (mBulletExists)
    {
        if (mBullet.isAlive())
        {
            mBullet.update(elapsedTime);

            if (mTarget.isAlive())
            {
                if (mBulletExists && mTarget.isHit(mBullet.getBounds()))
                {
                    mBullet.destroy();
                    mBulletExists = false;
                    mScore++;
                }
            }
        }
    }
    // Target mTarget;Button mRestart;Button mResults;Button mQuit;
    mTarget.update(elapsedTime); 
    mPlayRestart.update();
    mPlayResults.update();
    mPlayQuit.update();
}

/**
 * @brief Draws playable frame, target, and buttons.
 * 
 * @param window 
 */
void Play::render(sf::RenderWindow &window)
{
    mPlayBackground.draw(window);
    mGun.render(window);
    if (mBulletExists)
    {
        mBullet.render(window);
    }
    mTarget.render(window);
    window.draw(mPlayFrame);
    window.draw(mPlayRestart);
    window.draw(mPlayResults);
    window.draw(mPlayQuit);
}

void Play::reset() 
{
    mScore = 0;
    mBulletExists = false;
    mPlayClock.restart();
    mTarget.reset(600.f, 300.f);
    std::cout<<"Game restarted"<<std::endl;
}