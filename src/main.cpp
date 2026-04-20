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
#include "../header/target.h"
#include "../header/weapon.h"


int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Single Bullet Test");
    window.setFramerateLimit(60);

    sf::Texture backgroundTexture;

   if (!backgroundTexture.loadFromFile("Images/Background/Background1.png"))
    {
        std::cout << "Failed to load background.png\n";
        return 1;
    }

    sf::Sprite backgroundSprite(backgroundTexture);

    backgroundSprite.setScale(
        static_cast<float>(window.getSize().x) / backgroundTexture.getSize().x,
        static_cast<float>(window.getSize().y) / backgroundTexture.getSize().y);

    sf::Clock clock;

    Weapon gun(sf::Vector2f(60.f, 500.f), 500.f);
    Target target(600.f, 300.f, 30.f);

    bool bulletExists = false;
    Bullet bullet(sf::Vector2f(0.f, 0.f), sf::Vector2f(0.f, 0.f), 0.f);

    while (window.isOpen())
    {
        float dt = clock.restart().asSeconds();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePixel = sf::Mouse::getPosition(window);
                    sf::Vector2f mouseWorld = window.mapPixelToCoords(mousePixel);

                    bullet = gun.fireAt(mouseWorld);
                    bulletExists = true;

                    std::cout << "Bullet fired" << std::endl;
                }
            }
        }

        if (bulletExists)
        {
            if (bullet.isAlive())
            {
                bullet.update(dt);

                if (target.isAlive())
                {
                    if (bullet.getBounds().intersects(target.getBounds()))
                    {
                        bullet.destroy();
                        target.destroy();
                        std::cout << "Target hit" << std::endl;
                    }
                }
            }
        }

        window.clear();

        gun.render(window);
        window.draw(backgroundSprite);

        if (bulletExists)
        {
            bullet.render(window);
        }

        target.render(window);

        window.display();
    }

    // Testing backgorund class
    // sf::RenderWindow window(sf::VideoMode(800, 600), "Background Class Test");

    // Background background;
    // background.loadFile("Images/Background/Background1.png", window);

    

    // while(window.isOpen())
    // {
    //     sf::Event event;
    //     while(window.pollEvent(event))
    //     {
    //         if(event.type == sf::Event::Closed)
    //         {
    //             window.close();
    //         }
    //     }

    //     window.clear();
    //     background.draw(window);
    //     window.display();
    // }

    return 0;
}