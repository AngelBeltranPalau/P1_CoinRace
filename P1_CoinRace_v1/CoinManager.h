#pragma once
#include "Map.h"
class CoinManager
{

public:
	void rellenarMapa();
	void eliminarMoneda( int x, int y);
	Map &mimapa;
	CoinManager(Map &A);
	~CoinManager();
};

