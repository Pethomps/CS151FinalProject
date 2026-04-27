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
    mBackground.loadFile("../assets/Images/GameOver.png", window);
    
    // Title
    mFont.loadFromFile("../assets/Fonts/Gameplay.ttf");
    mTitle.setFont(mFont);
    mTitle.setString("GAME OVER");
    mTitle.setCharacterSize(75);
    mTitle.setOutlineThickness(2);
    mTitle.setOutlineColor(sf::Color(15, 86, 143));
    mTitle.setFillColor(sf::Color(205, 223, 237));


    // Play again text
    //mFontPlay.loadFromFile("assets/Fonts/VintageCharm-Regular.otf");
    mPlayAgain.setFont(mFont);
    mPlayAgain.setString("Press enter to play again");
    mPlayAgain.setCharacterSize(20);
    mPlayAgain.setFillColor(sf::Color(2, 70, 105));

    resize(window);
     
}

void GameOver::resize(sf::RenderWindow& window)
{
    mBackground.resizePic(window.getSize());

    float center = window.getSize().x / 2;

    // Title
    sf::FloatRect bounds = mTitle.getLocalBounds();
    mTitle.setOrigin(bounds.width / 2.f, bounds.height /2.f);
    mTitle.setPosition(center, window.getSize().y * 0.3f);

    // PLay Again
    bounds = mPlayAgain.getLocalBounds();
    mPlayAgain.setOrigin(bounds.width / 2.f, bounds.height /2.f);
    mPlayAgain.setPosition(center, window.getSize().y * 0.5f);
}

void GameOver::draw(sf::RenderWindow& window)
{
    mBackground.draw(window);
    window.draw(mTitle);

    //Blinking text
    static sf::Clock clock;
    float timeF = clock.getElapsedTime().asSeconds();

    int time = static_cast<int>(timeF * 1);
    if(time % 2 == 0)
    {
        window.draw(mPlayAgain);
    }
}