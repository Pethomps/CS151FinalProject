#ifndef TARGET_H
#define TARGET_H
#include <SFML/Graphics.hpp>

class Target
{
public:
    Target();

    void update(double elapsedTime, sf::RenderWindow& window);
    void render(sf::RenderWindow& window);
    void setBondary(int xPosition, int yPosition, int width, int hight);

private:

    sf::Texture mTextureTile;
    sf::CircleShape mTarget;
    sf::Vector2f mIncrement;
    sf::Vector2i mPosition;
    sf::Vector2i mSize;

    void moveTarget(double elapsedTime, sf::RenderWindow& window);
   
};
#endif