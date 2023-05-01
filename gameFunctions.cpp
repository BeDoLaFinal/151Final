/**
 * @file    gameFunctions.cpp
 * @author  Lacey Hunt (lhunt2@students.nic.edu), Dominic Acia
 * @brief   various function definitions needed for gameplay
 * @date    2023-04-23
 * 
 */
#include <SFML/Graphics.hpp>
#include <iostream>
#include <array>
#include <string>
#include <sstream>
#include <chrono>
#include <unistd.h>
#include <thread>

#include "gameFunctions.h"
#include "classDefinitions/tiles.h"


/**
 * @brief   a funtion to return the mouse position click as an int array
 * @author  Lacey and Dominic
 * @return  void // changes array of movement made in main 
 */
String mouseClickLocation(sf::Event &click,int arr[2], Texture &texture, RenderWindow &window)
{   
    String mouse;
    std::stringstream ss;
    ss.str();

    if (click.type == sf::Event::MouseButtonPressed&&click.mouseButton.button == sf::Mouse::Left)
    {
        ss<<"the left button was pressed\n";   //for testing
        ss<< "mouse x: " << click.mouseButton.x<<"__"; //for testing
        ss << "mouse y: " << click.mouseButton.y <<endl; //for testing
        
        int spanX=0;
        int spanY=0;
        int cellX;
        int cellY;
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
                cellX=spanX+170;
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
                cellY=spanY+150;
                break;
            }
        }

        if((click.mouseButton.x<720 && click.mouseButton.y<700)&&(click.mouseButton.x>200 && click.mouseButton.y>199)){
        sf::Sprite clickTile;
        
            clickTile.setTexture(texture);
            clickTile.setTextureRect(sf::IntRect(150, 0, 50, 50));
            clickTile.setPosition(cellX,cellY);
            window.draw(clickTile);
            window.display();
        }
        if ( click.type== sf::Event::MouseButtonReleased &&click.mouseButton.button == sf::Mouse::Left)
        {
            window.clear();
        }
        if (click.mouseButton.x>125 && click.mouseButton.x<320&&click.mouseButton.y>780 && click.mouseButton.y<906)
        {   
            //user clicked quit
            exit(2);
        }
    }
    if(arr[0]>10||arr[1]>10||arr[0]==-1||arr[1]==-1) cout<<"Out of Bounds!\n";
    else {cout<<"array location: "<<arr[0]<<" "<<arr[1]<<endl;}
    mouse = ss.str();
    return mouse;
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
 * @brief Create a Tile Array object
 * 
 * @param tileArray the chosen array name

void createTileArray(char tileArray[10][10])
{
    int x=0;
    int count=0;
    
    
    //create tile out here . . .
    for(float i=220; i<651; i+=50) 
    {
        
        for(float j=199; j<649; j+=50)  
        {   
            int y= 0+count;            
            
            tileArray[x][y]='-';
            tileArray[x][y+1]='-'; //assuming arrays are in char Letter/Number format
            //. . . and reassign here? so we don't have to create a ton at once
            count+=2;

        }
        count=0;
        x++;
    }


}; */

/**
 * @brief function to display the correct tile based on player and computer array contents. 
 * @author Dominic Acia
 * @param ta  the chosen array to display
 * @param texture texture file for sprites
 * @param window game window in which we're drawing
 * @param shiftx a modifier to allow the left or right board to be drawn
 * @param shiftY a modifier to allow the left or right board to be drawn
 */
void displayArrayofTiles(char ta[10][10], Texture texture, RenderWindow &window, int shiftx, int shiftY)
{ 
    int x=0;
    int count=0;
    int carrier=0;
    int sub=0;
    int dest=0;
    int batt=0;
    int cruis=0;
    int ship=0;

 for(float i=220+shiftx; i<675+shiftx; i+=50)//i=0 is only for test. i should equal the top left corner of tile board, approx 200.
    {
        
        for(float j=199+shiftY; j<659; j+=50) //j=0 is only for test. j should equal the top left corner of tile board, approx 200.
        {   
            int y= 0+count;            
            sf::Sprite tile(texture);
            tile.setOrigin(25,25);
            tile.setPosition(sf::Vector2f(i+25, j+25));
            //bool isMiddle()
                
                
            if(ta[x][y]=='c'||ta[x][y]=='d'||ta[x][y]=='s'||ta[x][y]=='r'||ta[x][y]=='b')
                {ship=1;}
                else ship=0;
            if(ta[x][y]=='c') carrier+=1;
            else if(ta[x][y]=='d') dest+=1;
            else if(ta[x][y]=='s') sub+=1;
            else if(ta[x][y]=='r') cruis+=1;  
            else if(ta[x][y]=='b') batt+=1;
            else ship+=0;
            if(ta[x][y]=='*')
            {
            tile.setTextureRect(sf::IntRect(50, 0, 50, 50));}
            else if(ta[x][y]=='-'){tile.setTextureRect(sf::IntRect(0, 0, 50, 50));}//should be correct
            else if(ta[x][y]=='m'){tile.setTextureRect(sf::IntRect(100, 0, 50, 50));}//should be correct
            else if(ta[x][y]=='c'&& carrier==1)
            {   
                tile.setTextureRect(sf::IntRect(200, 0, 50, 50));
                if (ta[x][y+1]!= 'c'){tile.setRotation(270);}
                }
            else if(ta[x][y] =='c'&& carrier>=2)
            {
                tile.setTextureRect(sf::IntRect(250, 0, 50, 50));
                if(ta[x-1][y]=='c'){tile.setRotation(90);}
            }
            else if(ta[x][y] =='c' &&carrier==5)
            {   
                tile.setTextureRect(sf::IntRect(300, 0, 50, 50));
                if(ta[x][y-1]!='c'){tile.setRotation(270);}
            } 
            else if(ta[x][y]=='s'){tile.setTextureRect(sf::IntRect(250, 0, 50, 50));}//these are not correct
            else if(ta[x][y]=='d'){tile.setTextureRect(sf::IntRect(300, 0, 50, 50));}//these are not correct
            else tile.setTextureRect(sf::IntRect(0,0,50,50));
             window.draw(tile);
            //ta[x][y]=boardTile; //assuming arrays are in char Letter/Number format
            //. . . and reassign here? so we don't have to create a ton at once
            count++;

        }
        count=0;
        x++;
    }
   
};

/**
 * @brief Function to display the information screen on game board
 * @author Dominic Acia
 * @param s string to be displayed
 * @param font assigned font
 * @param window game window
 */
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


/**
 * @brief an attempt to create a multi-thread rendering so the radar would rotate on the background and not affect player input. 
 * SFML does not allow more than one thread to share the same window. 
 * Thoughts are to use a thread to calculate teh position of the radar needle and stream it to the needle rotation command, 
 * but so far I've been unsuccessful. 
 *  
 * 
 */
// void radarDisplay(RenderWindow &window, Texture& texture, int angle)
// {   

    

//         sf::CircleShape radar(110);

//         //radar.setFillColor(sf::Color(5,5,5,90));
//         radar.setPosition(855,391);
//         radar.setTexture(&texture);
//         radar.setTextureRect(sf::IntRect(350, 0, 50, 50));
//         radar.setOutlineThickness(5);
//         radar.setOutlineColor(sf::Color(110,250,70));
        
//         window.draw(radar);
//         sf::RectangleShape needle(sf::Vector2f(8, 116));
//         needle.setPosition(965,501);
//         needle.setFillColor(sf::Color(100, 250, 50, 70));
//         needle.setOrigin(5,10);
        

//     while (window.isOpen())
//     {
      
    
        
           
//             needle.setRotation(angle);
//             //usleep(8000);
//             window.draw(needle);
//             window.display();
//     }
           

//         }

//         ;