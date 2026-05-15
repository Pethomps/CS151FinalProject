/**
 * @file Music.h
 * @author Target Acquisition Group
 * @brief Music class creates musical element for the game.
 * 
 * @date 2026-04-25
 * 
 * 
 */

#ifndef MUSIC_H
#define MUSIC_H

#include <SFML/Audio.hpp>
#include <string>

class Music{
public:
    bool load(const std::string& fileName);
    void play(bool loop = true);
    void stop();

private:
    sf::Music mMusic;
};

#endif