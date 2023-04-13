/**
 * @file    main.cpp
 * @author  Lacey Hunt, Ben Givens, Dominic Acia
 * @brief   test main that opens window and displays
 * @date    2023-04-10
 * 
 */
#include "gameObjects.h"
int main()
{
    sf::RenderWindow window(sf::VideoMode(800,500), "Battleship");//
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