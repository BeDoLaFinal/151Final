/**
 * @file gameFunctions.h
 * @author 
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

void mouseClickLocation(Event &click,int arr[2]);
void showInstructions(RenderWindow& window, Screen &screen);
void playGame(RenderWindow& window, Screen &screen);

#endif