#ifndef WEAPON_H
#define WEAPON_H

#include <SFML/Graphics.hpp>
#include <cmath>

class Bullet
{
private:
    sf::Texture mTexture;
    sf::Sprite mSprite; 
    sf::Vector2f mVelocity;
    bool mAlive;

public:
    Bullet(sf::Vector2f startPos, sf::Vector2f direction, float speed);

    void update(float dt);
    void render(sf::RenderWindow& window) const;
    sf::FloatRect getBounds() const;
    bool isAlive() const;
    void destroy();
};
 
class Weapon
{
private:
    sf::Vector2f mMuzzlePosition;
    float mBulletSpeed;

public:
    Weapon(sf::Vector2f muzzlePosition, float bulletSpeed);

    Bullet fireAt(sf::Vector2f targetPos) const;
    void render(sf::RenderWindow& window) const;
};

#endif