#ifndef PLAY_H
#define PLAY_H
#include "states.h"
#include "button.h"
#include "weapon.h"
#include "target.h"
#include "Sound.h"
#include "background.h"

class Play
{
    public:
        Play();
        State handleInput(sf::Event& e,  sf::RenderWindow& window);
        void update(double elapsedTime, sf::RenderWindow& window);
        void render(sf::RenderWindow& window);
        void reset();
        int getScore() const { return mScore; }
        bool isTimeUp() const { return mPlayClock.getElapsedTime().asSeconds() >= mPlayTime; }


    private:
        Weapon mGun{sf::Vector2f(60.f, 500.f), 500.f};
        Sound mGunshotSound;
        Bullet mBullet{sf::Vector2f(0.f, 0.f), sf::Vector2f(0.f, 0.f), 0.f};
        bool mBulletExists;
        Target mTarget{600.f, 300.f, 30.f};
        sf::Clock mPlayClock;
        float mPlayTime = 30.f; // 30 sec
        std::string mBackgroundPNG = "./assets/Images/Background2.png";
        sf::RectangleShape mPlayFrame;
        Background mPlayBackground;
        Button mPlayRestart;
        Button mPlayResults;
        Button mPlayQuit;
        int mScore = 0;
};

#endif