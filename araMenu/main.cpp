#define _WIN32_WINNT 0x0500
#include "../lib/SFML-2.5.1/include/SFML/Graphics.hpp"
#include <iostream>
#include <windows.h>
#include "Messages.h"

HWND hWnd = GetConsoleWindow();

int a;
sf::Vector2i mouse_position;
bool mouse_pressed = 0;

int main()
{

    ShowWindow( hWnd, SW_HIDE );
    sf::RenderWindow window(sf::VideoMode(1000, 720), "A.R.A");

    sf::Texture tlo;
    if (!tlo.loadFromFile("img\\backgroundImage.png"))
    {
        ms_error(12, "nie zaladowano menuBackground", true);
    }
    sf::Sprite Tlo;
    Tlo.setTexture(tlo);
    window.draw(Tlo);

    sf::Texture play;
    if (!play.loadFromFile("img\\play.png"))
    {
        ms_error(19, "nie zaladowano play", true);
    }
    sf::Sprite Play;
    Play.setTexture(play);
    Play.setPosition(sf::Vector2f(300, 150));
    Play.setScale(sf::Vector2f(1.5, 1.5));
    window.draw(Play);


    sf::Texture exit;
    if (!exit.loadFromFile("img\\exit.png"))
    {
        ms_error(24, "exit", true);
    }
    sf::Sprite Exit;
    Exit.setTexture(exit);
    Exit.setPosition(sf::Vector2f(400, 550));
    Exit.setScale(sf::Vector2f(0.6, 0.6));
    window.draw(Exit);

    sf::Texture edit;
    if (!edit.loadFromFile("img\\edit.png"))
    {
        ms_error(30, "nie zaladowano edit", true);
    }
    sf::Sprite Edit;
    Edit.setTexture(edit);
    Edit.setPosition(sf::Vector2f(450, 350));
    Edit.setScale(sf::Vector2f(0.2, 0.2));
    window.draw(Edit);

    window.display();
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        mouse_pressed = 0;

        mouse_position = sf::Mouse::getPosition(window);
        while(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            mouse_position = sf::Mouse::getPosition(window);
            mouse_pressed = 1;
        }
        if(mouse_pressed){
            std::cout<<mouse_position.x<<" "<<mouse_position.y<<std::endl;
            if(mouse_position.x>=300&&mouse_position.x<680&&mouse_position.y>150&&mouse_position.y<280){
                window.close();
                system("..\\..\\..\\bin\\Debug\\ara.exe");

            }else if (mouse_position.x>=450&&mouse_position.x<487&&mouse_position.y>358&&mouse_position.y<393){
                std::cout<<"tu bedzie kiedys przekierowanie do edytorMap.exe"<<std::endl;
            }

            if(mouse_position.x>=400&&mouse_position.x<560&&mouse_position.y>550&&mouse_position.y<630){
                window.close();
                return 0;
            }
        }


        //window.clear();
        //std::cin>>a;
        /*if(a==1){
            window.close();
            system("..\\..\\..\\bin\\Debug\\ara.exe");

        }*/
    }
}