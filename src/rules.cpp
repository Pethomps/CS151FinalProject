#include "../header/rules.h"

/**
 * @brief Construct a new Rules:: Rules object
 *        Assign values and construct private mem variables
 *
 */
Rules::Rules()
{
    // load font
    if (!mFont.loadFromFile("assets/Fonts/VintageCharm-Regular.otf"))
    {
        std::cout << "Rules: error opening .otf file\n"; // use throw instead?
        exit(1);
    }
    // load background
    mBackground.loadFile("assets/Images/Background1.png");
    mBackground.resizePic({800, 600});
    // header 1- "how to play"
    // place at top center
    sf::FloatRect bounds = mHeader[0].getLocalBounds();
    mHeader[0].setOrigin((bounds.width / 2), {bounds.height / 2});
    mHeader[0].setFillColor(sf::Color(249, 235, 205));
    mHeader[0].setOutlineThickness(20);
    mHeader[0].setOutlineColor(sf::Color(254, 208, 109));
    mHeader[0].setFont(mFont);
    mHeader[0].setCharacterSize(125);
    mHeader[0].setString("HOW TO PLAY");
    mHeader[0].setPosition({255, 125});
    // instruction 1 "left click to shoot"
    // instruction 2 "hit ducks with the bullet"
    // instruction 3 "each time you hit a duck, score goes up"
    // instruction 4 "scores will be saved and displayed at the end!"
    // header 2 - "have fun"
}

/**
 * @brief return main when user presses "esc", else return rules
 *
 * @param e
 * @param mWindow
 * @return State
 */
State Rules::handleInput(sf::Event &e, sf::RenderWindow &mWindow)
{
    if (e.type == sf::Event::KeyPressed)
    {
        if (e.key.code == sf::Keyboard::Escape)
        {
            // return welcome screen
            return welcome;
        }
    }

    return rules;
}
void Rules::update()
{
}
void Rules::render(sf::RenderWindow &mWindow)
{
    mBackground.loadFile("assets/Images/Background1.png");
    mBackground.resizePic({800, 600});
    mBackground.draw(mWindow);
    mWindow.draw(mHeader[0]);
}