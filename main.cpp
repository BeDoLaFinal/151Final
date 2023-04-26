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
    texture.loadFromFile("Images/SpriteTileMiss1.png");
        if (!texture.loadFromFile("Images/SpriteTileMiss1.png"))
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
        displayArrayofTiles(playertileArray, texture, window, 0,0);//this displays left board
        displayArrayofTiles(playertileArray, texture, window, 974, -2); //this will display the status array on right side of board
        window.display();

        
       
    }

    return 0;
}
