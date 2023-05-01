/**
 * @file audio.cpp
 * @author Ben Givens
 * @brief header file for both audio classes
 * @date 2023-04-17 
 */
#ifndef AUDIO_H
#define AUDIO_H
#include <SFML/Audio.hpp>
#include <string>
#include <iostream>
/**
 * @brief Class for sound
 * 
 */
class SoundClass{
public:
    void play(const std::string& filename);
    void pause();
    void stop();
private:
    sf::Sound mSound;
    sf::SoundBuffer mBuffer;
};

/**
 * @brief Class for music
 * 
 */
class MusicClass{
public:
    void play(const std::string& filename);//Loads the music file and plays the song
    void pause();//Pauses the song without restarting the audio stream
    void stop();//Stops the song without restarting the audio stream
    bool isPlaying() const;//Checks to see if the song is still playing, I am using it to know when to change songs
private:
    sf::Music mMusic;
};
#endif