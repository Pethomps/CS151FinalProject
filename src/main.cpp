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

    Background gameBackground;
    gameBackground.loadFile("assets/Images/Background2.png", window);

    sf::Clock clock;

    Weapon gun(sf::Vector2f(60.f, 500.f), 500.f);
    Target target(600.f, 300.f, 30.f);

    Play play;

    // Timer for shooting loop, (we can make it a classlater on)
    sf::Clock roundClock;
    float roundTime = 30.f; // 30 sec

    bool bulletExists = false;
    Bullet bullet(sf::Vector2f(0.f, 0.f), sf::Vector2f(0.f, 0.f), 0.f);

    // Use current time as seed for random generator
    srand(time(0));

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

            /* Passes event to each button which checks if it was clicked.
                This can be done within a class; maybe Game or Play.
                Play makes sense to me, but the Cherry game does it in Game.
            */
            State state = play.handleInput(event, window);
            if (state != cont) {
                switch (state)
                {
                    case welcome:   // Quit ("Give Up") button pressed
                        //std::cout<<"Game::handleInput case welcome" <<std::endl;
                        // state = Welcome.handleInput(event, window);
                        break;
                    case game:      // Restart button pressed
                        //std::cout<<"Game::handleInput case game" <<std::endl;
                        // state = game.handleInput(event, window);
                        break;
                    case results:   // Results ("Scores") button pressed
                        //std::cout<<"Game::handleInput case result" <<std::endl;
                        // state=gameover.handleInput(event, window);
                        break;
                    // case quit:   // I don't think we need a "close the whole window" button, during the game
                    //     //std::cout<<"Game::handleInput case quit" <<std::endl;
                    //     window.close();
                    //     break;       
                    default:        // catches everything else; continues game
                        state=cont;
                        break;
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

        gameBackground.draw(window);
        gun.render(window);

        if (bulletExists)
        {
            bullet.render(window);
        }

        target.render(window);
        play.render(window);

        window.display();
    }
    
    return 0;
}