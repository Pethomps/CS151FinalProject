/**
 * @file target.h
 * @author Target Acquisition Group
 * @brief This class represents a moving target in the game.
 *        The target moves around the scree, detects collisions with bullets,
 *        display "HIT!" effect when shot, and respawns in a new position
 *        with increased speed.
 * 
 * @date 2026-04-22
 * 
 */
#ifndef TARGET_H
#define TARGET_H

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#include <cmath>

class Target
{
private:
    bool mAlive;
    
    sf::Sprite mTarget;
    sf::RectangleShape mBodyTarget;
    sf::Texture mTexture;
    sf::Vector2u spriteSize;
    
    // Movement/direction variables
    int mPositionX{};
    int mPositionY{};
    sf::Vector2f mVelocity;
    float mSpeed;
    
    // HIT! variables
    sf::Font mFont;
    sf::Text mHitText;
    bool mExploding;
    sf::Clock mExplosionClock;
    
    
    public:
    Target() {};
    Target(float x, float y, float radius);
    
    void reset(float x = 600.f, float y = 300.f);   // initializes target (at start position/speed)
    float getSpeed() { return mSpeed; } // Getter function for speed
    
    void render(sf::RenderWindow& window) const;
    sf::FloatRect getBounds() const;
    bool isAlive() const;
    
    sf::Vector2f getPosition() const;
    int randomNumber(int min, int max);
    bool moveTarget(sf::Vector2u& winSize);
    bool isHit(const sf::FloatRect& bulletBounds);
    void newPosition();
    void update(float dt);
};

#endif