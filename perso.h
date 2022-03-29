#pragma once
#include "game.h"

class Perso : public Sprite , Texture 
{
public:

	Perso();
	void AnimPlayer()const;
	void Afficher()const;
	void CheckBtn()const;
	Sprite persoSprite;
	Texture persoTexture{};
private:
	//classe
	string m_nomArme;
	//valeur 
	int m_vie;
	int m_vitesse;
	int m_degatsArme;
	bool m_alive;

};