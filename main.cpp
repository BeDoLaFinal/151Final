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
#include "classDefinitions/audio.h"


//g++ *.cpp -o test -lpthread -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio
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
    IntroScreen IntroScreen;       
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
  //  testingPurposes(window);
    sf::Texture texture;
    texture.loadFromFile("Images/SpriteTileTextures.png");
        if (!texture.loadFromFile("Images/SpriteTileTextures.png"))
        { std::cout<<"failed to load texture file";
        exit (1);
        }           
    bool startGame=false;                         
    String mouseClick;
    SoundClass hitSound, missSound;
    MusicClass trackOne, trackTwo;
    while (window.isOpen())
    {
        sf::Event event;
        trackOne.play("audio/music/trackOne.wav");
        while(!startGame)
        {
            // DISPLAY INTRO SCREEN
            while (window.pollEvent(event))
            {
                window.draw(IntroScreen.getIntroScreen());
                IntroButton introButtons(sf::Vector2f (600, 800));
                introButtons.draw(window);   
                if (event.type == sf::Event::Closed)
                    window.close();
                //myScreen.updateScreen(event,window); //used to test
                else if(event.type == sf::Event::MouseButtonPressed&&event.mouseButton.button == sf::Mouse::Left)//user clicks left
                {
                    //if (user clicks instructions)
                    if(introButtons.isRulesButtonPressed(window,sf::Mouse::getPosition(window)))
                    {
                        std::cout<<"They pressed the rules button"<<std::endl;
                        hitSound.play("audio/Sounds/BombHit.wav");
                        showInstructions(window, myScreen);
                    }
                    //else if (user clicks play)
                    if (introButtons.isPlayButtonPressed(window,sf::Mouse::getPosition(window)))
                    {
                        missSound.play("audio/Sounds/BombMiss.wav");
                        startGame=true;
                        std::cout <<"They pressed the play button"<<std::endl;
                        playGame(window, myScreen);
                    }
                }
            }
            window.display();
        }
        trackOne.stop();
        trackTwo.play("radarChatter.wav");
        bool gameLoop=false;
        while (!gameLoop)
        {
        // DISPLAY MAIN GAME SCREEN
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            //myScreen.updateScreen(event,window); //used to test
            else if(event.type == sf::Event::MouseButtonPressed&&event.mouseButton.button == sf::Mouse::Left)//user clicks left
            {
                //for testing, shows location of click
                mouseClick=mouseClickLocation(event,userMove, texture, window);
            }
        }
        window.draw(myScreen.getScreen());
        if(i<200){
        needleTrace.push_back(RectangleShape());
        needleTrace.back().setSize(sf::Vector2f(2, 116));
        needleTrace.back().setPosition(965,501);
        needleTrace.back().setOrigin(1,10);
        needleTrace.back().setFillColor(sf::Color(100,250,50, 200-(i)));}
       // window.clear();
        window.draw(myScreen.getScreen());
    //     sf::Sprite tile(texture);        
  
        displayArrayofTiles(playertileArray, texture, window, 0,0);//this displays left board
        displayArrayofTiles(playertileArray, texture, window, 974, -2); //this will display the status array on right side of board
        //window.display();
        displayPrompt(mouseClick, fontStatus,window);  
         
        sf::CircleShape radar(105);
        //radar.setFillColor(sf::Color(5,5,5,90));
        radar.setPosition(860,396);
        radar.setTexture(&texture);
        radar.setTextureRect(sf::IntRect(353, 3, 44, 44));
        radar.setOutlineThickness(8);
        radar.setOutlineColor(sf::Color(60,90,90));
        
        window.draw(radar);
         
        sf::RectangleShape needle(sf::Vector2f(3, 111));
        needle.setPosition(965,501);
        needle.setFillColor(sf::Color(100, 250, 50, 210));
        needle.setOutlineThickness(1);
        needle.setOutlineColor(sf::Color(10,10,10));
        needle.setOrigin(3,5);
        needle.setRotation(i);  
         
        for(int k=0; k<needleTrace.size();k++)
        {
            needleTrace[k].setRotation((-k)+i);
            window.draw(needleTrace[k]);
        }
        window.draw(needle);
        
        window.display();
        i++;
        }
    }
    return 0;
}
