/**
 * @file tiles.cpp
 * @author Dominic Acia
 * @brief 
 * @version 0.1
 * @date 2023-04-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <vector>
#include "classDefinitions/tiles.h"

/**
 * @brief sets state of tile on board
 * 
 * @param ta 
 * @param ta2 
 */
void Tile::setState( char ta[11][11], Tile ta2[11][11] )
{
    if(ta[arrayLocationx][arrayLocationy]== '-')
    { ta2[arrayLocationx][arrayLocationy].mTexture.loadFromFile("Images/SpriteTileMiss1.png");}
    else  if(ta[arrayLocationx][arrayLocationy]== '*')
    {ta2[arrayLocationx][arrayLocationy].mTexture.loadFromFile("Images/SpriteTileHit.png");}
    else  if(ta[arrayLocationx][arrayLocationy]== 'c'&& ta[arrayLocationx-1][arrayLocationy]=='-')
    {ta2[arrayLocationx][arrayLocationy].mTexture.loadFromFile("Images/SpriteTileShip1.png");}
    else  if(ta[arrayLocationx][arrayLocationy]== 'c')
    {ta2[arrayLocationx][arrayLocationy].mTexture.loadFromFile("Images/SpriteTileShip2.png");}
    else  if(ta[arrayLocationx][arrayLocationy]== 'c')
    {ta2[arrayLocationx][arrayLocationy].mTexture.loadFromFile("Images/SpriteTileShip3.png");}
};

/**
 * @brief used for radar in game
 * 
 * @param needle 
 * @param i 
 * @param window 
 */
void needleDesign(sf::RectangleShape needle, int i, sf::RenderWindow& window)
{
        
    needle.setPosition(965,501);
    needle.setFillColor(sf::Color(100, 250, 50, 210));
    needle.setOutlineThickness(1);
    needle.setOutlineColor(sf::Color(10,10,10));
    needle.setOrigin(3,5);
    needle.setRotation(i); 
    window.draw(needle);
};


