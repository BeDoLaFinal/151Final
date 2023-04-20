/**
 * @file tiles.h
 * @author Dominic Acia
 * @brief  tiles class information for interactive display
 * @version 0.1
 * @date 2023-04-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef TILES_H
#define TILES_H

#include <SFML/Graphics.hpp>
#include <iostream>
 
 

enum state {base, shipF, shipM, shipR, clicked, hit, miss};  //maybe this is what we want to use for states of tiles? Obviously if we just use an if statement in the class to recognize the array value that is good for rendering, but we can define these states by that I think. 

class Tile : public sf::Drawable
{
public: 
    Tile();
    Tile(sf::Vector2f position, sf::Vector2f size, char arrayX,char arrayY);//need to clarify the array position type and if it's one char or a pair
    ~Tile(){};
    void getState(char row, char col);//I'm assuming we're using Char for the array identifier/input. 
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
    void update(sf::Event& e, sf::RenderWindow& window);
    virtual void draw(sf::RenderTarget& target,sf::RenderStates states) const;

private:
    sf::Sprite mButton;
    sf::Texture mTexture;    
    sf::Vector2f mPosition;
    sf::Uint32 mBtnState;
    sf::Text mText;

    
   
    
};

#endif