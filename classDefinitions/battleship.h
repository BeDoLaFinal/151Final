/**
 * @file    battleship.h
 * @author  Lacey Hunt | Ben Givens, Modified for SFML by Dominic and Lacey
 * @brief   Includes, globals, and function prototypes for battleship assignment
 * @date    2022-11-23
 */

#ifndef BATTLESHIP_H
#define BATTLESHIP_H

// Includes
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <unistd.h>
using sf::RenderWindow;
using namespace std;

// Globals
const int NUM_ROWS = 10;  // number of rows of the battleship game board
const int NUM_COLS = 10;  // number of columns of the battleship game board
const int NUM_SHIPS = 5;  // number of ships in the battelship game

// Each of the ships information in 3 arrays (parallel arrays)
const string SHIP_NAMES[] = {"carrier", "battleship", "cruiser", "submarine", "destroyer"};
const char SHIP_SYMBOLS[] = {'c', 'b', 'r', 's', 'd'};
const int SHIP_SIZES[] = {5, 4, 3, 3, 2};

// Prototypes
void initializeBoard(char board[][NUM_COLS]); //sets each cell in a game board to -
void displayBoard(int player, char board[][NUM_COLS]); // displays a board to the screen
void manuallyPlaceShipsOnBoard(char board[][NUM_COLS]); //allows the user to place each of the 5 types of ships on his/her game board.
void randomlyPlaceShipsOnBoard(char board[][NUM_COLS]); //randomly places the 5 types of ships on a given board.
int switchPlayer(int player); //if start of game, determines who goes first if game already started, switches player up next
bool checkShotIsAvailable(int row, int col, const char board[NUM_ROWS][NUM_COLS]); //returns true if position entered is still available, otherwise return false.
bool isWinner(char board[][NUM_COLS]);//determins if a winner exists
int checkShot(int row, int col, char board[][NUM_COLS]); 
                    //If the shot is a miss, then function returns -1, otherwise if it is a hit,
                    //function return 0 for hitting the carrier, 1 for hitting the battleship, 2 for hitting the cruiser, 
                    //3 for hitting the submarine, and 4 for hitting the destroyer.
bool checkIfSunk(int shipLength,char shipChar,char board[][NUM_COLS]);//checks to see if ship sunk
int updateBoard(int row, int col, char board2[][NUM_COLS], char boardSeen[][NUM_COLS], ofstream& logFile, int &userHit, int &userMiss, sf::Font &font,RenderWindow &window, sf::Text &message); // checks if hit, miss, sunk and writes to log
                    //then updates board
void outputStats(ofstream& logFile, int userHit, int userMiss, int computerHit, int computerMiss); //displays stats after game
#endif