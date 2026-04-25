/**
 * @file Music.cpp
 * @author 
 * @brief 
 * 
 * @date 2026-04-25
 * 
 */

#include "../header/Music.h"
#include <iostream>

bool Music::load(const std::string& fileName)
{
    if(!mMusic.loadFromFile(fileName))
    {
        std::cout << "Failed to load sound: " << fileName << std::endl;
        return false;
    }

    return true;
}


void Music::play(bool loop)
{
    mMusic.setLoop(loop);
    mMusic.play();
}


void Music::stop()
{
    mMusic.stop();
}