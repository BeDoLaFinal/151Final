#include "introScreen.h"

IntroButton::IntroButton(sf::Vector2f position)
{

    //Create the font by loading from file
    //font.loadFromFile("")

    //playButton Setup
    playButton.setSize(sf::Vector2f(200,100));
    playButton.setPosition(position.x, position.y);
    playButton.setFillColor(sf::Color::Green);

    //rulesButton Setup
    rulesButton.setSize(sf::Vector2f(200,100));
    rulesButton.setPosition(position.x, position.y);
    rulesButton.setFillColor(sf::Color::Red);

    //Labels for play and rule buttons
    //playLabel.setFont(font);
    playLabel.setString("Play");
    playLabel.setCharacterSize(30);
    playLabel.setFillColor(sf::Color::White);
    playLabel.setPosition(position.x+30, position.y+20);

    rulesLabel.setString("Rules");
    rulesLabel.setCharacterSize(30);
    rulesLabel.setFillColor(sf::Color::White);
    rulesLabel.setPosition(position.x+250, position.y+20);

}

void IntroButton::draw(sf::RenderWindow& window){
    window.draw(playButton);
    window.draw(rulesButton);
    window.draw(playLabel);
    window.draw(rulesLabel);
}
bool IntroButton::isPlayButtonPressed(sf::RenderWindow& window,sf::Vector2i mousePosition){
    sf::Vector2f mousePos=window.mapPixelToCoords(mousePosition);
    if (rulesButton.getGlobalBounds().contains(mousePos)){
        return true;
    }
    return false;
}
bool IntroButton::isRulesButtonPressed(sf::RenderWindow& window,sf::Vector2i mousePosition){
    sf::Vector2f mousePos=window.mapPixelToCoords(mousePosition);
    if (rulesButton.getGlobalBounds().contains(mousePos)){
        return true;
    }
    return false;
}
void testingPurposes(sf::RenderWindow& window)
{
    IntroButton button(sf::Vector2f(200, 200));
    
    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type ==sf::Event::Closed);
                window.close();
        }
        if (event.type==sf::Event::MouseButtonPressed){
            if (button.isPlayButtonPressed(window,sf::Mouse::getPosition(window)))
            {
                std::cout <<"They pressed the play button"<<std::endl;
            }
            if(button.isRulesButtonPressed(window,sf::Mouse::getPosition(window)))
            {
                std::cout<<"They pressed the rules button"<<std::endl;
            }
        }
    }
    window.clear();
}
