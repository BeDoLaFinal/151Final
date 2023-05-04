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
 * 
 * @param row 
 * @param col 
 * @param board2 
 * @param boardSeen 
 * @param font 
 * @param window 
 * @param message 
 * @return int 
 */
int updateBoard(int row, int col, char board2[][NUM_COLS], char boardSeen[][NUM_COLS], sf::Font &font,RenderWindow &window,sf::Text &message)  
{
    int isHit=0;
    int hitLocation = checkShot(row, col, board2); //find what ship user hit
    int shipLength = SHIP_SIZES[hitLocation];
    int shipChar = SHIP_SYMBOLS[hitLocation];
        
    if (hitLocation==-1)//hit was a miss
    {
        boardSeen[row][col]='m';
        isHit=1;
    }
    else
    {
        boardSeen[row][col]='*';
        board2[row][col]='-';
        isHit=2;
    
        if (checkIfSunk(shipLength,shipChar,board2)) //check if sunk
        {
            String ship;
            std::stringstream ss;
            ss.str();
            ss<<SHIP_NAMES[hitLocation];
            ship="You sunk the enemy's "+ss.str()+".\n Nice shooting!";
            message.setString(ship);
        }
    }
    return isHit;
}

/**
 * @brief update the array for the computer player and return a value to trigger actions
 * 
 * @param row 
 * @param col 
 * @param board 
 * @param window 
 * @param message 
 * @return int 
 */
int computerUpdateBoard(int row, int col, char board[][NUM_COLS], RenderWindow &window,sf::Text &message)  
{
    int isHit=0;
    int hitLocation = checkShot(row, col, board); //find what ship computer hit
    int shipLength = SHIP_SIZES[hitLocation];
    int shipChar = SHIP_SYMBOLS[hitLocation];
        
    if (hitLocation==-1)//shot was a miss
    {
        board[row][col]='m';
        isHit=3;
    }
    else
    {
        board[row][col]='*';
        isHit=4;
    
        if (checkIfSunk(shipLength,shipChar,board)) //check if sunk
        {
            String ship;
            std::stringstream ss;
            ss.str();
            ss<<SHIP_NAMES[hitLocation];
            ship="The enemy sunk your "+ss.str()+".";
            message.setString(ship);
        }
    }
    return isHit;
}
