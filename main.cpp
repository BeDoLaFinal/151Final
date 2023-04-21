
#include <SFML/Graphics.hpp>
#include <iostream>                  // today after struggling for hours with my vscode and getting almost nothing done, I learned that you have to put the #includes with <> BEFORE any includes with "". 
#include "gameObjects.h"
#include "tiles.h"
#include "introScreen.h"

void createTileArray();

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920,1080), "Battleship");//
    Screen myScreen;
    //testingPurposes(window);
    createTileArray();
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            myScreen.updateScreen(event,window);
        }
        window.clear();
        window.draw(myScreen.getScreen());
        window.display();
    }

    return 0;
}

/**
 * @brief Create a Tile Array object function to start the game with blank screen. 
 * 
 */
void createTileArray()
{
    char x= 'A';
    int count=0;
    Tile tileArray[10][10];
    for(int i=0; i<451; i+=50)//i=0 is only for test. i should equal the top left corner of tile board, approx 200.
    {
        
        for(int j=0; j<451; j+=50) //j=0 is only for test. j should equal the top left corner of tile board, approx 200.
        {   
            char y= '0'+count;            
            Tile boardTile( {i,j}, {50,50}, x, y);
            tileArray[x][y]=boardTile; //assuming arrays are in char Letter/Number format
            count++;

        }
        count=0;
        x++;
    }


};