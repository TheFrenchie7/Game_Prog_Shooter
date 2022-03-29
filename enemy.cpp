#pragma once
#include "enemy.h"
#include "main.h"
#include "game.cpp"

//le constructeur
Enemy::Enemy()
{

}

/*void Enemy::AnimEnemy() const
{
	//maj de notre sprite
	persoSprite.setTextureRect(IntRect(perso1Anim.x * SPRITE_SIZE, perso1Anim.y * SPRITE_SIZE, SPRITE_SIZE, SPRITE_SIZE));
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
}*/

void Enemy::Afficher() const
{

	//maj de notre sprite
	enemySprite.setTextureRect(IntRect(enemyAnim.x * SPRITE_SIZE, perso1Anim.y * SPRITE_SIZE, SPRITE_SIZE, SPRITE_SIZE));
	if (!enemyTexture.loadFromFile("res/monstre.png"))
		cerr << "erreur du chargement de la texture de l'ennemi" << endl;
	enemySprite.setTexture(enemyTexture);
	enemySprite.setTextureRect(IntRect(enemyAnim.x * SPRITE_SIZE, enemyAnim.y * SPRITE_SIZE, SPRITE_SIZE, SPRITE_SIZE));
	enemySprite.setPosition(5 * SPRITE_SIZE, 5 * SPRITE_SIZE);
}

