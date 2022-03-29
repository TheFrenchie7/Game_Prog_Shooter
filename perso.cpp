#pragma once
#include "perso.h"
#include "main.h"
#include "game.cpp"

//le constructeur
Perso::Perso()
{

}

void Perso::AnimPlayer() const
{
	//maj de notre sprite
	perso.persoSprite.setTextureRect(IntRect(perso1Anim.x * SPRITE_SIZE, perso1Anim.y * SPRITE_SIZE, SPRITE_SIZE, SPRITE_SIZE));
	//animation en bcl de la colonne
	if (persoAnimClock.getElapsedTime().asSeconds() > 0.1f)
	{
		//on est  bout de la texture en largeur
		if (perso1Anim.x * SPRITE_SIZE >= persoTexture.getSize().x - SPRITE_SIZE)
		{
			//on reset
			perso1Anim.x = 0;
			//si l anim d attaque tourne
			if (needResetAnim)
			{
				// on la stop et on retourne sur celle de marche
				needResetAnim = false;
				perso1Anim.y -= 4;
			}
		}
		else
		{
			perso1Anim.x++;
		}
		persoAnimClock.restart();
	}
}

void Perso::Afficher() const
{
	
	//maj de notre sprite
	perso.persoSprite.setTextureRect(IntRect(perso1Anim.x * SPRITE_SIZE, perso1Anim.y * SPRITE_SIZE, SPRITE_SIZE, SPRITE_SIZE));
	if (!perso.persoTexture.loadFromFile("res/perso1.png"))
		cerr << "erreur du chargement de la texture du perso" << endl;
	perso.persoSprite.setTexture(persoTexture);
	perso.persoSprite.setTextureRect(IntRect(perso1Anim.x * SPRITE_SIZE, perso1Anim.y * SPRITE_SIZE, SPRITE_SIZE, SPRITE_SIZE));
}

void CheckBtn()
{
	// position en x et y du perso
	int pPosX = round(perso.persoSprite.getPosition().x / SPRITE_SIZE);
	int pPosY = round(perso.persoSprite.getPosition().y / SPRITE_SIZE);
	if (canShowCollisionsDebug)
	{
		cout << levelLoaded[(pPosX + pPosY * COL_COUNT)] << endl;
		cout << pPosX << "  " << pPosY << endl;
	}

	if (!needResetAnim) // si pas d'attaque en cours
	{
		if (input.GetButton().left == true)
		{

			perso1Anim.y = Left;
			//verifions si a notre gauche on  na un solide ou non
			pPosX = round((perso.persoSprite.getPosition().x - (WALK_SPEED * 2)) / SPRITE_SIZE);
			//si la position future est sur une case solide
			if (levelLoadedCollisions[(pPosX + pPosY * COL_COUNT)] == 0)
			{
				perso.persoSprite.move(-WALK_SPEED, 0);
			}


		}
		if (input.GetButton().right == true)
		{
			perso1Anim.y = Right;
			pPosX = round((perso.persoSprite.getPosition().x + (WALK_SPEED * 2)) / SPRITE_SIZE);
			if (levelLoadedCollisions[(pPosX + pPosY * COL_COUNT)] == 0)
			{
				perso.persoSprite.move(WALK_SPEED, 0);
			}

		}
		if (input.GetButton().up == true)
		{
			perso1Anim.y = Up;
			pPosY = round((perso.persoSprite.getPosition().y - (WALK_SPEED * 2)) / SPRITE_SIZE);
			if (levelLoadedCollisions[(pPosX + pPosY * COL_COUNT)] == 0)
			{
				perso.persoSprite.move(0, -WALK_SPEED);
			}

		}
		if (input.GetButton().down == true)
		{
			perso1Anim.y = Down;
			pPosY = round((perso.persoSprite.getPosition().y + (WALK_SPEED * 2)) / SPRITE_SIZE);
			if (levelLoadedCollisions[(pPosX + pPosY * COL_COUNT)] == 0)
			{
				perso.persoSprite.move(0, WALK_SPEED);
			}


		}

		if (input.GetButton().attack == true)
		{
			needResetAnim = true; // apres attaque retourner sur l'anim walk
			perso1Anim.x = 0; // retourner a la col 0 (jouer l anim depuis le debut)
			perso1Anim.y += 4; // on descend de 4 lignes sur notre sprite sheet pour passer de l'anim walk a attaque
		}
	}

	if (input.GetButton().escape == true)
	{
		game_window.close();
	}
	canShowCollisionsDebug = input.GetButton().Debug;

}