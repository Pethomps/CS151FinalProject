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

void Background::loadFile(const std::string& pngName)
{
    if (!mTexture.loadFromFile(pngName))
    {
        std::cout<<"Error opening texture file\n";
        exit(1);
    }

    // Load texture to sprite
    mSprite.setTexture(mTexture);
}

void Background::resizePic(sf::Vector2u windowSize)
{
    // Fit png to window size
    sf::Vector2u textureSize = mTexture.getSize();
    
    float sizeX = static_cast<float>(windowSize.x) / textureSize.x;
    float sizeY = static_cast<float>(windowSize.y) / textureSize.y;
    
    mSprite.setScale(sizeX, sizeY);
}

void Background::draw(sf::RenderWindow& window)
{
    resizePic(window.getSize());
    window.draw(mSprite);
}