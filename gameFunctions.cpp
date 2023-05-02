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
String mouseClickLocation(sf::Event &click,int arr[2], Texture &texture, RenderWindow &window, sf::Text &message)
{   
    String mouse;
    std::stringstream ss;
    ss.str();

    if (click.type == sf::Event::MouseButtonPressed&&click.mouseButton.button == sf::Mouse::Left)
    {
        // ss<<"the left button was pressed\n";   //for testing
        // ss<< "mouse x: " << click.mouseButton.x<<"__"; //for testing
        // ss << "mouse y: " << click.mouseButton.y <<endl; //for testing
        
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
                    arr[1]=-1;
                    break;
                }
                //cout<<i<<endl;
                arr[1]=i-1;
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
                    arr[0]=-1;
                    break;
                }
                arr[0]=j-1;
                cellY=spanY+150;
                break;
            }
        }

        if((click.mouseButton.x<720 && click.mouseButton.y<700)&&(click.mouseButton.x>220 && click.mouseButton.y>199)){
        sf::Sprite clickTile;
        
            clickTile.setTexture(texture);
            clickTile.setTextureRect(sf::IntRect(150, 0, 50, 50));
            clickTile.setPosition(cellX,cellY);
            window.draw(clickTile);
            window.display();
        }
        if ( click.type== sf::Event::MouseButtonReleased &&click.mouseButton.button == sf::Mouse::Left)
        {
            //window.clear();
        }
        if (click.mouseButton.x>125 && click.mouseButton.x<320&&click.mouseButton.y>780 && click.mouseButton.y<906)
        {   
            //user clicked quit
            String exitWarning="\nDesertion is punishable by death!";
            
            message.setString(exitWarning);
            window.draw(message);
            window.display();
            sleep(3);
            window.close();
            exit(2);
        }
    }
    if(arr[0]>10||arr[1]>10||arr[0]==-1||arr[1]==-1) cout<<"Out of Bounds!\n";
    else {cout<<"array location: "<<arr[0]<<" "<<arr[1]<<endl;}
    mouse = ss.str();
    return mouse;
}



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
                
                
            // if(ta[y][x]=='c'||ta[y][x]=='d'||ta[y][x]=='s'||ta[y][x]=='r'||ta[y][x]=='b')
            //     {ship=1;}
            //     else ship=0;
            if(ta[y][x]=='c')
            {   
                carrier+=1;
                
            } 
            if(ta[y][x]=='c'&& carrier==1)
                {   
                tile.setTextureRect(sf::IntRect(200, 0, 50, 50));
                if (ta[y][x+1]== 'c'){tile.setRotation(270);}
                }
                else if(ta[y][x] =='c'&& carrier>=2 && carrier<5)
                {
                    tile.setTextureRect(sf::IntRect(250, 0, 50, 50));
                    if(ta[y-1][x]!='c'){tile.setRotation(270);}
                }
                else if(ta[y][x] =='c' &&carrier==5)
                {   
                    tile.setTextureRect(sf::IntRect(300, 0, 50, 50));
                    if(ta[y][x-1]=='c'){tile.setRotation(270);}
                } 
            else if(ta[y][x]=='d') 
            {
                dest+=1;
                if(ta[y][x]=='d'&& dest==1)
                {   
                tile.setTextureRect(sf::IntRect(200, 0, 50, 50));
                if (ta[y][x+1]== 'd'){tile.setRotation(270);}
                }
                
                else if(ta[y][x] =='d' &&dest==2)
                {   
                    tile.setTextureRect(sf::IntRect(300, 0, 50, 50));
                    if(ta[y][x-1]=='d'){tile.setRotation(270);}
                } 

            }
            else if(ta[y][x]=='s')
            {
                sub+=1;
                if(ta[y][x]=='s'&& sub==1)
                {   
                tile.setTextureRect(sf::IntRect(200, 0, 50, 50));
                if (ta[y][x+1]== 's'){tile.setRotation(270);}
                }
                else if(ta[y][x] =='s'&& sub==2)
                {
                    tile.setTextureRect(sf::IntRect(250, 0, 50, 50));
                    if(ta[y-1][x]!='s'){tile.setRotation(270);}
                }
                else if(ta[y][x] =='s' &&sub==3)
                {   
                    tile.setTextureRect(sf::IntRect(300, 0, 50, 50));
                    if(ta[y][x-1]=='s'){tile.setRotation(270);}
                } 
            }   
            else if(ta[y][x]=='r') 
            {
                cruis+=1;  
                if(ta[y][x]=='r'&& cruis==1)
                {   
                tile.setTextureRect(sf::IntRect(200, 0, 50, 50));
                if (ta[y][x+1]== 'r'){tile.setRotation(270);}
                }
                else if(ta[y][x] =='r'&& cruis==2)
                {
                    tile.setTextureRect(sf::IntRect(250, 0, 50, 50));
                    if(ta[y-1][x]!='r'){tile.setRotation(270);}
                }
                else if(ta[y][x] =='r' &&cruis==3)
                {   
                    tile.setTextureRect(sf::IntRect(300, 0, 50, 50));
                    if(ta[y][x-1]=='r'){tile.setRotation(270);}
                } 
            }
            else if(ta[y][x]=='b') 
            {
                batt+=1;
                if(ta[y][x]=='b'&& batt==1)
                {   
                tile.setTextureRect(sf::IntRect(200, 0, 50, 50));
                if (ta[y][x+1]== 'b'){tile.setRotation(270);
                window.draw(tile);}
                }
                else if(ta[y][x] =='b'&& batt>=2 && batt<4)
                {
                    tile.setTextureRect(sf::IntRect(250, 0, 50, 50));
                    if(ta[y-1][x]!='b'){tile.setRotation(270);}
                    window.draw(tile);
                }
                else if(ta[y][x] =='b' &&batt==4)
                {   
                    tile.setTextureRect(sf::IntRect(300, 0, 50, 50));
                    if(ta[y][x-1]=='b'){tile.setRotation(270);}
                    window.draw(tile);
                } 
            }
            //else ship+=0;
            else if(ta[y][x]=='*')
            {
                tile.setTextureRect(sf::IntRect(50, 0, 50, 50));
            }
            else if(ta[y][x]=='-'){tile.setTextureRect(sf::IntRect(0, 0, 50, 50));}//should be correct
            else if(ta[y][x]=='m'){tile.setTextureRect(sf::IntRect(100, 0, 50, 50));}//should be correct
            
            
            //else tile.setTextureRect(sf::IntRect(0,0,50,50));
            window.draw(tile);
            //ta[y][x]=boardTile; //assuming arrays are in char Letter/Number format
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
void displayPrompt(std::string s, sf::Font &font,RenderWindow &window,sf::Text &message)
{
    message.setCharacterSize(50);
    message.setPosition(505,810);
    message.setFillColor(sf::Color(100, 250, 50, 100));
    message.setFont(font);
    message.setString(s);
    window.draw(message);
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


/**
 * @brief FOR MANUAL PLACEMENT IF NEEDED
 * 
 */
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