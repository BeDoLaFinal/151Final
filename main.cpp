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


//g++ *.cpp -o test -lpthread -lsfml-system -lsfml-window -lsfml-graphics
//
//
//// SEE 'gameFunctions.cpp' FOR TENTATIVE MAIN GAME FUNCTION PSEUDOCODE, STILL ROUGH SKETCH
//
//
//


int main()
{
    int i=0;
    int userMove[2];
    char playertileArray[10][10];
    vector<RectangleShape> needleTrace;
    

    createTileArray(playertileArray);
    sf::Font fontStatus;
        if (!fontStatus.loadFromFile("Images/LiquidCrystal-BoldItalic.otf"))
        {
            cout<<"error loading file\n";
            exit(1);
        }
    
    sf::RenderWindow window(sf::VideoMode(1920,1080), "Battleship");
    Screen myScreen;      
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::Texture texture;
    texture.loadFromFile("Images/SpriteTileTextures.png");
        if (!texture.loadFromFile("Images/SpriteTileTextures.png"))
        { std::cout<<"failed to load texture file";
        exit (1);
        }           
                                      
    String mouseClick;
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
                mouseClick=mouseClickLocation(event,userMove, texture, window);
                
                //if (user clicks instructions)
                showInstructions(window, myScreen);

                //else if (user clicks play)
                playGame(window, myScreen);
            }
             
       
        
        }

          if(i<180){
        needleTrace.push_back(RectangleShape());
        needleTrace.back().setSize(sf::Vector2f(4, 116));
        needleTrace.back().setPosition(965,501);
        needleTrace.back().setOrigin(2,10);
        needleTrace.back().setFillColor(sf::Color(100,250,50, 180-(i)));}


       // window.clear();
        window.draw(myScreen.getScreen());
        sf::Sprite tile(texture);        
  
        displayArrayofTiles(playertileArray, texture, window, 0,0);//this displays left board
        displayArrayofTiles(playertileArray, texture, window, 974, -2); //this will display the status array on right side of board
        //window.display();
        displayPrompt(mouseClick, fontStatus,window);
        
         
        sf::CircleShape radar(110);
        //radar.setFillColor(sf::Color(5,5,5,90));
        radar.setPosition(855,391);
        radar.setTexture(&texture);
        radar.setTextureRect(sf::IntRect(350, 0, 50, 50));
        radar.setOutlineThickness(5);
        radar.setOutlineColor(sf::Color(110,250,70));
        
        window.draw(radar);
        sf::RectangleShape needle(sf::Vector2f(8, 116));
        needle.setPosition(965,501);
        needle.setFillColor(sf::Color(100, 250, 50, 166));
        needle.setOrigin(5,10);
        needle.setRotation(i);  
        window.draw(needle);
        
        for(int k=0; k<needleTrace.size();k++)
        {
            needleTrace[k].setRotation((-2*k)+i);
            window.draw(needleTrace[k]);
        }

       
       
        
        
        window.display();
        i+=4;
        
        

        
    }
    return 0;
}
