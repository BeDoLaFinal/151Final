/**
 * @file gameFunctions.h
 * @author Dominic Acia, Lacey Hunt, Ben Givens
 * @brief various function definitions needed for gameplay
 * @date 2023-04-23
 * 
 */
#ifndef GAMEFUNCTIONS_H
#define GAMEFUNCTIONS_H

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

#include "classDefinitions/ScreenClass.h"
#include "classDefinitions/tiles.h"
#include "classDefinitions/introScreen.h"

using std::cout;
using std::endl;
using namespace sf;

void displayArrayofTiles(char ta[10][10], Texture &texture, RenderWindow &window, int shiftx, int shiftY);
String mouseClickLocation(Event &click,int (&arr)[2], Texture &texture, RenderWindow &windowMain,Text &mMessage);
void displayPrompt(std::string s, sf::Font &font,RenderWindow &window,sf::Text &message);

#endif