/**
 * @file    gameObjects.h
 * @author  Lacey Hunt (lhunt2@students.nic.edu)
 * @brief   declaration file for BattleShip game object classes and includes
 * @date    2023-04-10
 * 
 */
#ifndef GAMEOBJECTS_H
#define GAMEOBJECTS_H

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
using std::cout;
using std::endl;
using namespace sf;

/**
 * @brief Class of Background Screens
 * @author Lacey
 * 
 */
class Screen
{
public:
    Screen();
    RectangleShape getScreen();
    Vector2f getScreenSize();
    void updateScreen(sf::Event& e, sf::RenderWindow& window); //change later to input from game instead of screen event
private:
    void setPrivateVariables();
    RectangleShape screenBckgrnd;
    Texture mImage;
    Vector2f screenSize={800,500};
};

/**
 * @brief class of overlays during gameplay
 *          i.e. ships, hit icon, miss icon, hit sound, miss sound?
 * @author Dom (graphics)
 * @author Ben (sounds)
 * 
 */
class Overlay
{
public:
private:
};

/**
 * @brief exit code meanings for debugging purposes
 * 
 * 1: error opening a png file
 *      will output specific file name to console
 * 
 */

#endif