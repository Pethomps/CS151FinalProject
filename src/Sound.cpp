/**
 * @file Sound.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2026-04-25
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include "../header/Sound.h"
#include <iostream>

bool Sound::loadSound(const std::string& fileName)
{
    if(!mBuffer.loadFromFile(fileName))
    {
        std::cout << "Failed to load sound: " << fileName << std::endl;
        return false;
    }

    mSound.setBuffer(mBuffer);
    return true;
}

void Sound::play()
{
    mSound.play();
}