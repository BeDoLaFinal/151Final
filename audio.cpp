/**
 * @file audio.cpp
 * @author Ben Givens
 * @brief cpp file for both audio classes
 * @date 2023-04-17 
 */
#include "classDefinitions/audio.h"
/**
 * @brief Plays the music and tests it to see if it opened correctly
 * 
 * @param filename 
 */
void SoundClass::play(const std::string& filename) 
{
    if (!mBuffer.loadFromFile(filename)) {
        std::cout<<"Sound failed to load..."<<std::endl;
        return;
    }
    mSound.setBuffer(mBuffer);
    mSound.play();
}
/**
 * @brief pauses sound
 * 
 */
void SoundClass::pause() 
{
    mSound.pause();
}
/**
 * @brief stops sound
 * 
 */
void SoundClass::stop() 
{
    mSound.stop();
}

//Start of music class

/**
 * @brief loads and plays the music based on user entry
 * @param filename name of music file the user wishes to enter
 */
void MusicClass::play(const std::string& filename) 
{
    if (!mMusic.openFromFile(filename)) 
    {
        std::cout<<"Error opening music file"<<std::endl;
        return;
    }
    mMusic.play();
    mMusic.setLoop(true);
}

/**
 * @brief Pauses the current music stream without reseting the place in the song
 * 
 */
void MusicClass::pause() 
{
    mMusic.pause();
}

/**
 * @brief Stops the music stream and restarts the place in the song
 * 
 */
void MusicClass::stop() 
{
    mMusic.stop();
}

/**
 * @brief Checks to see if the audio stream is still going. Used for switching songs
 * @return true if it is playing
 * @return false if it isn't playing
 */
bool MusicClass::isPlaying() const 
{
    return mMusic.getStatus() == sf::Music::Playing;
}