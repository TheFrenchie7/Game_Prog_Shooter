#ifndef INPUT_H
#define INPUT_H

#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class Input
{
	struct Button { bool left, right, up, down, attack, escape, Debug; };
public:

	Input();

	Button GetButton(void) const;

	void InputHanlder_Game(Event event, RenderWindow& window);
	

private:

	Button button;

};


#endif