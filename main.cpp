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
#include "gameFunctions.h"
#include "classDefinitions/ScreenClass.h"
#include "classDefinitions/audio.h"
#include "classDefinitions/battleship.h"

int main()
{
    //initilize parameters for game operation
    bool startGame=false,shipsDone=false,moveOK=false, gameOver1, gameOver2; 
    int i=0, userMiss=0, userHit=0, computerHit=0, computerMiss=0, triggerCount=0, triggerMove=0, hOm=0, turn=0, pending=0;
    int placeSelect, player, col, playerTag, row;
    int userMove[2];
    vector<RectangleShape> needleTrace;
    
    sf::Text message;
    String delim;

    char board1[NUM_ROWS][NUM_COLS];        //board of player 1 (user)
    char board2[NUM_ROWS][NUM_COLS];        //board of player 2 (computer)
    char boardSeen[NUM_ROWS][NUM_COLS];     //board seen by user (showing hits and misses but not opponent ships)

    initializeBoard(board1);            //user ships
    initializeBoard(board2);            //computer ships
    initializeBoard(boardSeen);         //computer board seen by user

    sf::Font fontStatus;
    if (!fontStatus.loadFromFile("Images/LiquidCrystal-BoldItalic.otf"))
    {
        cout<<"Error loading font file\n";
        exit(1);
    }
    
    //calling window for game display and setting parameters  
    sf::RenderWindow window(sf::VideoMode(1920,1080), "Battleship", sf::Style::Titlebar | sf::Style::Close);
    
    window.setFramerateLimit(60);
    Screen myScreen;
    IntroScreen IntroScreen;       
    sf::ContextSettings settings;
    // settings.antialiasingLevel = 8;
    
    sf::Cursor cursor;
    
    if (cursor.loadFromSystem(sf::Cursor::Hand))
    {   
        window.setMouseCursor(cursor);        
    }
    
    //set texture file for display tiles/arrays
    sf::Texture texture;
    texture.loadFromFile("Images/SpriteTileTextures.png");
    if (!texture.loadFromFile("Images/SpriteTileTextures.png"))
    { 
        std::cout<<"failed to load texture file";
        return 0;
    }      

    //calling sounds
    SoundClass hitSound, missSound, selectionSound;
    MusicClass  trackTwo, trackWin, trackLoss;

    sf::Music trackOne;
    //calling main sound with default class instead of overloaded class

    trackOne.openFromFile("audio/music/trackOne.wav");
  
    trackOne.play();
    sf::Event event;

    //start looping window
    while (window.isOpen())
    {  
        // INTRO SCREEN LOOP
        IntroButton introButtons(sf::Vector2f (600, 500));
        while(!startGame)
        {
            window.draw(IntroScreen.getIntroScreen());
            introButtons.draw(window); 
            while (window.pollEvent(event))
            {
                switch (event.type)
                {   

                    case sf::Event::Closed:
                    {
                        window.close();
                        break;
                        exit(1);
                    }
                    case sf::Event::MouseButtonPressed:
                        if(event.mouseButton.button == sf::Mouse::Left)
                        {
                        //if (user clicks instructions)
                            if(introButtons.isRulesButtonPressed(window,sf::Mouse::getPosition(window)))
                            {
                                selectionSound.play("audio/Sounds/selection.wav");
                                IntroScreen.setScreen("Images/RulesScreen.png");
                                introButtons.makeButtonBlank("Play"," ");
                                introButtons.moveButtons(sf::Vector2f (600, 800));
                            }
                        //else if (user clicks play)
                            if (introButtons.isPlayButtonPressed(window,sf::Mouse::getPosition(window)))
                            {
                                selectionSound.play("audio/Sounds/selection.wav");
                                randomlyPlaceShipsOnBoard(board1);  //place user ships
                                randomlyPlaceShipsOnBoard(board2);  //place opponent ships 
                                startGame=true;     
                            }
                        }
                    }
            }
            window.display();
        }

        trackOne.stop();
        trackTwo.play("audio/music/radarChatter.wav");
        window.display();
        
        //initialize gameOver flags to false
        gameOver1 = isWinner(board1);
        gameOver2 = isWinner(board2); // for computer, only pass board NOT seen by user
        player=1;//user goes first
        playerTag=1;

        message.setString("To Battle stations! \nSelect a Target, Captain.");
        window.draw(myScreen.getScreen());
        do //main game loop
        {   
            i++;
            //DISPLAY MAIN GAME SCREEN and radar
            traceVector(needleTrace,i);
            
            //rendering in the radar shape and texture to display over game board
            sf::CircleShape radar(105);
            radar.setPosition(860,396);
            radar.setTexture(&texture);
            radar.setTextureRect(sf::IntRect(353, 3, 44, 44));
            radar.setOutlineThickness(8);
            radar.setOutlineColor(sf::Color(60,90,90));
            
            //drawing the needle over the trace
            sf::RectangleShape needle(sf::Vector2f(3, 111));
            needle.setPosition(965,501);
            needle.setFillColor(sf::Color(100, 250, 50, 210));
            needle.setOutlineThickness(1);
            needle.setOutlineColor(sf::Color(10,10,10));
            needle.setOrigin(3,5);
            needle.setRotation(i);  
            
            if(triggerMove==0){window.draw(myScreen.getScreen());displayArrayofTiles(boardSeen, texture, window,  0,0);displayArrayofTiles(board1, texture, window, 974, -2);} 
            else if(triggerMove==1)
             {   
                message.setString("   ");
                triggerCount=0;
                triggerMove=2;
                turn++;
            }
            else if(triggerMove==2&&triggerCount==360)
            {
                displayArrayofTiles(boardSeen, texture, window,  0,0);
                displayArrayofTiles(board1, texture, window, 974, -2);//right board
                triggerMove=0;
                if(hOm==1)message.setString("You missed!");
                else if(hOm==2)message.setString("You hit an enemy ship!");
                else if(hOm==3)message.setString("They missed your ship!\nWE have the advantage. Fire!");
                else if(hOm==4)message.setString("They hit one of your ships!\nFIRE BACK!");
                playerTag++;
                pending=0;
            }
            else {triggerCount++;}

            message.setCharacterSize(50);
            message.setPosition(505,815);
            message.setFillColor(sf::Color(100, 250, 50, 150));
            message.setFont(fontStatus);   
            if(turn<2)displayArrayofTiles(board1, texture, window, 974, -2);   
            drawScreen(window,myScreen,radar,needle,needleTrace,message,i);      

            //window.draw(message);
            window.display();//display the layers we've layed down above
            
            if (playerTag==1&& pending==0)//user's turn
            {                     
                //GET USER MOVE
                while(window.pollEvent(event))
                {
                    if (event.type==sf::Event::Closed)
                        {   
                            window.close();
                            exit(1);
                        }
                    else if(event.type == sf::Event::MouseButtonPressed&&event.mouseButton.button == sf::Mouse::Left)//user clicks left
                    {   hOm=0;        
                        mouseClickLocation(event,userMove, texture, window, message);
                        row=userMove[0];
                        col=userMove[1];
                        
                        moveOK = checkShotIsAvailable(row, col, boardSeen);
                        if (moveOK)
                        {   pending=1;                            
                            trackTwo.pause();
                            hOm=updateBoard(row, col, board2, boardSeen,fontStatus,window,message); 
                            if (hOm==1)
                            {
                                missSound.play("audio/Sounds/BombMiss.wav");
                                triggerMove=1;
                            }
                            else if (hOm==2)
                            {   
                                hitSound.play("audio/Sounds/BombHit.wav");
                                triggerMove=1;
                            }
                            trackTwo.play("audio/music/radarChatter.wav");
                        }
                        else 
                        {
                            message.setString("Not a valid move. Try again.");
                        }
                    }
                }  
            }
               
            if(playerTag==2)//computer's turn
            {   
                if(!moveOK)
                { 
                    message.setString("\n Incoming attack!!!");
                    window.draw(message); 
                    window.display();
                    row=rand()%10;
                    col=rand()%10;
                
                    moveOK = checkShotIsAvailable(row, col, board1);
                    
                    if(moveOK)
                    {  
                        playerTag=0;
                        trackTwo.pause();
                        hOm=computerUpdateBoard(row,col,board1,window,message);
                        if (hOm==3)
                        {
                            missSound.play("audio/Sounds/BombMiss.wav");
                            triggerMove=1;
                        }
                        else if (hOm==4)
                        {
                            hitSound.play("audio/Sounds/BombHit.wav");
                            triggerMove=1; 
                        }
                        trackTwo.play("audio/music/radarChatter.wav");
                    }
                    else 
                    {
                        message.setString("                ");
                    }     
                }
                moveOK=false;
            }

                gameOver1 = isWinner(board1);
                gameOver2 = isWinner(board2); // for computer, only pass board NOT seen by user

                if(gameOver1==true||gameOver2==true) //game over
                {   
                    trackTwo.stop();
                    if (player==1)
                        {trackWin.play("audio/music/winScreen.wav");}
                    else
                    {
                        trackLoss.play("audio/music/lossScreen.wav");
                    }
                    sleep(1);
                    message.setString( "   G A M E   O V E R !  ");
                    window.clear();
                    window.draw(message);
                    window.display();
                    
                    sleep(1);//need to change to game time offset
                    if (player==1){myScreen.updateScreen(1,window);}
                    else if (player==2){myScreen.updateScreen(2,window);}
                    window.draw(myScreen.getScreen());
                    window.display();
                    sleep(25);
                    exit(3);
                }       
        }while(!gameOver1||!gameOver2&&shipsDone);   
    }
    return 0;
}
