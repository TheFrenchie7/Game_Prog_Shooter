//include
#include <SFML/Graphics.hpp>
#include<iostream>
#include"input.h"
#include"map.h"

//raccourci
using namespace sf;
using namespace std;

//variables
const int WIND_WIDTH = 1920; 
const int WIND_HEIGHT = 1080; 
const int WIND_WIDTH_G = 1080; // 25 tiles de 32px
const int WIND_HEIGHT_G = 920; //18 tiles de 32px
const int SPRITE_SIZE = 32; //sprites de 32*32
const int WALK_SPEED = 1;//aux mauvaise endroit
const int COL_COUNT = 50;
const int ROW_COUNT = 36;



//prototype de fcts

void InputHandlerWindow(Event event, RenderWindow& window);