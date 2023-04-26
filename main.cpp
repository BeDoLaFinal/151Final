/**
 * @file    main.cpp
 * @author  Ben Givens, Dominic Acia, Lacey Hunt
 * @brief   Main game for battleship final project.
 *              All team members contributed
 * @date    2023-04-23
 * 
 */
#include "classDefinitions/introScreen.h"
#include "classDefinitions/tiles.h"
#include "gameLogic/battleship.h"
#include "gameFunctions.h"
#include "classDefinitions/ScreenClass.h"


//
//
//
//// SEE 'gameFunctions.cpp' FOR TENTATIVE MAIN GAME FUNCTION PSEUDOCODE, STILL ROUGH SKETCH
//
//
//


int main()
{
    int userMove[2];
    char playertileArray[10][10];
    createTileArray(playertileArray);
    
    sf::RenderWindow window(sf::VideoMode(1920,1080), "Battleship");
    Screen myScreen;      
    sf::Texture texture;
    texture.loadFromFile("Images/SpriteTileMiss.png");
        if (!texture.loadFromFile("Images/SpriteTileMiss.png"))
    { std::cout<<"failed to load texture file";
    exit (1);
    }                                              //MAKE THIS PLAYSCREEN BACKGROUND
    //testingPurposes(window);
 
    while (window.isOpen())
    {
        sf::Event event;
        //DISPLAY INTRO SCREEN
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            
            //myScreen.updateScreen(event,window); //used to test
            else if(event.type == sf::Event::MouseButtonPressed&&event.mouseButton.button == sf::Mouse::Left)//user clicks left
            {
                //for testing, shows location of click
                mouseClickLocation(event,userMove);
                
                //if (user clicks instructions)
                showInstructions(window, myScreen);

                //else if (user clicks play)
                playGame(window, myScreen);
            }
        }
        
        //window.clear();
        window.draw(myScreen.getScreen());
        sf::Sprite tile(texture);
            
            // tile.setPosition(sf::Vector2f(200, 200));
            // if(playertileArray[2][2]=='*')
            // {
            // tile.setTextureRect(sf::IntRect(0, 0, 50, 50));}
            // else {tile.setTextureRect(sf::IntRect(0, 0, 50, 50));}
            // window.draw(tile);
            //  window.display();

        

    int x=0;
    int count=0;
    

     
    //create tile out here . . .
    for(float i=221; i<675; i+=50)//i=0 is only for test. i should equal the top left corner of tile board, approx 200.
    {
        
        for(float j=200; j<659; j+=50) //j=0 is only for test. j should equal the top left corner of tile board, approx 200.
        {   
            int y= 0+count;            
            // sf::Sprite tile;
            
            tile.setPosition(sf::Vector2f(i, j));
            window.draw(tile);
            if(playertileArray[x][y]=='*')
            {
            tile.setTextureRect(sf::IntRect(0, 0, 50, 50));}
            else {tile.setTextureRect(sf::IntRect(0, 0, 25, 25));}
            
             
            //ta[x][y]=boardTile; //assuming arrays are in char Letter/Number format
            //. . . and reassign here? so we don't have to create a ton at once
            count++;

        }
        count=0;
        x++;
    }

        window.display();

        //displayArrayofTiles(playertileArray);
       
    }

    return 0;
}
