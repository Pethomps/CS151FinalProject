/**
 * @file GameOver.cpp
 * @author Target Acquisition Group
 * @brief 
 * 
 * @date 2026-04-16
 * 
 */

#include "../header/GameOver.h"

GameOver::GameOver()
{

}

GameOver::GameOver(sf::RenderWindow& window) 
{
    // game over background
    mBackground.loadFile("assets/Images/Background2.png");
    
    // Title
    mFont.loadFromFile("assets/Fonts/Gameplay.ttf");
    mTitle.setFont(mFont);
    mTitle.setString("GAME OVER");
    mTitle.setCharacterSize(77);
    mTitle.setOutlineThickness(3);
    mTitle.setOutlineColor(sf::Color(254, 208, 109));
    mTitle.setFillColor(sf::Color(249, 235, 205));


    // View results text
    mPlayAgain.setFont(mFont);
    mPlayAgain.setString("Press enter to view results");
    mPlayAgain.setCharacterSize(22);
    mPlayAgain.setFillColor(sf::Color(249, 235, 205));

    resize(window);
     
}

void GameOver::resize(sf::RenderWindow& window)
{
    mBackground.resizePic(window.getSize());

    float center = window.getSize().x / 2;

    // Title
    sf::FloatRect bounds = mTitle.getLocalBounds();
    mTitle.setOrigin(bounds.width / 2.f, bounds.height /2.f);
    mTitle.setPosition(center, window.getSize().y * 0.4f);

    // PLay Again
    bounds = mPlayAgain.getLocalBounds();
    mPlayAgain.setOrigin(bounds.width / 2.f, bounds.height /2.f);
    mPlayAgain.setPosition(center, window.getSize().y * 0.7f);
}

void GameOver::render(sf::RenderWindow& window)
{
    mBackground.draw(window);
    window.draw(mTitle);
    window.draw(mPlayAgain);
}

State GameOver::handleInput(sf::Event& e, sf::RenderWindow& window)
{
    if(e.type == sf::Event::KeyPressed)
    {
        if(e.key.code == sf::Keyboard::Enter)
        {
            return results;
        }
    }

    return gameover;
}