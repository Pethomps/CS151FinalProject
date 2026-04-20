#include "../header/weapon.h"
#include <SFML/Graphics.hpp>
#include <cmath>


    Weapon::Weapon(sf::Vector2f muzzlePosition, float bulletSpeed)
        : mMuzzlePosition(muzzlePosition), mBulletSpeed(bulletSpeed)
    {
    }

    Bullet Weapon::fireAt(sf::Vector2f targetPos) const
    {
        sf::Vector2f direction = targetPos - mMuzzlePosition;

        float length = std::sqrt(direction.x * direction.x +
                                 direction.y * direction.y);

        if (length != 0.f)
        {
            direction.x = direction.x / length;
            direction.y = direction.y / length;
        }

        return Bullet(mMuzzlePosition, direction, mBulletSpeed);
    }

    void Weapon::render(sf::RenderWindow &window) const
    {
        sf::RectangleShape gunShape(sf::Vector2f(40.f, 10.f));
        gunShape.setPosition(mMuzzlePosition);
        gunShape.setFillColor(sf::Color::Green);
        window.draw(gunShape);
    }


    Bullet::Bullet(sf::Vector2f startPos, sf::Vector2f direction, float speed)
        : mAlive(true)
    {
        mShape.setRadius(5.f);
        mShape.setOrigin(5.f, 5.f);
        mShape.setPosition(startPos);
        mShape.setFillColor(sf::Color::Yellow);
        mVelocity = direction * speed;
    }

    void Bullet::update(float dt)
    {
        mShape.move(mVelocity * dt);
    }

    void Bullet::render(sf::RenderWindow &window) const
    {
        if (mAlive)
        {
            window.draw(mShape);
        }
    }

    sf::FloatRect Bullet::getBounds() const
    {
        return mShape.getGlobalBounds();
    }

    bool Bullet::isAlive() const
    {
        return mAlive;
    }

    void Bullet::destroy()
    {
        mAlive = false;
    }
