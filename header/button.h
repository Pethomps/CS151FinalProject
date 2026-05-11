/**
 * @file button.h
 * @author Target Acquisition Group
 * @brief Button class provides uniform buttons for the game.
 * 
 */

#ifndef BUTTON_H
#define BUTTON_H
#include <SFML/Graphics.hpp>
#include <iostream>


enum state {normal, hovered, clicked};

class Button: public sf::Drawable
{
    public:
        Button();
        Button(std::string s, sf::Vector2f position, sf::Vector2f size, sf::Color color);
        ~Button(){};
        void setPosition(sf::Vector2f position);
        void setSize(sf::Vector2f  size);
        void setColor(sf::Color btnColor);
        void setText(std::string s);
        void setColorTextNormal(sf::Color textNormalColor);
        void setColorTextHover(sf::Color textHoverColor);

        sf::Vector2f getPosition(){return mPosition;};
        sf::Vector2f getDimensions(){return sf::Vector2f(mButton.getGlobalBounds().width, mButton.getGlobalBounds().height);};
        sf::Uint32 getState(){return mBtnState;};

        bool handleInput(sf::Event& e, sf::RenderWindow& window);
        void update();
        virtual void draw(sf::RenderTarget& target,sf::RenderStates states) const;

    private:
        sf::Sprite mButton;
        sf::Texture mTexture;
        sf::Color mButtonColor;
        sf::Vector2f mPosition;
        sf::Uint32 mBtnState;
        
        // Text features
        sf::Text mText;
        sf::Font mFont;
        sf::Color mTextNormal;
        sf::Color mTextHover;
};


#endif
