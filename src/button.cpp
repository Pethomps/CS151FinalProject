/**
 * @file button.cpp
 * @author Target Acquisition Group
 * @brief Button class implementation
 * 
 */

#include "../header/button.h"
#include <SFML/Graphics.hpp>



/**
 * @brief Default constructor.
 *          Sets text, texture, origin, color, position, state, and scale.
 * 
 */
Button::Button():Button("Play!", {300,100}, {1,1}, sf::Color::White)
{
    mButton.setScale(1, 1);
    unsigned int fontSize = mButton.getGlobalBounds().height/2;
    mText.setCharacterSize(fontSize);
    mText.setOrigin(mText.getGlobalBounds().width/2, mText.getGlobalBounds().height/2);
    mText.setPosition(mPosition.x, mPosition.y-fontSize/4);

}

/**
 * @brief Constructor creates Button class using parameters.
 * 
 * @param s 
 * @param position 
 * @param size 
 * @param color 
 */
Button::Button(std::string s, sf::Vector2f position, sf::Vector2f size, sf::Color color)
{
    if (!mTexture.loadFromFile("./assets/Button/button.png"))
    {
        std::cout<<"Button: error opening button.png\n";
        exit(1);
    }
    // create sprite that looks like a button
    mButton.setTexture(mTexture);
    
    // get size of image
    sf::Vector2u imageSize=mTexture.getSize();
    // change origin to the center of the image (makes rotation easy)
    mButton.setOrigin(imageSize.x/2, imageSize.y/2);
    // set position
    mPosition = position;
    mButton.setPosition(mPosition.x,mPosition.y);
    // set color
    mButtonColor = color;
    mButton.setColor(mButtonColor);
    // set size as a ratio of original size
    mButton.setScale(size.x/imageSize.x, size.y/imageSize.y);
    // Load font
    if (!mFont.loadFromFile("./assets/Fonts/VintageCharm-Regular.otf"))
    {
        std::cout<<"Button: error opening .otf file\n";
        exit(2);
    }
    mText.setFont(mFont);
    //set fontsize (half the size of the button)
    unsigned int fontSize = mButton.getGlobalBounds().height/2;
    mText.setCharacterSize(fontSize);
    //set button text
    mText.setString(s);
    //set origin to the middle
    mText.setOrigin(mText.getGlobalBounds().width/2, mText.getGlobalBounds().height/2);
    //set position at the middle of the button
    mText.setPosition(mPosition.x, mPosition.y-fontSize/4);
    //set font colors
    mTextNormal = sf::Color::Black;
    mTextHover = sf::Color::Magenta;
    mText.setFillColor(mTextNormal);
    mBtnState=normal;
}

/**
 * @brief Changes button's position and adjusts fontsize accordingly.
 * 
 * @param position 
 */
void Button::setPosition(sf::Vector2f position)
{
    sf::Vector2u imageSize = mTexture.getSize();
    // adjust origin to the middle
    mPosition = position;
    mButton.setOrigin(imageSize.x/2, imageSize.y/2);
    mButton.setPosition(position);

    // get font size based on button size
    unsigned int fontSize = mButton.getGlobalBounds().height/2;
    // adjust text position to middle of the button
    mText.setPosition(mPosition.x, mPosition.y-fontSize/4);
}

/**
 * @brief Changes button's size (using SFML scale) 
 *          and adjusts character size, origin, and position.
 * 
 * @param size 
 */
void Button::setSize(sf::Vector2f  size)
{
    sf::Vector2u imageSize=mTexture.getSize();
    mButton.setScale(size.x/imageSize.x, size.y/imageSize.y);

    // adjust font size
    unsigned int fontSize = mButton.getGlobalBounds().height/2;
    mText.setCharacterSize(fontSize);
    // adjust origin
    mText.setOrigin(mText.getGlobalBounds().width/2, mText.getGlobalBounds().height/2);
    // adjust text position
    mText.setPosition(mPosition.x, mPosition.y-fontSize/4);
}

/**
 * @brief change button color
 * 
 * @param btnColor new color
 */
void Button::setColor(sf::Color btnColor)
{
    mButtonColor = btnColor;
    mButton.setColor(mButtonColor);
}

//change button label to s (what else needs to be changed?)
/**
 * @brief Change button's text and adjust text's origin and position.
 * 
 * @param s 
 */
void Button::setText(std::string s)
{
    mText.setString(s);
    // set text origin to the middle of new text
    mText.setOrigin(mText.getGlobalBounds().width/2, mText.getGlobalBounds().height/2);
    // set text position to middle of the button
    unsigned int fontSize = mButton.getGlobalBounds().height/2;
    mText.setPosition(mPosition.x, mPosition.y-fontSize/4);
}

/**
 * @brief Tracks the state of the button using events.
 * 
 * @param e 
 * @param window 
 * @return true 
 * @return false 
 */
bool Button::handleInput(sf::Event& e, sf::RenderWindow& window)
{
    //get position of the mouse
    sf::Vector2i mPos = sf::Mouse::getPosition(window);
    sf::Vector2f mousePosition = window.mapPixelToCoords(mPos);
    bool mouseInButton =    mousePosition.x >= mButton.getPosition().x - mButton.getGlobalBounds().width/2
                            && mousePosition.x <= mButton.getPosition().x + mButton.getGlobalBounds().width/2
                            && mousePosition.y >= mButton.getPosition().y - mButton.getGlobalBounds().height/2
                            && mousePosition.y <= mButton.getPosition().y + mButton.getGlobalBounds().height/2;
    if(e.type == sf::Event::MouseMoved)
    {
        if(mouseInButton)
        {
            mBtnState = state::hovered;
            update();
        }
        else
        {
            mBtnState = state::normal;
            update();
        }
    }
    if (e.type == sf::Event::MouseButtonPressed)
    {
        if(e.mouseButton.button==sf::Mouse::Left)
        {
            if(mouseInButton)
            {
                mBtnState = state::clicked;
                update();
                return true;
            }
            else
            {
                mBtnState = state::normal;
                update();
            }
        }
    }
    if (e.type == sf::Event::MouseButtonReleased)
    {
        if (e.mouseButton.button==sf::Mouse::Left)
        {
            if(mouseInButton)
            {
                mBtnState = state::hovered;
                update();
            }
            else
            {
                mBtnState = state::normal;
                update();
            }
        }
    }
    return false;
    
}

/**
 * @brief Changes the button based on button state.
 * 
 */
void Button::update()
{
    switch (mBtnState)
    {
    case normal:
        mButton.setRotation(0);
        mText.setFillColor(mTextNormal);
        break;
    case hovered:
        mButton.setRotation(0);
        mText.setFillColor(mTextHover);
        break;
    case clicked:
        mButton.setRotation(180);
        mText.setFillColor(mTextHover);
        break;
    }
}

/**
 * @brief Displays the button and text (relative to current state).
 * 
 * @param target 
 * @param states 
 */
void Button::draw(sf::RenderTarget& target,sf::RenderStates states) const
{
    target.draw(mButton, states);
    target.draw(mText, states);
}
