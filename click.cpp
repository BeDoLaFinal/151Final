#include <SFML/Graphics.hpp>
#include <iostream>
#include "button.h"

/**
 * @brief a funtion to return the mouse position as a pointer to a char array
 * 
 * @return char* 
 */
char* mouseClickLocation()
{
    static char r[2]
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {

            std::cout << "the left button was pressed" << std::endl;   //for testing
            std::cout << "mouse x: " << event.mouseButton.x << std::endl; //for testing
            std::cout << "mouse y: " << event.mouseButton.y << std::endl; //for testing

            if (event.mouseButton.x> 200 && event.mouseButton.x<250)
                r[0]='0';
            else if (event.mouseButton.x> 250 && event.mouseButton.x<300)
                r[0]='1';   
            else if (event.mouseButton.x> 300 && event.mouseButton.x<350)
                r[0]='2'; 
            else if (event.mouseButton.x> 350 && event.mouseButton.x<400)
                r[0]='3'; 
            else if (event.mouseButton.x> 400 && event.mouseButton.x<450)
                r[0]='4'; 
            else if (event.mouseButton.x> 450 && event.mouseButton.x<500)
                r[0]='5'; 
            else if (event.mouseButton.x> 500 && event.mouseButton.x<550)
                r[0]='6'; 
            else if (event.mouseButton.x> 600 && event.mouseButton.x<650)
                r[0]='7'; 
            else if (event.mouseButton.x> 650 && event.mouseButton.x<700)
                r[0]='8'; 
            else if (event.mouseButton.x> 700 && event.mouseButton.x<750)
                r[0]='9';
            else { cout<<"bad click";}//or something like that

            if (event.mouseButton.y> 200 && event.mouseButton.y<250)
                r[1]='0';
            else if (event.mouseButton.y> 250 && event.mouseButton.y<300)
                r[1]='1';   
            else if (event.mouseButton.y> 300 && event.mouseButton.y<350)
                r[1]='2'; 
            else if (event.mouseButton.y> 350 && event.mouseButton.y<400)
                r[1]='3'; 
            else if (event.mouseButton.y> 400 && event.mouseButton.y<450)
                r[1]='4'; 
            else if (event.mouseButton.y> 450 && event.mouseButton.y<500)
                r[1]='5'; 
            else if (event.mouseButton.y> 500 && event.mouseButton.y<550)
                r[1]='6'; 
            else if (event.mouseButton.y> 600 && event.mouseButton.y<650)
                r[1]='7'; 
            else if (event.mouseButton.y> 650 && event.mouseButton.y<700)
                r[1]='8'; 
            else if (event.mouseButton.y> 700 && event.mouseButton.yx<750)
                r[1]='9';
            else { cout<<"bad click"}//or something like that


        }
        if (event.mouseButton.button == sf::Mouse::Left && event.mouseButton.y> 900 && event.mouseButton.yx<150)
        {   
            r[0]='q';
            r[1]='q';
            return 0;
        }
    }
    return r;
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