#include "input.h"

//constructeur
Input::Input()
{
	//on initialise les valeurs a false
	button.left = button.right = button.up = button.down = button.attack = button.escape = button.Debug = false;
}

Input::Button Input::GetButton(void) const
{
	return button;
}

void Input::InputHanlder_Game(Event event, RenderWindow& window)
{
	if (event.type == Event::KeyPressed)
	{
		switch (event.key.code)
		{
		case Keyboard::Escape:
			button.escape = true;
			break;
		case Keyboard::R:
			button.right = true;
			printf("ye");
			break;
		case Keyboard::Z:
			button.left = true;
			break;
		case Keyboard::T:
			button.down = true;
			break;
		case Keyboard::Y:
			button.up = true;
			break;
		case Keyboard::H:
			button.Debug = true;
			break;
		}
	}

	if (event.type == Event::KeyReleased)
	{
		switch (event.key.code)
		{
		case Keyboard::Escape:
			button.escape = false;
			break;
		case Keyboard::R:
			button.right = false;
			break;
		case Keyboard::Z:
			button.left = false;
			break;
		case Keyboard::T:
			button.down = false;
			break;
		case Keyboard::Y:
			button.up = false;
			break;
		case Keyboard::H:
			button.Debug = false;
			break;
		}
	}

	// Détection btn souris
	if (event.type == Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == Mouse::Left)
		{
			button.attack = true;
		}
	}
	if (event.type == Event::MouseButtonReleased)
	{
		if (event.mouseButton.button == Mouse::Left)
		{
			button.attack = false;
		}
	}
}


