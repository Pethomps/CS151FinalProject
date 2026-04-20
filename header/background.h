/**
 * @file background.h
 * @author Pamela Thompson
 * @brief Background class defined.
 *       - This class loads a background texture from a png file.
 *       -
 * 
 * @date 2026-04-10
 * 
 */

#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <iostream>
#include <SFML/Graphics.hpp>

class Background{
public:
    Background();
    ~Background(){};

    void loadFile(const std::string& pngName, sf::RenderWindow& window);
    void resizePic(sf::Vector2u windowSize);
    void draw(sf::RenderWindow& window);

private:
    sf::Texture mTexture;
    sf::Sprite mSprite;

};



#endif