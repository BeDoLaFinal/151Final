/**
 * @file    tiles.h
 * @author  Dominic Acia
 * @brief   tiles class information for interactive display
 * @date    2023-04-17
 * 
 */

#ifndef TILES_H
#define TILES_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Tile : public sf::Drawable
{
public: 
    Tile(){};
    Tile(sf::Vector2f position, sf::Vector2f size, int arrayX,int arrayY)
    { 
        setPosition(position);
        setSize(size);
        arrayLocationx=arrayX;
        arrayLocationy=arrayY;
        mTexture.loadFromFile("Images/SpriteTileMiss.png");

    }; 
    ~Tile(){};
    void setState(char ta[11][11], Tile ta2[11][11]);//I'm assuming we're using Char for the array identifier/input. 
    void setPosition(sf::Vector2f position)//I just copy pasted these two functions from the lab, I haven't tweaked them for our purpose at all yet. 
    {   
        mPosition=position;
        mButton.setPosition(position);
        mText.setPosition(position.x, position.y-mText.getCharacterSize()/4);
        
    }
    void setSize(sf::Vector2f  size)// I just copy pasted these two functions from the lab, I haven't tweaked them for our purpose at all yet. 
    {
        sf::Vector2u imageSize=mTexture.getSize();
        mButton.setScale(size.x/imageSize.x, size.y/imageSize.y);
        mText.setCharacterSize(mButton.getGlobalBounds().height/2);
        mText.setOrigin(mText.getGlobalBounds().width/2, mText.getGlobalBounds().height/2);
        mText.setPosition(mPosition.x, mPosition.y-mText.getCharacterSize()/4);

    }
    sf::Vector2f getPosition()
    {
        return mPosition;
    }
    sf::Vector2f getDimensions()
    {
        return sf::Vector2f(mButton.getGlobalBounds().width, mButton.getGlobalBounds().height);
    }
    sf::Uint32 getState()
    {
        return mBtnState;
    }
    virtual void draw(sf::RenderTarget& target,sf::RenderStates states) const{};

private:
    sf::Sprite mButton;
    sf::Texture mTexture;    
    sf::Vector2f mPosition;
    sf::Uint32 mBtnState;
    sf::Text mText;
    int arrayLocationx;
    int arrayLocationy;

};

void needleDesign(sf::RectangleShape needle, int i,sf::RenderWindow &window);

#endif