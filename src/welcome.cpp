#include "../header/welcome.h"

Welcome::Welcome()
{
    // load font
    if(mFont.loadFromFile("../assets/Fonts/VintageCharm-Regular.otf")){
        std::cout<<"Welcome: error opening .otf file\n"; // use throw instead?
        exit(1);
    }

    mHeader.setFont(mFont);
    mHeader.setCharacterSize(20);
    mHeader.setString("Game test");

    mRules.setFont(mFont);
    mRules.setCharacterSize(16);
    mRules.setString("rule\nrule\nrule\n");
    mRules.setPosition({10,30});

    mStart.setText("start");
    mStart.setPosition({580, 450});
    mStart.setSize({60, 20});
    mStart.setColorTextNormal(sf::Color::Blue);
    //mStart.setColor(sf::Color(255,255,255));
}
State Welcome::handleInput(sf::Event &e, sf::RenderWindow &window)
{
    if(mStart.handleInput(e,window))
    {
        return game; // return state to go to game if user selects button
    }
    return welcome; // else stay on welcome screen
}
void Welcome::update()
{
    mStart.update(); // update button
}
void Welcome::render(sf::RenderWindow &window)
{
    window.draw(mHeader);
    window.draw(mRules);
    window.draw(mStart);
}