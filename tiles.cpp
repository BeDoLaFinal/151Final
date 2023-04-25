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

#include "classDefinitions/tiles.h"

//after a move we run this function to update the state of the tile that corresponds to the move. This is not a complete function by any means. 

void Tile::setState( char ta[11][11], Tile ta2[11][11] )//I'm assuming we're using Char for the array identifier/input. 
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
}