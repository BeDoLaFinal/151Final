/**
 * @file    introScreen.cpp
 * @author  Ben Givens
 * @brief   Contains the definitions for the functions in the introscreen.h files
 * @date    2023-04-23
 * 
 */
#include "classDefinitions/introScreen.h"
/**
 * @brief Constructs the Intro and Rules buttons
 * @param position the location of the play button
 */
IntroButton::IntroButton(sf::Vector2f position)
{

    //Create the font by loading from file
    font.loadFromFile("Images/LiquidCrystal-BoldItalic.otf");

    //playButton Setup
    playButton.setSize(sf::Vector2f(200,100)); //Sets the size of the button
    playButton.setPosition(position.x, position.y); //Sets the posistion of the button based on the Y and X axis
    playButton.setFillColor(sf::Color::Red); //Color of the button

    //rulesButton Setup
    rulesButton.setSize(sf::Vector2f(200,100));//Sets the size of the button
    rulesButton.setPosition(position.x+480, position.y);//Sets the posistion of the button based on the Y and X axis
    rulesButton.setFillColor(sf::Color::Green);//Color of the button

    //Labels for play and rule buttons
    playLabel.setFont(font);//Sets the font of the play button based off of what was previous loaded into font
    playLabel.setString("Play");//The string value that displays on the play button.
    playLabel.setCharacterSize(30);//Sets The size of the words on the button
    playLabel.setFillColor(sf::Color::White);//Sets the color of the letters
    playLabel.setPosition(position.x+70, position.y+30);//Sets the posistion offset from the button

    rulesLabel.setFont(font);//Sets the font of the rules button
    rulesLabel.setString("Rules"); //Sets the string value which displays on the button
    rulesLabel.setCharacterSize(30);//Sets size of the words on the button
    rulesLabel.setFillColor(sf::Color::White);//Color of the letters
    rulesLabel.setPosition(position.x+540, position.y+30);//Sets posistion offset from the button

}
/**
 * @brief Writes the two buttons and labels onto the window 
 * 
 * @param window the window provided for the program
 */
void IntroButton::draw(sf::RenderWindow& window){
    window.draw(playButton);//Displays the play button on the window
    window.draw(rulesButton);//Displays the Rules button on the window
    window.draw(playLabel);//Displays the play label
    window.draw(rulesLabel);//Displays the rules label
}
/**
 * @brief Returns true if the play button has been pressed
 * @param window The window for the game
 * @param mousePosition the location of the users mouse
 * @return true if the button has been pressed
 * @return false if not pressed
 */
bool IntroButton::isPlayButtonPressed(sf::RenderWindow& window,sf::Vector2i mousePosition){
    sf::Vector2f mousePos=window.mapPixelToCoords(mousePosition);
    if (playButton.getGlobalBounds().contains(mousePos)){
        return true;
    }
    return false;
}
/**
 * @brief Returns true if the Rules button has been pressed
 * @param window The window for the game
 * @param mousePosition the location of the users mouse
 * @return true if the button has been pressed
 * @return false if not pressed
 */
bool IntroButton::isRulesButtonPressed(sf::RenderWindow& window,sf::Vector2i mousePosition){
    sf::Vector2f mousePos=window.mapPixelToCoords(mousePosition);
    if (rulesButton.getGlobalBounds().contains(mousePos)){
        return true;
    }
    return false;
}
/**
 * @brief Constructs a the Intro Screen
 * 
 */
IntroScreen::IntroScreen()
{
    if(!mImage.loadFromFile("IntroScreen.png"))
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
RectangleShape IntroScreen::getIntroScreen()
{
    return screenBckgrnd;
}
/**
 * @brief sets background screen specific variables
 * 
 */
void IntroScreen::setPrivateVariables(sf::Texture &i,float scale)
{
    screenBckgrnd.setTexture(&mImage);
    screenBckgrnd.setSize({screenSize.x/scale,screenSize.y/scale});
    screenBckgrnd.setOrigin(0, 0);
    screenBckgrnd.setPosition(0,0);
    
}