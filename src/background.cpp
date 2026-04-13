/**
 * @file background.cpp
 * @author Pamela Thompson
 * @brief Implements Background class.
 * 
 * @date 2026-04-10
 * 
 */
#include "../header/background.h"

Background::Background()
{

}

void Background::loadFile(const std::string& pngName, sf::RenderWindow& window)
{
    if (!mTexture.loadFromFile(pngName))
    {
        std::cout<<"Error opening texture file\n";
        exit(1);
    }

    // Load texture to sprite
    mSprite.setTexture(mTexture);

    // Fit png to window size
    double sizeX = window.getSize().x / (double)mTexture.getSize().x;
    double sizeY = window.getSize().y / (double)mTexture.getSize().y;

    mSprite.setScale(sizeX, sizeY);
    
}

void Background::draw(sf::RenderWindow& window)
{
    window.draw(mSprite);
}