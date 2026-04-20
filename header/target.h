#ifndef TARGET_H
#define TARGET_H

#include <SFML/Graphics.hpp>

class Target
{
private:
    sf::CircleShape mShape;
    bool mAlive;

public:
    Target(){};
    Target(float x, float y, float radius);

    void render(sf::RenderWindow& window) const;
    sf::FloatRect getBounds() const;
    bool isAlive() const;
    void destroy();
};

#endif