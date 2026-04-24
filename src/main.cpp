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
    sf::RenderWindow window(sf::VideoMode(800, 600), "Play Test");
    window.setFramerateLimit(60);

    sf::Texture backgroundTexture;

   if (!backgroundTexture.loadFromFile("assets/Images/Background1.png"))
    {
        std::cout << "Failed to load background.png\n";
        return 1;
    }

    sf::Sprite backgroundSprite(backgroundTexture);

    backgroundSprite.setScale(
        static_cast<float>(window.getSize().x) / backgroundTexture.getSize().x,
        static_cast<float>(window.getSize().y) / backgroundTexture.getSize().y);

    sf::Clock clock;

    Play play;

    Weapon gun(sf::Vector2f(60.f, 500.f), 500.f);
    Target target(600.f, 300.f, 30.f);
    
    bool bulletExists = false;
    Bullet bullet(sf::Vector2f(0.f, 0.f), sf::Vector2f(0.f, 0.f), 0.f);
    
    while (window.isOpen())
    {
        float dt = clock.restart().asSeconds();
        sf::Event event;

        // Window open
        while (window.pollEvent(event))
        {
            // Window close
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            
            // Mouse click
            if (event.type == sf::Event::MouseButtonPressed)
            {
                play.update(dt, window);
                play.handleInput(event, window);
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

        // Game Loop
        if(roundClock.getElapsedTime().asSeconds() >= roundTime)
        {
            std::cout << "GAME OVER \n";
            window.close(); // replace with game over screen
        }

        // Bullet update
        if (bulletExists)
        {
            if (bullet.isAlive())
            {
                bullet.update(dt);

                if (target.isAlive())
                {
                    if (bulletExists && target.isHit(bullet.getBounds()))
                    {
                        bullet.destroy();
                        bulletExists = false;

                        std::cout << "Target hit!\n";
                    }
                }
            }
        }

        target.update(dt);

        // Rendering
        window.clear();

        // SFML displays things by precedence: the last thing drawn/rendered will be on top. 
        window.draw(backgroundSprite);
        play.render(window);
        gun.render(window);

        if (bulletExists)
        {
            bullet.render(window);
        }

        target.render(window);

        window.display();
    }
    return 0;
}