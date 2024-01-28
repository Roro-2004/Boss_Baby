#include <iostream>
#include <time.h>
#include <SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include<SFML/Audio.hpp>
#include "MainMenu.h"
using namespace std;
using namespace sf;
int page_number;
struct point {
	int x, y;
};
void timere(int& h, int& m, int& s, float& timere, float deltatime)
{
	if (timere <= 0) {
		if (s > 0) {
			s--;
		}
		else {
			if (m > 0) {
				m--;
				s = 60;
			}
			else {
				if (h > 0) {
					h--;
					m = 60;
				}
			}
		}
		timere = 1;
	}
	else {
		timere -= 1 * deltatime;
	}
}
int main() {
	Texture backgroundTex;
	backgroundTex.loadFromFile("My project-1 (7).png");
	Sprite background;
	background.setTexture(backgroundTex);
	RenderWindow window(sf::VideoMode(1600, 850), "SFML_Make_Menu");
	MainMenu menu(1600, 850);


	SoundBuffer ourBuffer;
	ourBuffer.loadFromFile("game_sound_1.wav");
	Sound ourSound;
	ourSound.setBuffer(ourBuffer);
	ourSound.setVolume(10);
	ourSound.play();

	bool gameStarted = false;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Up) {
					menu.MoveUp();
					break;
				}
				if (event.key.code == sf::Keyboard::Down) {
					menu.MoveDown();
					break;
				}
				if (event.key.code == sf::Keyboard::Return) {
					int x = menu.MainMenuPressed();
					if (menu.MainMenuPressed() == 0) {
						page_number = 0;
						gameStarted = true;
					}
					else if (menu.MainMenuPressed() == 1) {
						page_number = 1;
						gameStarted = true;
					}
				}

			}
		}
		if (gameStarted) {
			if (page_number == 0) {
				srand(time(0));
				RenderWindow window(VideoMode(1600, 850), "window");
				Event event;
				//TIMER
				int h = 0, m = 0, s = 20;
				Clock gameclock;
				float deltatime = 0;
				float timer = 0;
				float thetimer = 0;
				int countdown = 30;
				Clock clock;
				Font fonte;
				fonte.loadFromFile("From Cartoon Blocks.ttf");
				Text timing;
				timing.setFillColor(Color::Black);
				timing.setFont(fonte);
				timing.setPosition(750, 20);
				timing.setCharacterSize(50);
				Texture gameoverTex;
				gameoverTex.loadFromFile("gameover.png");
				Sprite gameover;
				gameover.setTexture(gameoverTex);
				gameover.scale(1, 1);
				gameover.setPosition(575, 125);

				//player run
				Texture run;
				run.loadFromFile("runp2.png");
				Sprite baby;
				baby.setTexture(run);
				baby.setPosition(100, 500);
				baby.setOrigin(Vector2f(48.4f / 2, 50.0 / 2));
				baby.setTextureRect(IntRect(0, 0, 48.4, 50));
				baby.setScale(2, 2);
				float delay = 0.1;
				int i = 0;
				Vector2f velocity = { 0,0 };
				float gravity = 3.0f;
				float jumpHeight = -1.0f;
				bool grounded = false;
				/*CircleShape circle(50.f);
				circle.setFillColor(Color::Red);
				circle.setRadius(10.f);
				circle.setPosition(Vector2f(600, 400));*/

				//win
				bool win = false;
				bool opend = false;
				bool pause = false;
				//baby win
				Texture babyw;
				babyw.loadFromFile("win-removebg-preview.png");
				Sprite babywin;
				babywin.setTexture(babyw);
				babywin.scale(1.5, 1.5);
				babywin.setPosition(325, 125);
				//grounded
				//bool grounded = false;
				RectangleShape shape(Vector2f(1700, 100));
				shape.setPosition(Vector2f(0, 800));
				shape.setFillColor(Color(54, 139, 193));
				//door
				Texture doortex;
				doortex.loadFromFile("door-removebg-preview.png");
				Sprite door;
				door.setTexture(doortex);
				door.setTextureRect(IntRect(0, 0, 360, 360));
				door.setOrigin(360 / 2, 360 / 2);
				door.setPosition(1550, 75);
				door.scale(0.5, 0.5);
				//bag
				Texture bagtex;
				bagtex.loadFromFile("bag-removebg-preview.png");
				Sprite bag;
				bag.setTexture(bagtex);
				bag.setTextureRect(IntRect(0, 0, 348, 279));
				bag.setOrigin(348 / 2, 279 / 2);
				bag.setPosition(1450, 130);
				bag.scale(0.17, 0.17);
				//bottle
				Texture bottletex;
				bottletex.loadFromFile("bottleImg.png");
				//shelf1
			//shelf1
				Sprite bottle11;
				bottle11.setTexture(bottletex);
				bottle11.setTextureRect(IntRect(0, 0, 360, 360));
				bottle11.setOrigin(360 / 2, 360 / 2);
				bottle11.setPosition(Vector2f(180, 375));
				bottle11.scale(0.17, 0.17);
				Sprite bottle12;
				bottle12.setTexture(bottletex);
				bottle12.setTextureRect(IntRect(0, 0, 360, 360));
				bottle12.setOrigin(360 / 2, 360 / 2);
				bottle12.setPosition(Vector2f(180, 375));
				bottle12.scale(0.17, 0.17);
				Sprite bottle13;
				bottle13.setTexture(bottletex);
				bottle13.setTextureRect(IntRect(0, 0, 360, 360));
				bottle13.setOrigin(360 / 2, 360 / 2);
				bottle13.setPosition(Vector2f(180, 375));
				bottle13.scale(0.17, 0.17);
				point plat1[20];
				int x1 = 550, y1 = 100;
				for (int i = 1; i <= 3; i++) {
					y1 = 175;
					x1 = x1;
					plat1[i].x = x1;
					plat1[i].y = y1;
					x1 = x1 - 100;
				}

			




				//shelf2
				Sprite bottle21;
				bottle21.setTexture(bottletex);
				bottle21.setTextureRect(IntRect(0, 0, 360, 360));
				bottle21.setOrigin(360 / 2, 360 / 2);
				bottle21.setPosition(Vector2f(180, 375));
				bottle21.scale(0.17, 0.17);
				Sprite bottle22;
				bottle22.setTexture(bottletex);
				bottle22.setTextureRect(IntRect(0, 0, 360, 360));
				bottle22.setOrigin(360 / 2, 360 / 2);
				bottle22.setPosition(Vector2f(180, 375));
				bottle22.scale(0.17, 0.17);
				Sprite bottle23;
				bottle23.setTexture(bottletex);
				bottle23.setTextureRect(IntRect(0, 0, 360, 360));
				bottle23.setOrigin(360 / 2, 360 / 2);
				bottle23.setPosition(Vector2f(180, 375));
				bottle23.scale(0.17, 0.17);
				point plat2[20];
				int x2 = 350, y2 = 250;
				for (int i = 1; i <= 3; i++) {
					y2 = 250 + 75;
					x2 = x2;
					plat2[i].x = x2;
					plat2[i].y = y2;
					x2 = x2 - 100;
				}
				//shelf3
				Sprite bottle31;
				bottle31.setTexture(bottletex);
				bottle31.setTextureRect(IntRect(0, 0, 360, 360));
				bottle31.setOrigin(360 / 2, 360 / 2);
				bottle31.setPosition(Vector2f(180, 375));
				bottle31.scale(0.17, 0.17);
				Sprite bottle32;
				bottle32.setTexture(bottletex);
				bottle32.setTextureRect(IntRect(0, 0, 360, 360));
				bottle32.setOrigin(360 / 2, 360 / 2);
				bottle32.setPosition(Vector2f(180, 375));
				bottle32.scale(0.17, 0.17);
				Sprite bottle33;
				bottle33.setTexture(bottletex);
				bottle33.setTextureRect(IntRect(0, 0, 360, 360));
				bottle33.setOrigin(360 / 2, 360 / 2);
				bottle33.setPosition(Vector2f(180, 375));
				bottle33.scale(0.17, 0.17);
				point plat3[20];
				int x3 = 550, y3 = 500;
				for (int i = 1; i <= 3; i++) {
					y3 = 575;
					x3 = x3;
					plat3[i].x = x3;
					plat3[i].y = y3;
					x3 = x3 - 100;
				}
				//shelf4
				Sprite bottle41;
				bottle41.setTexture(bottletex);
				bottle41.setTextureRect(IntRect(0, 0, 360, 360));
				bottle41.setOrigin(360 / 2, 360 / 2);
				bottle41.setPosition(Vector2f(180, 375));
				bottle41.scale(0.17, 0.17);
				Sprite bottle42;
				bottle42.setTexture(bottletex);
				bottle42.setTextureRect(IntRect(0, 0, 360, 360));
				bottle42.setOrigin(360 / 2, 360 / 2);
				bottle42.setPosition(Vector2f(180, 375));
				bottle42.scale(0.17, 0.17);
				Sprite bottle43;
				bottle43.setTexture(bottletex);
				bottle43.setTextureRect(IntRect(0, 0, 360, 360));
				bottle43.setOrigin(360 / 2, 360 / 2);
				bottle43.setPosition(Vector2f(180, 375));
				bottle43.scale(0.17, 0.17);
				point plat4[20];
				int x4 = 900, y4 = 300;
				for (int i = 1; i <= 3; i++) {
					y4 = 375;
					x4 = x4;
					plat4[i].x = x4;
					plat4[i].y = y4;
					x4 = x4 - 100;
				}
				//shelf5
				Sprite bottle51;
				bottle51.setTexture(bottletex);
				bottle51.setTextureRect(IntRect(0, 0, 360, 360));
				bottle51.setOrigin(360 / 2, 360 / 2);
				bottle51.setPosition(Vector2f(180, 375));
				bottle51.scale(0.17, 0.17);
				Sprite bottle52;
				bottle52.setTexture(bottletex);
				bottle52.setTextureRect(IntRect(0, 0, 360, 360));
				bottle52.setOrigin(360 / 2, 360 / 2);
				bottle52.setPosition(Vector2f(180, 375));
				bottle52.scale(0.17, 0.17);
				Sprite bottle53;
				bottle53.setTexture(bottletex);
				bottle53.setTextureRect(IntRect(0, 0, 360, 360));
				bottle53.setOrigin(360 / 2, 360 / 2);
				bottle53.setPosition(Vector2f(180, 375));
				bottle53.scale(0.17, 0.17);
				point plat5[20];
				int x5 = 1250, y5 = 500;
				for (int i = 1; i <= 3; i++) {
					y5 = 575;
					x5 = x5;
					plat5[i].x = x5;
					plat5[i].y = y5;
					x5 = x5 - 100;
				}
				//shelf6
				Sprite bottle61;
				bottle61.setTexture(bottletex);
				bottle61.setTextureRect(IntRect(0, 0, 360, 360));
				bottle61.setOrigin(360 / 2, 360 / 2);
				bottle61.setPosition(Vector2f(180, 375));
				bottle61.scale(0.17, 0.17);
				Sprite bottle62;
				bottle62.setTexture(bottletex);
				bottle62.setTextureRect(IntRect(0, 0, 360, 360));
				bottle62.setOrigin(360 / 2, 360 / 2);
				bottle62.setPosition(Vector2f(180, 375));
				bottle62.scale(0.17, 0.17);
				Sprite bottle63;
				bottle63.setTexture(bottletex);
				bottle63.setTextureRect(IntRect(0, 0, 360, 360));
				bottle63.setOrigin(360 / 2, 360 / 2);
				bottle63.setPosition(Vector2f(180, 375));
				bottle63.scale(0.17, 0.17);
				point plat6[20];
				int x6 = 1405, y6 = 250;
				for (int i = 1; i <= 3; i++) {
					y6 = 250 + 75;
					x6 = x6;
					plat6[i].x = x6;
					plat6[i].y = y6;
					x6 = x6 - 100;
				}
				//shelf7
				Sprite bottle71;
				bottle71.setTexture(bottletex);
				bottle71.setTextureRect(IntRect(0, 0, 360, 360));
				bottle71.setOrigin(360 / 2, 360 / 2);
				bottle71.setPosition(Vector2f(180, 375));
				bottle71.scale(0.17, 0.17);
				Sprite bottle72;
				bottle72.setTexture(bottletex);
				bottle72.setTextureRect(IntRect(0, 0, 360, 360));
				bottle72.setOrigin(360 / 2, 360 / 2);
				bottle72.setPosition(Vector2f(180, 375));
				bottle72.scale(0.17, 0.17);
				Sprite bottle73;
				bottle73.setTexture(bottletex);
				bottle73.setTextureRect(IntRect(0, 0, 360, 360));
				bottle73.setOrigin(360 / 2, 360 / 2);
				bottle73.setPosition(Vector2f(180, 375));
				bottle73.scale(0.17, 0.17);
				point plat7[20];
				int x7 = 1450, y7 = 50;
				for (int i = 1; i <= 2; i++) {
					y7 = 125;
					x7 = x7 - 100;
					plat7[i].x = x7;
					plat7[i].y = y7;
					x7 = x7 - 10;
				}

				//shelf
				Texture whiteshelf;
				whiteshelf.loadFromFile("white_shelflast.png");
				//Sprite shelf1;
				//shelf1.setTexture(whiteshelf);
				//shelf1.setPosition(Vector2f(600, 100));
				////shelf1.setOrigin(Vector2f(800 / 2, 344 / 2));
				//Sprite shelf2;
				//shelf2.setTexture(whiteshelf);
				//shelf2.setPosition(Vector2f(400, 250));
				////shelf2.setOrigin(Vector2f(800 / 2, 344 / 2));
				//Sprite shelf3;
				//shelf3.setTexture(whiteshelf);
				//shelf3.setPosition(Vector2f(600, 500));
				////shelf3.setOrigin(Vector2f(800 / 2, 344 / 2));
				////cout << shelf3.getPosition().y << endl;
				//Sprite shelf4;
				//shelf4.setTexture(whiteshelf);
				//shelf4.setPosition(Vector2f(950, 300));
				////shelf4.setOrigin(Vector2f(800 / 2, 344 / 2));
				//Sprite shelf5;
				//shelf5.setTexture(whiteshelf);
				//shelf5.setPosition(Vector2f(1300, 500));
				////shelf5.setOrigin(Vector2f(800 / 2, 344 / 2));
				//Sprite shelf6;
				//shelf6.setTexture(whiteshelf);
				//shelf6.setPosition(Vector2f(1455, 250));
				////shelf6.setOrigin(Vector2f(800 / 2, 344 / 2));
				//Sprite shelf7;
				//shelf7.setTexture(whiteshelf);
				//shelf7.setPosition(Vector2f(1500, 50));
				////shelf7.setOrigin(Vector2f(800 / 2, 344 / 2));
				RectangleShape shelfs[7];
				for (int i = 0; i < 7; i++) {
					shelfs[i].setFillColor(Color::White);
					shelfs[i].setSize({ 300, 50 });
				}
				shelfs[0].setPosition(300, 210);
				shelfs[1].setPosition(100, 360);
				shelfs[2].setPosition(300, 610);
				shelfs[3].setPosition(650, 410);
				shelfs[4].setPosition(1000, 610);
				shelfs[5].setPosition(1150, 360);
				shelfs[6].setPosition(1200, 160);
				//font
				/*Font our_font;
				our_font.loadFromFile("From Cartoon Blocks.ttf");
				Text lose;
				lose.setFillColor(Color::Black);
				lose.setFont(our_font);
				lose.setPosition(400, 300);
				lose.scale(5,5);*/
				Text scoret;
				Font our_font2;
				scoret.setFillColor(Color::Black);
				our_font2.loadFromFile("From Cartoon Blocks.ttf");
				scoret.setFont(our_font2);
				scoret.setString("score:0");
				scoret.setPosition(Vector2f(39, 10));
				scoret.scale(2, 2);
				int score = 0;
				bool played = false;

				//baby background
				Texture babytex;
				babytex.loadFromFile("boss baby.png");
				Sprite babyg;
				babyg.setTexture(babytex);
				babyg.scale(0.75, 0.75);
				babyg.setTextureRect(IntRect(0, 0, 500, 500));
				babyg.setOrigin(500 / 2, 500 / 2);
				babyg.setPosition(1450, 660);

				//sound
				/*SoundBuffer soundbuffer1;
				soundbuffer1.loadFromFile("w.wav");
				Sound colsound;
				colsound.setBuffer(soundbuffer1);
				colsound.setVolume(100.0f);*/



				SoundBuffer soundbuffer2;
				soundbuffer2.loadFromFile("lose_sound_wav.wav");
				Sound losesound;
				losesound.setBuffer(soundbuffer2);
				losesound.setVolume(100.0f);

				


		

				SoundBuffer soundbuffer3;
				soundbuffer3.loadFromFile("w.wav");
				Sound winsound;
				winsound.setBuffer(soundbuffer3);
				//winsound.setVolume(100.0f);
				//winsound.play();

				SoundBuffer sound2;
				if (!sound2.loadFromFile("pop-94319.wav")) {
					cout << "error";
				}
				Sound colsound;
				colsound.setBuffer(sound2);

				//backg
				Texture text;
				text.loadFromFile("the boss.png");
				Sprite sp;
				sp.setTexture(text);
				sp.setTextureRect(IntRect(0, 0, 820, 515));
				sp.scale(2, 1.5);
				while (window.isOpen()) {
					gameclock.restart();

					while (window.pollEvent(event)) {
						if (event.type == Event::Closed)
							window.close();
						if (event.type == Event::KeyPressed) {
							if (event.key.code == Keyboard::P) {
								if (pause)
									pause = false;
								else pause = true;
							}
						}
						/*else if (event.type == Event::KeyPressed) {
							if (event.key.code == Keyboard::Space && grounded) {

								velocity.y = jumpHeight;
								grounded = false;
							}
						}*/
					}
					if (!pause) {
						if (Keyboard::isKeyPressed(Keyboard::Right)) {
							baby.setScale(2, 2);
							if (timer < 0) {
								i++;
								i = i % 5;
								baby.setTextureRect(IntRect((i * 48.4), 0, 48.4, 50));
								timer = delay;
							}
							else {
								timer -= deltatime;
							}
							velocity.x = 200 * deltatime;
							//baby.move(velocity);
						}
						else if (Keyboard::isKeyPressed(Keyboard::Left)) {
							baby.setScale(-2, 2);
							if (timer < 0) {
								i++;
								i = i % 5;
								baby.setTextureRect(IntRect((i * 48.4), 0, 48.4, 50));
								timer = delay;
							}
							else {
								timer -= deltatime;
							}
							velocity.x = -200 * deltatime;
							//baby.move(velocity);
						}
						else
							velocity.x = 0;
						baby.move(velocity);

						if (baby.getGlobalBounds().intersects(shape.getGlobalBounds()))
						{
							if (baby.getGlobalBounds().top + baby.getGlobalBounds().height - 10 < shape.getGlobalBounds().top) {
								velocity.y = 0;
								grounded = true;

								if (Keyboard::isKeyPressed(Keyboard::Space)) {
									velocity.y = jumpHeight;
									baby.move(velocity);
								}
							}
							else {
								velocity.y += gravity * deltatime;
							}
						}

						else if (baby.getGlobalBounds().intersects(shelfs[0].getGlobalBounds()))
						{

							if (baby.getGlobalBounds().top + baby.getGlobalBounds().height - 10 < shelfs[0].getPosition().y) {
								velocity.y = 0;
								grounded = 1;
								if (Keyboard::isKeyPressed(Keyboard::Space)) {
									velocity.y = jumpHeight;
									grounded = false;
								}
							}
							else {
								velocity.y += gravity * deltatime;
							}
						}
						else if (baby.getGlobalBounds().intersects(shelfs[1].getGlobalBounds()))
						{
							if (baby.getGlobalBounds().top + baby.getGlobalBounds().height - 10 < shelfs[1].getPosition().y) {
								velocity.y = 0;
								grounded = 1;
								if (Keyboard::isKeyPressed(Keyboard::Space)) {
									velocity.y = jumpHeight;
									grounded = false;
								}
							}
							else {
								velocity.y += gravity * deltatime;
							}

						}
						else if (baby.getGlobalBounds().intersects(shelfs[2].getGlobalBounds()))
						{
							if (baby.getGlobalBounds().top + baby.getGlobalBounds().height - 3 < shelfs[2].getPosition().y) {
								velocity.y = 0;
								grounded = 1;
								if (Keyboard::isKeyPressed(Keyboard::Space)) {
									velocity.y = jumpHeight;
									grounded = false;
								}
							}
							else {
								velocity.y += gravity * deltatime;
							}
						}
						else if (baby.getGlobalBounds().intersects(shelfs[3].getGlobalBounds()))
						{
							if (baby.getGlobalBounds().top + baby.getGlobalBounds().height - 3 < shelfs[3].getPosition().y) {
								velocity.y = 0;
								grounded = 1;
								if (Keyboard::isKeyPressed(Keyboard::Space)) {
									velocity.y = jumpHeight;
									grounded = false;
								}
							}
							else {
								velocity.y += gravity * deltatime;
							}
						}
						else if (baby.getGlobalBounds().intersects(shelfs[4].getGlobalBounds()))
						{
							if (baby.getGlobalBounds().top + baby.getGlobalBounds().height - 3 < shelfs[4].getPosition().y) {
								velocity.y = 0;
								grounded = 1;
								if (Keyboard::isKeyPressed(Keyboard::Space)) {
									velocity.y = jumpHeight;
									grounded = false;
								}
							}
							else {
								velocity.y += gravity * deltatime;
							}
						}
						else if (baby.getGlobalBounds().intersects(shelfs[5].getGlobalBounds()))
						{
							if (baby.getGlobalBounds().top + baby.getGlobalBounds().height - 3 < shelfs[5].getPosition().y) {
								velocity.y = 0;
								grounded = 1;
								if (Keyboard::isKeyPressed(Keyboard::Space)) {
									velocity.y = jumpHeight;
									grounded = false;
								}
							}
							else {
								velocity.y += gravity * deltatime;
							}
						}
						else if (baby.getGlobalBounds().intersects(shelfs[6].getGlobalBounds()))
						{
							if (baby.getGlobalBounds().top + baby.getGlobalBounds().height - 3 < shelfs[6].getPosition().y) {
								velocity.y = 0;
								grounded = 1;
								if (Keyboard::isKeyPressed(Keyboard::Space)) {
									velocity.y = jumpHeight;
									grounded = false;
								}
							}
							else {
								velocity.y += gravity * deltatime;
							}
						}
						else {
							grounded = false;
							velocity.y += gravity * deltatime;
						}


						window.clear(Color(128, 216, 255));
						timere(h, m, s, thetimer, deltatime);
						timing.setString((to_string(h) + ":" + to_string(m) + ":" + to_string(s)));
						window.draw(timing);
						//shelf1
						bottle11.setPosition(plat1[1].x, plat1[1].y);
						window.draw(bottle11);
						bottle12.setPosition(plat1[2].x, plat1[2].y);
						window.draw(bottle12);
						bottle13.setPosition(plat1[3].x, plat1[3].y);
						window.draw(bottle13);
						if (baby.getGlobalBounds().intersects(bottle11.getGlobalBounds())) {
							bottle11.setScale(0, 0);
							score += 10;
							colsound.play();
							scoret.setString("score:" + to_string(score));
						}
						if (baby.getGlobalBounds().intersects(bottle12.getGlobalBounds())) {
							bottle12.setScale(0, 0);
							score += 10;
							colsound.play();
							scoret.setString("score:" + to_string(score));
						}
						if (baby.getGlobalBounds().intersects(bottle13.getGlobalBounds())) {
							bottle13.setScale(0, 0);
							score += 10;
							colsound.play();
							scoret.setString("score:" + to_string(score));
						}
						//shelf2
						bottle21.setPosition(plat2[1].x, plat2[1].y);
						window.draw(bottle21);
						bottle22.setPosition(plat2[2].x, plat2[2].y);
						window.draw(bottle22);
						bottle23.setPosition(plat2[3].x, plat2[3].y);
						window.draw(bottle23);
						if (baby.getGlobalBounds().intersects(bottle21.getGlobalBounds())) {
							bottle21.setScale(0, 0);
							score += 10;
							colsound.play();
							scoret.setString("score:" + to_string(score));
						}
						if (baby.getGlobalBounds().intersects(bottle22.getGlobalBounds())) {
							bottle22.setScale(0, 0);
							score += 10;
							colsound.play();
							scoret.setString("score:" + to_string(score));
						}
						if (baby.getGlobalBounds().intersects(bottle23.getGlobalBounds())) {
							bottle23.setScale(0, 0);
							score += 10;
							colsound.play();
							scoret.setString("score:" + to_string(score));
						}
						//shelf3
						bottle31.setPosition(plat3[1].x, plat3[1].y);
						window.draw(bottle31);
						bottle32.setPosition(plat3[2].x, plat3[2].y);
						window.draw(bottle32);
						bottle33.setPosition(plat3[3].x, plat3[3].y);
						window.draw(bottle33);
						if (baby.getGlobalBounds().intersects(bottle31.getGlobalBounds())) {
							bottle31.setScale(0, 0);
							score += 10;
							colsound.play();
							scoret.setString("score:" + to_string(score));
						}
						if (baby.getGlobalBounds().intersects(bottle32.getGlobalBounds())) {
							bottle32.setScale(0, 0);
							score += 10;
							colsound.play();
							scoret.setString("score:" + to_string(score));
						}
						if (baby.getGlobalBounds().intersects(bottle33.getGlobalBounds())) {
							bottle33.setScale(0, 0);
							score += 10;
							colsound.play();
							scoret.setString("score:" + to_string(score));
						}
						//shelf4
						bottle41.setPosition(plat4[1].x, plat4[1].y);
						window.draw(bottle41);
						bottle42.setPosition(plat4[2].x, plat4[2].y);
						window.draw(bottle42);
						bottle43.setPosition(plat4[3].x, plat4[3].y);
						window.draw(bottle43);
						if (baby.getGlobalBounds().intersects(bottle41.getGlobalBounds())) {
							bottle41.setScale(0, 0);
							score += 10;
							colsound.play();
							scoret.setString("score:" + to_string(score));
						}
						if (baby.getGlobalBounds().intersects(bottle42.getGlobalBounds())) {
							bottle42.setScale(0, 0);
							score += 10;
							colsound.play();
							scoret.setString("score:" + to_string(score));
						}
						if (baby.getGlobalBounds().intersects(bottle43.getGlobalBounds())) {
							bottle43.setScale(0, 0);
							score += 10;
							colsound.play();
							scoret.setString("score:" + to_string(score));
						}
						//shelf5

						bottle51.setPosition(plat5[1].x, plat5[1].y);
						window.draw(bottle51);
						bottle52.setPosition(plat5[2].x, plat5[2].y);
						window.draw(bottle52);
						bottle53.setPosition(plat5[3].x, plat5[3].y);
						window.draw(bottle53);
						if (baby.getGlobalBounds().intersects(bottle51.getGlobalBounds())) {
							bottle51.setScale(0, 0);
							score += 10;
							colsound.play();
							scoret.setString("score:" + to_string(score));
						}
						if (baby.getGlobalBounds().intersects(bottle52.getGlobalBounds())) {
							bottle52.setScale(0, 0);
							score += 10;
							colsound.play();
							scoret.setString("score:" + to_string(score));
						}
						if (baby.getGlobalBounds().intersects(bottle53.getGlobalBounds())) {
							bottle53.setScale(0, 0);
							score += 10;
							colsound.play();
							scoret.setString("score:" + to_string(score));
						}
						//shelf6
						bottle61.setPosition(plat6[1].x, plat6[1].y);
						window.draw(bottle61);
						bottle62.setPosition(plat6[2].x, plat6[2].y);
						window.draw(bottle62);
						bottle63.setPosition(plat6[3].x, plat6[3].y);
						window.draw(bottle63);
						if (baby.getGlobalBounds().intersects(bottle61.getGlobalBounds())) {
							bottle61.setScale(0, 0);
							score += 10;
							colsound.play();
							scoret.setString("score:" + to_string(score));
						}
						if (baby.getGlobalBounds().intersects(bottle62.getGlobalBounds())) {
							bottle62.setScale(0, 0);
							score += 10;
							colsound.play();
							scoret.setString("score:" + to_string(score));
						}
						if (baby.getGlobalBounds().intersects(bottle63.getGlobalBounds())) {
							bottle63.setScale(0, 0);
							score += 10;
							colsound.play();
							scoret.setString("score:" + to_string(score));
						}
						//shelf7
						bottle71.setPosition(plat7[1].x, plat7[1].y);
						window.draw(bottle71);
						bottle72.setPosition(plat7[2].x, plat7[2].y);
						window.draw(bottle72);
						bottle73.setPosition(plat7[3].x, plat7[3].y);
						window.draw(bottle73);
						if (baby.getGlobalBounds().intersects(bottle71.getGlobalBounds())) {
							bottle71.setScale(0, 0);
							score += 10;
							colsound.play();
							scoret.setString("score:" + to_string(score));
						}
						if (baby.getGlobalBounds().intersects(bottle72.getGlobalBounds())) {
							bottle72.setScale(0, 0);
							score += 10;
							colsound.play();
							scoret.setString("score:" + to_string(score));
						}
						if (baby.getGlobalBounds().intersects(bottle73.getGlobalBounds())) {
							bottle73.setScale(0, 0);
							score += 10;
							colsound.play();
							scoret.setString("score:" + to_string(score));
						}
						if (baby.getGlobalBounds().intersects(bag.getGlobalBounds())) {
							win = true;
							bag.setScale(0, 0);
							score += 40;
							colsound.play();
							scoret.setString("score:" + to_string(score));
						}
						if (baby.getGlobalBounds().intersects(door.getGlobalBounds())) {
							opend = true;
							baby.setScale(0, 0);
						}
						window.draw(babyg);

						window.draw(scoret);
						window.draw(shape);
						for (int i = 0; i < 7; i++) {
							window.draw(shelfs[i]);
						}
						//window.draw(shelf1);
						//window.draw(shelf2);
						//window.draw(shelf3);
						//window.draw(shelf4);
						//window.draw(shelf5);
						//window.draw(shelf6);
						//window.draw(shelf7);
						window.draw(baby);
						window.draw(bag);
						window.draw(door);
						/*RectangleShape test;
						test.setSize({20, 20		});
						test.setPosition(500, 600);
						test.setFillColor(Color::Black);
						window.draw(test);
						cout << shelf3.getPosition().y << endl;*/
						if (score >= 200 && win && opend) {
							baby.setScale(0, 0);
							if (!played) {
								winsound.play();
								played = true;
							}
							window.draw(babywin);
						}
						else if (s ==0 && score < 200) {
							baby.setScale(0, 0);
							window.draw(gameover);
							//lose.setString("GAME OVER ");
							if (!played) {
								losesound.play();
								played = true;
							}
							//window.draw(gameover);
						}
						window.display();
						deltatime = gameclock.getElapsedTime().asSeconds();

					}
				}
			}
			else if (page_number == 1) {
				window.close();
			}
		}

		window.clear();
		window.draw(background);
		menu.draw(window);
		window.display();

	}
	return 0;
}