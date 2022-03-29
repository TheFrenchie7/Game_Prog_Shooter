#pragma once
#include "game.h"

class Enemy
{
public:
	Enemy();
	//void AnimEnemy()const;
	void Afficher()const;
	


private:

	int m_vie;
	int m_vitesse;
	int m_degatsArme;
	bool m_alive;
	string m_nomArme;
};
