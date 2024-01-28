#include "MainMenu.h"
MainMenu::MainMenu(float width, float height)
{
    if (!font.loadFromFile("From Cartoon Blocks.ttf")) {}
    mainMenu[0].setFont(font);
    mainMenu[0].setFillColor(Color(100, 149, 237));
    mainMenu[0].setString("Play");
    mainMenu[0].setCharacterSize(160);
    mainMenu[0].setPosition(Vector2f((1.1*width) / 2, 1.8*(height / (MAX_main_menu + 2))));


    if (!font.loadFromFile("From Cartoon Blocks.ttf")) {}
    mainMenu[1].setFont(font);
    mainMenu[1].setFillColor(Color::White);
    mainMenu[1].setString("Exit");
    mainMenu[1].setCharacterSize(160);
    mainMenu[1].setPosition(Vector2f((1.1*width) / 2, 1.9*(height / (MAX_main_menu + 1))));


    MainMenuSelcted = 0;


}
MainMenu::~MainMenu() {

}
void MainMenu::draw(sf::RenderWindow& window) {
    for (int i = 0; i < 2; i++) {
        window.draw(mainMenu[i]);
    }
}
void MainMenu::MoveDown() {
    if (MainMenuSelcted + 1 <= MAX_main_menu)
    {
        mainMenu[MainMenuSelcted].setFillColor(Color::White);
        MainMenuSelcted++;
        if (MainMenuSelcted == 2) {
            MainMenuSelcted = 0;
        }
        mainMenu[MainMenuSelcted].setFillColor(Color(100, 149, 237));
    }
}
void MainMenu::MoveUp() {
    if (MainMenuSelcted - 1 >= -1)
    {
        mainMenu[MainMenuSelcted].setFillColor(Color::White);
        MainMenuSelcted--;
        if (MainMenuSelcted == -1) {
            MainMenuSelcted = 1;
        }
        mainMenu[MainMenuSelcted].setFillColor(Color(100, 149, 237));
    }
}


