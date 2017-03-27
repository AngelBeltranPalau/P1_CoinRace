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
	
	void mover(int x, int y, Input::Key tecla/*, Map A, CoinManager Z*/);
		
	Player(Map &a, CoinManager &b);
	~Player();
};