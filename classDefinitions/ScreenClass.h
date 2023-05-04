/**
 * @file    ScreenClass.h
 * @author  Screen: Lacey, Dominmic Acia
 * @brief   declaration file for Screen class
 *          definition of mouseClickLocation function
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
 * @brief   Class of Background Screens
 * @author  Lacey
 * 
 */
class Screen
{
public:
    Screen();
    RectangleShape getScreen();
    void updateScreen(int i, sf::RenderWindow& window); 
private:
    void setPrivateVariables(sf::Texture &i,float scale=1);
    RectangleShape screenBckgrnd;
    Texture mImage;
    Vector2f screenSize={1920,1080};
};


#endif