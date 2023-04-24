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

    sf::RenderWindow window(sf::VideoMode(1920,1080), "Battleship");
    Screen myScreen;                                                    //MAKE THIS PLAYSCREEN BACKGROUND
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
        
        window.clear();
        window.draw(myScreen.getScreen());
        window.display();
    }

    return 0;
}
