/**
 * @file    main.cpp
 * @author  Lacey Hunt | Ben Givens
 * @brief   Program that allows the user to play a game of battleship,
 *          recording the results of the match to a log file
 * @date    2022-11-23
 */

#include "battleship.h"

int main()
{
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

    //User determines ship placement
    do
    {
        cout << "Select how you would like to place your ships:\n";
        cout << "1. Manually Place\n2. Randomly Place\n";
        cin>>placeSelect;
        cin.ignore();
        if(placeSelect<1 || placeSelect>2)
        {
            cout << "Invalid Entry. ";
        }
    } while (placeSelect<1 || placeSelect>2);

    //user chose manual placement
    if(placeSelect==1)
    {
        cout << "You have chosen to manually place your ships.\n";
        manuallyPlaceShipsOnBoard(board1);
    }
    //user chose random placement
    else if(placeSelect==2)
    {
        cout << "You have chosen to randomly place your ships.\n";
        randomlyPlaceShipsOnBoard(board1);
    }

    //place opponent ships
    randomlyPlaceShipsOnBoard(board2);

    displayBoard(1, board1);
    //sleep(4);
    pressEnterToContinue();
    system("clear");

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
        banner(player);
        if (player==1)//user's turn
        {
            displayBoard(player+1, boardSeen);//Displays the player's board when the computer is making their move
            logFile << "Player1: ";
            do //get valid move location
            {
                cout << "Enter where you would like to shoot (row, then column): ";
                cin >> row;
                cin.ignore();
                cin >> col;
                cin.ignore();
                row--;
                col--;
                moveOK = checkShotIsAvailable(row, col, boardSeen);
                if (moveOK)
                {
                    updateBoard(row, col, board2, boardSeen, logFile, userHit,userMiss); //check shot and update board
                }
                else 
                {
                    cout <<"Invalid move. ";
                }
            } while (!moveOK);
            displayBoard(2,boardSeen);
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
                        cout << "\nComputer missed!" << endl;
                        board1[row][col]='m';
                        computerMiss++;
                    }
                    else
                    {
                        logFile <<row<<","<<col<<" Hit! ";
                        cout << " Computer hit one of your ships! ";
                        board1[row][col]='*';
                        computerHit++;
                        if (checkIfSunk(shipLength,shipChar,board1)) //check if sunk
                        {
                            logFile << SHIP_NAMES[hitLocation] << " sunk!";
                            cout << SHIP_NAMES[hitLocation] << " sunk!";
                        }
                        logFile << endl;
                        cout << endl;
                    }
                }

            } while (!moveOK);
            displayBoard(1, board1);  
        }             
        
        gameOver1 = isWinner(board1);
        gameOver2 = isWinner(board2); // for computer, only pass board NOT seen by user

        if(gameOver1==true||gameOver2==true) //game over
        {
            cout << "\n----- G A M E   O V E R ! -----\n";
            logFile << "Player " << player << " wins! ";
            cout << "Player " << player << " wins! ";
            logFile << "Player " << selectOrSwitchPlayer(player) << " loses. ";
            cout << "Player " << selectOrSwitchPlayer(player) << " loses." << endl;
            outputStats(logFile, userHit, userMiss, computerHit, computerMiss);
        }
        else //game still going
        {
            player=selectOrSwitchPlayer(player);
            pressEnterToContinue();
            //sleep(4);
            system("clear"); 
        }
    }

    //close the log file
    logFile.close();

    return 0;
}