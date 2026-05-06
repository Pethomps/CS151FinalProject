#include "../header/target.h"

Target::Target(float x, float y, float radius)
    : mAlive(true)
{
    mShape.setRadius(radius);
    mShape.setOrigin(radius, radius);
    mShape.setPosition(x, y);
    mShape.setFillColor(sf::Color::Blue);
}

void Target::render(sf::RenderWindow &window) const
{
    if (mAlive)
    {
        window.draw(mShape);
    }
}

sf::FloatRect Target::getBounds() const
{
    return mShape.getGlobalBounds();
}

bool Target::isAlive() const
{
    return mAlive;
}

void Target::destroy()
{
    mAlive = false;
}

