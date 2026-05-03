/**
 * @file main.cpp
 * @author Adia Hite, Jonathan Jones, Ray Louthan, Pamela Thompson
 * @brief 
 * @version 0.1
 * @date 2026-03-23
 * 
*/
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../header/game.h"
#include "../header/background.h"
#include "../header/button.h"
#include "../header/target.h"
#include "../header/weapon.h"
#include "../header/play.h"



int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Single Bullet Test");
    window.setFramerateLimit(60);
    sf::Clock clock;
    
    while (window.isOpen())
    {
        Game game;
        game.render(window);
        float dt = clock.restart().asSeconds();
        game.handleInput(window);
        game.update(dt, window);
        game.render(window);
            
    }
    
    return 0;
}

