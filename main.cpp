#include "menu.h"
#include "main.h"
#include "game.h"



int main()
{


	RenderWindow MENU(VideoMode(WIND_WIDTH, WIND_HEIGHT), "Main Menu");
	MainMenu mainMenu(MENU.getSize().x, MENU.getSize().y);
	RectangleShape background;
	background.setSize(Vector2f(WIND_WIDTH, WIND_HEIGHT));
	Texture Maintexture;
	Maintexture.loadFromFile("res/image/fond.png");
	background.setTexture(&Maintexture);
	
	RectangleShape Pbackground;
	Pbackground.setSize(Vector2f(WIND_WIDTH, WIND_HEIGHT));
	Texture back_texture;
	back_texture.loadFromFile("res/image/play.png");
	Pbackground.setTexture(&back_texture);

	RectangleShape Obackground;
	Obackground.setSize(Vector2f(WIND_WIDTH, WIND_HEIGHT));
	Texture Optiontexture;
	Optiontexture.loadFromFile("res/image/option.png");
	Obackground.setTexture(&Optiontexture);

	RectangleShape Abackground;
	Abackground.setSize(Vector2f(WIND_WIDTH, WIND_HEIGHT));
	Texture Abouttexture;
	Abouttexture.loadFromFile("res/image/about.png");
	Abackground.setTexture(&Abouttexture);

	

	while (MENU.isOpen())
	{
		Event event;
		while (MENU.pollEvent(event))
		{
			InputHandlerWindow(event, MENU);

			if (event.type == Event::KeyReleased) {
				if (event.key.code == Keyboard::Up) {
					mainMenu.MoveUp();
					break;
				}
				if (event.key.code == Keyboard::Down)
				{
					mainMenu.MoveDown();
					break;
				}
				if (event.key.code == Keyboard::Return) {
					RenderWindow Play(VideoMode(WIND_WIDTH, WIND_HEIGHT), "Shooteur");
					RenderWindow OPTIONS(VideoMode(WIND_WIDTH, WIND_HEIGHT), "OPTIONS");
					RenderWindow ABOUT(VideoMode(WIND_WIDTH, WIND_HEIGHT), "ABOUT");

					int x = mainMenu.MainMenuPressed();
					if (x == 0)
					{
						Play.close();
						OPTIONS.close();
						ABOUT.close();
						Game();

					}
					if (x == 1)
					{
						while (OPTIONS.isOpen())
						{
							Event event;
							while (OPTIONS.pollEvent(event)) {
								InputHandlerWindow(event, OPTIONS);
							}
							Play.close();
							ABOUT.close();
							OPTIONS.clear();
							OPTIONS.draw(Obackground);
							OPTIONS.display();
						}
					}
					if (x == 2)
					{
						while (ABOUT.isOpen())
						{
							Event event;
							while (ABOUT.pollEvent(event)) {
								InputHandlerWindow(event, ABOUT);
							}
							Play.close();
							OPTIONS.close();
							ABOUT.clear();
							ABOUT.draw(Abackground);
							ABOUT.display();
						}
					}
					if (x == 3)
						MENU.close();
					break;
				}
			}
		}
		MENU.clear();
		MENU.draw(background);
		mainMenu.draw(MENU);
		MENU.display();
	}
	return 0;
}

void InputHandlerWindow(Event event, RenderWindow &window)
{

	if (event.type == Event::Closed)
	{
		window.close();
	}

	if (event.type == Event::KeyPressed)
	{
		if (event.key.code == Keyboard::Escape) {
			window.close();
		}
	}
}