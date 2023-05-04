/**
 * @file    ScreenClass.cpp
 * @author  Lacey Hunt, Dominic Acia
 * @brief   definitions for functions needed to implement Screen class 
 *              declared in "ScreenClass.h"
 * @date    2023-04-13
 * 
 */

#include "classDefinitions/ScreenClass.h" 

using std::cout; 
/**
 * @brief Constructs a default screen (intro)
 * 
 */
Screen::Screen()
{
    //if(!mImage.loadFromFile("Images/introTest.png"))
    if(!mImage.loadFromFile("Images/bitmapGameBoardv3.bmp"))
    {
        cout<<"Error opening intro screen file.\n";
        exit(1);
    }
    setPrivateVariables(mImage);
}

/**
 * @brief returns background for display
 * 
 * @return RectangleShape 
 */
RectangleShape Screen::getScreen()
{
    return screenBckgrnd;
}

/**
 * @brief updates screen 
 *                          ***TEST***
 *  if left click, show winner screen; if right click, show loser screen
 * 
 * @param e 
 * @param window 
 */
void Screen::updateScreen(int i, sf::RenderWindow& window)
{
    
    if (i==1)         //USER WON
    {
        if(!mImage.loadFromFile("Images/youWonResize.png"))
        {
            std::cout<<"Error opening 'youWon.png' screen file.\n";
            exit(1);
        }
        setPrivateVariables(mImage,1);
    }
    else if (i==2)    //USER LOST
    {
        if(!mImage.loadFromFile("Images/youLostUPDATE.png"))
        {
            std::cout<<"Error opening 'youLost.png' screen file.\n";
            exit(1);
        }
        setPrivateVariables(mImage,1);
    }
    
}

/**
 * @brief sets background screen specific variables
 * 
 */
void Screen::setPrivateVariables(sf::Texture &i,float scale)
{
    screenBckgrnd.setTexture(&mImage);
    screenBckgrnd.setSize({screenSize.x/scale,screenSize.y/scale});
    screenBckgrnd.setOrigin(0, 0);
    screenBckgrnd.setPosition(0,0);
    
}
