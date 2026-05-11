/**
 * @file weapon.h
 * @author Target Acquisition Group
 * @brief Weapon class handles the firing point. 
 * 
 */

#ifndef WEAPON_H
#define WEAPON_H

#include <SFML/Graphics.hpp>
#include <cmath>
#include "bullet.h"


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