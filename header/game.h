#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include "states.h"
#include "welcome.h"
#include "play.h"
#include "results.h"
#include "Music.h"
#include "Sound.h"
#include "GameOver.h"



class Game 
{
public:
    Game(sf::RenderWindow &window);
    ~Game(){}

    void handleInput(sf::RenderWindow &window);
    void update(double elapsedTime, sf::RenderWindow &window);
    void render(sf::RenderWindow &window);

private:
    State mGameState;
    Welcome mWelcomeScreen;
    Play mGame;
    Results mResults;
    GameOver mGameOver;
    Music mBackgroundMusic;
};
#endif