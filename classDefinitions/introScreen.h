/**
 * @file    introScreen.h
 * @author  Ben Givens
 * @brief 
 * @date    2023-04-23
 * 
 */
#ifndef INTROSCREEN_H
#define INTROSCREEN_H
#include <SFML/Graphics.hpp>
#include <iostream>
using std::cout;
using std::endl;
using namespace sf;
/**
 * @brief Class for the intro button and rules button
 * 
 */
class IntroButton{
public:
    IntroButton(sf::Vector2f position);
    void draw(sf::RenderWindow& window);
    bool isPlayButtonPressed(sf::RenderWindow& window,sf::Vector2i mousePosition);
    bool isRulesButtonPressed(sf::RenderWindow& windowsf,sf::Vector2i mousePosition);
private:
    sf::RectangleShape playButton;
    sf::RectangleShape rulesButton;
    sf::Text playLabel;
    sf::Text rulesLabel;
    sf::Font font;
    sf::Text logo;
    sf::Font logoFont;
    sf::Text logo2;

};

/**
 * @brief   Class for intro screen
 * @author  Ben/Lacey
 * 
 */
class IntroScreen
{
public:
    IntroScreen();
    RectangleShape getIntroScreen();
private:
    void setPrivateVariables(sf::Texture &i,float scale=1);
    RectangleShape screenBckgrnd;
    Texture mImage;
    Vector2f screenSize={1920,1080};
};
#endif