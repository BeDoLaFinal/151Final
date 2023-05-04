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
#include "ScreenClass.h"
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
void initializeBoard(char board[][NUM_COLS]); 
void displayBoard(int player, char board[][NUM_COLS]);
void randomlyPlaceShipsOnBoard(char board[][NUM_COLS]); 
int switchPlayer(int player); 
bool checkShotIsAvailable(int row, int col, const char board[NUM_ROWS][NUM_COLS]); 
bool isWinner(char board[][NUM_COLS]);
int checkShot(int row, int col, char board[][NUM_COLS]); 
bool checkIfSunk(int shipLength,char shipChar,char board[][NUM_COLS]);
int updateBoard(int row, int col, char board2[][NUM_COLS], char boardSeen[][NUM_COLS],sf::Font &font,RenderWindow &window,sf::Text &message);
int computerUpdateBoard(int row, int col, char board[][NUM_COLS], RenderWindow &window,sf::Text &message);
#endif