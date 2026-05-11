/**
 * @file Sound.h
 * @author Target Acquisition Group
 * @brief Sound class creates and handles in-game sound effects.
 * 
 * @date 2026-04-25
 * 
 */

#ifndef SOUND_H
#define SOUND_H

#include <SFML/Audio.hpp>
#include <string>

class Sound{
public:
    bool loadSound(const std::string& fileName);
    void play();

private:
    sf::SoundBuffer mBuffer;
    sf::Sound mSound;
};

#endif