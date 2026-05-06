#include "../header/rules.h"

/**
 * @brief Construct a new Rules:: Rules object
 *        Assign values and construct private mem variables
 *
 */
Rules::Rules()
{
    // load background
    mBackground.loadFile("assets/Background/rulesBackground.png");
    mBackground.resizePic({800, 600});

    // load font
    if (!mFont.loadFromFile("assets/Fonts/VintageCharm-Regular.otf"))
    {
        std::cout << "Rules: error opening .otf file\n"; // use throw instead?
        exit(1);
    }

    // header 1- "how to play"
    mHeader[0].setString("HOW TO PLAY");
    mHeader[0].setFillColor(sf::Color(180, 130, 71));
    mHeader[0].setOutlineThickness(20);
    mHeader[0].setOutlineColor(sf::Color(107, 77, 42));
    mHeader[0].setFont(mFont);
    mHeader[0].setCharacterSize(75);
    // place at top center
    sf::FloatRect bounds = mHeader[0].getLocalBounds();
    mHeader[0].setOrigin((bounds.width / 2), (bounds.height / 2));
    mHeader[0].setPosition({425, 100});

    // colors and size for rule lines
    sf::Color rulesOutline{sf::Color::White};
    sf::Color rulesFill{sf::Color::Black};
    sf::Vector2f rulesPos(sf::Vector2f(425,225));

    // set fonts
    mRuleTxt[0].setFont(mFont);
    mRuleTxt[1].setFont(mFont);
    mRuleTxt[2].setFont(mFont);
    mRuleTxt[3].setFont(mFont);

    // set fill colors
    mRuleTxt[0].setFillColor(rulesFill);
    mRuleTxt[1].setFillColor(rulesFill);
    mRuleTxt[2].setFillColor(rulesFill);
    mRuleTxt[3].setFillColor(rulesFill);
    

    // set outline colors
    mRuleTxt[0].setOutlineColor(rulesOutline);
    mRuleTxt[1].setOutlineColor(rulesOutline);
    mRuleTxt[2].setOutlineColor(rulesOutline);
    mRuleTxt[3].setOutlineColor(rulesOutline);
    int outlineThickness = 5;
    mRuleTxt[0].setOutlineThickness(outlineThickness);
    mRuleTxt[1].setOutlineThickness(outlineThickness);
    mRuleTxt[2].setOutlineThickness(outlineThickness);
    mRuleTxt[3].setOutlineThickness(outlineThickness);

    // set char size
    int charRulesSize = 25;
    mRuleTxt[0].setCharacterSize(charRulesSize);
    mRuleTxt[1].setCharacterSize(charRulesSize);
    mRuleTxt[2].setCharacterSize(charRulesSize);
    mRuleTxt[3].setCharacterSize(charRulesSize);

    float xPos = 425;
    float yPos = 245;

    // instruction 1 "left click to shoot"
    mRuleTxt[0].setString("left-click to shoot");
    // position
    sf::FloatRect tBounds0 = mRuleTxt[0].getLocalBounds();
    mRuleTxt[0].setOrigin((tBounds0.width / 2), (tBounds0.height / 2));
    mRuleTxt[0].setPosition({xPos, yPos});

    // instruction 2
    mRuleTxt[1].setString("try to hit the ducks with \nthe weapon!");
    // position
    sf::FloatRect tBounds1 = mRuleTxt[1].getLocalBounds();
    mRuleTxt[1].setOrigin((tBounds1.width / 2), (tBounds1.height / 2));
    mRuleTxt[1].setPosition({xPos, yPos+75});

    // instruction 3 "each time you hit a duck, score goes up"
    mRuleTxt[2].setString("each time you hit a duck\nthe score goes up!");
    // position
    sf::FloatRect tBounds2 = mRuleTxt[2].getLocalBounds();
    mRuleTxt[2].setOrigin((tBounds2.width / 2), (tBounds2.height / 2));
    mRuleTxt[2].setPosition({xPos, yPos+150});

    // instruction 4 "scores will be saved and displayed at the end!"
    mRuleTxt[3].setString("you have 60 seconds");
    // position
    sf::FloatRect tBounds3 = mRuleTxt[3].getLocalBounds();
    mRuleTxt[3].setOrigin((tBounds3.width / 2), (tBounds3.height / 2));
    mRuleTxt[3].setPosition({xPos, yPos+225});


    // header 2 - "esc to return to main menu"
    mHeader[1].setString("press esc to return");
    mHeader[1].setFillColor(sf::Color(180, 130, 71));
    mHeader[1].setOutlineThickness(5);
    mHeader[1].setOutlineColor(sf::Color(107, 77, 42));
    mHeader[1].setFont(mFont);
    mHeader[1].setCharacterSize(25);
    // place at bottom center
    sf::FloatRect hBounds1 = mHeader[1].getLocalBounds();
    mHeader[1].setOrigin((hBounds1.width / 2), (hBounds1.height / 2));
    mHeader[1].setPosition({425, 570});
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
    if (e.type == sf::Event::KeyPressed) // check for key presse
    {
        if (e.key.code == sf::Keyboard::Escape) // if user presses escape
        {
            // return welcome screen
            return welcome;
        }
    }
    // otherwise returns rules (stay on rules screen)
    return rules;
}
void Rules::update()
{
}
void Rules::render(sf::RenderWindow &mWindow)
{
    mBackground.draw(mWindow);
    mWindow.draw(mHeader[0]);
    mWindow.draw(mHeader[1]);
    mWindow.draw(mRuleTxt[0]);
    mWindow.draw(mRuleTxt[1]);
    mWindow.draw(mRuleTxt[2]);
    mWindow.draw(mRuleTxt[3]);
}