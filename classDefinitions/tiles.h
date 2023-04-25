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

enum state {base, shipF, shipM, shipR, clicked, hit, miss};  //maybe this is what we want to use for states of tiles? 
            //Obviously if we just use an if statement in the class to recognize the array value that is good for rendering, 
            //but we can define these states by that I think. 

class Tile : public sf::Drawable
{
public: 
    Tile();
    Tile(sf::Vector2f position, sf::Vector2f size, char arrayX,char arrayY);//need to clarify the array position type and if it's one char or a pair
    //SEE BELOW FOR PROPOSED CONSTRUCTOR(end of this file)
    //***
    //***


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
    sf::RectangleShape mTile;   //this may be easier than Sprite... I didn't remove the previous line cause I didn't want squiggles lol but
                                //  rectangleshapes are easier to work with
    sf::Texture mTexture;       //image that tile displays  (hit icon, miss icon, blank square)
    int arrayLoc[2];            // holds location within array, assigned at creation of Tile; {x,y}
    sf::Vector2f mPosition;     // assigned with the function outlined below
    char mBtnState;             //char may be easier to check in main... was originally uint32
    //sf::Text mText;           //not necessary
};

/**
 * @author Lacey
 * @brief 
 * 
 * pseudocode proposition for array location->tile location:
 * 
 * My thought is that since the tiles are drawn from the top left corner of each square,
 *      when the tile is being created, they will be assigned an array location instead of a pixel position.
 * The pixel position of each tile will be determined by the aforementioned array location, simplifying logic
 *      outside the class.
 * The following function will acceot the member variable "arrayLoc" and return "mPosition" 
 * 
 * 
 * sf::Vector2f tileToLocation(int arrayLoc[2])        //not sure if the type is correct, but will return position to be drawn
 * {
 *      Vector2f pos={ (200+arrayLoc[0]*50), (200+arrayLoc[1]*50) };        //{x,y}
 *      return pos;
 * }
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * So in the constructor:
 * Tile(char status, int arrayLocation[2])
 * {
 *      sf::Texture image;
 *      if(status=='b')//if creating blank tile, should be blank if constructor but this it to show
 *      {
 *          if(!image.loadFromFile("Images/SpriteTile.png"))
 *          {
 *              std::cout<<"Error opening 'SpriteTile.png' screen file.\n";
 *              exit(1);
 *          }
 *      }
 *      Vector2f position=tileToLocation(arrayLocation);        //function outlined above
 *      mTile.setTexture(&image);
 *      mTile.setSize({50,50});
 *      mTile.setOrigin(25,25);                         //middle of tile
 *      mTile.setPosition(position.x, position.y);      //not sure if some dividing factor is needed here, this is just outline for now
 * }
 * 
 * 
 * Then when a turn is taken and something is hit or miss:
 * void changeTile(char status, int arrayLocation[2])
 * {
 *      if(status=='h')
 *      {
 *          open correct tile image and assign to mTexture
 *      }
 * }
 */

#endif