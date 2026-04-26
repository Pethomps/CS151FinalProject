/**
 * @file target.cpp
 * @author Target Acquisition Group
 * @brief Implements movement, collision detection, rendering,
 *        hit effects, and new position logic for the Target class
 * 
 * @date 2026-04-22
 * 
 */
#include "../header/target.h"

/**
 * @brief Constructor:
 *        Initializes the target with a texture, position,
 *        movement directon, speed, and hit text used for "HIT!" effect.
 * 
 * @param x 
 * @param y 
 * @param radius 
 */
Target::Target(float x, float y, float radius)
    : mAlive(true), mExploding(false)
{
    // Load texture to a sprite
    if(!mTexture.loadFromFile("assets/target/duckTarget.png"))
    {
        std::cout << "Failed to load duck texture\n";
    }
    mTarget.setTexture(mTexture);
    mTarget.setPosition(x, y);
    mTarget.setScale(0.2f, 0.2f);

    // Target movement setup
    mSpeed = 60.f; //starting speed

    // Move to random direction
    float moveX = randomNumber(-1, 1);
    float moveY = randomNumber(-1, 1);

    if(moveX == 0 && moveY == 0)
    {
        moveX = 1;
    }

    mVelocity = sf::Vector2f(moveX, moveY);

    float length = sqrt(moveX * moveX + moveY * moveY);
    mVelocity.x /= length;
    mVelocity.y /= length;

    //Hit message setup
    if(!mFont.loadFromFile("assets/Fonts/KGPerfectPenmanship.otf"))
    {
        std::cout << "Failed to load font\n";
    }

    mHitText.setFont(mFont);
    mHitText.setString("HIT!");
    mHitText.setCharacterSize(30);
    mHitText.setFillColor(sf::Color(255, 86, 0));

    sf::FloatRect textBounds = mHitText.getLocalBounds();
    mHitText.setOrigin(textBounds.left + textBounds.width / 2.f, textBounds.top + textBounds.height / 2.f); 
}

/**
 * @brief Helper function to generate a random number between min and max.
 *        Used for random movement direction and spawn positions.
 * 
 * @param min 
 * @param max 
 * @return int 
 */
int Target::randomNumber(int min, int max)
{
    return min + (rand() %(max - min + 1));
}

/**
 * @brief Renders the target and hit effect on the screen.
 * 
 * @param window 
 */
void Target::render(sf::RenderWindow &window) const
{
    if (mAlive)
    {
        window.draw(mTarget);
    }

    if(mExploding)
    {
        window.draw(mHitText);
    }
}

/**
 * @brief Returns global bounds of the target sprite.
 *        Used for collision detection with bullets.
 * 
 * @return sf::FloatRect 
 */
sf::FloatRect Target::getBounds() const
{
    return mTarget.getGlobalBounds();
}

/**
 * @brief Check if target is currently active(alive).
 * 
 * @return true 
 * @return false 
 */
bool Target::isAlive() const
{
    return mAlive;
}

/**
 * @brief Returns current position of target sprite.
 * 
 * @return sf::Vector2f 
 */
sf::Vector2f Target::getPosition() const
{
    return mTarget.getPosition();
}

/**
 * @brief Checks if bullet hit the target.
 * 
 * NOTES:
 * If hit:
 * - trigger hit effect
 * - resets position
 * - increase speed
 * 
 * @param bulletBounds 
 * @return true 
 * @return false 
 */
bool Target::isHit(const sf::FloatRect& bulletBounds)
{
    if (mAlive && mTarget.getGlobalBounds().intersects(bulletBounds))
    {
        mAlive = false;

        mHitText.setPosition(mTarget.getPosition());
        
        //Reset fade
        sf::Color color = mHitText.getFillColor();
        color.a = 255;
        mHitText.setFillColor(color);

        mExploding = true;
        mExplosionClock.restart();

        newPosition();
        mAlive = true;

        return true;
    }
    
    return false;
}

/**
 * @brief Updates target movement, boundary collision, and
 *        handdles animation (fade-out) for hit effect
 * 
 * @param dt 
 */
void Target::update(float dt)
{
    //Move target only if alive
    if(mAlive)
    {
        mTarget.move(mVelocity * mSpeed * dt);
        
        // Check if target still within bounds
        sf::FloatRect bound = mTarget.getGlobalBounds();

        // Left edge
        if(bound.left <= 0.f)
        {
            mTarget.setPosition(0.f, mTarget.getPosition().y);
            mVelocity.x = abs(mVelocity.x);
        }
        else if(bound.left + bound.width >= 800.f) //Right edge
        {
            mTarget.setPosition(800.f - bound.width, mTarget.getPosition().y);
            mVelocity.x = -abs(mVelocity.x);
        }

        // Top and bottom edge
        if(bound.top <= 0.f)
        {
            mTarget.setPosition(mTarget.getPosition().x, 0.f);
            mVelocity.y = abs(mVelocity.y); // goes down
        }
        else if(bound.top + bound.height > 600.f) 
        {
            mTarget.setPosition(mTarget.getPosition().x, 600.f - bound.height);
            mVelocity.y = -abs(mVelocity.y); // goes up
        }
    }
    // Fade logic
    if(mExploding)
    {
        float elapsed = mExplosionClock.getElapsedTime().asSeconds();
        float duration = 2.0f;

        if( elapsed < duration)
        {
            // Fade
            float fade = 255.f * (1.f - (elapsed/duration));

            sf::Color color = mHitText.getFillColor();
            color.a = static_cast<sf::Uint8>(fade);
            mHitText.setFillColor(color);
        }
        else
        {
            mExploding = false;
        }
    }
}

/**
 * @brief Respawns target at a new random position,
 *        increases speed for difficulty, and assings a new
 *        random direction for movement
 * 
 */
void Target::newPosition()
{
    mAlive = true;

    // New random Position
    float x = randomNumber(40, 750);
    float y = randomNumber(40, 550);

    mTarget.setPosition(x, y);

    // Increase speed every time target gets hit
    if(mSpeed < 260.f)
    {
        mSpeed += 20.f;
    }

    // New random direction
    float dx = randomNumber(-1, 1);
    float dy = randomNumber(-1, 1);

    if(dx == 0 && dy == 0)
    {
        dx = 1;
    }

    mVelocity = sf::Vector2f(dx, dy);
}
