#include "../header/welcome.h"

Welcome::Welcome()
{
    // load font
    if(!mFont.loadFromFile("assets/Fonts/VintageCharm-Regular.otf")){
        std::cout<<"Welcome: error opening .otf file\n"; // use throw instead?
        exit(1);
    }

    mHeader.setFont(mFont);
    mHeader.setCharacterSize(20);
    mHeader.setString("Game test");

    mRules.setText("Rules");
    mRules.setPosition({400,300});
    mRules.setSize({80,80});
    mRules.setColorTextNormal(sf::Color::Blue);

    mStart.setText("start");
    mStart.setPosition({250, 300});
    mStart.setSize({80, 80});
    mStart.setColorTextNormal(sf::Color::Blue);
    //mStart.setColor(sf::Color(255,255,255));
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
    window.draw(mHeader);
    window.draw(mRules);
    window.draw(mStart);
}