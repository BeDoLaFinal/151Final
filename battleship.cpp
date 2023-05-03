/**
 * @file    battleship.cpp
 * @author  Lacey Hunt | Ben Givens,  Modified for SFML by Dominic and Lacey
 * @brief   function definitions for battleship assignment
 * @date    2022-11-23
 */

#include "classDefinitions/battleship.h"
#include "gameFunctions.h"

/**
 * @brief sets each cell in a game board to -
 * 
 * @param board The array which corresponds to the board to be initialized
 */
void initializeBoard(char board[][NUM_COLS])
{
    //initialize seed for random number generator
    srand(time(NULL));

    for (int i=0; i<NUM_ROWS;i++)
    {
        for (int j=0; j<NUM_COLS;j++)
        {
            board[i][j]='-';
        }
    }
}

/**
 * @brief displays the boards to the screen.
 * 
 * @param int player displays which player's board is being shown
 * @param board The array which corresponds to the player's board
 */
void displayBoard(int player, char board[][NUM_COLS]) 
{
    //headers
    if(player==1) // user
    {
        cout << endl;
        for(int i=0; i<30; i++)
        {
            cout << "~";
        }
        cout << "\n   Y O U R   S H I P S :\n\n";
    }
    else if(player==2) // computer
    {
        cout << endl;
        for(int i=0; i<30; i++)
        {
            cout << "~";
        }
        cout << "\n E N E M Y   W A T E R S :\n\n";

    }
    cout << "  ";
    for(int n=1; n<=NUM_COLS; n++)
    {
        cout << setw(2) <<n;
    }
    cout << endl;
    for (int i =0; i<NUM_ROWS;i++)
    {
        cout << setw(2) << i+1;
        for (int j=0; j<NUM_COLS;j++)
        {
            cout<<setw(2)<<board[i][j];
        }
        cout <<endl;
    }

    //footer
    if(player==1 || player ==2)
    {
        for(int i=0; i<30; i++)
            {
                cout << "~";
            }
        cout<< endl;
    }
}
/**
 * @brief place one ship on board
 * 
 * @param board 
 * @param spot 
 * @param shipNum 
 * @param orientation 
 */
void placeShip(char board[][NUM_COLS],int spot[2],int shipNum,int orientation)
{
    int row=spot[0]-1;
    int col=spot[1]-1;
    for(int j=0; j<SHIP_SIZES[shipNum]; j++)
    {
        board[row+j-1][col-1] = SHIP_SYMBOLS[shipNum];
    }
}
/**
 * @brief   allows the user to place each of the 5 types of ships on his/her game board.
 *          runs through all ships. User selects location and orientation, which is validated and ship is placed if spot ok.
 * 
 * @param board board to place ships on
 */
void manuallyPlaceShipOnBoard(char board[][NUM_COLS],RenderWindow& window, sf::Text& message, sf::Texture &texture, sf::Font& fontStatus, Screen & myScreen, int shipNum) 
{
    int row, col, orientation;
    bool spotOK;
    sf::Event thing;
    int spot[2];
    String delim;
    bool stillPlacing;

    while(stillPlacing)
    {
        for(int i=0; i<NUM_SHIPS; i++)
        {
            while (spotOK==false) //make sure in bounds and not taken
            {
                spotOK=true; // initialize to ok spot
                displayArrayofTiles(board,texture,window,974,-2);
                // select location in bounds
                do
                {
                    message.setString("Select a location to place the "+SHIP_NAMES[i]+"\nwhich is "+to_string(SHIP_SIZES[i])+" units long.");
                    while(window.pollEvent(thing))
                    {
                        if(thing.type == sf::Event::MouseButtonPressed&&thing.mouseButton.button == sf::Mouse::Left)
                        {
                            delim=mouseClickLocation(thing,spot,texture,window,message);
                        }
                    }
                    if(spot[0]<1 || spot[0]>10 || spot[1]<1 || spot[1]>10)
                    {
                        message.setString("Out of bounds.");
                    }
                } while (spot[0]<1 || spot[0]>10 || spot[1]<1 || spot[1]>10);

                // select orientation
                row=spot[0];
                col=spot[1];
                for(int j=0; j<SHIP_SIZES[i]; j++)
                {
                    board[row+j-1][col-1] = SHIP_SYMBOLS[i];
                }
            }
        }
    }

    // for all ships
    // for(int i=0; i<NUM_SHIPS; i++)
    // {
    //     while (spotOK==false) //make sure in bounds and not taken
    //     {
    //         spotOK=true; // initialize to ok spot
    //         displayArrayofTiles(board,texture,window,0,0);
    //         // select location in bounds
    //         do
    //         {
    //             message.setString("Select a location to place the "+SHIP_NAMES[i]+"\nwhich is "+to_string(SHIP_SIZES[i])+" units long.");
    //             while(window.pollEvent(event))
    //             {
    //                 if(event.type == sf::Event::MouseButtonPressed&&event.mouseButton.button == sf::Mouse::Left)
    //                 {
    //                     delim=mouseClickLocation(event,spot,texture,window,message);
    //                 }
    //             }
    //             if(spot[0]<1 || spot[0]>10 || spot[1]<1 || spot[1]>10)
    //             {
    //                 message.setString("Out of bounds.");
    //             }
    //         } while (spot[0]<1 || spot[0]>10 || spot[1]<1 || spot[1]>10);

    //         // select orientation
    //         row=spot[0];
    //         col=spot[1];
    //         for(int j=0; j<SHIP_SIZES[i]; j++)
    //         {
    //             board[row+j-1][col-1] = SHIP_SYMBOLS[i];
            // do
            // {
            //     message.setString("Select an orientation of the "+SHIP_NAMES[i]);
            //     IntroButton orientButton(sf::Vector2f (600,500),"Horizontal","Vertical");
            //     orientButton.draw(window); 
            //     while(window.pollEvent(event))
            //     {
            //         if(event.mouseButton.button == sf::Mouse::Left)
            //         {
            //             //user click horizontal
            //             if(orientButton.isRulesButtonPressed(window,sf::Mouse::getPosition(window)))
            //             {
            //                 orientation=1;
            //                 for(int c=0; c<SHIP_SIZES[i]; c++)
            //                 {
            //                     if(board[row-1][col+c-1]!='-' || (col+c-1)>9 ) // check if spot is taken or out of bounds
            //                     {
            //                         message.setString("Invalid Spot.");
            //                         spotOK=false;
            //                     }
            //                     if(spotOK==true) //place ship
            //                     {
            //                         for(int j=0; j<SHIP_SIZES[i]; j++)
            //                         {
            //                             board[row-1][col+j-1] = SHIP_SYMBOLS[i];
            //                         }
            //                     }
            //                 }
            //             }
            //             //user click vertical
            //             if (orientButton.isPlayButtonPressed(window,sf::Mouse::getPosition(window)))
            //             {
            //                 orientation=2;
            //                 for(int c=0; c<SHIP_SIZES[i]; c++)
            //                 {
            //                     if(board[row+c-1][col-1]!='-' || (row+c-1)>9 ) // check if spot is taken or out of bounds
            //                     {
            //                         message.setString("Invalid Spot.");
            //                         spotOK=false;
            //                     }
            //                 }
            //                 if(spotOK==true) //place ship
            //                 {
            //                     for(int j=0; j<SHIP_SIZES[i]; j++)
            //                     {
            //                         board[row+j-1][col-1] = SHIP_SYMBOLS[i];
            //                     }
            //                 }   
            //             }
            //         }
            //     }
            // }while (orientation<1 || orientation>2);


}

/**
 * @brief randomly places the 5 types of ships on a given board.
 * 
 * @param board board to place ships on
 */
void randomlyPlaceShipsOnBoard(char board[][NUM_COLS]) 
{
    int row, col, orientation;
    bool spotOK;

    // for all ships
    for(int i=0; i<NUM_SHIPS; i++)
    {
        do
        {
            spotOK=true; // initialize to ok spot

            // select location in bounds
            do
            {
                row=rand()%NUM_ROWS+1;
                col=rand()%NUM_COLS+1;
            } while (row<1 || row>10 || col<1 || col>10);

            // select orientation
            do
            {
                orientation=rand()%2+1;
                if(orientation==1) // horizontal
                {
                    for(int c=0; c<SHIP_SIZES[i]; c++)
                    {
                        if(board[row-1][col+c-1]!='-' || (col+c-1)>9 ) // check if spot is taken or out of bounds
                        {
                            spotOK=false;
                        }
                    }
                    if(spotOK==true) //if spot open, place ship
                    {
                        for(int j=0; j<SHIP_SIZES[i]; j++)
                        {
                            board[row-1][col+j-1] = SHIP_SYMBOLS[i];
                        }
                    }
                }
                else if(orientation==2) // vertical
                {
                    for(int c=0; c<SHIP_SIZES[i]; c++)
                    {
                        if(board[row+c-1][col-1]!='-' || (row+c-1)>9 ) // check if spot is taken or out of bounds
                        {
                            spotOK=false;
                        }
                    }
                    if(spotOK==true) //if spot open, place ship
                    {
                        for(int j=0; j<SHIP_SIZES[i]; j++)
                        {
                            board[row+j-1][col-1] = SHIP_SYMBOLS[i];
                        }
                    }  
                } 
            }while (orientation<1 || orientation>2);

        }while (spotOK==false); //make sure in bounds and not taken
    }

}

/**
 * @brief if start of game, determines who goes first
 *          if game already started, switches player up next
 * 
 * @param player current player, -1 if game is just starting
 * @return int player up next
 */
int switchPlayer(int player) 
{   
    int newP=0;
    if(player==1)
        newP= 2;
    else if(player==2)
        newP=1;
    return newP;
}

/**
 * @brief checks entered position
 * 
 * @param row entered row pos
 * @param col entered col pos
 * @return true if position available
 * @return false if not available
 */
bool checkShotIsAvailable(int row, int col, const char board[NUM_ROWS][NUM_COLS]) 
{
    row;
    col;
    if(row<0 || row>9 || col<0 || col>9 || board[row][col]=='*' || board[row][col]=='m')
    {
        return false;
    }
    else
    {
        return true;
    }
}
/**
 * @brief Determines if someone has won. We check the inputed array for '*' values, which represent a hit on the player's board
          and the computers hidden board. If the total number of '*'=17, then someone has sunk all of their opponents ships.
 * @param board[][NUM_COLS] board values for inputed array
 * @return true if game over, someone won
 * @return false if no winner yet
 */
bool isWinner(char board[][NUM_COLS])
{
    //run through each cell in array
    for(int i=0; i<NUM_ROWS; i++)
    {
        for(int j=0; j<NUM_COLS; j++)
        {
            //compare cell to ship symbol
            for(int s=0; s<5; s++)
            {
                if(board[i][j]==SHIP_SYMBOLS[s])
                {
                    return false; //return and exit if any ships still left
                }
            }
        }
    }
    return true; // winner exists
}
/**
 * @brief checks what is hit on board 
 * @param row entered row pos
 * @param col entered col pos
 * @return int If the shot is a miss, then function returns -1
 *          otherwise if it is a hit, function return 0 for hitting the carrier, 
 *          1 for hitting the battleship, 2 for hitting the cruiser, 
 *          3 for hitting the submarine, and 4 for hitting the destroyer.
 */
int checkShot(int row, int col, char board[][NUM_COLS])
{
    if (board[row][col]=='-')
    {
        return -1;
    }
    else if (board[row][col]=='c')
    {
        return 0;
    }
    else if (board[row][col]=='b')
    {
        return 1;
    }
    else if (board[row][col]=='r')
    {
        return 2;
    }
    else if (board[row][col]=='s')
    {
        return 3;
    }
    else if (board[row][col]=='d')
    {
        return 4;
    }
    return 5;
}

/**
 * @brief Checks to see if a ship has been sunk
 * 
 * @param shipLength length of hit ship
 * @param shipChar char of hit ship
 * @param board game board of hit ship
 * @return true if the ship has been sunk
 * @return false if not sunk
 */
bool checkIfSunk(int shipLength,char shipChar,char board[][NUM_COLS])
{
    for (int i=0; i<NUM_ROWS; i++)
    {
        for (int j=0; j<NUM_COLS; j++)
        {
            if (board[i][j]==shipChar)
            {
                return false;
            }
        }
    }
    return true;
}

/**
 * @brief checks if hit, miss, and/or sunk and writes to log file
 *          then Updates the board position with '*' indicates a hit and 'm' indicates a miss.
 *          outputs to terminal hit or miss and if sunk
 * @param row row location entered in main
 * @param col column location entered in main
 * @param board2 behind the scenes board
 * @param boardSeen board seen by user
 * @param logFile log file tracking moves
 */
int updateBoard(int row, int col, char board2[][NUM_COLS], char boardSeen[][NUM_COLS], ofstream& logFile, int &userHit, int &userMiss,sf::Font &font,RenderWindow &window,sf::Text &message)  
{
    int isHit=0;
    int hitLocation = checkShot(row, col, board2); //find what ship user hit
    int shipLength = SHIP_SIZES[hitLocation];
    int shipChar = SHIP_SYMBOLS[hitLocation];
        
    if (hitLocation==-1)//hit was a miss
    {
        logFile<<row+1<<","<<col+1<<" Miss!"<<endl;
        // message.setString("You missed!");
        boardSeen[row][col]='m';
        userMiss++;
        isHit=1;
    }
    else
    {
        logFile<<row+1<<","<<col+1<<" Hit! ";
        // message.setString("You hit an enemy ship!");
        boardSeen[row][col]='*';
        board2[row][col]='-';
        userHit++;
        isHit=2;
    
        if (checkIfSunk(shipLength,shipChar,board2)) //check if sunk
        {
            String ship;
            std::stringstream ss;
            ss.str();
            logFile << SHIP_NAMES[hitLocation] << " sunk!";
            ss<<SHIP_NAMES[hitLocation];
            ship="You sunk the enemy's "+ss.str()+".\n Nice shooting!";
            message.setString(ship);
        }
        logFile << endl;
    }
    return isHit;
}
/**
 * @brief update the array for the computer player and return a value to trigger actions
 * 
 * @param row 
 * @param col 
 * @param board 
 * @param logFile 
 * @param computerHit 
 * @param computerMiss 
 * @param window 
 * @param message 
 * @return int 
 */
int computerUpdateBoard(int row, int col, char board[][NUM_COLS], ofstream& logFile, int &computerHit, int &computerMiss,RenderWindow &window,sf::Text &message)  
{
    int isHit=0;
    int hitLocation = checkShot(row, col, board); //find what ship computer hit
    int shipLength = SHIP_SIZES[hitLocation];
    int shipChar = SHIP_SYMBOLS[hitLocation];
        
    if (hitLocation==-1)//shot was a miss
    {
        logFile<<row+1<<","<<col+1<<" Miss!"<<endl;
        //message.setString("The enemy missed!");
        board[row][col]='m';
        computerMiss++;
        isHit=3;
    }
    else
    {
        logFile<<row+1<<","<<col+1<<" Hit! ";
        //message.setString("The enemy hit your ship!");
        board[row][col]='*';
        computerHit++;
        isHit=4;
    
        if (checkIfSunk(shipLength,shipChar,board)) //check if sunk
        {
            String ship;
            std::stringstream ss;
            ss.str();
            logFile << SHIP_NAMES[hitLocation] << " sunk!";
            ss<<SHIP_NAMES[hitLocation];
            ship="The enemy sunk your "+ss.str()+".";
            message.setString(ship);
        }
        logFile << endl;
    }
    return isHit;
}

/**
 * @brief completes battleship.log file info after gameplay
 * 
 * @param logFile file to output final info
 */
void outputStats(ofstream& logFile, int userHit, int userMiss, int computerHit, int computerMiss)
{
    logFile << "\n\n*** Player1 Stats ***" << endl;
    logFile << "Number Hits   : " << userHit << endl;
    logFile << "Number Misses : " << userMiss << endl;
    logFile << "Total Shots   : " << userHit+userMiss << endl;
    logFile << "Hit/Miss Ratio: " << ((static_cast<double>(userHit))/((static_cast<double>(userHit))+userMiss))*100 << "%" << endl; // hits/total shots

    logFile << "\n\n*** Player2 Stats ***" << endl;
    logFile << "Number Hits   : " << computerHit << endl;
    logFile << "Number Misses : " << computerMiss << endl;
    logFile << "Total Shots   : " << computerHit+computerMiss << endl;
    logFile << "Hit/Miss Ratio: " << ((static_cast<double>(computerHit))/((static_cast<double>(computerHit))+computerMiss))*100 << "%" << endl; // hits/total shots
}