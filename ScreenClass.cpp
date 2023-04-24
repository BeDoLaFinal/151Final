/**
 * @file    ScreenClass.cpp
 * @author  Lacey Hunt (lhunt2@students.nic.edu)
 * @brief   definitions for functions needed to implement Screen class 
 *              declared in "gameObjects.h"
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
    if(!mImage.loadFromFile("Images/gameboard.bmp"))
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
void Screen::updateScreen(sf::Event& e, sf::RenderWindow& window)
{
    if(e.type==sf::Event::MouseButtonPressed)
    {
    if (e.mouseButton.button==sf::Mouse::Left)         //USER WON
    {
        if(!mImage.loadFromFile("Images/youWonResize.png"))
        {
            std::cout<<"Error opening 'youWon.png' screen file.\n";
            exit(1);
        }
        setPrivateVariables(mImage,0.97);
    }
    else if (e.mouseButton.button==sf::Mouse::Right)    //USER LOST
    {
        if(!mImage.loadFromFile("Images/youLostResize.png"))
        {
            std::cout<<"Error opening 'youLost.png' screen file.\n";
            exit(1);
        }
        setPrivateVariables(mImage,.97);
    }
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
    screenBckgrnd.setOrigin(screenSize.x/2, screenSize.y/2);
    screenBckgrnd.setPosition(screenSize.x/2, screenSize.y/2);
}