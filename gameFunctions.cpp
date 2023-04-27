/**
 * @file    gameFunctions.cpp
 * @author  Lacey Hunt (lhunt2@students.nic.edu)
 * @brief   various function definitions needed for gameplay
 * @date    2023-04-23
 * 
 */
#include <SFML/Graphics.hpp>
#include <iostream>
#include <array>
#include <string>
#include <sstream>
#include "gameFunctions.h"
#include "classDefinitions/tiles.h"


/**
 * @brief   a funtion to return the mouse position click as an int array
 * @author  Lacey
 * @return  void // changes array of movement made in main 
 */
String mouseClickLocation(sf::Event &click,int arr[2])
{   
    String mouse;
    std::stringstream ss;
    ss.str();

    if (click.type == sf::Event::MouseButtonPressed&&click.mouseButton.button == sf::Mouse::Left)
    {
        ss<<"the left button was pressed\n";   //for testing
        ss<< "mouse x: " << click.mouseButton.x<<"--"; //for testing
        ss << "mouse y: " << click.mouseButton.y <<endl; //for testing
        int spanX=0;
        int spanY=0;
        for(int i=0; i<click.mouseButton.x; i++)
        {   spanX=i*50;
            //cout<<spanX<<endl;
            if(spanX+220>=click.mouseButton.x)
            {
                if(click.mouseButton.x<200) 
                {
                    arr[0]=-1;
                    break;
                }
                //cout<<i<<endl;
                arr[0]=i;
                break;
            } 
        }
        for(int j=0; j<click.mouseButton.y;j++)
        {   spanY=j*50;
            if(spanY+200>=click.mouseButton.y)
            {
                if(click.mouseButton.y<199) 
                {
                    arr[1]=-1;
                    break;
                }
                arr[1]=j;
                break;
            }
        }
        /*if (click.mouseButton.x>50 && click.mouseButton.x<150&&click.mouseButton.y>930 && click.mouseButton.y<980)
        {   
            //user clicked quit
            exit(2);
        }*/
    }
    if(arr[0]>10||arr[1]>10||arr[0]==-1||arr[1]==-1) cout<<"Out of Bounds!\n";
    else {cout<<"array location: "<<arr[0]<<" "<<arr[1]<<endl;}
    mouse = ss.str();
    return mouse;
}

/**
 * @brief displays instructions
 * @author
 * @param window 
 * @param screen 
 */
void showInstructions(RenderWindow& window, Screen &screen)
{
    //change screen image
    //show instructions
    //user clicks to exit and return to play screen
}

/**
 * @brief handle all gamePlay elements
 * @author Lacey
 * 
 * @param window 
 * @param screen 
 */
void playGame(sf::RenderWindow& window, Screen &screen)
{
    //INITIALIZE GAME ELEMENTS
    /*int placeSelect, player, col, row;
    bool moveOK=false, gameOver1, gameOver2;

    int userMiss=0;
    int userHit=0;
    int computerHit=0;
    int computerMiss=0;

    char board1[NUM_ROWS][NUM_COLS]; //initializes array for the board of player 1 (user)
    char board2[NUM_ROWS][NUM_COLS]; //initializes array for the board of player 2 (computer)
    char boardSeen[NUM_ROWS][NUM_COLS]; //initializes array for board seen by user (showing hits and misses but not opponent ships)
    initializeBoard(board1); //user ships
    initializeBoard(board2); //computer ships
    initializeBoard(boardSeen); //computer board seen by user
    */

    //PLACE SHIPS (RANDOM FOR NOW) for both players

    //display ships
    /*do
    {
        display
        PLAY
        display
    }while(!gameOver1&&!gameOver2);
    if(gameOver1)
        display correct end
    else if(gameOver2)
        display correct end
    */
}






/*
how to read the array:
    
    
    char *p;

    p = mouseClickLocation();
    
    for ( int i = 0; i < 2; i++ ) {
        cout << "*(p + " << i << ") : ";
        cout << *(p + i) << endl;
    }


*/
/**
 * @brief Create a Tile Array object function to start the game with blank screen. 
 * 
 */
void createTileArray(char tileArray[10][10])
{
    int x=0;
    int count=0;
    
    
    //create tile out here . . .
    for(float i=200; i<651; i+=50)//i=0 is only for test. i should equal the top left corner of tile board, approx 200.
    {
        
        for(float j=197; j<649; j+=50) //j=0 is only for test. j should equal the top left corner of tile board, approx 200.
        {   
            int y= 0+count;            
            
            tileArray[x][y]='*';
            tileArray[x][y+1]='-'; //assuming arrays are in char Letter/Number format
            //. . . and reassign here? so we don't have to create a ton at once
            count+=2;

        }
        count=0;
        x++;
    }


};

void displayArrayofTiles(char ta[10][10], Texture texture, RenderWindow &window, int shiftx, int shiftY)
{ 
    int x=0;
    int count=0;
    
 for(float i=220+shiftx; i<675+shiftx; i+=50)//i=0 is only for test. i should equal the top left corner of tile board, approx 200.
    {
        
        for(float j=199+shiftY; j<659; j+=50) //j=0 is only for test. j should equal the top left corner of tile board, approx 200.
        {   
            int y= 0+count;            
            sf::Sprite tile(texture);
            
            tile.setPosition(sf::Vector2f(i, j));
            
            if(ta[x][y]=='*')
            {
            tile.setTextureRect(sf::IntRect(50, 0, 50, 50));}
            else {tile.setTextureRect(sf::IntRect(0, 0, 50, 50));}
            
             window.draw(tile);
            //ta[x][y]=boardTile; //assuming arrays are in char Letter/Number format
            //. . . and reassign here? so we don't have to create a ton at once
            count++;

        }
        count=0;
        x++;
    }
   
};

void displayPrompt(std::string s, sf::Font &font,RenderWindow &window)
{
    sf::Text status;
        status.setCharacterSize(50);
        status.setPosition(505,810);
        status.setFillColor(sf::Color(100, 250, 50, 100));
        status.setFont(font);
        status.setString(s);
        window.draw(status);
}