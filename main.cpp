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



//g++ *.cpp -o test   -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio
//
//
//// SEE 'gameFunctions.cpp' FOR TENTATIVE MAIN GAME FUNCTION PSEUDOCODE, STILL ROUGH SKETCH
//
//
//


int main()
{
    //initilize parameters for game operation
    bool startGame=false; 
    int i=0;
    int userMove[2];
    vector<RectangleShape> needleTrace;
    sf::Text message;
    
    int placeSelect, player, col, row;
    bool moveOK=false, gameOver1, gameOver2;

    int userMiss=0;
    int userHit=0;
    int computerHit=0;
    int computerMiss=0;

    char board1[NUM_ROWS][NUM_COLS]; //initializes array for the board of player 1 (user)
    char board2[NUM_ROWS][NUM_COLS]; //initializes array for the board of player 2 (computer)
    char boardSeen[NUM_ROWS][NUM_COLS]; //initializes array for board seen by user (showing hits and misses but not opponent ships)
    //welcomeScreen();
    initializeBoard(board1); //user ships
    initializeBoard(board2); //computer ships
    initializeBoard(boardSeen); //computer board seen by user

    sf::Font fontStatus;
        if (!fontStatus.loadFromFile("Images/LiquidCrystal-BoldItalic.otf"))
        {
            cout<<"error loading font file\n";
            exit(1);
        }
    

    //calling window for game display and setting parameters  
    sf::RenderWindow window(sf::VideoMode(1920,1080), "Battleship");
    Screen myScreen;
    IntroScreen IntroScreen;       
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    
    //set texture file for display tiles/arrays
    sf::Texture texture;
    texture.loadFromFile("Images/SpriteTileTextures.png");
        if (!texture.loadFromFile("Images/SpriteTileTextures.png"))
        { std::cout<<"failed to load texture file";
        exit (1);
        }           


    //calling sounds
    SoundClass hitSound, missSound;
    MusicClass  trackTwo;
    sf::Sound trackOne;
    //calling main sound with default class instead of overloaded class
    
    sf::SoundBuffer bufferOne;
    if (!bufferOne.loadFromFile("audio/music/trackOne.wav"))
    {
        cout<<"error...";
    }
    trackOne.setBuffer(bufferOne);
    trackOne.play();
    //start looping window
    while (window.isOpen())
    {
        sf::Event event;
        
        while(!startGame)
        {
                        // DISPLAY INTRO SCREEN
                        while (window.pollEvent(event))
                        {
                            window.draw(IntroScreen.getIntroScreen());
                            IntroButton introButtons(sf::Vector2f (600, 500));
                            introButtons.draw(window);   
                            if (event.type == sf::Event::Closed)
                                window.close();
                            else if(event.type == sf::Event::MouseButtonPressed&&event.mouseButton.button == sf::Mouse::Left)//user clicks left
                            {
                                //if (user clicks instructions)
                                if(introButtons.isRulesButtonPressed(window,sf::Mouse::getPosition(window)))
                                {
                                    //std::cout<<"They pressed the rules button"<<std::endl;
                                    // hitSound.play("audio/Sounds/BombHit.wav");
                                    //showInstructions(window, myScreen);
                                }
                                //else if (user clicks play)
                                if (introButtons.isPlayButtonPressed(window,sf::Mouse::getPosition(window)))
                                {
                                    // /
                                    startGame=true;
                                    //std::cout <<"They pressed the play button"<<std::endl;
                                    //playGame(window, myScreen);
                                }
                            }
                        }
                        window.display();
        }
        trackOne.stop();
        trackTwo.play("audio/radarChatter.wav");
        window.display();
        cout << "You have chosen to randomly place your ships.\n";
        randomlyPlaceShipsOnBoard(board1);
        //place opponent ships
        randomlyPlaceShipsOnBoard(board2);

        //test console displays
        displayBoard(1,board1);
        displayBoard(2,board2);

        //create and open log file, we can use to test stuff and remove later if wanted
        ofstream logFile;
        logFile.open("battleship.log");
        
        //initialize gameOver flags to false
        gameOver1 = isWinner(board1);
        gameOver2 = isWinner(board2); // for computer, only pass board NOT seen by user
        player=1;//user goes first
        message.setString("To start the game \nSelect a Target, Captain.");
        while (!gameOver1 && !gameOver2) //main game loop
        {   i++;
            //DISPLAY MAIN GAME SCREEN and radar
            window.draw(myScreen.getScreen());
            if(i<200){
            needleTrace.push_back(RectangleShape());
            needleTrace.back().setSize(sf::Vector2f(2, 116));
            needleTrace.back().setPosition(965,501);
            needleTrace.back().setOrigin(1,10);
            needleTrace.back().setFillColor(sf::Color(100,250,50, 200-(i)));}
            //window.draw(myScreen.getScreen());       
            
            //rendering in the radar shape and texture to display over game board
            sf::CircleShape radar(105);
            radar.setPosition(860,396);
            radar.setTexture(&texture);
            radar.setTextureRect(sf::IntRect(353, 3, 44, 44));
            radar.setOutlineThickness(8);
            radar.setOutlineColor(sf::Color(60,90,90));
            
            window.draw(radar);
            
            //drawing the needle over the trace
            sf::RectangleShape needle(sf::Vector2f(3, 111));
            needle.setPosition(965,501);
            needle.setFillColor(sf::Color(100, 250, 50, 210));
            needle.setOutlineThickness(1);
            needle.setOutlineColor(sf::Color(10,10,10));
            needle.setOrigin(3,5);
            needle.setRotation(i);  
            
            //loop needed to make the needle trace fade correctly
            for(int k=0; k<needleTrace.size();k++)
            {
                needleTrace[k].setRotation((-k)+i);
                window.draw(needleTrace[k]);
            }
            window.draw(needle);

            displayArrayofTiles(board1, texture, window, 974, -2);//right board
            displayArrayofTiles(boardSeen, texture, window,  0,0);//left board 
            message.setCharacterSize(50);
            message.setPosition(505,815);
            message.setFillColor(sf::Color(100, 250, 50, 150));
            message.setFont(fontStatus);
            
            window.draw(message);


            window.display();
                if (player==1)//user's turn
                {
                    logFile << "Player1: ";
                    
                    window.display();
                    
                    do //get valid move location
                    { 
                        //GET USER MOVE
                        if(window.pollEvent(event))
                        {
                            if (event.type == sf::Event::Closed)
                                window.close();
                            else if(event.type == sf::Event::MouseButtonPressed&&event.mouseButton.button == sf::Mouse::Left)//user clicks left
                            {   int hOm=0;
                                mouseClickLocation(event,userMove, texture, window, message);
                                userMove[0];
                                userMove[1];
                                row=userMove[0];
                                col=userMove[1];
                                moveOK = checkShotIsAvailable(userMove[0], userMove[1], boardSeen);     //row and col may be switched
                                if (moveOK)
                                {   
                                    trackTwo.pause();
                                    hOm=updateBoard(row, col, board2, boardSeen, logFile, userHit,userMiss,fontStatus,window,message); 
                                    if (hOm==1){missSound.play("audio/Sounds/BombMiss.wav");}
                                    else if (hOm==2){hitSound.play("audio/Sounds/BombHit.wav");}
                                    trackTwo.play("audio/radarChatter.wav");
                                }
                                else 
                                {
                                    message.setString("Not a valid move. Try again.");
                                }
                            }
                        }
                       
                    } while (!moveOK);
                }
                /*else if(player==2)//computer's turn
                {
                    logFile << "Player2: ";
                    displayPrompt("Incoming attack!!!",font,window,message);
                    do //get valid move location
                    {
                        row=rand()%10+1;
                        col=rand()%10+1;
                        row--;
                        col--;
                        moveOK = checkShotIsAvailable(row, col, board1);
                        if(moveOK)
                        {
                            int hitLocation = checkShot(row, col, board1);
                            int shipLength = SHIP_SIZES[hitLocation];
                            int shipChar = SHIP_SYMBOLS[hitLocation];
                
                            if (hitLocation==-1)//hit was a miss
                            {
                                logFile<<row+1<<","<<col+1<<" Miss!"<<endl;
                                displayPrompt("The enemy missed!",fontStatus,window);
                                board1[row][col]='m';
                                computerMiss++;
                            }
                            else
                            {
                                logFile <<row<<","<<col<<" Hit! ";
                                displayPrompt("The enemy hit one of your ships!",fontStatus,window);
                                sleep(3);
                                board1[row][col]='*';
                                computerHit++;
                                if (checkIfSunk(shipLength,shipChar,board1)) //check if sunk
                                {
                                    logFile << SHIP_NAMES[hitLocation] << " sunk!";
                                    cout << SHIP_NAMES[hitLocation] << " sunk!";
                                    displayPrompt("The enemy sunk "+SHIP_NAMES[hitLocation],fontStatus,window);
                                }
                                logFile << endl;
                            }
                        }

                    } while (!moveOK); 
                    displayArrayofTiles(board1,texture,window,0,0); 
                    sleep(3);
                }             
                */
                gameOver1 = isWinner(board1);
                gameOver2 = isWinner(board2); // for computer, only pass board NOT seen by user

                if(gameOver1==true||gameOver2==true) //game over
                {   trackTwo.stop();
                    trackOne.play();
                    sleep(3);
                    message.setString( "   G A M E   O V E R !  ");
                    window.clear();
                    window.draw(message);
                    window.display();
                    
                    sleep(5);//need to change to game time offset
                    if (player==1){myScreen.updateScreen(1,window);}
                    else if (player==2){myScreen.updateScreen(2,window);}
                    window.draw(myScreen.getScreen());
                    window.display();
                    sleep(25);
                    logFile << "Player " << player << " wins! ";
                    logFile << "Player " << switchPlayer(player) << " loses. ";
                    outputStats(logFile, userHit, userMiss, computerHit, computerMiss);
                    exit(3);
                }
                else //game still going
                {
                    //player=switchPlayer(player);
                    //system("clear"); 
                }
            
        }

    logFile.close();       
    
        
        }
}
    

