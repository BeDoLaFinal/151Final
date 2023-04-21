/**
 * @file audio.cpp
 * @author Ben Givens
 * @brief cpp file for both audio classes
 * @date 2023-04-17 
 */
#include "audio.h"
/**
 * @brief Constructor for audio object. Initializes sound with sound buffer default value
 */
Sound::Sound(){
    mSound.load(mSoundBuffer);
}
/**
 * @brief Loads the sound file into the sound buffer.
 * @param file name of the file that you want to load
 */
void Sound::load(const std::string& file){
    mSoundBuffer.loadFromFile(file);
}
/**
 * @brief Plays the sound saved in mSound
 * 
 */
void Sound::play(){
    mSound.play();
}
/**
 * @brief Stops the sound that is being played.
 * 
 */
void Audio::stop(){
    mSound.stop();
}


//Start of music class


/**
 * @brief Constructor for Music File. Initializes the loop value to true which will make the song continue to play after the audio file has completed.
 * 
 */
Music::Music(){
    mMusic.setLoop(true);
}
/**
 * @brief Loads the file to the mMusic variable
 * 
 * @param file 
 */
void Music::load(const std::string& file){
    mMusic.openFromFile(file);
}
/**
 * @brief Makes the music start to play
 * 
 */
void Music::play(){
    mMusic.play();
}
/**
 * @brief Pauses the music without starting from the beginning
 * 
 */
void Music::pause(){
    mMusic.pause();
}
/**
 * @brief Stops the music and closes the file
 * 
 */
void Music::stop(){
    mMusic.stop();
}