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
};

void testingPurposes(sf::RenderWindow& window);

#endif