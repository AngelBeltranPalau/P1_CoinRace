#pragma once
#include "Map.h"
#include "Input.h"
#include "CoinManager.h"
class Player
{
public:
	CoinManager &micoinmanager;
	Map &mimapa;

	int x, y, puntos;
	bool gameESC;
	
	void mover(int &x, int &y, int &puntos, Input::Key tecla);
		
	Player(Map &a, CoinManager &b);
	~Player();
};