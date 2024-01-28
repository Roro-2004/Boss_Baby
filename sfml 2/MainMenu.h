
#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
using namespace std;
using namespace sf;

#define MAX_main_menu 2
class MainMenu
{
public:
    MainMenu(float width, float height);
    void draw(sf::RenderWindow& window);
    void MoveUp();
    void MoveDown();
    int MainMenuPressed() {
        return MainMenuSelcted;
    }

    ~MainMenu();

private:
    int MainMenuSelcted;
    Font font;
    Text mainMenu[MAX_main_menu];
};