/**
 * @file    ScreenClass.cpp
 * @author  Lacey Hunt (lhunt2@students.nic.edu)
 * @brief   definitions for functions needed to implement Screen class 
 *              declared in "gameObjects.h"
 * @date    2023-04-13
 * 
 */
#include "gameObjects.h"

/**
 * @brief Constructs a default screen (intro)
 * 
 */
Screen::Screen()
{
    if(!mImage.loadFromFile("Images/introTest.png"))
    {
        cout<<"Error opening intro screen file.\n";
        exit(1);
    }
    setPrivateVariables();
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
            cout<<"Error opening 'youWon.png' screen file.\n";
            exit(1);
        }
        setPrivateVariables();
    }
    else if (e.mouseButton.button==sf::Mouse::Right)    //USER LOST
    {
        if(!mImage.loadFromFile("Images/youWonResize.png"))
        {
            cout<<"Error opening 'youLost.png' screen file.\n";
            exit(1);
        }
        setPrivateVariables();
    }
    }
}

/**
 * @brief sets background screen specific variables
 * 
 */
void Screen::setPrivateVariables()
{
    screenBckgrnd.setTexture(&mImage);
    screenBckgrnd.setSize(screenSize);
    screenBckgrnd.setOrigin(screenSize.x/2, screenSize.y/2);
    screenBckgrnd.setPosition(screenSize.x/2, screenSize.y/2);
}