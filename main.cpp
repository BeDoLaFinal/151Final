/**
 * @file    main.cpp
 * @author  Lacey Hunt, Ben Givens, Dominic Acia
 * @brief   test main that opens window and displays
 * @date    2023-04-10
 * 
 */
#include "gameObjects.h"
#include "tiles.h"

void creatTileArray();

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920,1080), "Battleship");//
    Screen myScreen;
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
void createTileArray ()
{
    char x= 'A';
    int count=0;
    Tile tileArray[10][10];
    for(int i=0; i<451; i+=50)//i=0 is only for test. i should equal the top left corner of tile board, approx 200.
    {
        
        for(int j=0; j<451; j+=50) //j=0 is only for test. j should equal the top left corner of tile board, approx 200.
        {   
            char y= '0'+count;            
            Tile boardTile( {i,j}, {50,50});
            tileArray[x][y]=boardTile; //assuming arrays are in char Letter/Number format
            count++;

        }
        count=0;
        x++;
    }


}