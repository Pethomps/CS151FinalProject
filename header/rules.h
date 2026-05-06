#ifndef RULES_H
#define RULES_H
#include "states.h"
#include "button.h"
#include "background.h"

class Rules
{
public:
    Rules();
    State handleInput(sf::Event& e,  sf::RenderWindow& mWindow);
    void update();
    void render(sf::RenderWindow& mWindow);


private:
    sf::Font mFont;
    sf::Text mHeader[2];
    sf::Text mRuleTxt[4];
    Button Back;  
    Background mBackground;
};

#endif