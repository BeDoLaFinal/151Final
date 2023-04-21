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
class Sound{
public:
    Sound();
    void load(const std::string& filePath);
    void play();
    void stop();
private:
    sf::SoundBuffer mSoundBuffer;
    sf::Sound mSound;
};
class Music{
public:
    Music();
    void load(const std::string& filePath);
    void play();
    void pause();
    void stop();
private:
    sf::Music mMusic;
};
#endif