#ifndef PLAY_H
#define PLAY_H
#include "states.h"
#include "button.h"
#include "target.h"

class Play
{
    public:
        Play();
        State handleInput(sf::Event& e,  sf::RenderWindow& window);
        void update(double elapsedTime, sf::RenderWindow& window);
        void render(sf::RenderWindow& window);


    private:
        Button mRestart;
        Button mResults;
        Button mQuit;
        sf::RectangleShape mFrame;
};

#endif