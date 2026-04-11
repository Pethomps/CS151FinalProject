/**
 * @file main.cpp
 * @author Adia Hite, Jonathan Jones, Ray Louthan, Pamela Thompson
 * @brief 
 * @version 0.1
 * @date 2026-03-23
 * 
 * @copyright Copyright (c) 2026
 * 
 */
#include "../header/game.h"
#include "../header/background.h"
#include "../header/button.h"
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    // Testing backgorund class
    sf::RenderWindow window(sf::VideoMode(800, 600), "Background Class Test");

    Background background;
    background.loadFile("Images/Background/Background1.png", window);

    

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear();
        background.draw(window);
        window.display();
    }

    return 0;
}