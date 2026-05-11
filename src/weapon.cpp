#include "../header/weapon.h"
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>


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
        if (!mTexture.loadFromFile("./assets/target/cat2.png"))
        {
            std::cout << "Failed to load cat texture\n";
        }

        mSprite.setTexture(mTexture);
        mSprite.setScale(0.15f, 0.15f);

        mSprite.setOrigin(
        mSprite.getLocalBounds().width / 2.f,
        mSprite.getLocalBounds().height / 2.f
        );

        mSprite.setPosition(startPos);

        mVelocity = direction * speed;
    }

    Bullet::Bullet(Bullet&& other) noexcept : 
            mTexture(std::move(other.mTexture)),
            mSprite(std::move(other.mSprite)),
            mVelocity(other.mVelocity), 
            mAlive(other.mAlive)
    {
        //Re-binding after move
        mSprite.setTexture(mTexture, true);
    }

    Bullet& Bullet::operator=(Bullet&& other) noexcept 
    {
        if (this != &other)
        {
            mTexture = std::move(other.mTexture);
            mSprite = std::move(other.mSprite);
            mVelocity = other.mVelocity;
            mAlive = other.mAlive;

            // Rebind after move
            mSprite.setTexture(mTexture, true);
        }
        return *this;
    }

    void Bullet::update(float dt)
    {
        mSprite.move(mVelocity * dt);
        mSprite.rotate(360.f * dt);
    }

    void Bullet::render(sf::RenderWindow &window) const
    {
        if (mAlive)
        {
            window.draw(mSprite);
        }
    }

    sf::FloatRect Bullet::getBounds() const
    {
        return mSprite.getGlobalBounds();
    }

    bool Bullet::isAlive() const
    {
        return mAlive;
    }

    void Bullet::destroy()
    {
        mAlive = false;
    }
