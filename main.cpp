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
    vector<RectangleShape> needleTrace;
    
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
                                    //showInstructions(window, myScreen);
                                }
                                //else if (user clicks play)
                                if (introButtons.isPlayButtonPressed(window,sf::Mouse::getPosition(window)))
                                {
                                    missSound.play("audio/Sounds/BombMiss.wav");
                                    startGame=true;
                                    std::cout <<"They pressed the play button"<<std::endl;
                                    //playGame(window, myScreen);
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
            
                    displayArrayofTiles(board1, texture, window, 0,0);//this displays left board
                    displayArrayofTiles(boardSeen, texture, window, 974, -2); //this will display the status array on right side of board
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





    //User determines ship placement
   /* do
    {
        cout << "Select how you would like to place your ships:\n";

        cout << "1. Manually Place\n2. Randomly Place\n";
        cin>>placeSelect;
        cin.ignore();
        if(placeSelect<1 || placeSelect>2)
        {
            cout << "Invalid Entry. ";
        }
    } while (placeSelect<1 || placeSelect>2);*/

    //user chose manual placement
    /*if(placeSelect==1)
    {
        displayPrompt("Manually placing your ships...", fontStatus,window); 
        manuallyPlaceShipsOnBoard(board1);
    }*/
    //user chose random placement
    //else if(placeSelect==2)
    //{
        cout << "You have chosen to randomly place your ships.\n";
        randomlyPlaceShipsOnBoard(board1);
    displayArrayofTiles(board1, texture, window, 0,0);//this displays left board
    displayBoard(1,board1);
    //}
} 
    //place opponent ships
    randomlyPlaceShipsOnBoard(board2);

    //displayBoard(1, board1);
    displayArrayofTiles(board1, texture, window, 0,0);//this displays left board
    displayArrayofTiles(board2, texture, window,  974, -2);//this displays right board

 /**COMMENT SECTION START
    //sleep(4);
    //pressEnterToContinue();
    //system("clear");

    player = selectOrSwitchPlayer(-1); //select first player
    //displayBoard(2,boardSeen); //only shows dashes since no spots guessed yet

    //create and open log file
    ofstream logFile;
    logFile.open("battleship.log");
    
    //initialize gameOver flags to false
    gameOver1 = isWinner(board1);
    gameOver2 = isWinner(board2); // for computer, only pass board NOT seen by user

    while (!gameOver1 && !gameOver2) //while game not over
    {
        if (player==1)//user's turn
        {
            //displayBoard(player+1, boardSeen);//Displays the player's board when the computer is making their move
            logFile << "Player1: ";
            do //get valid move location
            {
                banner(player,fontStatus,window);
                //GET USER MOVE
                while (window.pollEvent(event))
                    {
                        if (event.type == sf::Event::Closed)
                            window.close();
                        else if(event.type == sf::Event::MouseButtonPressed&&event.mouseButton.button == sf::Mouse::Left)//user clicks left
                        {
                            mouseClick=mouseClickLocation(event,userMove, texture, window);
                        }
                    }
                userMove[0]--;
                userMove[1]--;
                moveOK = checkShotIsAvailable(userMove[0], userMove[1], boardSeen);     //row and col may be switched
                if (moveOK)
                {
                    updateBoard(row, col, board2, boardSeen, logFile, userHit,userMiss,fontStatus,window); //check shot and update board
                }
                else 
                {
                    displayPrompt("Not a valid move. Try again.",fontStatus,window);
                }
            } while (!moveOK);
            displayArrayofTiles(boardSeen,texture,window,974,-2);
        }
        else if(player==2)//computer's turn
        {
            logFile << "Player2: ";
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
        
        gameOver1 = isWinner(board1);
        gameOver2 = isWinner(board2); // for computer, only pass board NOT seen by user

        if(gameOver1==true||gameOver2==true) //game over
        {
            cout << "\n----- G A M E   O V E R ! -----\n";
            displayPrompt("Game Over!",fontStatus,window);
            logFile << "Player " << player << " wins! ";
            logFile << "Player " << selectOrSwitchPlayer(player) << " loses. ";
            outputStats(logFile, userHit, userMiss, computerHit, computerMiss);
        }
        else //game still going
        {
            player=selectOrSwitchPlayer(player);
            system("clear"); 
        }
    }

    //close the log file
    logFile.close();*/
    }
    
    return 0;
}
