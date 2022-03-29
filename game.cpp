#include "game.h"
#include "main.h"
#include "perso.h"
#include "enemy.h"

//variable globale

#pragma region Variables Globales
RenderWindow game_window;
Input input;
Perso perso;



Enemy enemy;
Sprite enemySprite;
Texture enemyTexture{};

// Timer
Clock persoAnimClock;
enum Dir { Down, Right, Up, Left, Down_Atk, Right_Atk, Up_Atack, Left_Atack };
Vector2i perso1Anim(0, Down);
Vector2i enemyAnim(0, Down);
//gestion de l'attaque a l'epee
bool needResetAnim = false;

//tableaux representant la map
int levelLoaded[1800]; // 60 * 34
//tableaux representant les collisions de la map
int levelLoadedCollisions[1800];

//debug collision
RectangleShape rects[1800];
bool canShowCollisionsDebug = false;
#pragma endregion

int Game()
{
	
	//antialiazing
	ContextSettings options;
	options.antialiasingLevel = 8;
	//creation de la fenetre
	game_window.create(VideoMode(WIND_WIDTH_G, WIND_HEIGHT_G), "Game", Style::Default, options);
	//camera follow le perso
	View view(Vector2f(0.0f, 0.0f), Vector2f(WIND_WIDTH_G, WIND_HEIGHT_G));
	//activation de la vsync
	game_window.setVerticalSyncEnabled(true);
	//chargement texture du heros

	//Chargement de la map depuis le fichier   
	ifstream ifs("res/map.txt");
	string content((istreambuf_iterator<char>(ifs)), (istreambuf_iterator<char>()));
	cout << "Map chargee avec succes : " << content << endl;
	//découppe de la chaine en char
	auto exploded = explode(content, ' ');
	for (int i = 0; i < 894; i++)
		levelLoaded[i] = stoi(exploded[i]);

	//Chargement des collisions de la map depuis les fihiers collisions 
	ifstream ifsCol("res/mapcollision.txt");
	string contentCol((istreambuf_iterator<char>(ifsCol)), (istreambuf_iterator<char>()));
	cout << "Map collision chargee avec succes : " << contentCol << endl;
	//découppe de la chaine en char
	auto explodedCol = explode(contentCol, ' ');
	for (int i = 0; i < 894; i++)
		levelLoadedCollisions[i] = stoi(explodedCol[i]);

	
	launch_game();
	return 0;
}





void launch_game()
{

	

	View view,viewmap;
	Map map;
	if (!map.load("res/tileset.png", Vector2u(SPRITE_SIZE, SPRITE_SIZE), levelLoaded, COL_COUNT, ROW_COUNT))
		return; //arreter le prog si ca marche pas

	while (game_window.isOpen())
	{
		Event event;
		while (game_window.pollEvent(event))
		{
			input.InputHanlder_Game(event, game_window);
		}
		
		perso.CheckBtn();
		perso.AnimPlayer();
		
		//on recupere la positon du perso pour mettre le centre de la cam decu
		view.setCenter(perso.persoSprite.getPosition());
		//on actualise l ecran
		game_window.clear();
		game_window.setView(view);
		game_window.draw(map);
		//dessin du perso		
		game_window.draw(perso.persoSprite);
		game_window.draw(enemySprite);

		// on dessine a l ecran les elements
		game_window.display();
		debugMode();
	}
	
}

void debugMode()
{
	//pour debug visuellment les collisions de la map
	for (unsigned int j = 0; j < ROW_COUNT; ++j)
	{// on boucle sur chaque l et c
		for (unsigned int i = 0; i < COL_COUNT; ++i)
		{
			if (levelLoadedCollisions[(i + j * COL_COUNT)] == 1)
			{
				Vector2f pos = Vector2f(i * SPRITE_SIZE, j * SPRITE_SIZE);
				rects[(i + j * COL_COUNT)].setPosition(pos);
				rects[(i + j * COL_COUNT)].setSize(Vector2f(SPRITE_SIZE, SPRITE_SIZE));
				rects[(i + j * COL_COUNT)].setFillColor(Color(250, 0, 0, 100));
				if (canShowCollisionsDebug)
					game_window.draw(rects[(i + j * COL_COUNT)]);
			}
		}
	}
}



//fct explode
vector<string> explode(string const& s, char delim)
{
	vector<string> result;
	istringstream iss(s);

	for (string token; getline(iss, token, delim); )
	{
		result.push_back(move(token));
	}

	return result;
}

