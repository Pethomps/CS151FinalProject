/**
 * @file bullet.h
 * @author Target Acquisition Group
 * @brief Bullet class handles the flying projectile.
 * 
 */

#ifndef BULLET_H
#define BULLET_H

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
    Bullet(Bullet&& other) noexcept;
    Bullet& operator=(Bullet&& other) noexcept;
    Bullet fireAt(sf::Vector2f targetPos) const;
    void update(float dt);
    void render(sf::RenderWindow& window) const;
    sf::FloatRect getBounds() const;
    bool isAlive() const;
    void destroy();
};

#endif