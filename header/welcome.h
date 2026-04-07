#ifndef WELCOME_H
#define WELCOME_H
#include "states.h"
#include "button.h"

class Welcome
{
public:
    Welcome();
    State handleInput(sf::Event& e,  sf::RenderWindow& mWindow);
    void update();
    void render(sf::RenderWindow& mWindow);


private:
    sf::Text mRules;
    sf::Text mHeader;
    sf::Font mFont;
    Button mStart;  
};

#endif