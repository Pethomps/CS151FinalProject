#include "../header/target.h"


class Target
{
private:
    sf::CircleShape mShape;
    bool mAlive;

public:
    Target(float x, float y, float radius)
        : mAlive(true)
    {
        mShape.setRadius(radius);
        mShape.setOrigin(radius, radius);
        mShape.setPosition(x, y);
        mShape.setFillColor(sf::Color::Blue);
    }

    void render(sf::RenderWindow &window) const
    {
        if (mAlive)
        {
            window.draw(mShape);
        }
    }

    sf::FloatRect getBounds() const
    {
        return mShape.getGlobalBounds();
    }

    bool isAlive() const
    {
        return mAlive;
    }

    void destroy()
    {
        mAlive = false;
    }
};
// Target::Target()
// {

// }
// void Target::update(double elapsedTime, sf::RenderWindow &window)
// {

// }
// void Target::render(sf::RenderWindow &window)
// {

// }
// void Target::setBondary(int xPosition, int yPosition, int width, int height)
// {

// }
// void Target::moveTarget(double elapsedTime, sf::RenderWindow& window)
// {
    
// }
