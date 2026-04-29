#include "../header/welcome.h"
#include <iostream>

Welcome::Welcome()
{
    // load font
    if(!mFont.loadFromFile("assets/Fonts/VintageCharm-Regular.otf")){
        std::cout<<"Welcome: error opening .otf file\n"; // use throw instead?
        exit(1);
    }

    sf::FloatRect bounds = mHeader.getLocalBounds();
    mHeader.setOrigin((bounds.width/2),{bounds.height/2});
    mHeader.setFillColor(sf::Color(249,235,205));
    mHeader.setOutlineThickness(20);
    mHeader.setOutlineColor(sf::Color(254,208,109));
    mHeader.setFont(mFont);
    mHeader.setCharacterSize(125);
    mHeader.setString("DUCK\nHUNT");
    mHeader.setPosition({255,125});

    mRules.setText("Rules");
    mRules.setPosition({400,550});
    mRules.setSize({300,60});
    mRules.setColorTextNormal(sf::Color(249,235,205));
    mRules.setColorTextHover(sf::Color(254, 208, 109));
    mRules.setColor(sf::Color(254,208,109));

    mStart.setText("START!");
    mStart.setPosition({400, 450});
    mStart.setSize({350, 75});
    mStart.setColorTextNormal(sf::Color(249,235,205));
    mStart.setColorTextHover(sf::Color(254, 208, 109));
    mStart.setColor(sf::Color(254,208,109));
}
State Welcome::handleInput(sf::Event &e, sf::RenderWindow &window)
{
    if(mStart.handleInput(e,window))
    {
        return game; // return state to go to game if user selects button
    }
    else if(mRules.handleInput(e,window))
    {
        return rules;
    }
    else
        return welcome; // else stay on welcome screen
}
void Welcome::update()
{
    mStart.update(); // update button
    mRules.update();
}
void Welcome::render(sf::RenderWindow &window)
{
    mBackground.loadFile("assets/Images/welcomeScreen.png",window);
    mBackground.resizePic({800, 600});
    mBackground.draw(window);

    window.draw(mHeader);
    window.draw(mRules);
    window.draw(mStart);
}